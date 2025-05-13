#include "a.h"

static char buffer[BUFFER_SIZE];
static char* word;
static int array[N*M];

int ten_pow(int p){
    int result = 10;
    while(--p > 0) result *= 10;
    return result;
}

void string_to_int_array(){
    int j = N*M;
    memset(array, 0, sizeof(int) * N * M);
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

void my_write(int fd){
    
    // READING
    lseek(fd, 0, SEEK_SET);

    // read string from file
    read(fd, buffer, BUFFER_SIZE);
    
    // string -> INT
    string_to_int_array();

    // shift
    memcpy(array+N, array, sizeof(int)*((M-1)*N));

    // generate randoms
    int tp = ten_pow(SIGNES);
    srand(time(NULL));
    for(int i = 0; i < N; i++)
        array[i] = rand()%(tp+1)-tp/2;
        
    // WRITING

    lseek(fd, 0, SEEK_SET);
    // write array to file
    
    memset(buffer, 0, BUFFER_SIZE);
    for(int i = 0; i < M*N; i++){
        sprintf(buffer+strlen(buffer), "%d ", array[i]);
        if((i+1) % N == 0) sprintf(buffer+strlen(buffer),"\n");
    }

    write(fd, buffer, strlen(buffer));
    //fprintf(general_file, "%s", buffer);

}

void my_read(int fd){

    // READING
    lseek(fd, 0, SEEK_SET);

    // read string from file
    read(fd, buffer, BUFFER_SIZE);
    
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

    pid_t pid1; 
    pid_t pid2;

    int gl_m;

    pid1 = getpid();

    // open file
    int general_file = open(TXT_FILE, O_RDWR);

    pid2 = fork();
    if (pid2 == 0) /* process 2 */
    {
        signal(SIG1, handler1);
        pid2 = getpid();
        for (;;){

            pause(); // wait signal from parent

            my_write(general_file); // making his work

            kill(pid1, SIG1); // answering parent the end
        }
    }
    else /* process 1 */
    {
        sleep(1); // timeout for correct child
        signal(SIG1, handler2);
        signal(SIGTERM, handler3); // settin handlers

        for(gl_m = M; gl_m != 0; gl_m--){
            
            kill(pid2, SIG1); // signal to child

            pause(); // wait for answer

            my_read(general_file); // do parent work
        }

        close(general_file); // saving


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
    sleep(1); // timeout to normal rand   

}

void handler3(int signum)
{
    if(signum == SIGTERM) exit(0);
    else exit(-1);
}

