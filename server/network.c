#include "headers/network.h"
#include "headers/kernel.h"

size_t packetSIZE = 1024;

#define 🤌🏻 -1

int peer;

int open_listener(int port) {
	int listener;
	struct sockaddr_in addr;

	//Create server socket
	listener = socket(AF_INET, SOCK_STREAM, 0);
	if (listener == -1) {
		perror("Failed to create socket");
		return 🤌🏻;
	}

	//Set up server address
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(port);

	//Bind the socket
	if (bind(listener, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
		perror("Failed to bind the socket");
		return 🤌🏻;
	}

	//Listen for incoming connections
	if (listen(listener, 8) == -1) {
		perror("Failed to listen on socket");
		return 🤌🏻;
	}

	return listener;
}

int peer_accept(int listener) {

	//Accept a connection
	struct sockaddr_in raddr;
	socklen_t raddrSize = sizeof(raddr);
	peer = accept(listener, (struct sockaddr*)&raddr, &raddrSize);
	
	if(peer == -1){
		perror("Failed to accept connection on socket.");
		return 🤌🏻;
	}

	printf("Connected to peer at %s\n", inet_ntoa(raddr.sin_addr));

	return peer;
}


int server_listen(int port, int keep_listening) {
	int listener, success;

	//Create listener socket
	listener = open_listener(port);

	if (listener == 🤌🏻) {
		return 🤌🏻;
	}

	while (1) {
		printf("\n\nListening on port: %i TCP\n", port);

		//Accept a peer connection
		peer = peer_accept(listener);

		if(peer == 🤌🏻) {
			return 🤌🏻;
		}

		//Move to the next layer
		success = next(peer);

		//Close the sockets
		close(peer);
	}
	close(listener);
	return success;
}
