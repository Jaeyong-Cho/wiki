all: epoll_server epoll_client

epoll_server: epoll_server.c
	gcc epoll_server.c -o epoll_server

epoll_client: epoll_client.c
	gcc epoll_client.c -o epoll_client

clean:
	rm epoll_server epoll_client
