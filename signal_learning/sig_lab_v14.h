#ifndef A_H_
#define A_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>



void handler1(int);
void handler2(int);
void handler3(int);

void my_read(int);
void my_write(int);
void string_to_int_array();

int ten_pow(int p);

#define M 5
#define N 10
#define SIGNES 2

#define SIG1 SIGUSR1

#define TXT_FILE "/home/vboxuser/Repos/manualDir/signal_learning/lab_tmp.txt"
#define BUFFER_SIZE SIGNES*2*M*N


#endif