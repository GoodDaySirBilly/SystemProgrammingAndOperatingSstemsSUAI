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
#define SIG2 SIGUSR2
#define PATH "~/Repos/manualDir"
#define TXT_FILE PATH"/lab_tmp.txt"
#define BUFFER_SIZE 1000

static FILE* general_file;
static char buffer[BUFFER_SIZE];
static int array[N*M];
pid_t p1,p2,pb;

void signal_handler1(int signo){
    signal(SIG1, signal_handler1);
    fprintf(stdout, "\n%s %d %dcatched!\n", "SIG1", p1, p2);

    sleep(1);
    kill(p2,SIG2);
    return;
}

void signal_handler2(int signo){
    signal(SIG2, signal_handler2);
    fprintf(stdout, "\n%s %d %dcatched!\n", "SIG2", p1, p2);

    sleep(1);
    kill(p1,SIG1);
    printf("Me: %d Father: %d",getpid(),getppid());
    return;
}

void my_write(){
    int m = M;
    while(--m > 0){
        //pause();
        // READING
        // open file
        general_file = fopen(TXT_FILE, "r");
        
        // read string from file
        fread(buffer,sizeof(char),BUFFER_SIZE, general_file);
        
        // close
        fclose(general_file);
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
        memcpy(array+N, array, sizeof(int)*((M-1)*N));
        // generate randoms
        srand(time(NULL));
        for(int i = 0; i < N; i++)
            array[i] = rand()%100;
        // WRITING
        // open file
        general_file = fopen(TXT_FILE, "w");
        
        // write array to file
        for(int i = 0; i < M*N; i++) fprintf(general_file, "%d ", array[i]);
        
        // close
        fclose(general_file);
    }
}

void my_read(){
    int m = M;
    while(--m > 0){
        // READING
        // open file
        general_file = fopen(TXT_FILE, "r");
        
        // read string from file
        fread(buffer,sizeof(char),BUFFER_SIZE, general_file);
        
        // close
        fclose(general_file);
        // string -> INT
        int j = N*M;
        while(--j > 0){
            if(j == N*M-1)
                array[N*M-1-j] = atoi(strtok(buffer, " "));
            else
                array[N*M-1-j] = atoi(strtok(NULL, " "));
            //sscanf(buffer,"%d",array+(N*M-1-j));
        } 
        for(int i = 0; i < N; i++){
            printf("%d ", array[i]);
            if(i == N - 1) printf("\n");
        }
    }
}

int main(){
        setpgrp();
    pid_t p1 = fork();
    int status;

    if(p1 == 0){
        pb = getpid();
        printf("%d",p1);
        p2 = getppid();
        if (signal (SIG1, signal_handler1) == SIG_ERR) {
            fprintf (stderr, "Невозможно обработать SIGINT!\n");
            exit (EXIT_FAILURE);
        }

        
    }else if(p1 > 0){
        p2 = getpid();
        pb = p1;
        if (signal (SIG2, signal_handler2) == SIG_ERR) {
            fprintf (stderr, "Невозможно обработать SIGINT!\n");
            exit (EXIT_FAILURE);
        }
        sleep(1);
        kill(p1,SIG1);
        for(;;);
        
    }else{
        perror("fork");
    }

    sleep(20);

    return 0;
}