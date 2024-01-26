#include <stdio.h>
#include <unistd.h>
#include <wait.h>

/**
 * How many processes are created? 
 * 
 * 8!
 * 
 * +) 코드보고 출력 예상하는 것도 메모리 레이아웃 그려가면서 해보기
*/

int value = 5;

int main(){
    fork(); // child process
    value += 5;
    printf("Hello, fork()! %d\n", value);

    fork(); // fork another child process
    value += 5;
    printf("Hello, fork()! %d\n", value);

    fork(); // and fork another
    value += 5;
    printf("Hello, for3.31_process_creation5.ck()! %d\n",value);


    return 0;
}