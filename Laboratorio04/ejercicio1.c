#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void FindLargestLine(int **matrix, int size, int *result) {
    int maxLine = 0; // este sera un contadorsillo que lleva el dato de unos mas largo
    int lineaActual = 0; // contador de la secuencia actual de 1s
    int total = size * size;
    int *linear = *(matrix + 0); // puntero al primer elemento de la matriz

    for (int i = 0; i < total; i++) {
        if (*(linear + i) == 1) {
            lineaActual++;
        } else {
            if (lineaActual > maxLine) {
                maxLine = lineaActual;
            }
            lineaActual = 0;
        }
    }

    if (lineaActual > maxLine) {
        maxLine = lineaActual;
    }

    *result = maxLine;
}

void allocateMatrix(int ***matrix, int size) {
    int *data = (int *)malloc(size * size * sizeof(int));
    *matrix = (int **)malloc(size * sizeof(int *));

    for (int i = 0; i < size; i++) {
        *(*matrix + i) = data + i * size;
    }
}

void fillmatrix(int **matrix, int size) {
    srand(time(NULL)); 
    printf("Rellenando la matriz con 0s y 1s de manera aleatoria.\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            *(*(matrix + i) + j) = rand() % 2; // guarda el valor aleatorio en cada entrada de la matriz.
        }
    }
    return;
}

void printMatrix(int **matrix, int size) {
    printf("Matriz (%d x %d):\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) { 
            printf("%d", *(*(matrix + i) + j));
        }
        printf("\n");
    }
    return;
}

void freematrix(int **matrix, int size) {
    free(*matrix); // libera el bloque contiguo de datos
    free(matrix);
}

int main(void) {
    int size, largestLine;
    int **matrix= NULL;

    printf("Ingrese el tamano de la matriz: ");
    scanf("%d", &size);

    allocateMatrix(&matrix, size);
    fillmatrix(matrix, size);
    FindLargestLine(matrix, size, &largestLine);
    printMatrix(matrix, size);
    freematrix(matrix, size);

    printf("El tamano de la secuencia de 1s mas grande es: %d\n", largestLine);
    return 0;
}