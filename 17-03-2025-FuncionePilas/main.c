#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

void cargarPilaPorUsuario(Pila * dada);
void pasaDatosPilas(Pila * origen, Pila * destino);
void copiaPila(Pila origen, Pila * destino);

int main()
{

    Pila pilita, dada;
    inicpila(&pilita);
    inicpila(&dada);

    cargarPilaPorUsuario(&pilita);
    mostrar(&pilita);

   pasaDatosPilas(&pilita,&dada);
    //copiaPila(pilita,&dada);

    mostrar(&dada);

    printf("La pila pilita: \n");
    mostrar(&pilita);


    return 0;
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

void copiaPila(Pila origen, Pila * destino){

    while(!pilavacia(&origen))
    {
        apilar(destino,desapilar(&origen));
    }

}







