#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mylib/mylib.h"

#define LOWER 1
#define UPPER 9

int generateRandomInt(int lower, int upper){
    return (rand() % (upper-lower+1)) + lower;
}

void initMat(int* M, int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            M[N*i+j] = generateRandomInt(LOWER,UPPER);
        }
    }
}

void initVec(int* v, int N){
    for(int i=0; i<N; i++){
        v[i] = generateRandomInt(LOWER,UPPER);
    }
}

void test_multiply_vector_matrix(int *M, int *v, int N, int *vector_expected){
    int *Mv = (int*)malloc(N * sizeof(int));

    if (Mv == NULL){
        printf("Malloc is failed!\n");
        return;
    }
    
    matVecMult(M, v, Mv, N);

    int i;
    for (i = 0; i < N; i++){
        printf("Actual V[%d] = %-2d; Expected V[%d] = %-2d\n", i, Mv[i], i, vector_expected[i]);
        assert(Mv[i] == vector_expected[i]);
    }
}

int main(){
    int total_test_cases = 3;
    int N = 3;

    int matrix_input_test_case[3][9] = {
        {1, 2, 3, 3, 4, 5, 1, 2, 3},
        {3, 5, 6, 7, 8, 9, 12, 15, 12},
        {1, 2, 3, 3, 2, 1, 1, 2, 3}
    };

    int vector_input_test_case[3][3] = {
        {1, 2, 3},
        {1, 4, 7},
        {4, 5, 6}
    };

    int vector_expected_test_case[3][3] = {
        {14, 26, 14},
        {65, 102, 156},
        {32, 28, 32}
    };

    int i;
    for (i = 0; i < total_test_cases; i++)
    {
        printf("Test #%d:\n", i + 1);

        test_multiply_vector_matrix(
        matrix_input_test_case[i],
        vector_input_test_case[i],
        N,
        vector_expected_test_case[i]
        );
         
        printf("\n");
    }

    return 0;
}