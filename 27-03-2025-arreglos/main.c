#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>




int cargaElementosArreglo(int arreglo[], int v, int dim);
void cargaDiezElementosRandomArreglo(int arreglo[], int * v);

int main()
{

    srand(time(NULL));

    int arreglo[10];
    int validos = 0;

   // validos = cargaElementosArreglo(arreglo,validos, 10);
    printf("\n");
    muestraArreglo(arreglo,validos);


    int arreglito[50];
    int vArreglito = 0;

    cargaDiezElementosRandomArreglo(arreglito, &vArreglito);
    printf("\n\n");
    muestraArreglo(arreglito,vArreglito);


    return 0;
}


int cargaElementosArreglo(int arreglo[], int v, int dim){

    char option = 's';

    while(v < dim && option != 27){

        printf("Ingrese un valor al arreglo, a la posicion a[%d]: \n", v);
        scanf("%d", &arreglo[v]);
        v++;

        printf("Quiere continuar? ESC para salir \n");
        option = getch();
    }

    return v;

}



void cargaDiezElementosRandomArreglo(int arreglo[], int * v){

    int val = *v;

    for(int i = 0; i < 10; i++){
        arreglo[val] = rand()% 10 + 1;
        val++;
    }

    *v = val;

}

void muestraArreglo(int arreglo[], int v){

    for(int i = 0; i<v; i++){
        printf("%d |", arreglo[i]);
    }

}

