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
void insertarElementoEnOrden(Pila * dada, int dato);
void ordenacionXInsercion(Pila * origen, Pila * destino);

float dividir (int num1, int num2 );
float promedioElementosPila(Pila dada);


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

        case 6:
            printf("6. Inserta elemento en Pila ordenada \n");
            insertarElementoEnOrden(&destino, 99);
            mostrar(&destino);
            break;

        case 7:
            printf("7. Ordenacion por insercion \n");
            ordenacionXInsercion(&dada, &destino);
            mostrar(&destino);
            break;


        case 9:
            printf("9. Promedio elementos pila ");
            float rta = promedioElementosPila(dada);
            printf("El promedio de la pila dada es %.2f \n",rta);
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
    printf("6. Inserta en una pila ordenada un nuevo elemento, conservando el orden de ésta. \n");
    printf("7. Ordenación por Inserción  \n");
    printf("9. Promedio pila dada  \n");
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


void ordenacionXSeleccion(Pila * dada, Pila * destino)
{

    int menor;

    while(!pilavacia(dada))
    {
        menor = buscaEliminaMenorPila(dada);
        apilar(destino, menor);
    }

}


void insertarElementoEnOrden(Pila * dada, int dato)
{

    Pila aux;
    inicpila(&aux);

    while(!pilavacia(dada) && tope(dada) < dato)
    {
        apilar(&aux, desapilar(dada));
    }

    apilar(dada, dato);
    pasaPila(&aux, dada);

}


void ordenacionXInsercion(Pila * origen, Pila * destino)
{

    while(!pilavacia(origen))
    {
        insertarElementoEnOrden(destino, desapilar(origen));
    }
}


/// 9.

int sumaElementosPila(Pila dada)
{

    int acum = 0;

    while(!pilavacia(&dada))
    {
        acum = acum + desapilar(&dada); /// acum+=desapilar(&dada)
    }

    return acum;
}

/// con condicion
int sumaElementosPilaCondicion(Pila dada, int condicion)
{
    Pila aux;
    inicpila(&aux);
    int acum = 0;

    while(!pilavacia(&dada))
    {
        if(tope(&dada) >= condicion)
        {
            acum = acum + tope(&dada);
        }

        apilar(&aux, desapilar(&dada));
    }

    return acum;
}

int cantidadElementosPila(Pila dada)
{

    Pila aux;
    inicpila(&aux);

    int cant = 0;

    while(!pilavacia(&dada))
    {
        cant = cant + 1; /// cant++; cant +=1;
        apilar(&aux,desapilar(&dada));
    }

    return cant;

}

float dividir (int num1, int num2 )
{
    return (float) num1 / num2;
}

float promedioElementosPila(Pila dada)
{

    float resultado = 0.0;
    int sumaElementos = sumaElementosPila(dada);
    int cantElementos = cantidadElementosPila(dada);

    resultado = dividir(sumaElementos,cantElementos);

    return resultado;

}




