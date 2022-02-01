#include "client.h"
#include <string>
#include <iostream>

int main() {

    // Instantiate a new client object with
    Client* client = new Client(0, 8080, 1024);
    
    // Hold user input (will be sent to server)
    std::string input;

    // Allow user to interactively send "ping" to the
    // server. Loop continues until user inputs something
    // other than "ping"
    do {
        // Each time you send something to the server, 
        // you have to make a connection
        client->makeConnection();

        // get user input
        std::cin >> input;
        
        // Set the input that will be sent
        client->setSendContents(input);

        // this actually does the sending.
        // This seems like it should be one step, 
        // and porbably should be. 
        client->sendMessage();
            
        // This has the client retrieve the server response, 
        // which is then stored in the object. It will
        // overwrite anything there!
        client->recieveResponseContents();

        // get the server response as a string
        std::string respns = client->getResponseContents();

        // output server response. 
        std::cout << "Server Response:" << respns << std::endl;
    } while (input == "ping");


}