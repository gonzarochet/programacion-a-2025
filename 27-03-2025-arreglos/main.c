#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "pila.h"



int cargaElementosArreglo(int arreglo[], int v, int dim);
void cargaDiezElementosRandomArreglo(int arreglo[], int * v);
void muestraArreglo(int arreglo[], int v);
void copiaElementosArregloToPila(int A[], int v, Pila * dada);
void copiaElementosArregloToPilaCond(int A[], int v, Pila * dada, int cond);
int copiaElementosPilaToArregloVacio(Pila dada, int A[], int dim);
int copiaElementosPilaToArreglo(Pila dada, int A[], int v, int dim);
int copiaElementosPilaToArregloCondicion(Pila dada, int A[], int v, int dim, int cond);
int cantidadElementosPila(Pila p);
int existeElementoArreglo(int A[], int v, int datoABuscar);
int insertaCaracterEnArregloOrdenado(char A[], int v, char dato);
int buscaMenorPosicion(int arreglo[], int v);
int esCapicua(char arr[], int v);
void intercambio(int * a, int * b);
void invertirArregloEnteros(int A[], int v);
void ordenacionPorSeleccion(int A[], int v);
void ordenacionPorInsercion(int A[], int v);
void intercalarArreglos(int a[],int vA, int b[], int vB, int c[]);

int main()
{

    srand(time(NULL));

    /// TO-DO: HACER MENU CON OPCIONES PARA QUE EL USUARIO NAVEGUE ENTRE LOS PUNTOS.


    return 0;
}

/// 1. Carga DE ARREGLO con intervención del usuario.
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


/// 1. Funcion que carga 10 elementos aleatorios (enteros) al arreglo. Trabaja válidos por referencia.
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

/// 2. Recorre y muestra los elementos del arreglo.
void muestraArreglo(int arreglo[], int v)
{

    for(int i = 0; i<v; i++)
    {
        printf("%d |", arreglo[i]);
    }

}

///4. Copia los elementos del arreglo a la pila.
void copiaElementosArregloToPila(int A[], int v, Pila * dada)
{

    for(int i = 0; i < v; i++)
    {
        apilar(dada, A[i]);
    }

}


/// 4.bis Arreglo Hacia Pila con condicion.
void copiaElementosArregloToPilaCond(int A[], int v, Pila * dada, int cond)
{

    for(int i = 0; i < v; i++)
    {
        if(A[i] == cond) /// la condicion puede variar: ( <, > , == ,%2)
        {
            apilar(dada, A[i]);
        }

    }

}




/// 4.bisbis COPIA LOS ELEMENTOS DE UNA PILA A UN ARREGLO VACIO.
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


/// 4. bisbisbis COPIA LOS ELEMENTOS DE UNA PILA A UN ARREGLO (PUEDE TENER DATOS ANTES).
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

/// extra: cant elementos pila
int cantidadElementosPila(Pila p)
{

    Pila aux;
    inicpila(&aux);
    int contador = 0;

    while(!pilavacia(&p))
    {
        apilar(&aux,desapilar(&p));
        contador ++;
    }

    return contador;

}


/// 4. bisbisbisbis COPIA LOS ELEMENTOS DE UNA PILA A UN ARREGLO CON CONDICIÓN.
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



/// 6.  Determinar si un elemento existe en un arreglo. Devuele 1 si existe, 0 si no.
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

/// 6.bis. Buscar la posición de un elemento determinado.
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

/// 7. Insertar un caracter en un arreglo ordenado.
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

/// 8. Función que busca la posición del menor elemento.
int buscaMenorPosicion(int arreglo[], int v)
{

    int posMenor = -1;
    int i = 0;

    if(i<v)
    {
        posMenor = i;
    }

    for(i+1 ; i<v; i++)
    {
        if(arreglo[i] < arreglo[posMenor])
        {
            posMenor = i;
        }

    }

    return posMenor;
}

/// 9. Determina Arreglo Capicua.
int esCapicua(char arr[], int v)
{

    int posini = 0;
    int posfin = v-1;

    int flag = 1; // es capicua

    while(posini <= posfin && flag == 1)
    {
        if(arr[posini] == arr[posfin])
        {
            posini++;
            posfin--;
        }
        else
        {
            flag = 0;
        }
    }

    return flag;

}



/// 9. Invertir los elementos de un arreglo.

/// AUX - Función de Intercambio
void intercambio(int * a, int * b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}


void invertirArregloEnteros(int A[], int v)
{

    int posIni = 0;
    int posFin = v-1;

    while(posIni < posFin)
    {
        intercambio(&A[posIni],&A[posFin]);
        posIni++;
        posFin--;
    }

}

///11.a Ordenamiento por Seleccion.

void ordenacionPorSeleccion(int A[], int v)
{
    int inicio = 0;
    int fin = v-1;

    int i;
    int posMenor;
    int aux;

    while(inicio < fin)
    {
        i = inicio;
        posMenor = inicio;

        i = i+1;

        while(i<v)
        {
            if(A[i]< A[posMenor])
            {
                posMenor = i;
            }
            i++;
        }

        aux = A[inicio];
        A[inicio] = A[posMenor];
        A[posMenor] = aux;

        inicio++;
    }


}

/// 11.b Ordenamiento por Inserción.

void ordenacionPorInsercion(int A[], int v)
{
    int inicio;
    int dato;

    for(inicio = 0; inicio < v; inicio++)
    {
        dato = A[inicio + 1];

        while(inicio >= 0 && A[inicio] > dato)
        {
            A[inicio + 1] = A[inicio];
            inicio--;
        }

        A[inicio + 1] = dato;
    }

}

/// 12. Intercalar dos arreglos ordenados en un tercer arreglo y que quede ordenado.

void intercalarArreglos(int a[],int vA, int b[], int vB, int c[])
{

    int iA = 0;
    int iB = 0;
    int iC = 0;


    while(iA < vA && iB < vB)
    {

        if(a[iA]<= b[iB])
        {
            c[iC] = a[iA];
            iA++;

        }
        else
        {

            c[iC] = b[iB];
            iB++;

        }

        iC++;
    }


    while(iA < vA)
    {
        c[iC] = a[iA];
        iA++;
        iC++;
    }

    while(iB < vB)
    {
        c[iC] = b[iB];
        iB++;
        iC++;
    }


    return iC;

}



/// 13.









