#include <stdio.h>
#include <stdlib.h>

void FindLargestLine(int **matrix, int size, int *result) {
    int maxLine = 0;// este sera un contadorsillo que lleva el dato de unos mas largo
    for (int i = 0; i < size; i++) {
        int lineaactual = 0; //seteamos el contador de la linea actual a 0
        for (int j = 0; j < size; j++) {
            if (*(*(matrix + i) + j) == 1) { // en el if, vemos entrada por entrada si hay un uno
                lineaactual++;// si se cumple, entonces sumamos uno al contador
            } else {
                if (lineaactual > maxLine) { // peguuntamos si el conador es mayor al maximo para actualizar
                    maxLine = lineaactual; // defiino el nuevo valor que tendra el maximo en ese pinto
                }
                lineaactual = 0;// aqui seteo el contador para la siguiente linea.
            }
        }
        if (lineaactual > maxLine) {// pregnuro si el contador es mayor al maximo, para actualizar
            maxLine = lineaactual;
        }
    }
*result = maxLine; // pasamos el dato de la linea por debajo, por  el puntero *result
return;

}

void allocateMatrix(int ***matrix, int size) {
    *matrix = (int **)malloc(size * sizeof(int *));// se asigna o reserva la memoria para las entradas. esta parte es un poco compleja para mi.
    for (int i = 0; i < size; i++) {
        *(*matrix + i) = (int *)malloc(size * sizeof(int));// se reserva la memoria para cada fila, se ven como listas.
    }
    return;

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