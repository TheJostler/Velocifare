#ifndef HTTP_H 
#define HTTP_H

struct http_header{
    char *method, *path, *protocol;
    char *fields[100][2];
};

extern struct http_header HTTP_header;
extern char *http_type;
extern int http_status;

int http_parse(char *packet);
int http_respond();
#endif