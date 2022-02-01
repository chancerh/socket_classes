#include "client.h"

Client::Client(int sock, int port, int bufferSize) {
    this->sock = sock;
    this->port = port;
    this->bufferSize = bufferSize;

    
}

int Client::makeConnection() {
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}

    serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);

    // Convert IPv4 and IPv6 addresses from text to binary form
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
	{
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}

    return 0;
}

int Client::setSendContents(std::string sendContents) {
    this->sendContents = sendContents;
}

int Client::sendMessage() {
    char* sendCharArry = &sendContents[0];
    send(sock, sendCharArry, sendContents.length(), 0);
    // maybe should send results of send function call?
    return 0;

}

int Client::recieveResponseContents() {
    char* buffer = new char[bufferSize]{0};
    valread = read( sock , buffer, bufferSize);
    std::string str(buffer);
	responseContents = str;

}

std::string Client::getResponseContents() {
    return responseContents;
}