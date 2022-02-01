#include "server.h"
#include <unistd.h>
#include <sys/socket.h>
#include <string.h> // for strlen()
#include <iostream>

Server::Server(int opt, int bufferSize, int port) {
    this->opt = opt;
    this->bufferSize = bufferSize;

	

    // Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

    	// Forcefully attaching socket to the port 8080
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, 
        sizeof(opt)))
	{
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}

    address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons( port );

    // Forcefully attaching socket to the port 8080
	if (bind(server_fd, (struct sockaddr *)&address,
								sizeof(address))<0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}


}  
int Server::startListen() {

	// I *think* read and send functions require character arrays, so we will make 
	// a char array and convert it to a string when we have recieved from the client
	// We probably want to replace this with smart pointers, but use standard ones for now
	char* buffer = new char[bufferSize]{0};
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
		(socklen_t*)&addrlen))<0)
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}
	
	valread = read( new_socket , buffer, bufferSize);

	// This is a round about way to change a char array to stl string.
	// Convert the buffer contents to a string and set the readContents attribute
	std::string str(buffer);
	readContents = str;
	// delete buffer after finished listening. 
	delete[] buffer;
    return 0;
}

int Server::sendToClient() {
	// Need to pass contents to send as char array, rather than a string.
	char* buffer = &sendContents[0];
	send(new_socket , buffer, sendContents.size(), 0 );
	return 0;
}

std::string Server::getReadContents() {
	return readContents;
}

void Server::setSendContents(std::string sendContents) {
	this->sendContents = sendContents;
}


