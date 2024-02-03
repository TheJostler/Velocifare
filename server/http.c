#include <string.h>
#include <unistd.h>

// Define data structures for the application:
struct http_header{
    char *method, *path, *protocol;
};

struct http_header HTTP_header;

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
