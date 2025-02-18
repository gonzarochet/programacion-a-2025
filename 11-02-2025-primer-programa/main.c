#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#define NUMERO 120

int main()
{

//    int num = 5;
//    int valor = 10;
//    char caracter = 's';
//
//
//    printf("La variable num es %d \n",  num );
//    printf("La constante NUMERO es %d \n",  NUMERO );
//
//    printf("\nIngresa un caracter: ");
//    scanf("%c", &caracter);
//
//    printf("La variable caracter es %c \n",  caracter );
//
//
//    printf("\nIngresa un numero: ");
//    scanf("%d", &num);
//
//
//
//
//    if(num > 0)
//    {
//        printf("El valor ingresado es positivo\n");
//    }
//    else
//    {
//        if(num < 0)
//        {
//            printf("El valor ingresado es negativo ");
//        }
//        else
//        {
//            printf("El valor ingresado es 0 cero");
//        }
//    }
//
//


    int contador = 0;
    int acumulador = 0;

    while(contador < 10)
    {

        acumulador = acumulador + rand() % 10 + 1 ;

        printf("El valor del acumulado es %d \n", acumulador);

        contador= contador + 1; // contador++; contador+=1;
    }

    printf("El valor final de contador es %d \n", contador);
    printf("El valor del acumulador es %d \n", acumulador);



    return 0 ;
}




