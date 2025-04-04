#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "pila.h"




int cargaElementosArreglo(int arreglo[], int v, int dim);
void cargaDiezElementosRandomArreglo(int arreglo[], int * v);

int main()
{
    /*
    srand(time(NULL));

    int arreglo[10];
    int validos = 0;

    // validos = cargaElementosArreglo(arreglo,validos, 10);
    printf("\n");
    // muestraArreglo(arreglo,validos);


    int arreglito[5];
    int vArreglito = 0;

    cargaDiezElementosRandomArreglo(arreglito, &vArreglito);
    printf("\n\n");
    muestraArreglo(arreglito,vArreglito);

    */

    printf("Ingresa el nombre del alumno: \n");
    fflush(stdin);

    //scanf("%s", alumno);
    gets(alumno);

    // printf("El nombre del alumno es %s \n", alumno);

    puts(alumno);




    return 0;
}


int cargaElementosArreglo(int arreglo[], int v, int dim)
{

    char option = 's';

    while(v < dim && option != 27)
    {

        printf("Ingrese un valor al arreglo, a la posicion a[%d]: \n", v);
        scanf("%d", &arreglo[v]);
        v++;

        printf("Quiere continuar? ESC para salir \n");
        option = getch();
    }

    return v;

}


/// 1.
void cargaDiezElementosRandomArreglo(int arreglo[], int * v)
{

    int val = *v;

    for(int i = 0; i < 10; i++)
    {
        arreglo[val] = rand()% 10 + 1;
        val++;
    }

    *v = val;

}

/// 2.
void muestraArreglo(int arreglo[], int v)
{

    for(int i = 0; i<v; i++)
    {
        printf("%d |", arreglo[i]);
    }

}

///4. copia elementos del arreglo a la pila.
void copiaElementosArregloToPila(int A[], int v, Pila * dada)
{

    for(int i = 0; i < v; i++)
    {
        apilar(dada, A[i]);
    }

}


int copiaElementosPilaToArregloVacio(Pila dada, int A[], int dim)
{
    int v = 0;

    while(!pilavacia(&dada) && v < dim)
    {
        A[v] = desapilar(&dada);
        v++;
    }

    return v;
}


/*
int copiaElementosPilaToArreglo(Pila dada, int A[], int v, int dim)
{

    int cantEspacioLibresArreglo = dim - v;
    int cantElemPila = cantidadElementosPila(dada);

    if(cantEspacioLibresArreglo >= cantElemPila)
    {

        while(!pilavacia(&dada))
        {
            A[v] = desapilar(&dada);;
            v++;
        }

    }

    return v;

}




int copiaElementosPilaToArregloCondicion(Pila dada, int A[], int v, int dim, int cond)
{

    int cantEspacioLibresArreglo = dim - v;
    int cantElemPila = cantidadElementosPila(dada);

    if(cantEspacioLibresArreglo >= cantElemPila)
    {

        while(!pilavacia(&dada))
        {
            if(tope(&dada) >= cond)
            {
                A[v] = tope(&dada);
                v++;
            }
            desapilar(&dada);
        }

    }

    return v;

}
*/

int existeElementoArreglo(int A[], int v, int datoABuscar)
{

    int i = 0;
    int flag = 0;

    while(i<v && flag == 0)
    {
        if(A[i] == datoABuscar)
        {
            flag = 1;
        }
        i++;
    }

    return flag;

}

int buscaPosicionElemento(int A[], int v, int datoABuscar)
{

    int i = 0;
    int flag = 0;
    int posicionElemento = -1;

    while(i < v && flag == 0)
    {
        if(A[i] == datoABuscar)
        {
            posicionElemento = i;
            flag = 1;
        }
        i++;
    }

    return posicionElemento;
}

/// 7. Inserar un caracter en un arreglo ordenado
int insertaCaracterEnArregloOrdenado(char A[], int v, char dato)
{

    int posActual = v - 1;

    while(posActual >= 0 && A[posActual] > dato)
    {
        A[posActual + 1 ] = A[posActual];
        posActual--;
    }

    A[posActual + 1] = dato;

    return v + 1;

}




/// 8. Arreglo capicua
int esCapicua(char arr[], int v)
{

    int posIni = 0;
    int posFin = v-1;

    int flag = 1; // es capicua

    while(posIni <= posFin && flag == 1)
    {
        if(A[posIni] == A[posFin])
        {
            posIni++;
            posFin--;
        }
        else
        {
            flag = 0;
        }
    }

    return flag;

}







