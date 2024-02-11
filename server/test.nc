#include <string.h>
#include <stdio.h>

int main() {
    char *fields[100][2];
    for (int i=0; i<100; i++) {
        fields[i][0] = "\0";
        fields[i][1] = "\0";
    }
    char *string = "Hello: World\r\nIam: Jeoffery\r\n";
    int is_v=0, line=0, one_i=0, two_i=-1;
    char one[48], two[96];
    
    memset(one, '\0', 48);
    memset(two, '\0', 96);

    for (int i=0; i<strlen(string); i++) {
        if (string[i] == ':') is_v=1;
        else if (string[i] == '\r') {
            fields[line][0] = one;
            fields[line][1] = two;
            is_v=0;
            i = i+4;
            line++;
        }
        else if (is_v) {
            if (two_i >= 0) two[two_i] = string[i];
            two_i++;
        } else {
            one[one_i] = string[i];
            one_i++;
        }
    }

    printf("%s\n", fields[1][1]);
}