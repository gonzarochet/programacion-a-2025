#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int randomRango(int min, int max);

int main()
{

    srand(time(NULL));

    /// ARREGLO DE STRINGS (ARREGLO DE CADENA DE CARACTERES)
    /*
    char arregloNombres[20][100];
    int arregloEdades[20];

    int v = 0;

    int i = 0;

    for(i = 0; i < 3; i++){
        printf("Ingrese el nombre del alumno\n");
        fflush(stdin);
       /// scanf("%s", arregloNombres[i]);
       gets(arregloNombres[i]);

        printf("Ingrese la edad del alumno\n");
        fflush(stdin);
        scanf("%d", &arregloEdades[i]);
    }

    v = i;

    system("pause");
    system("cls");

    for(int j = 0; j < v; j++){
        printf("\n---------------\n");
        printf("Nombre......%s\n", arregloNombres[j]);
        printf("Edad......%d\n", arregloEdades[j]);
    }



    */


    /// MATRICES DE CARACTERES. SS

    char matrix[3][3];
    int cantFilas = 3;
    int cantColum = 3;

    /*
    for(int i = 0; i < cantFilas; i++)
    {
        for(int j = 0; j < cantColum; j++ )
        {

            matrix[i][j] = randomRango(64,122);
        }
    }*/


    for(int i = 0; i < cantFilas; i++)
    {
        for(int j = 0; j < cantColum; j++ )
        {
            printf("Ingrese un caracter \n");
            fflush(stdin);
            scanf("%c", &matrix[i][j]);
        }
    }


    for(int i = 0; i < cantFilas; i++){
        for(int j = 0; j < cantColum; j++){
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}



int randomRango(int min, int max){
    return rand()% (max - min) + min;
}












