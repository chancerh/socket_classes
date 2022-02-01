#include <netinet/in.h> 
#include <string>

#ifndef SERVER_H
#define SERVER_H

class Server {

private:
    int port; // store port
    int server_fd, new_socket, valread; // variables needed for the socket
    struct sockaddr_in address; // needed for the socket
    int opt;
    int addrlen;
    int bufferSize; // bufferSize is set when the obj is instantiated

    std::string readContents, sendContents; // store send and revieve data as strings


public:
    // Constructor
    Server(int opt, int bufferSize, int port);

    // Listen for the client message. When recieved, store
    // message recieved and exit function
    int startListen();

    // set message to be sent
    void setSendContents(std::string);

    // Send the stored message to the client
    int sendToClient();

    // get the contents that were sent from the client
    std::string getReadContents();

    
};

#endif