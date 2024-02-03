struct http_header{
    char *method, *path, *protocol;
};

extern struct http_header HTTP_header;

int http_parse(char *packet);