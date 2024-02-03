struct http_header{
    char *method, *path, *protocol;
};

extern struct http_header HTTP_header;
extern int http_status;

int http_parse(char *packet);
int http_respond();