#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    char *str;
    str = (char*) malloc(4*sizeof(char));
    str = "asd\0"; //strndup("#", 10);
    printf(str);
    fflush(stdout);



    /*
    int i;
    for(i = 0; i < 10; ++i) {
        printf("\r");
        size_t len = (size_t) i;
        printf(strndup("#", 10));
        fflush(stdout);
        sleep(1);
    }

    return 0;*/
}