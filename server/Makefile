
# Link driver and server to create executable
driver : driver.o server.o
	g++ driver.o server.o -o driver


# Compile any required .cpp file required by the driver
driver.o : driver.cpp
	g++ -c $<

server.o : server.cpp server.h
	g++ -c $<