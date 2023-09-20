#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <assert.h>

int main()
{
    struct sockaddr_in s_so_in;

    int sock1;
    int sock2;
    int ret;

    char buf[1024];

    sock1 = socket(AF_INET, SOCK_STREAM, 0);
    assert(sock1 != -1);

    sock2 = socket(AF_INET, SOCK_STREAM, 0);
    assert(sock2 != -1);

    s_so_in.sin_family = AF_INET;
    s_so_in.sin_addr.s_addr = 0;
    s_so_in.sin_port = htons(12345);

    ret = connect(sock1, (struct sockaddr*) &s_so_in, sizeof(struct sockaddr));
    assert(ret != -1);

    ret = connect(sock2, (struct sockaddr*) &s_so_in, sizeof(struct sockaddr));
    assert(ret != -1);

    sprintf(buf, "Send message 1\n");

    ret = send(sock1, &buf, sizeof(buf), 0);
    assert(ret != -1);
    printf("client send to 1: %d\n", ret);

    sprintf(buf, "Send message 2\n");

    ret = send(sock2, &buf, sizeof(buf), 0);
    assert(ret != -1);
    printf("client send to 2: %d\n", ret);

    close(sock1);
    close(sock2);

    return 0;
}
