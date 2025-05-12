#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    
    
    pid_t pid1,pid2,pid3,pid4,pid5,pid6;

    pid1 = fork();

    if(pid1 == 0){

        pid2 = fork();

        if(pid2 == 0);
        else if(pid2 > 0);
        else perror("fork2");

    }else if(pid1 > 0){

        pid3 = fork();
        
        if(pid3 == 0){

            pid4 = fork();

            if(pid4 == 0){

                pid5 = fork();

                if(pid5 == 0);
                else if(pid5 > 0){

                    pid6 = fork();

                    if(pid6 == 0);
                    else if(pid6 > 0);

                    else perror("fork6");

                }else perror("fork5");

            }else if(pid4 > 0);
            else perror("fork4");

        } else if(pid3 > 0){

            char buff[100];
            sprintf(buff,"%d", (int)getpid());
            execl("/bin/pstree", "pstree", buff, "-p", NULL);
        
        }else perror("fork3");

    }else perror("fork1");
    
    sleep(5);
    
    return 0;
}