#include <sys/types.h>
#include <sys/uio.h>
#include <stdio.h>

#include <fcntl.h>
#include <assert.h>

int main()
{
    int fifo = open("./fifo", O_RDONLY);
    if(fifo == -1)
        perror("open failed");

    ssize_t nread;
    struct iovec iov[2];
    char str0[7] = {0};
    char str1[7] = {0};

    iov[0].iov_base = str0;
    iov[0].iov_len = sizeof(str0) - 1;
    iov[1].iov_base = str1;
    iov[1].iov_len = sizeof(str1) - 1;

    nread = readv(fifo, iov, 2);
    if(nread == -1)
        perror("readv failed");

    printf("readv %ld bytes\n", nread);

    printf("%s%s", str0, str1);
}
