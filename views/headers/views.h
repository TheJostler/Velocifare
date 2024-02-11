#include <unistd.h>
#include "../../server/headers/network.h"
#include "../../server/headers/kernel.h"
#include "../../server/headers/http.h"

int isroute(char *method, char *path);
int render_index();
int render_ode2ip();
int render_404();
int render_testjs();
int render_javatime_js();
