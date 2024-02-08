#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "headers/kernel.h"

// Define data structures for the application:
struct http_header{
    char *method, *path, *protocol;
};

// This struct contains the HTTP request header information and makes it available globally
struct http_header HTTP_header;
// This int contain the HTTP Response Status code and is available globally(200 by default)
int http_status = 200;

int http_parse(char *packet) {

    // read line 1 and gether useful info
    int counter = 0;
    HTTP_header.method = "Undefined";
    HTTP_header.path = "Undefined";
    HTTP_header.protocol = "Undefined";

    for (char *line = strtok(packet," "); line != NULL; line = strtok(NULL, " "))
    {
        counter++;
        switch (counter) {
            case 1:
                HTTP_header.method = line;
                break;
            case 2:
                HTTP_header.path = line;
                break;
            case 3:
                HTTP_header.protocol = line;
                break;
        }
    }
    return 0;
}

int http_respond() {
    char http1[14];
    snprintf(http1, 14, "HTTP/%s %03i\n", "1.1", http_status);
    put1(http1);
    put1("Server: siteinc.tego\r\n");
    put1("Content-Type: text/html\r\n");
    put1("\r\n");
    return 0;
}
