#include <stdio.h>
#include <stdlib.h>



unsigned char *read_pgm (const char *filename, int *width, int *height, int *max_val){
    
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
    unsigned char *actual = pixels; // este puntero va a los pixeles
    unsigned char *fin = pixels + total; // va al final

    while (actual < fin) { // preguntamos si es logico que no estemos en el final
        *actual = 255 - *actual; //como se invierte, entonces se resta el valor a 255
        actual++;
    }

    return pixels;

}

void write_pgm(const char *filename, unsigned char *pixels, int width, int height, int max_val) {

}

void print_stats(unsigned char *original, unsigned char *thresholded,int total) {

}

int main(void){
    int width, height, max_val;
    unsigned char *pixels = NULL;
    unsigned char *negative = NULL;


    return 0;

}