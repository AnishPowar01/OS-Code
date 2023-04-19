#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
// #include <sys/wait.h>

int main()
{

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", i);
        if (i == 5)
            exit(0);
    }

    return 0;
}