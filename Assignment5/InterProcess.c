#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>

int main()
{
    int pfd[2];

    int r = pipe(pfd);

    assert(r == 0);

    char wbuf[BUFSIZ];

    sprintf(wbuf, "Hello From Process ID %d\n", getpid());

    ssize_t n = write(pfd[1], wbuf, strlen(wbuf));

    assert(n == (ssize_t)strlen(wbuf));

    //  reader

    char rbuf[BUFSIZ];

    n = read(pfd[0], rbuf, BUFSIZ);

    assert(n >= 0);

    rbuf[n] = 0;

    // compare

    assert(strcmp(wbuf, rbuf) == 0);
    printf("Write %s", wbuf);
    printf("Read %s", rbuf);
}