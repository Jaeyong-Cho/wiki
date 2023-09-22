#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>

int main()
{
    struct sockaddr_in s_so_in1;
    struct sockaddr_in s_so_in2;
    struct sockaddr_in c_so_in1;
    struct sockaddr_in c_so_in2;

    socklen_t so_len;

    char str1[7] = {0};
    char str2[7] = {0};

    int serv_fd1;
    int serv_fd2;
    int clnt_fd1;
    int clnt_fd2;
    int ret;

    s_so_in1.sin_family = AF_INET;
    s_so_in1.sin_addr.s_addr = 0;
    s_so_in1.sin_port = htons(12345);

    s_so_in2.sin_family = AF_INET;
    s_so_in2.sin_addr.s_addr = 0;
    s_so_in2.sin_port = htons(12346);

    serv_fd1 = socket(AF_INET, SOCK_STREAM, 0);
    if (serv_fd1 == -1)
        perror("socket failed");

    serv_fd2 = socket(AF_INET, SOCK_STREAM, 0);
    if (serv_fd2 == -1)
        perror("socket failed");

    ret = bind(serv_fd1, (struct sockaddr*) &s_so_in1, sizeof(struct sockaddr));
    if (ret == -1)
        perror("bind failed");

    ret = bind(serv_fd2, (struct sockaddr*) &s_so_in2, sizeof(struct sockaddr));
    if (ret == -1)
        perror("bind failed");

    ret = listen(serv_fd1, 10);
    if (ret == -1)
        perror("listen failed");

    ret = listen(serv_fd2, 10);
    if (ret == -1)
        perror("listen failed");

    clnt_fd1 = accept(serv_fd1, (struct sockaddr*) &c_so_in1, &so_len);
    if (clnt_fd1 == -1)
        perror("accept failed");

    clnt_fd2 = accept(serv_fd2, (struct sockaddr*) &c_so_in2, &so_len);
    if (clnt_fd2 == -1)
        perror("accept failed");

    ret = recv(clnt_fd1, str1, sizeof(str1) - 1, 0);
    if (ret == -1)
        perror("recvmsg failed");

    printf("recvmsg recv data: %d\n", ret);
    printf("%s\n", str1);

    ret = recv(clnt_fd2, str2, sizeof(str2) - 1, 0);
    if (ret == -1)
        perror("recvmsg failed");

    printf("recvmsg recv data: %d\n", ret);
    printf("%s", str2);
}
