#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pila.h"

void ejercicio1();
void ejercicio2();
void ejercicio3();
void ejercicio4();
void ejercicio5();

int main()
{
    //srand(time(NULL));

    int option;


    do
    {
//        printf("Elija el ejercicio a trabajar: \n");
//        printf("0. Presione 0 (cero) para salir \n");
//        printf("1. Ejercicio 1:  \n");
//        printf("2. Ejercicio 2:  \n");
//        printf("3. Ejercicio 3:  \n");

        menuOpciones();

        scanf("%d", &option);

        switch(option)
        {

        case 0:
            printf("Gracias por usar nuestro sistema\n");
            option = 0;
            break;

        case 1:
            ejercicio1();
            break;

        case 2:
            ejercicio2();
            break;

        case 3:
            ejercicio3();
            break;
        case 4:
            ejercicio4();
            break;

        case 5:
            ejercicio5();
            break;
        case 7:
            ejercicio7();
            break;
        case 8:
            ejercicio8();
            break;
        case 9:
            ejercicio9();
            break;

        case 11:
            ejercicio11( );
            break;

        case 12:
            ejercicio12( );
            break;

        default:
            printf("La tecla ingresada no corresponde con ninguna opción \n");
            break;
        }

        system("pause");
        system("cls");

    }
    while(option != 0);



    return 0;
}



void menuOpciones()
{

    printf("<<<Ingrese el numero del ejercicio>>>\n\n");
    printf("1. Cargar desde el teclado una pila DADA con 5 elementos. Pasar los tres primeros elementos a la pila AUX1 y los dos restantes a la pila AUX2. \n\n");
    printf("2. Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO. Pasar todos los elementos de la pila ORIGEN a la pila DESTINO \n\n");
    printf("3. Cargar desde teclado una pila DADA y pasar a la pila DISTINTOS todos aquellos elementos distintos al valor 8.\n");
    printf("4. Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO. Pasar los elementos de la pila ORIGEN a la pila DESTINO, pero dejándolos en el mismo orden. \n");
    printf("5. Cargar desde el teclado la pila DADA. Invertir la pila de manera que DADA contenga los elementos cargados originalmente en ella, pero en orden inverso. \n");
    printf("6. Pasar el primer elemento (tope) de la pila DADA a su última posición (base), dejando los restantes elementos en el mismo orden. \n");
    printf("7. Pasar el último elemento (base) de la pila DADA a su primera posición (tope), dejando los restantes elementos en el mismo orden. \n");
    printf("8. Repartir los elementos de la pila MAZO en las pilas JUGADOR1 y JUGADOR2 en forma alternativa. \n");
    printf("9. Comparar la cantidad de elementos de las pilas A y B. Mostrar por pantalla el resultado. \n");
    printf("10. Cargar las pilas A y B, y luego compararlas, evaluando si son completamente iguales (en cantidad de elementos, valores que contienen y posición de los mismos). Mostrar por pantalla el resultado. \n ");
    printf("11. Suponiendo la existencia de una pila MODELO que no esté vacía, eliminar de la pila DADA todos los elementos que sean iguales al tope de la pila MODELO. \n");
    printf("12. Suponiendo la existencia de una pila MODELO (vacía o no), eliminar de la pila DADA todos los elementos que existan en MODELO. \n");
    /* printf("13. Suponiendo la existencia de una pila LÍMITE, pasar los elementos de la pila DADA que sean mayores o iguales que el tope de LIMITE a la pila MAYORES, y los elementos que sean menores a la pila MENORES. \n");
     printf("14. Determinar si la cantidad de elementos de la pila DADA es par. Si es par, pasar el elemento del tope de la pila AUX a la pila PAR y si es impar pasar el tope a la pila IMPAR. (NO contar los elementos) \n");
     printf("15. GUIA 2 - Dada la pila ORIGEN ordenarla en forma ascendente por método de inserción dejando el resultado en la pila ORIGEN. Para este ejercicio usar lo aprendido para el ejercicio 5.  \n");
     */
}


void ejercicio1()
{

    Pila pilita, aux1, aux2;
    inicpila(&pilita);
    inicpila(&aux1);
    inicpila(&aux2);

    apilar(&pilita,9);
    apilar(&pilita,6);
    apilar(&pilita,2);
    apilar(&pilita,10);
    apilar(&pilita,5);

    int top = tope(&pilita);

    printf("El tope de la pilita es %d", top);

    mostrar(&pilita);


    apilar(&aux1, desapilar(&pilita));
    apilar(&aux1, desapilar(&pilita));
    apilar(&aux1, desapilar(&pilita));

    apilar(&aux2, desapilar(&pilita));
    apilar(&aux2, desapilar(&pilita));

    printf("\n PILITA: \n");
    mostrar(&pilita);

    printf("\n AUX 1: \n");
    mostrar(&aux1);

    printf("\n AUX 2: \n");
    mostrar(&aux2);


}


/*
2. Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO.
Pasar todos los elementos de la pila ORIGEN a la pila DESTINO.
*/
void ejercicio2()
{
    Pila origen, destino;

    inicpila(&origen);
    inicpila(&destino);

    char option = 's';

    do
    {
        leer(&origen);
        printf("Desea continuar? s/n \n");
        fflush(stdin);
        scanf("%c", &option);
    }
    while(option == 's');


    printf("ORIGEN ANTES \n");
    mostrar(&origen);

    while(!pilavacia(&origen))
    {
        apilar(&destino,desapilar(&origen));
    }

    printf("ORIGEN DESPUES \n");
    mostrar(&origen);

    printf("DESTINO FIN \n");
    mostrar(&destino);

}

void ejercicio3()
{

    Pila dada, aux1, distinto;

    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&distinto);

    char option = 's';

    do
    {
        leer(&dada);
        printf("Desea continuar? s/n \n");
        fflush(stdin);
        scanf("%c", &option);
    }
    while(option == 's');

    while(!pilavacia(&dada))
    {

        if(tope(&dada)!=8)
        {
            apilar(&distinto,desapilar(&dada));
        }
        else
        {
            apilar(&aux1,desapilar(&dada));
        }
    }


}


void ejercicio4()
{


    Pila dada, aux, destino;

    inicpila(&dada);
    inicpila(&aux);
    inicpila(&destino);


    char option = 's';

    do
    {
        leer(&dada);
        printf("Desea continuar? s/n \n");
        fflush(stdin);
        scanf("%c", &option);
    }
    while(option == 's');


    while(!pilavacia(&dada))
    {
        apilar(&aux,desapilar(&dada));
    }


    while(!pilavacia(&aux))
    {
        apilar(&destino,desapilar(&aux));
    }

}



void ejercicio5()
{


    Pila dada, aux, aux2;

    inicpila(&dada);
    inicpila(&aux);
    inicpila(&aux2);

    char option = 's';

    do
    {
        printf("quiere cargar un dato a la pila? s/n \n");
        fflush(stdin);
        scanf("%c", &option);

        if(option=='s')
        {
            leer(&dada);
        }
    }
    while(option == 's');


    printf("DADA ANTES \n");
    mostrar(&dada);


    while(!pilavacia(&dada))
    {
        apilar(&aux,desapilar(&dada));
    }

    while(!pilavacia(&aux))
    {
        apilar(&aux2,desapilar(&aux));
    }

    while(!pilavacia(&aux2))
    {
        apilar(&dada,desapilar(&aux2));
    }

    printf("llegue al final correctamente");
    system("pause");

}


void ejercicio6()
{

    Pila dada, aux, aux2;

    inicpila(&dada);
    inicpila(&aux);
    inicpila(&aux2);

    char option = 's';

    do
    {
        leer(&dada);
        printf("Desea continuar? s/n \n");
        fflush(stdin);
        scanf("%c", &option);
    }
    while(option == 's');


    if(!pilavacia(&dada))
    {

        apilar(&aux, desapilar(&dada));

        while(!pilavacia(&dada))
        {
            apilar(&aux2, desapilar(&dada));
        }

        if(!pilavacia(&aux))
        {
            apilar(&dada, desapilar(&aux));
        }

        while(!pilavacia(&aux2))
        {
            apilar(&dada, desapilar(&aux2));
        }
    }


}



void ejercicio7()
{
    Pila dada, aux;

    inicpila(&dada);
    inicpila(&aux);

    int cantElementos = 0;

    // snake-case
    // lowerCamelCase
    // UpperCamelCase

    int tope;

    do
    {
        printf("Ingrese la cantidad de elementos a cargar \n");
        scanf("%d", &cantElementos);

        if(cantElementos < 50 && cantElementos > 0)
        {
            for(int i = 0; i < cantElementos; i++)
            {
                int num = rand() % 11;
                apilar(&dada,num);
            }
        }
        else
        {
            printf("La cantidad de elementos supera al limite de la pila \n");
        }
    }
    while(cantElementos >= 50 || cantElementos < 0);

    printf("DADA ANTES \n");
    mostrar(&dada);

    while(!pilavacia(&dada))
    {
        apilar(&aux, desapilar(&dada));
    }

    tope = desapilar(&aux);

    while(!pilavacia(&aux))
    {
        apilar(&dada, desapilar(&aux));
    }

    apilar(&dada, tope);

    printf("DADA DESPUES\n");
    mostrar(&dada);

}


void ejercicio8()
{

    Pila mazo, jugador1, jugador2;

    inicpila(&mazo);
    inicpila(&jugador1);
    inicpila(&jugador2);

    int cantElementos = 0;

    do
    {
        printf("Ingrese la cantidad de elementos a cargar \n");
        scanf("%d", &cantElementos);

        if(cantElementos < 50 && cantElementos > 0)
        {
            for(int i = 0; i < cantElementos; i++)
            {
                int num = rand() % 11;
                apilar(&mazo,num);
            }
        }
        else
        {
            printf("La cantidad de elementos supera al limite de la pila \n");
        }
    }
    while(cantElementos >= 50 || cantElementos < 0);

    printf("El mazo despues \n");
    mostrar(&mazo);


    while(!pilavacia(&mazo))
    {
        apilar(&jugador1, desapilar(&mazo));

        if(!pilavacia(&mazo))
        {
            apilar(&jugador2, desapilar(&mazo));
        }
    }

    printf("El mazo despues \n");
    mostrar(&mazo);

    printf("El mazo de jugador 1 \n");
    mostrar(&jugador1);

    printf("El mazo de jugador2  \n");
    mostrar(&jugador2);

}


void ejercicio9()
{

    Pila A, B, aux, aux2;

    inicpila(&A);
    inicpila(&B);
    inicpila(&aux);
    inicpila(&aux2);


    int cantElementosA = 0;

    do
    {
        printf("Ingrese la cantidad de elementos a cargar en la Pila A \n");
        scanf("%d", &cantElementosA);

        if(cantElementosA < 50 && cantElementosA > 0)
        {
            for(int i = 0; i < cantElementosA; i++)
            {
                int num = rand() % 11;
                apilar(&A,num);
            }
        }
        else
        {
            printf("La cantidad de elementos supera al limite de la pila \n");
        }
    }
    while(cantElementosA >= 50 || cantElementosA < 0);


    int cantElementosB = 0;

    do
    {
        printf("Ingrese la cantidad de elementos a cargar en la Pila B \n");
        scanf("%d", &cantElementosB);

        if(cantElementosB < 50 && cantElementosB > 0)
        {
            for(int i = 0; i < cantElementosB; i++)
            {
                int num = rand() % 11;
                apilar(&B,num);
            }
        }
        else
        {
            printf("La cantidad de elementos supera al limite de la pila \n");
        }
    }
    while(cantElementosB >= 50 || cantElementosB < 0);


    printf("A despues \n");
    mostrar(&A);

    printf("B despues \n");
    mostrar(&B);


    while(!pilavacia(&A) && !pilavacia(&B))
    {
        apilar(&aux, desapilar(&A));
        apilar(&aux2, desapilar(&B));
    }


    if(pilavacia(&A)&& pilavacia(&B))
    {
        printf("La cantidad de elementos es igual en ambas pilas \n");
    }
    else
    {
        printf("La cantidad de elementos es distinta entre las pilas\n");

        if(pilavacia(&A) == 0) /// if(!pilavacia(&A))
        {
            printf("La pila A tiene mas elementos\n");
        }
        else
        {
            printf("La pila B tiene mas elementos\n");
        }

    }


}



void ejercicio10()
{

    Pila A, B, aux, aux2;

    inicpila(&A);
    inicpila(&B);
    inicpila(&aux);
    inicpila(&aux2);


    int cantElementosA = 0;

    do
    {
        printf("Ingrese la cantidad de elementos a cargar en la Pila A \n");
        scanf("%d", &cantElementosA);

        if(cantElementosA < 50 && cantElementosA > 0)
        {
            for(int i = 0; i < cantElementosA; i++)
            {
                int num = rand() % 11;
                apilar(&A,num);
            }
        }
        else
        {
            printf("La cantidad de elementos supera al limite de la pila \n");
        }
    }
    while(cantElementosA >= 50 || cantElementosA < 0);


    int cantElementosB = 0;

    do
    {
        printf("Ingrese la cantidad de elementos a cargar en la Pila B \n");
        scanf("%d", &cantElementosB);

        if(cantElementosB < 50 && cantElementosB > 0)
        {
            for(int i = 0; i < cantElementosB; i++)
            {
                int num = rand() % 11;
                apilar(&B,num);
            }
        }
        else
        {
            printf("La cantidad de elementos supera al limite de la pila \n");
        }
    }
    while(cantElementosB >= 50 || cantElementosB < 0);


    printf("A despues \n");
    mostrar(&A);

    printf("B despues \n");
    mostrar(&B);


    int bandera = 1; /// flag



    while(!pilavacia(&A) && !pilavacia(&B) && bandera == 1)
    {
        if(tope(&A) == tope(&B))
        {
            apilar(&aux, desapilar(&A));
            apilar(&aux2, desapilar(&B));
        }
        else
        {
            bandera = 0;
        }
    }

    if(pilavacia(&A) && pilavacia(&B) && bandera == 1)
    {
        printf("La cantidad, la posicion y los valores de los elementos es igual en ambas pilas.  \n");
    }
    else
    {
        printf("La cantidad de elementos es distinta entre las pilas\n");
    }


}


void ejercicio11()
{

    Pila modelo, dada, aux, basura, auxModelo;
    inicpila(&modelo);
    inicpila(&dada);
    inicpila(&aux);
    inicpila(&basura);
    inicpila(&auxModelo);

    int numero = 0;

    for(int i = 0; i < 5; i++)
    {
        numero = rand()%10 ;
        apilar(&modelo,numero);
    }


    for(int i = 0; i < 10; i++)
    {
        numero = rand()%10 ;
        apilar(&dada,numero);
    }

    printf("La pila modelo");
    mostrar(&modelo);

    printf("La pila dada antes");
    mostrar(&dada);



    while(!pilavacia(&dada))
    {

        if(tope(&modelo) == tope(&dada))
        {
            apilar(&basura,desapilar(&dada));
        }
        else
        {
            apilar(&aux,desapilar(&dada));

        }
    }

    while(!pilavacia(&aux))
    {
        apilar(&dada,desapilar(&aux));
    }





    printf("La pila dada despues");
    mostrar(&dada);



    return 0;
}





void ejercicio12()
{

    Pila modelo, dada, aux, basura,auxModelo;
    inicpila(&modelo);
    inicpila(&dada);
    inicpila(&aux);
    inicpila(&basura);
    inicpila(&auxModelo);

    int numero = 0;

    for(int i = 0; i < 5; i++)
    {
        numero = rand()%10 ;
        apilar(&modelo,numero);
    }


    for(int i = 0; i < 10; i++)
    {
        numero = rand()%10 ;
        apilar(&dada,numero);
    }

    printf("La pila modelo");
    mostrar(&modelo);

    printf("La pila dada antes");
    mostrar(&dada);


    while(!pilavacia(&modelo))
    {

        while(!pilavacia(&dada))
        {

            if(tope(&modelo) == tope(&dada))
            {
                apilar(&basura,desapilar(&dada));
            }
            else
            {
                apilar(&aux,desapilar(&dada));

            }
        }

        apilar(&auxModelo, desapilar(&modelo));

        while(!pilavacia(&aux))
        {
            apilar(&dada,desapilar(&aux));
        }


    }


    while(!pilavacia(&auxModelo))
    {
        apilar(&modelo,desapilar(&auxModelo));
    }



    printf("La pila dada despues");
    mostrar(&dada);



    return 0;
}











