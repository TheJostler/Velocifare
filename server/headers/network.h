#ifndef NETWORK_H
#define NETWORK_H

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
extern int peer;

//int http(int peer);
int open_listener(int port);
int peer_accept(int listener);
int server_listen(int port, int keep_listening);

#endif
