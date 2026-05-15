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
    int contador_ceros = 0;
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
            else{
                if (m[i][j] != 0) // condicion para verifiacar que el resto de los elementos de la matriz sean ceros
                {
                    contador_ceros++;
                }
            }
        }
    }
    if (contador_unos == size && contador_ceros == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};
int tiene_fila_completa(int m[][size]){
    int contador_unos = 0;
    int resultado = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++){
            
            if (m[i][j] == 1)
            {
            contador_unos++;
            }
            else
            {
                contador_unos = 0; // si encuentra un cero en la fila, el contador de unos se reinicia
            }

        }
        if (contador_unos == size)
        {
            resultado += 1; //tiene la fila completa de unos
        }
        
    }


    if (resultado >= 1)
    {
        return 1; //tiene la fila completa de unos
    }
    else
    {
        return 0; // no tiene la fila completa de unos
    }
};

int tiene_columna_completa(int m[][size]){
    int contador_unos = 0;
    int resultado = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++){

            if (m[j][i] == 1)
            {
                contador_unos++;
            }
            else
            {
                contador_unos = 0; // si encuentra un cero en la columna, el contador de unos se reinicia
            }
        }
        if (contador_unos == size)
        {
            resultado += 1; //tiene la columna completa de unos
        }
    }
    



    if (resultado >= 1)
    {
        return 1; //tiene la columna completa de unos
    }
    else
    {
        return 0; // no tiene la columna completa de unos
    }
};


void mostrar_matriz(int m[][size]){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
};

void generar_matriz(int m[][size]){
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            m[i][j] = rand() % 2; // genera un numero aleatorio entre 0 y 1
        }
    }
};


int main(void){
    // int fila, columna;
    int m[size][size] = {
                    {1, 0, 0, 0},
                    {1, 1, 0, 0},
                    {1, 0, 1, 0},
                    {1, 1, 1, 1}};

    // printf("ingrese el numero de la fila para contar unos: ");
    // printf("\n");
    // scanf("%d", &fila);
    // fila = fila - 1; //ajuste de numero de la fila debido a que inicia en 0
    // int contador_unos_fila = contar_unos_fila(m, fila);
    // printf("la cantidad de unos en la fila %d es: %d\n", fila, contador_unos_fila);

    // printf("ingrese el numero de la columna para contar unos: ");
    // printf("\n");
    // scanf("%d", &columna);
    // columna = columna - 1; //ajuste de numero de la columna debido a que inicia en 0
    // int contador_unos_columna = contar_unos_columna(m, columna);
    // printf("la cantidad de unos en la columna %d es: %d\n", columna, contador_unos_columna);
    // printf("\n");
    printf("\n");
    mostrar_matriz(m);

    int identidad = es_identidad(m);
    if (identidad == 1)
    {
        printf("la matriz es identidad\n");
    }
    else
    {
        printf("la matriz no es identidad\n");
    }

    
   
    int fila_completa = tiene_fila_completa(m);
    if (fila_completa == 1)
    {
        printf("la mariz tiene almenos una fila completa de unos\n");
    }
    else
    {
        printf("la matriz no tiene una fila completa de unos\n");
    }

    
    int columna_completa = tiene_columna_completa(m);
    if (columna_completa == 1)
    {
        printf("la matriz tiene al menos una columna completa de unos\n");
    }
    else
    {
        printf("la matriz no tiene una columna completa de unos\n");
    }

    int tamano;
    printf("ingrese el tamaño de la matriz: ");
    printf("\n");
    scanf("%d", &tamano);
    printf("\n");

    int m2[tamano][tamano];
    generar_matriz(m2);
    printf("\n");
    printf("Matriz generada aleatoriamente:\n");
    mostrar_matriz(m2);
    printf("\n");

    identidad = es_identidad(m2);
    if (identidad == 1)
    {
        printf("la matriz es identidad\n");
    }
    else
    {
        printf("la matriz no es identidad\n");
    }

    fila_completa = tiene_fila_completa(m2);
    if (fila_completa == 1)
    {
        printf("la mariz tiene almenos una fila completa de unos\n");
    }
    else
    {
        printf("la matriz no tiene una fila completa de unos\n");
    }

    columna_completa = tiene_columna_completa(m2);
    if (columna_completa == 1)
    {
        printf("la matriz tiene al menos una columna completa de unos\n");
    }
    else
    {
        printf("la matriz no tiene una columna completa de unos\n");
    }


    return 0;
}

