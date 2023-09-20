#include <stdio.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/unistd.h>
#include <errno.h>
#include <assert.h>

#define MAX_EVENTS 10

int main()
{
    struct epoll_event ev;
    struct epoll_event events[MAX_EVENTS];

    struct sockaddr_in l_so_in;
    struct sockaddr_in a_so_in;

    int listen_sock;
    int conn_sock;
    int nfds;
    int epollfd;

    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    assert(listen_sock != -1);

    l_so_in.sin_family = AF_INET;
    l_so_in.sin_addr.s_addr = INADDR_ANY;
    l_so_in.sin_port = htons(12345);

    int ret = bind(listen_sock, (struct sockaddr*) &l_so_in, sizeof(struct sockaddr));
    assert(ret != -1);

    ret = listen(listen_sock, 100);
    assert(ret != -1);

    epollfd = epoll_create1(0);
    assert(epollfd != -1);

    ev.events = EPOLLIN;
    ev.data.fd = listen_sock;
    ret = epoll_ctl(epollfd, EPOLL_CTL_ADD, listen_sock, &ev);
    assert(ret != -1);

    for (;;) {
        printf("epoll_wait\n");
        nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        assert(nfds != -1);
        printf("epoll_wait nfds: %d\n", nfds);

        for (int i = 0; i < nfds; ++i) {
            printf("events fd: %d\n", events[i].data.fd);
            if (events[i].data.fd == listen_sock) {
                socklen_t so_len = sizeof(struct sockaddr);
                conn_sock = accept(listen_sock, (struct sockaddr*) &a_so_in, &so_len);
                assert(conn_sock != -1);
                printf("client sock fd: %d\n", conn_sock);

                ev.events = EPOLLIN | EPOLLRDHUP;
                ev.data.fd = conn_sock;
                ret = epoll_ctl(epollfd, EPOLL_CTL_ADD, conn_sock, &ev);
                assert(ret != -1);
            } else if (events[i].events & EPOLLIN) {
                char buf[1024];
                ret = recv(events[i].data.fd, buf, sizeof(buf), 0);
                assert(ret != -1);
                printf("server receive from %d/%d: %s", events[i].data.fd, ret, buf);

                if (ret == 0 && errno != EAGAIN) {
                    printf("If recv return 0, peer socket is closed\n");
                    printf("client socket %d closed\n", events[i].data.fd);
                    close(events[i].data.fd);
                    epoll_ctl(epollfd, EPOLL_CTL_DEL, events[i].data.fd, NULL);
                    continue;
                }
            }
        }
        sleep(1);
    }

    return 0;
}
