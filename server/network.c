#include "headers/network.h"
#include "headers/kernel.h"

size_t packetSIZE = 1024;

#define 🤌🏻 -1

int peer;

int open_listener(int port) {
	int listener;
	int optval = 1;
	struct sockaddr_in addr;

	//Create server socket
	listener = socket(AF_INET, SOCK_STREAM, 0);
	if (listener == -1) {
		perror("Failed to create socket");
		return 🤌🏻;
	}
	//A thinga majig
	setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

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

	printf("%s -- ", inet_ntoa(raddr.sin_addr));

	return peer;
}

void handle_signal(int sig) {
	if (sig == SIGINT) {
		printf("\nQuitting\n");
		close(peer);
		exit(0);
	}
}

int server_listen(int port) {
	int listener, success;

	//Create listener socket
	listener = open_listener(port);

	if (listener == 🤌🏻) {
		return 🤌🏻;
	}
	printf("Listening on port: %i TCP\n", port);
	while (1) {

		//Accept a peer connection
		peer = peer_accept(listener);

		if(peer == 🤌🏻) {
			return 🤌🏻;
		}
		// Check for kill signal
		signal(SIGINT, handle_signal);
		//Move to the next layer
		success = next(peer);

		//Close the sockets
		close(peer);
	}
	close(listener);
	return success;
}
