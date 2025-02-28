#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "headers/kernel.h"

#define false 0
#define true 1

// Define data structures for the application:
struct http_header{
    char *method, *path, *protocol;
    int accept_gzip;
    char *fields[100][2];
};

// This struct contains the HTTP request header information and makes it available globally
struct http_header HTTP_header;
// This int contain the HTTP Response Status code and is available globally(200 by default)
int http_status;
char *http_type;

int http_parse(char *packet) {

    // read line 1 and gether useful info
    int counter = 0;

    http_status = 200;
    http_type = "text/html";
    HTTP_header.method = NULL;
    HTTP_header.path = NULL;
    HTTP_header.protocol = NULL;
    HTTP_header.accept_gzip = false;

    char *packet_copy = strdup(packet);

    for (char *line1 = strtok(packet_copy," "); line1 != NULL; line1 = strtok(NULL, " "))
    {
        counter++;
        switch (counter) {
            case 1:
                HTTP_header.method = line1;
                break;
            case 2:
                HTTP_header.path = line1;
                break;
            case 3:
                HTTP_header.protocol = line1;
                break;
        }
    }

    if(HTTP_header.protocol == NULL || HTTP_header.path == NULL || HTTP_header.method == NULL) {
	return 1;
    }
    
    // Reset strtok
    strtok(NULL, "");
    
    const char *line = strtok((char *)packet, "\r\n");
    while (line != NULL) {
        // Find the first occurrence of ':'
        const char *colon = strchr(line, ':');

        if (colon != NULL) {
            // Calculate the length of the field name
            size_t field_name_length = colon - line;

            // Allocate memory for field name and copy it
            char *field_name = malloc(field_name_length + 1);
            strncpy(field_name, line, field_name_length);
            field_name[field_name_length] = '\0'; // Null-terminate the field name

            // Skip spaces after ':'
            const char *value = colon + 1;
            while (*value == ' ' || *value == '\t') {
                value++;
            }

            // Allocate memory for value and copy it
            char *field_value = strdup(value);

            // Print or use field name and value as needed
            //printf("Field Name: %s, Field Value: %s\n", field_name, field_value);

            // Free allocated memory
            free(field_name);
            free(field_value);
        }

        line = strtok(NULL, "\r\n");
    }
    return 0;
}

int http_respond() {
    char http1[14];
    snprintf(http1, 14, "HTTP/%s %03i\n", "1.1", http_status);
    put1(http1);
    put1("Server: 192.168.137.115\r\n");
    put1("Content-Type: ");
    	put1(http_type);
    	put1("\r\n");
    put1("Cache-Control: public, max-age=31536000\r\n");
    put1("\r\n");
    return 0;
}
