/*
funciones.c
IE-0117 Laboratorio 05

los camibios y manejo de la logica de las funciones se manejan en este archivo.
*/
#include "Funciones.h"

//funcion para crear un arreglo con memoria dinamica
int* crearArreglo(int tamano) {
    int* arreglo = (int*)malloc(tamano * sizeof(int));
    if (arreglo == NULL) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    return arreglo;
}

//funcion para agregar un elemento al arreglo
void agregarElemento(int* arreglo, int tamano, int elemento) {
    for (int i = 0; i < tamano; i++) {
        if (arreglo[i] == 0) { // Asumiendo que 0 indica una posición vacía
            arreglo[i] = elemento;
            return;
        }
    }
    printf("No hay espacio disponible para agregar el elemento.\n");
}