#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>

int main()
{
    struct sockaddr_in s_so_in1;
    struct sockaddr_in s_so_in2;

    struct sockaddr_in c_so_in;

    int sock_fd1;
    int sock_fd2;
    int ret;

    sock_fd1 = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd1 == -1)
        perror("socket failed");

    sock_fd2 = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd2 == -1)
        perror("socket failed");

    int optval = 1;
    ret = setsockopt(sock_fd1, SOL_SOCKET, SO_REUSEPORT, &optval, sizeof(optval));
    if (ret == -1)
        perror("setsockopt failed");

    ret = setsockopt(sock_fd2, SOL_SOCKET, SO_REUSEPORT, &optval, sizeof(optval));
    if (ret == -1)
        perror("setsockopt failed");

    c_so_in.sin_family = AF_INET;
    c_so_in.sin_addr.s_addr = 0;
    c_so_in.sin_port = htons(54321);

    ret = bind(sock_fd1, (struct sockaddr*) &c_so_in, sizeof(struct sockaddr));
    if (ret == -1)
        perror("bind failed");

    ret = bind(sock_fd2, (struct sockaddr*) &c_so_in, sizeof(struct sockaddr));
    if (ret == -1)
        perror("bind failed");

    s_so_in1.sin_family = AF_INET;
    s_so_in1.sin_addr.s_addr = 0;
    s_so_in1.sin_port = htons(12345);

    ret = connect(sock_fd1, (struct sockaddr*) &s_so_in1, sizeof(struct sockaddr));
    if (ret == -1)
        perror("connect failed");

    s_so_in2.sin_family = AF_INET;
    s_so_in2.sin_addr.s_addr = 0;
    s_so_in2.sin_port = htons(12346);

    ret = connect(sock_fd2, (struct sockaddr*) &s_so_in2, sizeof(struct sockaddr));
    if (ret == -1)
        perror("connect failed");

    char* str1 = "hello ";
    char* str2 = "world\n";

    ret = send(sock_fd1, str1, strlen(str1), 0);
    if (ret == -1)
        perror("sendmsg failed");

    printf("sendmsg send data: %d\n", ret);

    ret = send(sock_fd2, str2, strlen(str2), 0);
    if (ret == -1)
        perror("sendmsg failed");

    printf("sendmsg send data: %d\n", ret);
}
