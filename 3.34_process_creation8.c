#include <stdio.h>
#include <unistd.h>
#include <wait.h>

/**
 * What are the pid values?
 * A: 0
 * B: child pid
 * C: the pid of child process(; B)
 * D: parent pid
*/

int main(){
    pid_t pid, pid1;
    pid = fork();

    if(pid == 0){ // child process
        pid1=getpid(); // 자신의 pid
        printf("child: pid = %d\n",pid); // A
        printf("child: pid1 = %d\n",pid1); // B
    }
    else if(pid > 0){ // parent process
        wait(NULL);
        pid1=getpid(); 
        printf("parent: pid= %d\n",pid); // C
        printf("parent: pid1= %d\n",pid1); // D
    }

    return 0;
}