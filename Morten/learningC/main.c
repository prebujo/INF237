#include <stdio.h>
#include <stdlib.h>

void dynamicMemory();
void pointers();

int main(int argc, char *argv[]) {
    dynamicMemory2d();
    return 0;
}

void dynamicMemory2d() {
    int m = 100, n = 200;
    int **a; //array of int-arrays points to the first pointer
    a = (int**) malloc(m*sizeof(int*)); //allocate memory for an array of pointers
    //allocate memory for each row:
    int i;
    for (i = 0; i < m; ++m) {
        a[i] = (int*) malloc(n*sizeof(int*));
    }
    //fill with random numbers:
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = rand()%10;
        }
    }
    //print:
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("a[%d][%d] = %d\n", i, j, a[i][j]);
        }
    }
}

void pointers() {
    //*a is the memory adress a points to
    //&a is the value (memory cell) a points to

    int shaka = 10;
    int *pointer;    //create a pointer
    pointer = &shaka;   //refers to adress of shaka
    printf("%d", *pointer);     //print the content at this adress
}

void dynamicMemory() {
    int n = 1000;   //# of array elements
    int *a;     //pointer to first array element
    a = (int*) malloc(n*sizeof(int));   //dynamically allocate memory for n int$

    int b[1000];   //equivalent, but static!

    //a can now be used as an array!

    int i; //counters cannot be declared in for-statements
    for (i = 0; i < n; i++) {
        a[i] = rand()%10;  //fill with random elements
    }

    for (i = 0; i < n; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
    /* ABOUT MALLOC:
     * malloc(m)
        ● allocates m bytes of contiguous memory
        ● returns the memory address (void*) of the first byte
        ● must cast returned memory address to wanted type
    ● sizeof(datatype) = number of bytes occupied by datatype-variables
    ● when the memory is no longer needed it must be
    released (free) to avoid memory leaks
    ● the compiler (might) accept
    int *a;
    a[5] = 73;
    but a runtime error (segmentation fault) could occur
    ● You can write either int *a or int* a
    ● You can write either a[i] (recommended) or *(a+i)
    ● Note that there is no range checking at runtime
     */
}

