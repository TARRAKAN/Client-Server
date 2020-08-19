#include <cstdlib>
#include <iostream>
#include "Server.hpp"
int main(){
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(serverSocket < 0){
        std::cerr << ("Error: can\'t' call a socket!");
        return 0;
    }
    Server my_server(serverSocket, 18666);
    my_server.startToListen();
    return EXIT_SUCCESS;
}
