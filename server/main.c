#include "../.env.h"
#include "headers/kernel.h"

int main() {
	printf("Starting %s\n", APP_NAME);
	return kernel_start();
}
