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
        printf("\n");
        scanf("%d", &exponente);
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

int es_par(int n){
    if (n % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void){

    int exponente =verificar_exponente();
    int base = verificar_base();
    int resultado = potencia(base, exponente);
    printf("%d elevado a %d es igual a %d\n", base, exponente, resultado);
    printf("\n");
    int par_o_impar = es_par(resultado);
    if (par_o_impar == 1)
    {
        printf("El resultado de N fue %d y es par\n", par_o_impar);
    }
    else
    {
        printf("El resultado de N fue %d y es impar\n", par_o_impar);
    }



    

    return 0;
}