#include <unistd.h>
#include <stdio.h>
#include "../server/headers/kernel.h"
#include "../server/headers/http.h"
#include "../views/headers/index.html.h"

/*
this is a switch case that takes a path
as an argument and calls a funtion depending on ths path.

this file contains the User's defined routes
*/

int route() {
	//Log reuests to the terminal
    printf("%s: %s\n", HTTP_header.method, HTTP_header.path);

    switch (HTTP_header.path) {
        case "/":
            return render_index0html(peer);
        default:
            return static_routes();
    }
}
