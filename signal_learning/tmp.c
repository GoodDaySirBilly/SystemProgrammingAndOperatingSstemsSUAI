#include <stdio.h>
#define __USE_POSIX
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>


void signal_handler(int signo){
    fprintf(stdout, "\n%s catched!\n", "SIGINT");
    exit(0);
}


int main(){
    
    sigset_t set;
    sigfillset(&set);
    sigdelset(&set,SIGINT);
    sigprocmask(SIG_BLOCK,&set,NULL);

    if (signal (SIGINT, signal_handler) == SIG_ERR) {
        fprintf (stderr, "Невозможно обработать SIGINT!\n");
        exit (EXIT_FAILURE);
    }

    while(1) pause();
    return 0;
}