#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char argv[])
{
    printf("PID in ex1 = %d\n", getpid());
    char *args[] = {"A", "B"};
    execv("/ex2", args);
    printf("back to ex1\n");
    return 0;
}