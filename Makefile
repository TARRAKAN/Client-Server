all:
	g++ mainServer.cpp Server.cpp -o server
	g++ mainClient.cpp Client.cpp -o client

server: mainServer.cpp Server.cpp 
	g++ mainServer.cpp Server.cpp -o server

client: mainClient.cpp Server.cpp
	g++ mainClient.cpp Client.cpp -o client
