#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main(){
    pid_t pid;
    pid = fork();
    if(pid > 0) // parent process
        wait(NULL);
    printf("Hello, Process! %d\n", pid);

    /*
    부모 프로세스는 wait(NULL)을 만나 wait함.
    P0가 CPU를 점유하다가 wait를 만나 CPU를 반납하고 wait queue에서 기다림.
    P1이 CPU 점유 가능해짐. 점유해서 if문 무시하고 print함. pid는 child process이므로 0을 반환.
    P1이 끝나면, wait queue에서 대기하는 P0에 끝났다는 interrupt함.
    P0가 다음 문장인 print를 마무리함.
    */
}