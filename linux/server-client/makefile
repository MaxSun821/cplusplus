.PHONY:all
all:server client
	
client:client.cpp
	g++ -o $@ $^ -g
server:server.cpp
	g++ -o $@ $^ -g
.PHONY:clean
clean:
	rm -f client server