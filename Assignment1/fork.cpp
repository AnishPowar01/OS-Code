#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
// #include <sys/wait.h>


int main() {
    
    fork();
    fork();
    fork();
    printf("Hello\n");
    
    return 0;
}