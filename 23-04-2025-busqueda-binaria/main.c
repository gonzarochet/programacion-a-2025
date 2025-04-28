#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define REPETICIONES 50000

int main()
{
    srand(time(NULL));

    int a[50000]; /// Declaramos un arreglo de 50000 enteros
    int v = 0;

    clock_t inicio, fin, inicio2, fin2;          /// Variables para medir el tiempo de ejecución
    double tiempoLineal, tiempoBinaria; /// Variables para guardar los tiempos finales de cada búsqueda

    cargaElementosRandomArreglo(a, &v);

    ordenacionPorSeleccion(a, v); /// Ordena el arreglo usando el método de selección

    // muestraArreglo(a, v);

    /// Mide el tiempo de búsqueda lineal REPETICIONES veces
    inicio = clock();
    for (int i = 0; i < REPETICIONES; i++)
    {
        existeElementoArreglo(a, v, 49999); /// Busca el número 49999 de forma lineal
    }
    system("pause");
    fin = clock();
    tiempoLineal = (double)(fin - inicio) / CLOCKS_PER_SEC; /// Calcula el tiempo total en segundos

    /// Mide el tiempo de búsqueda binaria REPETICIONES veces
    inicio2 = clock();
    for (int i = 0; i < REPETICIONES; i++)
    {
        busquedaBinariaArreglo(a, v, 49999); /// Busca el número 49999 usando búsqueda binaria
    }
    fin2 = clock();
    tiempoBinaria = (double)(fin2 - inicio2) / CLOCKS_PER_SEC; /// Calcula el tiempo total en segundos

    /// Imprime los tiempos totales de búsqueda lineal y binaria
    printf("Tiempo total Lineal (%d repeticiones): %f segundos\n", REPETICIONES, tiempoLineal);
    printf("Tiempo total Binaria (%d repeticiones): %f segundos\n", REPETICIONES, tiempoBinaria);

    return 0;
}



void cargaElementosRandomArreglo(int arreglo[], int * v)
{
    int val = *v;

    for(int i = 0; i < 50000; i++)
    {
        arreglo[val] = i;
        val++;
    }

    *v = val;

}

void muestraArreglo(int arreglo[], int v)
{

    for(int i = 0; i<v; i++)
    {
        printf("%d |", arreglo[i]);
    }

}


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


int busquedaBinariaArreglo(int A[], int v, int dato)
{
    int inicio = 0;
    int fin = v - 1;
    int flag = 0;
    int indiceActual;

    while (inicio <= fin && flag == 0)
    {
        indiceActual = (inicio + fin) / 2;

        if (A[indiceActual] == dato)
        {
            flag = 1;
        }
        else
        {
            if (A[indiceActual] > dato)
            {
                fin = indiceActual - 1;
            }
            else
            {
                inicio = indiceActual + 1;
            }
        }
    }
    return flag;
}
