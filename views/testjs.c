#include "headers/views.h"

int render_testjs() {
    http_type = "text/html";
    http_respond();
    
    char *page[] = {
        "<!DOCTYPE html>",
        "<html>",
        "<body>",
        "<div id=\"test\"></div>",
        "</body>",
        "<script src=\"/javatime.js\"></script>",
        "</html>",
    };
	int n = sizeof(page)/sizeof(page[0]);
	return put(page, n);
}
