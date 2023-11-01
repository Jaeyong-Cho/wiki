all: server client shm_iface.o

shm_iface.o: shm_iface.cc shm_iface.h
	g++ -c shm_iface.cc -g -o shm_iface.o

server: server.cc shm_iface.o
	g++ server.cc shm_iface.o -g -o server

client: client.cc shm_iface.o
	g++ client.cc shm_iface.o -g -o client

clean:
	rm -f server client shm_iface.o shm
