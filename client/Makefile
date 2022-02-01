# Link driver and server to create executable
pingPongClient : pingPongClient.o client.o
	g++ pingPongClient.o client.o -o pingPongClient

# compile each cpp file into 
%.o : %.cpp
	g++ -c $<
