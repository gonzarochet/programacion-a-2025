#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

#define ESC 27

void menu();
void menuOpciones();
void cargarPilaPorUsuario(Pila * dada);
void pasaDatosPilas(Pila * origen, Pila * destino);
void copiaPila(Pila origen, Pila * destino);
void pasaPila(Pila * origen, Pila * destino);
void pasaDatosPilaOrden(Pila * origen, Pila * destino);
int buscaEliminaMenorPila(Pila * origen);
void ordenacionXSeleccion(Pila * dada, Pila * destino);

int main()
{
    menu();

    return 0;
}



void menu()
{

    Pila dada;
    Pila destino;
    inicpila(&dada);
    inicpila(&destino);

    char option = 's';
    int dato;

    do
    {
        menuOpciones();

        printf(" \n Ingrese el ejercicio que quiere visualizar: \n");
        scanf("%d", &dato);

        switch(dato)
        {

        case 1:
            printf("1. Carga con intervencion del usuario  \n");
            cargarPilaPorUsuario(&dada);
            printf("Carga realizaza con exito \n");
            break;

        case 2:
            printf("2. Mostrar Pila dada \n");
            mostrar(&dada);
            break;

        case 3:
            printf("3.Pasar los datos de una pila a otra, en el mismo orden \n ");
            pasaDatosPilaOrden(&dada, &destino);
            break;

        case 4:
            printf("4. Busca menor en Pila, lo elimina y lo retorna \n");
            int menor = buscaEliminaMenorPila(&dada);

            if(menor == 0)
            {
                printf("La pila no tiene datos \n");
            }
            else
            {
                printf("El menor de mi pila es %d \n", menor);
            }

            mostrar(&dada);

            break;

        case 5:
            printf("5. Ordenacion por Seleccion \n");
            ordenacionXSeleccion(&dada, &destino);
            mostrar(&destino);
            break;


        }

        system("pause");
        system("cls");

        printf("Quiere continuar? ESC para salir \n");
        option = getch();


    }
    while (option != ESC);


}


/*
void menuEjercicios(int indice)
{

    Pila dada;
    Pila destino;
    inicpila(&dada);
    inicpila(&destino);


    switch(indice)
    {

    case 1:
        printf("1. Carga con intervencion del usuario  \n");
        cargarPilaPorUsuario(&dada);
        printf("Carga realizaza con exito \n");
        break;

    case 2:
        printf("2. Mostrar Pila dada \n");
        mostrar(&dada);
        break;

    case 3:
        printf("3.Pasar los datos de una pila a otra, en el mismo orden \n ");
        pasaDatosPilaOrden(&dada, &destino);
        break;

    case 4:
        printf("4. Busca menor en Pila, lo elimina y lo retorna");
        int menor = buscaEliminaMenorPila(&dada);

        if(menor == 0)
        {
            printf("La pila no tiene datos \n");
        }
        else
        {
            printf("El menor de mi pila es %d \n", menor);
        }

        mostrar(&dada);


    }

}

*/

void menuOpciones()
{
    printf("1. Carga con intervencion del usuario  \n");
    printf("2. Mostrar Pila dada \n");
    printf("3. Pasar los datos de una pila a otra, en el mismo orden \n ");
    printf("4. Busca menor en Pila, lo elimina y lo retorna \n");
    printf("5. Ordenación por Selección  \n");
}


void cargarPilaPorUsuario(Pila * dada)
{
    char option = 's';
    int dato;

    do
    {
        printf("Ingrese un valor a la pila \n");
        scanf("%d",&dato);
        apilar(dada, dato);

        printf("Quiere continuar? ESC para salir\n");
        fflush(stdin);
        option = getch();
    }
    while(option != 27);

}

void pasaDatosPilas(Pila * origen, Pila * destino)
{
    while(!pilavacia(origen))
    {
        apilar(destino,desapilar(origen));
    }
}

void copiaPila(Pila origen, Pila * destino)
{

    while(!pilavacia(&origen))
    {
        apilar(destino,desapilar(&origen));
    }

}

void pasaPila(Pila * origen, Pila * destino)
{

    while(!pilavacia(origen))
    {
        apilar(destino, desapilar(origen));
    }

}

void pasaDatosPilaOrden(Pila * origen, Pila * destino)
{
    Pila aux;
    inicpila(&aux);

    pasaPila(origen, &aux);
    pasaPila(&aux, destino);

}

int buscaEliminaMenorPila(Pila * origen)
{

    Pila aux;
    inicpila(&aux);

    int menor = 0;

    if(!pilavacia(origen))
    {
        menor = desapilar(origen);

        while(!pilavacia(origen))
        {
            if(tope(origen) < menor)
            {
                apilar(&aux, menor);
                menor = desapilar(origen);
            }
            else
            {
                apilar(&aux, desapilar(origen));
            }
        }
        pasaPila(&aux, origen);
    }

    return menor;
}


void ordenacionXSeleccion(Pila * dada, Pila * destino){

    int menor;

    while(!pilavacia(dada)){
        menor = buscaEliminaMenorPila(dada);
        apilar(destino, menor);
    }

}




