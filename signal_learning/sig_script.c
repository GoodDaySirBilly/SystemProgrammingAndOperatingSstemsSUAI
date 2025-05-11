#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <signal.h>


void sig_hand(int sig) {
    printf("\nSIGNAL catched: %d\n", sig);
    if(sig == 2){    
        
        exit(0);
    }else{

        printf("\nNo.\n");
    }
}


int main(int argc, char *argv[]){

    struct sigaction act;
    sigset_t set;
    
    act.sa_handler = sig_hand; 
    sigemptyset(&act.sa_mask); 
    act.sa_flags = 0;          
    
    
    if (sigaction(SIGINT, &act, NULL) < 0) {
        perror("sigaction");
        return 1;
    }
    
    
    
    printf("Programm running. Type Ctrl+C to send SIGINT...\n");
    
    
    while(1) {
        sleep(1);
    }
    


    return 0;
}