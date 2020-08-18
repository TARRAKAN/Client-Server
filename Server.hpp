#ifndef SERVER_HPP
#define SERVER_HPP
#include<iostream>
#include <netinet/in.h>
#include <memory.h>
#include <string.h>
#include <errno.h>


class Server{
private:
    int sSocket;
    int infoSocket;
    struct sockaddr_in sAddress;
public:
    bool setAdress(int port);
    void response();
    void startToListen();
    Server(int sckt, int prt);
};

#endif //SERVER_HPP

