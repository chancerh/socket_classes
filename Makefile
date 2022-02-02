# THis is the master Makefile - it runs the makefiles in the other directories

.PHONY : server
.PHONY : client
.PHONY : all

all : server client

server:
	cd server && make

client:
	cd client && make

