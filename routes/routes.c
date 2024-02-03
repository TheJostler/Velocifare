#include <unistd.h>

/*
this is a switch case that takes a path
as an argument and calls a funtion depending on ths path.

this file contains the User's defined routes
*/

int route() {
	write(1, HTTP_header.path, sizeof(HTTP_header.path));
    return 0;
}
