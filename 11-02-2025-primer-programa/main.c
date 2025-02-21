#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#define NUMERO 120

int main()
{

    srand(time(NULL));


    /// Ejercicios de bucles - 18/02/2025


    int opcion = 0;
    char control = 's';






    do
    {
        printf("\nElija un ejercicio:  \n\n");
        printf("D) PROBLEMAS CON REPETICIONES\n");
        printf("\n---------------------------------------------------------------\n");
        printf("11. Obtener el promedio de 7 notas de un estudiante:  \n");
        printf("12. Obtener el promedio de 7 notas de un estudiante, con carga random:  \n");
        printf("13. Leer 10 numeros y obtener su cubo y su cuarta.\n\n");
        printf("14. Leer 10 numeros e imprimir solamente los positivos\n\n");
        printf("15. Leer 15 numeros negativos, convertirlos en positivos e imprimirlos.\n\n");
        printf("16. Suponga que se tiene un conjunto de calificaciones de un grupo de 40 estudiantes. Realizar un algoritmo para calcular la calificacion promedio y la calificacion mas baja de todo el grupo.\n\n");
        printf("17. Calcular e imprimir la tabla de multiplicar de un numero cualquiera. Imprimir el multiplicando, el multiplicador y el producto.\n\n");
        printf("18. Explicación de la función rand()\n\n");
        printf("\n---------------------------------------------------------------\n");
        printf("0. Salir:  \n");



        fflush(stdin);
        scanf("%d",&opcion);
        system("cls");

        switch(opcion)
        {

        case 0:

            printf("Gracias por usar nuestro sistema: \n");
            control = 'n';
            break;

        case 11:

            printf("11. Obtener el promedio de 7 notas de un estudiante:  \n");

            int contador1 = 0;
            int notas = 0;
            int sumaNotas = 0;
            float promedioNotas = 0;

            for(contador1 = 0; contador1 < 7; contador1++)
            {
                printf("Ingrese la nota n°%d del alumno \n", contador1+1);

                do
                {
                    fflush(stdin);
                    scanf("%d", &notas);

                    if(notas > 10 || notas < 1)
                    {
                        printf("\n La nota es inválida. El rango de notas validas es de 1 a 10 Ingrese una nuevamente \n");
                    }

                }
                while(notas > 10 || notas < 1);

                sumaNotas += notas;
            }
            promedioNotas = (float)sumaNotas / (float)contador1;

            printf("El promedio de notas de la materia Programacion A es de %.1f\n", promedioNotas);

            system("pause");
            system("cls");

            break;

        case 12:

            printf("12. Obtener el promedio de 7 notas de un estudiante, con carga random:  \n");

            int i = 0, nota2 = 0, acum = 0;
            float prom = 0;

            for(i = 0; i < 10; i++)
            {
                nota2 = -20 + (rand () % -10 + 1);
                acum = acum + nota2; /// acum += nota2;
                printf("\n La nota nro: %d del alumno es: %d\n", i+1, nota2, acum);
            }

            prom = (float) acum/i;

            printf("\n El promedio de notas de la materia Programacion A es de %.2f \n", prom);

            system("pause");
            system("cls");
            break;

        case 13:

            printf("Leer 10 numeros y obtener su cubo y su cuarta.\n\n");

            int valor = 0, contador2, valorCubo = 0, valorCuarta = 0;

            for(contador2 = 0 ; contador2 < 10; contador2++)
            {
                printf("\nIngrese numero %d\n", contador2+1);
                fflush(stdin);
                scanf("%d", &valor);

                valorCubo = pow(valor,3);
                valorCuarta = pow(valor,4);

                printf("El cubo de %d es %d\n", valor, valorCubo);

                printf("La cuarta de %d es %d\n", valor, valorCuarta);
            }

            system("pause");
            system("cls");
            break;

        case 14:
            printf("Leer 10 numeros e imprimir solamente los positivos\n\n");

            int contador3, numero = 0;

            for(contador3 = 0; contador3 < 10; contador3++)
            {
                printf("\nIngrese numero %d\n", contador3+1);
                fflush(stdin);
                scanf("%d", &numero);

                if(numero >= 0)
                {
                    printf("El numero es positivo, se muestra: %d\n", numero);
                }
                else
                {
                    printf("El numero es negativo, no se muestra\n");
                }
            }

            system("pause");
            system("cls");



            break;

        case 15:

            printf("Leer 15 numeros negativos, convertirlos en positivos e imprimirlos.\n\n");

            int contador4, numero4 = 0, positivo = 0;

            for(contador4 = 0; contador4 < 15; contador4++)
            {
                printf("Ingrese numero %d\n", contador4+1);
                fflush(stdin);
                scanf("%d", &numero4);

                while(numero4 >= 0)
                {
                    printf("Ingrese un numero NEGATIVO!\n");
                    fflush(stdin);
                    scanf("%d", &numero4);
                }

                positivo = abs(numero4);  ///(-1) * numero4; /// ;
                printf("El numero en positivo es %d\n", positivo);
            }

            system("pause");
            system("cls");

            break;

        case 16:
            printf("Suponga que se tiene un conjunto de calificaciones de un grupo de 40 estudiantes. Realizar un algoritmo para calcular la calificacion promedio y la calificacion mas baja de todo el grupo.\n\n");

            int cantidad, calificacion = 0, sumaMedia = 0, notaMenor =0;
            float media = 0;

            for(cantidad = 0; cantidad < 3; cantidad++)
            {
                printf("Ingrese nota del alumno %d\n", cantidad+1);
                fflush(stdin);
                scanf("%d", &calificacion);

                if(cantidad == 0)
                {
                    notaMenor = calificacion;
                }
                else
                {
                    if(notaMenor > calificacion)
                    {
                        notaMenor = calificacion;
                    }
                }

                sumaMedia = sumaMedia +  calificacion;
            }

            media = (float)sumaMedia / cantidad;
            printf("La nota mas baja es %d\n", notaMenor);
            printf("La media de las notas es de %.2f\n", media);

            system("pause");
            system("cls");
            break;

        case 17:
            printf("Calcular e imprimir la tabla de multiplicar de un numero cualquiera. Imprimir el multiplicando, el multiplicador y el producto.\n\n");

            int multiplicando = 0, multiplicador, producto = 0;

            printf("Ingrese numero para mostrar su tabla de multiplicar\n");
            fflush(stdin);
            scanf("%d", &multiplicando);

            for(multiplicador = 0; multiplicador <= 10; multiplicador++)
            {
                producto = multiplicando * multiplicador;
                printf("%d x %d = %d\n", multiplicando, multiplicador, producto);
            }

            system("pause");
            system("cls");
            break;


        case 18:
            printf("Explicación de la función rand()\n\n");

            printf("La función rand() devuele un valor comprendido entre 0 y RAND_MAX.\n");
            printf("RAND_MAX es el valor maximo que almacena una variable de tipo INT.\n");
            printf("Entonces, si queremos trabajar con un rango de números positivo: \n");
            printf("min + rand()% (max- min +1 )\n");
            printf("5 + rand()% (10 - 5 + 1 )\n");
            printf("5 + rand()% 6\n");
            printf("5 + [0-5]\n");

            system("pause");
            system("cls");

        break;

        default:
            printf("La opción seleccionada no esta disponible en el sistema\n");
            break;

        }


    }
    while (control == 's');



    return 0 ;
}




