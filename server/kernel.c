#include <unistd.h>
#include <string.h>
#include "headers/http.h"
#include "headers/network.h"
#include "../routes/headers/routes.h"

int put(char *string) {
        int size = strlen(string);
        return write(peer, string, size);
}

// network.c calls for this function after receiving a tcp packet
// here we need to start the http parser
// at the moment it ignored the http packet entirely and replies with the homepage lol
int next(int peer) {
	for (int l=0; l<(sizeof(http)/sizeof(http[0])); l++) {
		if (! put(http[l])) return 1;
	}
        char packet[1024];
        read(peer, packet, sizeof(packet));
        http_parse(packet);
        http_respond();
	return route();
}

int kernel_start() {
	return server_listen(PORT, 0);
}
