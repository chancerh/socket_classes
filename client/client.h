#include <netinet/in.h> 
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string>
#include <unistd.h>

#ifndef CLIENT_H
#define CLIENT_H
class Client {

private:
    int sock, valread, port;
    struct sockaddr_in serv_addr; //This store all of the connection stuff (I think?)

    // buffers have to be sent/recieved as char arrays, but the object can
    // store them as strings
    std::string sendContents, responseContents; 

    // Store the buffersize
    int bufferSize;

public:
    // Constructor - set sock(?), the port, and the buffersize
    Client(int sock, int port, int bufferSize);

    // This makes a connection to the server. It currently
    // must be run each time you want to send/recieve from a server
    int makeConnection();

    // This sets the message to be sent to the server. It does not 
    // send it though
    void setSendContents(std::string);

    // this sends the message set by the setSendContents function
    int sendMessage();

    // This retrieves the message sent by the server and stores
    // it as a field of the client object
    int recieveResponseContents();

    // This gets the stored server response
  std::string getResponseContents();

  int closeSocket();
    
};
#endif
