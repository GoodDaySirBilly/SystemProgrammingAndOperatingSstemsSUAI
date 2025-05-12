#ifndef A_H_
#define A_H_

#include <sys/types.h>
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
void my_read();
void my_write();
void string_to_int_array();

#define M 5
#define N 10

#define SIG1 SIGUSR1

#define TXT_FILE "/home/vboxuser/Repos/manualDir/signal_learning/lab_tmp.txt"
#define BUFFER_SIZE 1009
#define WORD_SIZE 100

#endif