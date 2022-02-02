#include "server.h"
#include <string>
#include <iostream>

int main() {

    // Instantiate a new Server object
    Server *server = new Server(1, 1024, 8080);

    // Store string recieved by client
    std::string recieved;

    do {  
        // Tell the server to start listening. This funtion will end when
        // it recieves a message from the client (this message will be stored)
        server->startListen();

        // Get the stored message recieved by the client
        recieved = server->getReadContents();

        // dsiplay message
        std::cout << "Recieved: " << recieved << std::endl;

        // If the client sends Ping, have the server send PONG
        if (recieved == "ping") {
            // currently two-step process. First - tell the server what
            // it is going to send...
            server->setSendContents("PONG!");

            // then actually send it
            server->sendToClient();
        }

        // repeat until the server hears something other than "ping"
    } while (recieved == "ping");
    
    return 0;
} 
