#include <stdio.h>
#include <stdlib.h>

void sumarEdadesReferencia(int* num1, int* num2, int*resultado);

int main()
{
    printf("Hello world!\n");

    int edadJuan = 12;
    int edadMaria = 15;
    int sumaEdadesAlumnos;


    printf("\n La variable edadJuan vive en %p y almacena %d", &edadJuan, edadJuan);
    printf("\n La variable edadMaria vive en %p y almacena %d", &edadMaria, edadMaria);
    printf("\n La variable sumaEdadesAlumnos vive en %p y almacena %d", &sumaEdadesAlumnos, sumaEdadesAlumnos);


    sumarEdadesReferencia(&edadJuan, &edadMaria, &sumaEdadesAlumnos);

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
