#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "../server/headers/kernel.h"
#include "../server/headers/http.h"
#include "../views/headers/views.h"
#include "../views/static/headers/views.h"
#include "headers/static-routes.h"

/*
this is a switch case that takes a path
as an argument and calls a funtion depending on ths path.

this file contains the User's defined routes
*/
int isroute(char *method, char *route) {
    return (strcmp(HTTP_header.path, route) == 0) && (strcmp(HTTP_header.method, method) == 0);
}

int route() {
	//Log reuests to the terminal
    printf("%s: %s\n", HTTP_header.method, HTTP_header.path);

    if (isroute("GET", "/")) return render__index_html();
    if (isroute("GET", "/ode2ip")) return render__ode2ip_html();
    if (isroute("GET", "/testjs")) return render_testjs();
    if (isroute("GET", "/javatime.js")) return render_javatime_js();

    else return static_routes();
    //return render_404();
}
