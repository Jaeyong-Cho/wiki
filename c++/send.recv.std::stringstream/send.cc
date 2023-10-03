#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <iostream>

int main()
{
    struct sockaddr_in so_in;
    std::stringstream stream;
    const char* buf;

    int msg1 = 1234;
    char msg2[10] = "hello";

    stream << msg1 << msg2;

    buf = stream.str().c_str();
    int size = sizeof(msg1) + sizeof(msg2);

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

    ret = send(sock_fd, buf, size, 0);
    if (ret == -1)
        perror("send failed");
}
