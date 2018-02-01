#include <stdio.h>

int main() {

#pragma omp parallel
    {



#pragma omp critical  //critical section!
        {

        }
        //consume
#pragma omp atomic //only protect update/read of X, Cheaper than critical
        {
            //X += tmp
        };
    };

    printf("Hello, World!\n");
    return 0;
}