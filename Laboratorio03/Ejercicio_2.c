#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 4

int contar_unos_fila(int m[][size], int fila){
    int contador = 0;
    for (int i = 0; i < size; i++)
    {
        if (m[fila][i] == 1)
        {
            contador++;
        }
    }
    return contador;
}
int contar_unos_columna(int m[][size], int col){
    int contador = 0;
    for (int i = 0; i < size; i++)
    {
        if (m[i][col] == 1)
        {
            contador++;
        }
    }
    return contador;
};
int es_identidad(int m[][size]){
    int contador_unos = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i==j){ // para buscar en las coordenadas de la diagonal principal
                if (m[i][j] == 1) // guardamos un uno en el contador para compararlo con el tamaño de la matriz
                {
                    contador_unos++;
                }
            }
        }
    }
    if (contador_unos == size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};
//int tiene_fila_completa(int m[][size]);
//int tiene_columna_completa(int m[][size]);

int main(void){
    int fila, columna;
    int m[size][size] = {
                    {1, 0, 0, 0},
                    {0, 1, 0, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 1}};

    printf("ingrese el numero de la fila para contar unos: ");
    printf("\n");
    scanf("%d", &fila);
    fila = fila - 1; //ajuste de numero de la fila debido a que inicia en 0
    int contador_unos_fila = contar_unos_fila(m, fila);
    printf("la cantidad de unos en la fila %d es: %d\n", fila, contador_unos_fila);

    printf("ingrese el numero de la columna para contar unos: ");
    printf("\n");
    scanf("%d", &columna);
    columna = columna - 1; //ajuste de numero de la columna debido a que inicia en 0
    int contador_unos_columna = contar_unos_columna(m, columna);
    printf("la cantidad de unos en la columna %d es: %d\n", columna, contador_unos_columna);
    printf("\n");

    int identidad = es_identidad(m);
    if (identidad == 1)
    {
        printf("la matriz es identidad\n");
    }
    else
    {
        printf("la matriz no es identidad\n");
    }

    return 0;
}