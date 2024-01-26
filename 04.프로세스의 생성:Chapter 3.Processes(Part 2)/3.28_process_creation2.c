#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t pid;
    pid = fork();
    printf("Hello, Process! %d\n", pid);
    /*
    First Pid : child process의 pid가 리턴된다.
    Second Pid: child process가 끝난 뒤 이므로 0이 리턴된다.
    */
    return 0;
}