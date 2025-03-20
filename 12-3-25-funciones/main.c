#include <stdio.h>
#include <stdlib.h>

void sumarEdadesReferencia(int* num1, int* num2, int*resultado);
void intercambio (int * n1, int * n2);

int main()
{
    printf("Hello world!\n");


    /*

    int edadJuan = 12;
    int edadMaria = 15;
    int sumaEdadesAlumnos;


    printf("\n La variable edadJuan vive en %p y almacena %d", &edadJuan, edadJuan);
    printf("\n La variable edadMaria vive en %p y almacena %d", &edadMaria, edadMaria);
    printf("\n La variable sumaEdadesAlumnos vive en %p y almacena %d", &sumaEdadesAlumnos, sumaEdadesAlumnos);


    sumarEdadesReferencia(&edadJuan, &edadMaria, &sumaEdadesAlumnos);



    */

    /*
    int edadPedro = 15;

    printf("\n Edad Pedro vive (ddm) en %p y almacena %d \n", &edadPedro, edadPedro);

    int * pEdadPedro = &edadPedro;

    printf("\n pEdadPedro vive (ddm) en %p y almacena %p \n", &pEdadPedro, pEdadPedro);

    int ** pApEdadPedro = pEdadPedro;

    printf("\n pApEdadPedro vive (ddm) en %p y almacena %p \n", &pApEdadPedro, pApEdadPedro);

    *pApEdadPedro = 10;

    printf("La edad de Pedro es %d", edadPedro);

    */


    /*

    int A = 5;
    int B = 2;

    printf("La variable A antes %d y la variable B antes %d \n" ,A, B);

    intercambio(&A,&B);

    printf("La variable A despues %d y la variable B despues %d \n" ,A, B);

    */

    muestraMayorMenor(10,8,9);

    return 0;
}


void sumarEdadesReferencia(int* num1, int* num2, int*resultado){

    printf("\n------------- EN LA FUNCION ------------\n");
    printf("\n El parametro formal num1 vive en %p y almacena la dirección %p", &num1, num1);
    printf("\n El parametro formal num2 vive en %p y almacena la dirección %p", &num2, num2);
    printf("\n El parametro formal resultado vive en %p y almacena la dirección %p", &resultado, resultado);

    printf("\n El parametro formal num1 vive en %p y lo que guarda la direccion de memoria que almacena es  %d", &num1, *num1);
    printf("\n El parametro formal num2 vive en %p y lo que guarda la direccion de memoria que almacena es%d", &num2, *num2);
    printf("\n El parametro formal resultado vive en %p y lo que guarda la direccion de memoria que almacena es %d", &resultado, *resultado);


    *resultado = *num1 + *num2;
}


void intercambio (int * n1, int * n2){

    // printf("\n\nAntes - N1: %d - N2 %d", n1, n2);

    int aux = * n1;
    *n1 = *n2;
    *n2 = aux;

   // printf("\n\nDespues - N1: %d - N2 %d \n\n", n1, n2);
}




void muestraMayorMenor(int nro1, int nro2, int nro3)
{

    int mayor;

    int menor;

    if(nro1 > nro2 && nro1 > nro3)
    {
        mayor = nro1;

        if(nro2 < nro3)

        {
            menor = nro2;

        }
        else
        {
            menor = nro3;
        }

    }
    else if ( nro2 > nro1 && nro2 > nro3)
    {

        mayor = nro2;

        if(nro1 < nro3)
        {
            menor = nro1;
        }
        else
        {
            menor  = nro3;
        }


    }
    else
    {
        mayor = nro3;


        if(nro1 < nro2)
        {
            menor = nro1;
        }
        else
        {
            menor  = nro2;
        }


    }


    printf("\nEl numero mayor es %d\n", mayor);
    printf("El numero menor es %d\n", menor);


}
