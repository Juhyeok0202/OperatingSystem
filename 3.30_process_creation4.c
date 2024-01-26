#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int value = 5;

int main(){
    pid_t pid;
    pid = fork();

    if(pid==0) { // child process
        value + 15;
        return 0;
    }
    else if(pid > 0) { // parent process
        wait(NULL);
        printf("Parent: value = %d\n",value); //LINE A
    }

    return 0;
}

/*
[What output will be at Line A?]
A answer is 5
: 먼저, fork() system-call을 통해 parent process의 address space를 '그대로' copy하여 새로운 child process를 만든다.
그리고 이 때, 반환된 pid는 pid>0이다. 또한, fork() 시점에서 parent, child 모두 value =5 이다.

아직 wait call이 안왔기에 parent process가 else if 조건문에 들어가 wait(NULL) system-call을 만나 => wait queue로 !
child process가 CPU를 점유하게 된다. if 조건문을 만나 value값을 증가시켜 child process의 value가 20이 되고 return 0;를 만나 exit 상태가 되면,
wait-queue에 있는 parent process에게 끝났다고 알리는 interrupt를 걸어  CPU를 재점유. restore하게 하여 이전 PC값인 printf를 실행하게 하여 증가된 value값이 아닌, parent process의 value인 5를 출력된다.

지역변수로 해도 마찬가지!
*/