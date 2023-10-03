#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>
#include <iostream>
#include <sstream>

int main()
{
    struct sockaddr_in s_so_in;
    struct sockaddr_in c_so_in;

    socklen_t so_len;

    std::stringstream stream;

    int msg1;
    char msg2[10] = {0};
    int size = sizeof(msg1) + sizeof(msg2);
    char buf[size];

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

    ret = recv(clnt_fd, buf, size, 0);
    if (ret == -1)
        perror("recv failed");

    stream.write(reinterpret_cast<char*>(buf), size);
    stream >> msg1 >> msg2;

    printf("recv recv data: %d\n", ret);
    printf("%d %s", msg1, msg2);
}
