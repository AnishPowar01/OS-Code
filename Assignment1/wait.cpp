#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main() {
   
    if(fork() == 0)
    {
    printf("I am child\n");
   
    }
    else
    {
    printf("im parent\n");
    wait(NULL);
    printf("child terminated\n");
    }
    printf("bye\n");
    return 0;
}