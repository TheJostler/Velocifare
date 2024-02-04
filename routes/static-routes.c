#include "headers/static-routes.h"

/*This file will be generated at build
time and will contain route definitions
for all the static files publicly 
available. it will work the same way as
the user defined routes and will be called by the default switch case in the
routes.c file.

if this file has no route for a given path, a 404 response will be given from here.
*/

int static_routes() {
    http_status = 400;
    return render_404();
}
