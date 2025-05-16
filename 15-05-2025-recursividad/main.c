#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[5] = {1 , 2 , 3 , 4 , 5 };
    muestraArregloRecursivoImplicito(a,5,0);
  //  muestraArregloRecursivoExplicito(a,5,5);

  int suma = sumaElementosArregloRecursivoTernario(a,5,0);

  printf("\n La suma de los elementos del arreglo es %d", suma);


    return 0;
}


void muestraArregloRecursivoImplicito(int a[], int v, int i)
{
    if(i<v)
    {
        printf("%d | ", a[i]);
        muestraArregloRecursivoImplicito(a,v,i+1);
    }
}



/// tarea para casa

//void muestraArregloRecursivoExplicito(int a[], int v){
//
//    if(i == 0){
//      i = -1;
//    }
//    else {
//        printf("%d | ", a[i]);
//        muestraArregloRecursivoExplicito(a,v,i-1);
//    }
//
//
//}



int sumaElementosArregloImplicita(int a[], int v, int i){

    int rta;

    if(i<v){
       rta = a[i] + sumaElementosArregloImplicita(a,v,i+1);
    }

    return rta;

}

int sumaElementosArregloRecursivoTernario(int a[], int v, int i){

    return (i<v) ? a[i] + sumaElementosArregloRecursivoTernario(a,v, i+1) : 0 ;

}






