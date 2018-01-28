#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    return 0;
}

void pointers() {
    int shaka = 10;
    int *pointer;    //create a pointer
    pointer = &shaka;   //refers to adress of shaka
    printf("%d", *pointer);     //print the content at this adress
}

void dynamicMemory() {
    int n = 1000;   //# of array elements
    int *a;     //pointer to first array element
    a = (int*) malloc(n*sizeof(int));   //dynamically allocate memory for n integers

    //a can now be considered as an array!

    int i; //counters cannot be declared in for-statements
    for (i = 0; i < n; i++) {
        a[i] = rand();  //fill with random elements
    }

    for (i = 0; i < n; i++) {
        printf("a[%d] = %d", i, a[i]);
    }
}