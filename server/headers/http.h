struct http_header{
    char *method, *path, *protocol;
};

int http_parse(char *packet);