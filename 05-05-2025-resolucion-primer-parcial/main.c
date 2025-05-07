#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "pila.h"


int main()
{
    Pila p;
    inicpila(&p);

    apilar(&p,5);
    apilar(&p,6);
    apilar(&p,3);
    apilar(&p,9);
    apilar(&p,2);


    int a[5];

   // cargarArregloDesdePila(p,a,5);

    int cantidad = cargarArregloDesdePila(&p, a, 5);

    printf("Arreglo cargado con valores pares ordenados:\n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("%d ", a[i]);
    }


    mostrar(&p);


}

 ///1. ingresar manualmente los valores de compra del producto PlayStation 5 a una Pila.

int cantElementosPila(Pila p){

    int cant = 0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&p))
    {
        cant++;
        apilar(&aux, desapilar(&p));
    }

    return cant;

}


int cargaPila(Pila * p, int cantElem)
{
    int i = cantElem;
    int valor;
    char op = 's';
    while(i < 50 && op != 27)
    {

        printf("Ingrese el valor:\n");
        fflush(stdin);
        scanf("%d", &valor);
        while(valor < 500 || valor > 650)
        {
            printf("ERROR. Ingrese un rango de 500 a 650:\n");
            fflush(stdin);
            scanf("%d", &valor);
        }
        apilar(p, valor);
        i ++;

        printf("Presione ESC para salir o cualquier tecla para continuar\n");
        fflush(stdin);
        op = getch();
    }

    return i;
}


///2. Hacer una función que muestre los precios almacenados en la pila.
void muestraPila(Pila p)
{
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(&p))
    {
        int dolar = desapilar(&p);
        //apilar(&aux, dolar);
        float peso = dolar*1180.60;
        printf("%.2f |", peso);
    }
}


///3. Hacer una función que cargue en un arreglo los valores de compra del paquete de yerba Playadito de forma aleatoria.
int cargaRandom(int a[], int v, int dim)
{
    int i;
    for(i = v; i <= dim; i ++)
    {
        a[i] = rand() %2500 + 3000;
    }
    return i;
}

///4. Hacer una función que muestre los elementos invertidos del arreglo.
void mostrarInvertido(int a[], int v)
{
    for(int i = v - 1; i >= 0; i --)
    {
        printf("%d |", a[i]);
    }
}


///5. Hacer una función que calcule el promedio de los elementos del arreglo.

int sumaElementosArreglo(int a[], int v)
{
    int suma = 0;

    for(int i =0 ; i < v; i++){
        suma= suma + a[i];
    }
    return suma;
}


float promedioArreglo(int a[], int v)
{
    float promedio = 0;
    promedio = (float)sumaElementosArreglo(a,v)/v;
    return promedio;
}


/// 6.
int eliminarMayoresArreglo(int a[], int v, float promedio)
{
    for(int i = 0; i < v; i ++)
    {
        if(a[i] > promedio)
        {
             for(int j = i; j < v - 1; j++){
                a[j] = a[j + 1];
             }
            v --;
            i --;
        }
    }
    return v;
}


/// 7.
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
        while(!pilavacia(&aux))
        {
            apilar(origen, desapilar(&aux));
        }
    }

    return menor;
}

/// 8.
int cargarArregloDesdePila(Pila * p, int arreglo[], int dimension)
{
    Pila aux;
    inicpila(&aux);

    int i = 0;
    while (!pilavacia(p) && i < dimension)
    {
        int resultado = buscaEliminaMenorPila(p);
        if (resultado % 2 == 0)
        {
            arreglo[i] = resultado;
            i++;
        } else {

            apilar(&aux, resultado);
        }
    }

    while(!pilavacia(&aux))
    {
        apilar(p, desapilar(&aux));
    }

    return i;

}



