#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <memory.h>

#define __USE_POSIX
#include <signal.h>

#include <sys/wait.h>

// for random numbers
#include <time.h>
#include <math.h>

#define M 5
#define N 10

#define SIG1 SIGUSR1
#define PATH "~/Repos/manualDir"
#define TXT_FILE PATH"/lab_tmp.txt"
#define BUFFER_SIZE 1000

static struct FILE* general_file;
static char buffer[BUFFER_SIZE];
static int array[N*M];

void signal_handler(int signo){
    fprintf(stdout, "\n%s catched!\n", "SIGINT");
    return;
}

int main(){
    
    pid_t proc_id = fork();
    int status;

    if(proc_id == 0){
            
        sigset_t set;
        sigfillset(&set);
        sigdelset(&set,SIG1);
        sigprocmask(SIG_BLOCK,&set,NULL);

        int m = M;
        while(--m > 0){
            // open file
            general_file = fopen(TXT_FILE, "rw");
            
            // read string from file
            fread(buffer,sizeof(char),BUFFER_SIZE, general_file);
            
            // string -> INT
            int j = N*M;
            while(--j > 0){
                if(j == N*M-1)
                    array[N*M-1-j] = atoi(strtok(buffer, " "));
                else
                    array[N*M-1-j] = atoi(strtok(NULL, " "));
                //sscanf(buffer,"%d",array+(N*M-1-j));
            } 

            // shift
            memcpy(array+N, array, sizeof(int)*(M*N-1));

            // generate randoms
            srand(time(NULL));
            for(int i = 0; i < 10; i++)
                array[i] = rand()%100;

            // close
            fclose(general_file);

            kill(getppid(),SIG1);
            pause();
        }
        // do child    

        // open
        // write
        // signal -> parent
        // close
        // wait
    }else if(proc_id > 0){

        sigset_t set;
        sigfillset(&set);
        sigdelset(&set,SIG1);
        sigprocmask(SIG_BLOCK,&set,NULL);

        /*// 
             */
        // do parent
    }else{
        perror("fork");
    }

    return 0;
}