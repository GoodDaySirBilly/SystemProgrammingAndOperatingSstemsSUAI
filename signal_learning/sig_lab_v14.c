#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define __USE_POSIX
#include <signal.h>

#include <sys/wait.h>

// for random numbers
#include <time.h>
#include <math.h>

#define M 5
#define N 10

#define SIG1 SIGUSR1

static struct FILE* general_file;

int main(){
    
    pid_t proc_id = fork();
    int status;

    if(proc_id == 0){
        // do child
        
        wait(&status);


    }else if(proc_id > 0){
        // do parent
    }else{
        perror("fork");
    }

    return 0;
}