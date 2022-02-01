
# Link driver and server to create executable
pingPongClient : pingPongClient.o client.o
	g++ pingPongClient.o client.o -o pingPongClient


# Compile any required .cpp file required by the driver
pingPongClient.o : pingPongClient.cpp
	g++ -c $<

client.o : client.cpp client.h
	g++ -c $<