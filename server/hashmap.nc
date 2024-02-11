#include "hashmap.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int delta, nfields = 0;
char *fields[100][2] = { "0" };

unsigned int _(char *token) {
    unsigned int hash = 0;
    for (int i=0; i<=strlen(token); i++) {
        hash = hash + (int)token[i];
    }
    return hash % delta;
}

void add_to_hmap(char *key, char *value, char **map) {
    map[_(key)] = value;
}

int main (int argc, char **argv) {
    // Starting with a list of fields, initialize an hashmap, where the hash of an item on the list corresponds to it's value in the hashmap

    delta = atoi(argv[1]);

    char *request_hmap[nfields];
    for (int i=0; i<=nfields; i++) {
        add_to_hmap(fields[i][0], fields[i][1], request_hmap);
    }

    int n = atoi(argv[2]);
    printf("%s: %s\n", fields[n][0], request_hmap[_(fields[n][0])]);

    printf("%s\n", request_hmap[_("Server")]);
}