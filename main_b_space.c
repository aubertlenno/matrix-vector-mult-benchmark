#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mylib/mylib.h"

int main(void) {

    int N = 2000;
    int* Matrix = (int *) malloc(N*N*sizeof(int));
    int* Vector = (int *) malloc(N*sizeof(int));
    int* Result = (int *) malloc(N*sizeof(int));

    initMat(Matrix, N);
    printf("Matrix = ");
    initVec(Vector, N);
    printf("Vector = ");

    while (1) {
        matVecMult(Matrix,Vector,Result,N);
        }

    return 0;

    
}