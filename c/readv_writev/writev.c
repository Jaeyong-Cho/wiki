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
    if (ret == -1) {
        perror("mkfifo failed");
    } 

    int fifo = open("./fifo", O_WRONLY);
    if (ret == -1) {
        perror("open failed");
    } 

    char *str0 = "hello ";
    char *str1 = "world\n";
    ssize_t nwritten;
    struct iovec iov[2];
    iov[0].iov_base = str0;
    iov[0].iov_len = strlen(str0);
    iov[1].iov_base = str1;
    iov[1].iov_len = strlen(str1);

    nwritten = writev(fifo, iov, 2);
    if (nwritten == -1) {
        perror("writev failed");
    } 
    printf("writev %ld bytes ", nwritten);
}
