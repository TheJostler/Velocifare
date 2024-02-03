#include <unistd.h>
#include <string.h>
#include "headers/http.h"
#include "headers/network.h"
#include "../routes/headers/routes.h"

char *http[] = {
        "HTTP/1.1 200\r\n",
        "Host: siteinc.tego\r\n",
	"\r\n",

};

char *page[] = {
	"<html>",
                "<head>",
                        "<title>Test Site</title>",
                "</head>",
                "<body>",
                        "<h1>This is a test</h1>",
                "</body>",
        "</html>",
	"\r\n",
};

int put(char *string, int soc) {
        int size = strlen(string);
        return write(soc, string, size);
}

// network.c calls for this function after receiving a tcp packet
// here we need to start the http parser
// at the moment it ignored the http packet entirely and replies with the homepage lol
int next(int peer) {
	for (int l=0; l<(sizeof(http)/sizeof(http[0])); l++) {
		if (! put(http[l], peer)) return 1;
	}
        char packet[1024];
        read(peer, packet, sizeof(packet));
        http_parse(packet);
	route();
	return 0;
}

int kernel_start() {
	return server_listen(PORT, 0);
}
