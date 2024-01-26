#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main(){
    pid_t pid;
    pid = fork();

    if(pid == 0){ // child process
        execlp("/bin/ls", "ls", NULL);
        printf("LINE J\n"); // 실행이 안됨 ; ls로 갈아 끼웠으니, copy한 context에 대한 것이 없다.
    }
    else if(pid > 0){ // parent process
        wait(NULL);
        printf("Child Complete\n");
    }

    return 0;
}