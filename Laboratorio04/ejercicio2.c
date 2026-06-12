#include <stdio.h>
#include <stdlib.h>



unsigned char *read_pgm (const char *filename, int *width, int *height, int *max_val){
    
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error al abrir el archivo %s\n", filename);
        return NULL;
    }

    char magic[3] = {0};
    if (fscanf(file, "%2s", magic) != 1 || magic[0] != 'P' || magic[1] != '2') {
        fprintf(stderr, "Error: formato no valido o no es P2 en %s\n", filename);
        fclose(file);
        return NULL;
    }

    int c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '#') {
            while (c != '\n' && c != EOF) {
                c = fgetc(file);
            }
            continue;
        }
        if (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
            continue;
        }
        ungetc(c, file);
        break;
    }

    if (fscanf(file, "%d %d %d", width, height, max_val) != 3) {
        fprintf(stderr, "Error al leer el encabezado del archivo %s\n", filename);
        fclose(file);
        return NULL;
    }

    int total = (*width) * (*height);
    unsigned char *pixels = malloc(total * sizeof(unsigned char));
    if (pixels == NULL) {
        fprintf(stderr, "Error al asignar memoria para los pixeles\n");
        fclose(file);
        return NULL;
    }

    unsigned char *current = pixels;
    unsigned char *end = pixels + total;
    while (current < end) {
        int value;
        if (fscanf(file, "%d", &value) != 1) {
            fprintf(stderr, "Error al leer los pixeles del archivo %s\n", filename);
            free(pixels);
            fclose(file);
            return NULL;
        }
        *current = (unsigned char)value;
        current++;
    }

    fclose(file);
    return pixels;
}

void apply_threshold(unsigned char *pixels, int total, int threshold) {
    unsigned char *actual = pixels; // este puntero va a los pixeles
    unsigned char *fin = pixels + total; // va al final

    while (actual < fin) { // preguntamos si es logico que no estemos en el final
        if (*actual >= threshold) { // decimos que si el pixel es mayor al himbral, lo seteamos en blanco
            *actual = 255;
        } else {
            *actual = 0; // si no es asi, lo seteamos en negro
        }
        actual++; // avanzamos en el recorrrido
    }

    // funcioncita mas dolor de cabezaaaa!!!!
}

unsigned char *make_negative(unsigned char *pixels, int total) {
    unsigned char *negative = malloc(total * sizeof(unsigned char));
    if (negative == NULL) {
        fprintf(stderr, "Error al asignar memoria para el negativo\n");
        return NULL;
    }

    unsigned char *actual = pixels; // puntero a pixels original
    unsigned char *fin = pixels + total; // va al final
    unsigned char *neg_ptr = negative; // puntero a negativo

    while (actual < fin) {
        *neg_ptr = 255 - *actual; // invertir: 255 - pixel
        actual++;
        neg_ptr++;
    }

    return negative;
}

void write_pgm(const char *filename, unsigned char *pixels, int width, int height, int max_val) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error al abrir el archivo %s para escribir\n", filename);
        return;
    }

    // Escribir encabezado
    fprintf(file, "P2\n");
    fprintf(file, "%d %d\n", width, height);
    fprintf(file, "%d\n", max_val);

    // Escribir píxeles usando aritmética de punteros
    unsigned char *current = pixels;
    unsigned char *end = pixels + (width * height);
    int count = 0;

    while (current < end) {
        fprintf(file, "%d", *current);
        current++;
        count++;
        
        // Añadir salto de línea cada 'width' píxeles para formato legible
        if (count % width == 0) {
            fprintf(file, "\n");
        } else if (current < end) {
            fprintf(file, " ");
        }
    }

    fclose(file);
}

void print_stats(unsigned char *original, unsigned char *thresholded, int total) {
    int white_count = 0;  // píxeles con valor 255
    int black_count = 0;  // píxeles con valor 0
    long sum = 0;         // suma de píxeles originales para calcular promedio

    unsigned char *curr_threshold = thresholded;
    unsigned char *curr_original = original;
    unsigned char *end = thresholded + total;

    while (curr_threshold < end) {
        // Contar blancos y negros en la imagen umbralizada
        if (*curr_threshold == 255) {
            white_count++;
        } else if (*curr_threshold == 0) {
            black_count++;
        }
        
        // Sumar valores originales
        sum += *curr_original;
        
        curr_threshold++;
        curr_original++;
    }

    // Calcular promedio
    double average = (double)sum / total;

    // Imprimir estadísticas
    printf("\n===== ESTADÍSTICAS =====\n");
    printf("Píxeles blancos (255): %d\n", white_count);
    printf("Píxeles negros (0): %d\n", black_count);
    printf("Valor promedio de píxeles originales: %.2f\n", average);
    printf("========================\n");
}


int main(void){
    int width, height, max_val;
    unsigned char *pixels = NULL;
    unsigned char *pixels_threshold = NULL;
    unsigned char *negative = NULL;
    int threshold = 0;

    // Leer la imagen PGM
    pixels = read_pgm("input.pgm", &width, &height, &max_val);
    if (pixels == NULL) {
        fprintf(stderr, "Error: No se pudo leer input.pgm\n");
        return 1;
    }

    int total = width * height;

    // Solicitar umbral al usuario
    printf("Ingrese el valor del umbral (0-255): ");
    if (scanf("%d", &threshold) != 1) {
        fprintf(stderr, "Error al leer el umbral\n");
        free(pixels);
        return 1;
    }

    // Validar rango del umbral
    if (threshold < 0 || threshold > 255) {
        fprintf(stderr, "Error: El umbral debe estar entre 0 y 255\n");
        free(pixels);
        return 1;
    }

    // Crear copia de pixels para aplicar umbral (preservar original para estadísticas)
    pixels_threshold = malloc(total * sizeof(unsigned char));
    if (pixels_threshold == NULL) {
        fprintf(stderr, "Error al asignar memoria para la imagen umbralizada\n");
        free(pixels);
        return 1;
    }

    // Copiar pixels a pixels_threshold
    unsigned char *src = pixels;
    unsigned char *dst = pixels_threshold;
    unsigned char *end = pixels + total;
    while (src < end) {
        *dst = *src;
        src++;
        dst++;
    }

    // Aplicar umbral a la copia
    apply_threshold(pixels_threshold, total, threshold);

    // Crear negativo de la imagen umbralizada
    negative = make_negative(pixels_threshold, total);
    if (negative == NULL) {
        fprintf(stderr, "Error al crear el negativo\n");
        free(pixels);
        free(pixels_threshold);
        return 1;
    }

    // Escribir archivos de salida
    write_pgm("output_threshold.pgm", pixels_threshold, width, height, 255);
    write_pgm("output_negative.pgm", negative, width, height, 255);

    printf("Archivo output_threshold.pgm escrito correctamente\n");
    printf("Archivo output_negative.pgm escrito correctamente\n");

    // Imprimir estadísticas
    print_stats(pixels, pixels_threshold, total);

    // Liberar memoria
    free(pixels);
    free(pixels_threshold);
    free(negative);

    return 0;

}