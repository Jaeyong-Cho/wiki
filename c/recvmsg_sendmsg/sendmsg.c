#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>

int main()
{
    struct sockaddr_in so_in;
    struct msghdr mh;
    struct iovec iov[2];

    int sock_fd;
    int ret;

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1)
        perror("socket failed");

    so_in.sin_family = AF_INET;
    so_in.sin_addr.s_addr = 0;
    so_in.sin_port = htons(12345);

    ret = connect(sock_fd, (struct sockaddr*) &so_in, sizeof(struct sockaddr));
    if (ret == -1)
        perror("connect failed");

    char* str0 = "hello ";
    char* str1 = "world\n";
    iov[0].iov_base = str0;
    iov[0].iov_len = strlen(str0);
    iov[1].iov_base = str1;
    iov[1].iov_len = strlen(str1);

    mh.msg_name = NULL;
    mh.msg_namelen = 0;
    mh.msg_iov = iov;
    mh.msg_iovlen = 2;
    mh.msg_control = NULL;
    mh.msg_controllen = 0;
    mh.msg_flags = 0;

    ret = sendmsg(sock_fd, &mh, 0);
    if (ret == -1)
        perror("sendmsg failed");

    printf("sendmsg send data: %d\n", ret);
}
