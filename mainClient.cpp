#include<cstdlib>
#include"Client.hpp"

int main(){
    int clSocket = socket( AF_INET, SOCK_STREAM, 0 );
    Client my_client(clSocket);
    my_client.cConnect();
}
