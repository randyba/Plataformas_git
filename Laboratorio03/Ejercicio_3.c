#include <stdio.h>
#define MAX_SENSORES 10

typedef enum {NORMAL, ALERTA, FALLO} EstadoSensor;

typedef struct {
    int id;
    float valor;
    EstadoSensor estado;
} Lectura;

EstadoSensor clasificar(float valor){
    if (40.0 <= valor && valor <= 60.0)
    {
        return NORMAL;
    }
    else if (20.0 <= valor && valor < 40.0 || 60.0 < valor && valor <= 80.0)
    {
        return ALERTA;
    }
    else if (20.0 > valor || 80.0 < valor)
    {
        return FALLO;
    }
};

const char nombre_estado[][8] = {
    "NORMAL",
    "ALERTA",
    "FALLO"
};

int contar_estado(Lectura s[], int n, EstadoSensor e){
    int contador = 0;
    for (int i = 0; i < n; i++){
        if (s[i].estado == e){
            contador++;
        }
    }
    return contador;
}

int lectura_extrema(Lectura s[], int n){
    int indice_extremo = 0;
    float max_distancia = 0.0f;

    for (int i = 0; i < n; i++){
        float distancia = s[i].valor - 50.0f;
        if (distancia < 0.0f){
            distancia = -distancia;
        }
        if (i == 0 || distancia > max_distancia){
            max_distancia = distancia;
            indice_extremo = i;
        }
    }

    return indice_extremo;
}

int main(void){
    Lectura lecturas[MAX_SENSORES];

    printf("Ingrese %d lecturas (identificador y valor)\n", MAX_SENSORES);
    for (int i = 0; i < MAX_SENSORES; i++) {
        printf("Lectura %d - id: ", i + 1);
        scanf("%d", &lecturas[i].id);
        printf("Valor: ");
        scanf("%f", &lecturas[i].valor);
        lecturas[i].estado = clasificar(lecturas[i].valor);
    }

    printf("\n%-12s %-12s %-12s\n", "Identificador", "Valor", "Estado"); // lo encontre en stackoverflow
    printf("%-12s %-12s %-12s\n", "------------", "------", "------"); // y sirve para tabular o presentar la tabla
    for (int i = 0; i < MAX_SENSORES; i++) {
        printf("%-12d %-12.2f %-12s\n",
               lecturas[i].id,
               lecturas[i].valor,
               nombre_estado[lecturas[i].estado]);
    }
// mostrramos la cantidad de estados de los sensores en la pantalla
    printf("\nConteo de estados:\n");
    printf("%s: %d\n", nombre_estado[NORMAL], contar_estado(lecturas, MAX_SENSORES, NORMAL));
    printf("%s: %d\n", nombre_estado[ALERTA], contar_estado(lecturas, MAX_SENSORES, ALERTA));
    printf("%s: %d\n", nombre_estado[FALLO], contar_estado(lecturas, MAX_SENSORES, FALLO));

    int indice_extremo = lectura_extrema(lecturas, MAX_SENSORES);
    printf("\nLectura extrema:\n");
    printf("Identificador: %d\n", lecturas[indice_extremo].id);
    printf("Valor: %.2f\n", lecturas[indice_extremo].valor);

    return 0;
}
