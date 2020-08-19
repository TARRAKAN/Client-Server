#include"Client.hpp"

void Client::respond(){
     char buf[] = "Hello, world!";
      result = send(cSocket, "Hello, world!", 13, 0);
      if( result <= 0 )
      {
              perror( "Error calling send" );
      }
      /* закрываем соединения для посылки данных */
      if( shutdown(cSocket, 1) < 0){
              perror("Error calling shutdown");
      }
}

void Client::cConnect(){
    result = connect(cSocket, (struct sockaddr*)&cAddress, sizeof(cAddress));
}

Client::Client(int sckt): cSocket(sckt){
    cAddress.sin_family = AF_INET;
    cAddress.sin_port = htons( 18666 );
    cAddress.sin_addr.s_addr = inet_addr( "127.0.0.1" );
}
