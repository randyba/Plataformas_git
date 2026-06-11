#include <stdio.h>
#include <stdlib.h>

void FindLargestLine(int **matrix, int size, int *result) {

}

void allocateMatrix(int ***matrix, int size) {

}

void fillmatrix(int **matrix, int size) {

}

void printMatrix(int **matrix, int size) {
    printf("Matriz (%d x %d):\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) { 
            printf("%d", *(*(matrix + i) + j));
        }
        printf("\n");
    }

}

void freematrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(*(matrix + i));
    }
    free(matrix);
}

int main(void) {
    int size, largestLine;
    int **matrix= NULL;



    printf("El tamano de la secuencia de 1s mas grande es: %d\n", largestLine);
    return 0;
}