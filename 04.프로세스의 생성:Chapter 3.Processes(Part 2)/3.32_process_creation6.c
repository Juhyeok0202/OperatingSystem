#include <stdio.h>
#include <unistd.h>
#include <wait.h>


/**
 * How many processes are created?
 * 
 * 16! 
*/
int main(){
    int i;
    pid_t pid;

    for(i=0; i<4; i++){
        pid=fork();
        printf("Hello, fork %d\n", pid);
    }    

    return 0;
}