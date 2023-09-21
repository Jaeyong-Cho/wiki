#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>

int main()
{
    struct sockaddr_in s_so_in;
    struct sockaddr_in c_so_in;
    struct msghdr mh;
    struct iovec iov[2];

    socklen_t so_len;

    char str0[7] = {0};
    char str1[7] = {0};

    iov[0].iov_base = str0;
    iov[0].iov_len = sizeof(str0) - 1;
    iov[1].iov_base = str1;
    iov[1].iov_len = sizeof(str1) - 1;

    mh.msg_iov = iov;
    mh.msg_iovlen = 2;

    int serv_fd;
    int clnt_fd;
    int ret;

    s_so_in.sin_family = AF_INET;
    s_so_in.sin_addr.s_addr = 0;
    s_so_in.sin_port = htons(12345);

    serv_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (serv_fd == -1)
        perror("socket failed");

    ret = bind(serv_fd, (struct sockaddr*) &s_so_in, sizeof(struct sockaddr));
    if (ret == -1)
        perror("bind failed");

    ret = listen(serv_fd, 10);
    if (ret == -1)
        perror("listen failed");

    clnt_fd = accept(serv_fd, (struct sockaddr*) &c_so_in, &so_len);
    if (clnt_fd == -1)
        perror("accept failed");

    ret = recvmsg(clnt_fd, &mh, 0);
    if (ret == -1)
        perror("recvmsg failed");

    printf("recvmsg recv data: %d\n", ret);
    printf("%s%s", str0, str1);
}
