#include <unistd.h>
#include <string.h>
#include "headers/http.h"
#include "headers/network.h"
#include "../routes/headers/routes.h"

#define MAX_PKT 1500

int put(char **page, int n) {
	for (int l=0; l<n; l++) {
	        int size = strlen(page[l]);
        	write(peer, page[l], size);
	}
	return 0;
}

int put1(char *string) {
	int size = strlen(string);
	return write(peer, string, size);
}

// network.c calls for this function after receiving a tcp packet
// here we need to start the http parser
int next(int peer) {
        char packet[MAX_PKT];
        read(peer, packet, MAX_PKT);
        http_parse(packet);
	//Obviously, later on we will implement controllers and middleware here
        http_respond();
	return route();
}

int kernel_start() {
	return server_listen(PORT, 0);
}
