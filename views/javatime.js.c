#include "headers/views.h"

int render_javatime_js() {
    http_type = "text/javascript";
    http_respond();
    
    char *page[] = {
        "alert('yay javatime!');",
        "var box = document.getElementById('test');",
        "box.innerHTML = \"<h1>Success</h1>\";",
    };
	int n = sizeof(page)/sizeof(page[0]);
	return put(page, n);
}