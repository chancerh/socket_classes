
# Link driver and server to create executable
driver : driver.o server.o
	g++ driver.o server.o -o driver

# compile each cpp file into 
%.o : %.cpp
	g++ -c $<
