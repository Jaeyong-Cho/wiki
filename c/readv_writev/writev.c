#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <stdio.h>

#include <string.h>
#include <fcntl.h>
#include <assert.h>

int main()
{
    int ret = mkfifo("./fifo", 0666);
    assert(ret != -1);

    int fifo = open("./fifo", O_WRONLY);
    assert(ret != -1);

    char *str0 = "hello ";
    char *str1 = "world\n";
    ssize_t nwritten;
    struct iovec iov[2];
    iov[0].iov_base = str0;
    iov[0].iov_len = strlen(str0);
    iov[1].iov_base = str1;
    iov[1].iov_len = strlen(str1);

    nwritten = writev(fifo, iov, 2);
    printf("writev %ld bytes ", nwritten);
}
