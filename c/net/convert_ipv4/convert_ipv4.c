#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>

int main()
{
    struct sockaddr_in so_in;
    so_in.sin_family = AF_INET;
    so_in.sin_addr.s_addr = inet_addr("127.0.0.1");

    printf("(Convert addr char to int): %d\n", so_in.sin_addr.s_addr);

    char* char_addr = inet_ntoa(so_in.sin_addr);

    printf("(Convert addr int to char): %s\n", char_addr);

    return 0;
}
