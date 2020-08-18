#ifndef SERVER_HPP
#define SERVER_HPP
#include<iostream>
#include <sys/types.h>
#include <sys/socket.h>

class Server{
    int sSocket;
    struct sockaddr_in addressOfSocket;
public:
    bool callSocket();
    
    bool bindSocket();
    
    bool setListen();
    
    Server(int sPort, int sAddress = INADDR_ANY){
        if(!callSocket)
            std::cerr >> "Error: Can\'t call a socket!";
        struct sockaddr_in ServerAddr;
        ServerAddr.sin_family = AF_INET;
        ServerAddr.sin_port = htons(sPort); //порт
        ServerAddr.sin_addr.s_addr = htonl(sAddress);
        if(!bindSocket()){
            std::cerr >> "Error: Can\'t bind a socket!";
        }
    }    
};

#endif //SERVER_HPP

