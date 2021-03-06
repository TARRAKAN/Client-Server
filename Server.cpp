#include "Server.hpp"

void Server::startToListen(){
    listen(this->sSocket, 5);
    this->infoSocket = accept(sSocket, NULL, NULL);
    char buffer[63];
    int counter = 0;
    std::cout << "...listening..." << std::endl;
        while(true){
            memset(static_cast<void*>(buffer), 0, sizeof(char)*63);
                int rc = recv(infoSocket, buffer, 61, 0);
                if( rc < 0 ){
                    if(errno == EINTR)
                        continue;
                    std::cerr << ("Can't receive data.");
                }
                if( rc == 0 )
                    break;
                std::cout << buffer << std::endl;
        }
    this->response();
    
}

void Server::response(){
    char response[] = "~basic response~";
      if(sendto(this->infoSocket, response, sizeof(response), 0, 
        (struct sockaddr *)&sAddress, sizeof(sAddress)) < 0)
              std::cerr << "Error sending response";
      std::cout << "Response \"" << response <<"\" sended" << std::endl;
}

bool Server::setAdress(int port){
      sAddress.sin_family = AF_INET;
      sAddress.sin_port = htons(port); //порт
      sAddress.sin_addr.s_addr = htonl(INADDR_ANY);
      if(bind(sSocket, (struct sockaddr *)&sAddress, sizeof(sAddress)) < 0){
              return false;
      }
      return true;
}

Server::Server(int sckt, int prt) : sSocket(sckt){
    if(this->setAdress(prt))
        std::cerr << "Error: can\'t set an adress!";
}
