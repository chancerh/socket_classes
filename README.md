This repository contains code adapted from the [socket programming lesson on Geeks for Geeks](https://www.geeksforgeeks.org/socket-programming-cc/)

At this point, a rough attempt has been made to construct classes for a modular interface to this functionality. A demonstration is available using the driver and pingPongClient programs in the server and client folders repectivly.

To see the ping pong example, type make while in the root directory of this project. This will create the server/driver and client/pingPongClient programs. Start the server (type server/driver) in one terminal. Start another terminal, change to the project directory, and start the pingPongClient program (client/pingPongClient). Type "ping" (without quotes). You should get a response of "PONG!" from the server. You can continue typingping to ge responses. Typing anything other then ping stops the client and the server. In the server terminal, you should see the messages recieved from the client. 
