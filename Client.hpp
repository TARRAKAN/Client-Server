#ifndef CLIENT_H
#define CLIENT_H
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
/* hton, ntoh и проч. */
#include <arpa/inet.h>
#include <memory.h>
#include <stdio.h>

class Client{
    int cSocket;
    int result;
    struct sockaddr_in cAddress;
public:
    void respond();
    void cConnect();
    Client(int sckt);
};

#endif //CLIENT_H
