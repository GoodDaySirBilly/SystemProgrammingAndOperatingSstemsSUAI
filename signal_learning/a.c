#include "a.h"

static FILE* general_file;

static char buffer[BUFFER_SIZE];
static char* word;
static int array[N*M];

static pid_t pid1; 
static pid_t pid2;
static pid_t pid2;

static int gl_m;

void string_to_int_array(){
    int j = N*M;
    
    while(--j > 0){
        
        if(j == N*M-1){
            if(( word = strtok(buffer, " ")) == NULL) break;
            array[N*M-1-j] = atoi(word);
        }else{
            if(( word = strtok(NULL, " ")) == NULL) break;
            array[N*M-1-j] = atoi(word);
        }

    }
}

void my_write(){
    
    // READING
    // open file
    general_file = fopen(TXT_FILE, "r");
    
    // read string from file
    fread(buffer,sizeof(char),BUFFER_SIZE, general_file);
    
    // close
    fclose(general_file);

    // string -> INT
    string_to_int_array();

    // shift
    memcpy(array+N, array, sizeof(int)*((M-1)*N));
    // generate randoms
    srand(time(NULL));
    for(int i = 0; i < N; i++)
        array[i] = rand()%100;
    // WRITING
    // open file
    general_file = fopen(TXT_FILE, "w");
    
    // write array to file
    for(int i = 0; i < M*N; i++){
        fprintf(general_file, "%d ", array[i]);
        if((i+1) % N == 0) fprintf(general_file,"\n");
    }
    // close
    fclose(general_file);
    
}

void my_read(){

    // READING
    // open file
    general_file = fopen(TXT_FILE, "r");
    
    // read string from file
    fread(buffer,sizeof(char),BUFFER_SIZE, general_file);
    
    // close
    fclose(general_file);
    
    // string -> INT
    string_to_int_array();

    for(int i = 0; i < N; i++){
        printf("%d ", array[i]);
        if(i == N - 1) printf("\n");
    }
}

int main()
{
    setpgrp();

    pid1 = getpid();
    pid2 = fork();
    if (pid2 == 0) /* process 1 */
    {
        signal(SIG1, handler1);
        pid2 = getpid();
        for (;;){
            pause();
            my_write();
            kill(pid1, SIG1);  
        }
    }
    else /* process 0 */
    {
        sleep(1); // timeout for correct child
        signal(SIG1, handler2);
        signal(SIGTERM, handler3);
        kill(pid2,SIG1);
        for(gl_m = M; gl_m != 0; gl_m--){
            pause();
            my_read();
            kill(pid2, SIG1);
        }
        kill(0, SIGTERM); 
    }
    
    return 0;
}

void handler1(int signum)
{
    signal(SIG1, handler1);
    //printf("Process 1 (%d) has got a signal from process 2 (%d)\n",pid2,pid1);

}

void handler2(int signum)
{
    signal(SIG1, handler2);
    //printf("Process 0 (%d) has got a signal from process 1 (%d)\n",pid1,pid2);
    sleep(1); // timeout to normal output   

}

void handler3(int signum)
{
    if(signum == SIGTERM) exit(0);
    else exit(-1);
}

