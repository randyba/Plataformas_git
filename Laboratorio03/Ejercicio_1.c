#include<stdio.h>

int potencia(int base, int exponente){
    int resultado=1;

    while (exponente>0)
    {
        resultado = resultado * base;
        exponente = exponente -1;
    }
    return resultado;
}

int verificar_exponente(){
    
    int variable_control = 0;
    int exponente;
    do
    {
        printf("ingrese el exponente: ");
        scanf("%d", &exponente);
        printf("\n");
        if (exponente < 0)
        {
                printf("el exponente no puede ser negativo\n");
        }
        else
        {
            variable_control = 1;
        }
    } while (variable_control == 0);
    
    return exponente;
}

int verificar_base(){
    
    int variable_control = 0;
    int base;
    do
    {
        printf("ingrese la base: ");
        printf("\n");
        scanf("%d", &base);
        if (base == 0)
        {
                printf("la base no puede ser cero\n");
        }
        else
        {
            variable_control = 1;
        }
    } while (variable_control == 0);
    
    return base;
}

int main(void){

    int exponente =verificar_exponente();
    int base = verificar_base();
    int resultado = potencia(base, exponente);
    printf("%d elevado a %d es igual a %d\n", base, exponente, resultado);


    

    return 0;
}