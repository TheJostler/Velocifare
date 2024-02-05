#include <unistd.h>
#include <stdio.h>

void put(char **page, int n) {
	for (int l=0; l<n; l++) {
		printf("%s\n", page[l]);
	}
}

int main() {
	char *page[] = {"Hello World"};
	//int n = sizeof(page)/sizeof(page[0]);

	put((char *[]){"Hello World"}, 1);
}
