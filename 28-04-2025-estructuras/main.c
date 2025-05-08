#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "stPaciente.h"

#define AR_PACIENTES "pacientes.dat"


/// PROTOTIPADOS
int cargaArregloPacientes(stPaciente arrPaciente[], int v, int dim);
void muestraUnPaciente(stPaciente p);
void muestraArregloPacientes(stPaciente arr[], int v);

stPaciente * reservarEspacioEnMemoriaDevolviendoPtr(stPaciente *ptr, int dim);
stPaciente * redefinirDimensionArreglo(stPaciente * ptr, int nuevaDim);

int main()
{
    stPaciente pepe;

    pepe.id = 1;
    strcpy(pepe.dni,"20457985");
    strcpy(pepe.nroAfiliado,"AAA-001");
    strcpy(pepe.nombreApellido,"Pepe Argento");

    // muestraUnPaciente(pepe);


//    ///ARREGLO ESTATICO DE PACIENTES
//    stPaciente pacientes[5];
//    pacientes[0] = pepe;
//    int vPacientes = 1;
//
//    vPacientes = cargaArregloPacientes(pacientes,vPacientes,5);
//    muestraArregloPacientes(pacientes, vPacientes);


    /// ARREGLO DINAMICO DE PACIENTES
//    stPaciente * arrDinPacientes = NULL;
//
//    arrDinPacientes = reservarEspacioEnMemoriaDevolviendoPtr(arrDinPacientes,5);
//
//
//    for(int i = 0; i<5; i++)
//    {
//        arrDinPacientes[i] = pepe;
//    }
//
//
//    printf("\n");
//
//    muestraArregloPacientes(arrDinPacientes,5);
//
//
//    system("pause");
//    system("cls");
//
//
//    arrDinPacientes = redefinirDimensionArreglo(arrDinPacientes, 15);
//
//    system("pause");
//
//
//    for(int i = 0; i<10; i++)
//    {
//        arrDinPacientes[i] = pepe;
//    }
//
//
//    printf("\n");
//
//    muestraArregloPacientes(arrDinPacientes,15);

/// ARCHIVOS PACIENTES

    stPaciente arrPacientes[10];
    stPaciente arrPacientes2[10];
    int v = 0;
    int v2 = 0;

    v = cargaArregloPacientes(arrPacientes,v,10);

    arregloPacientesHaciaArchivo(arrPacientes,v,AR_PACIENTES);

    v2 = archivoHaciaArreglo(AR_PACIENTES,arrPacientes2, 10);

    muestraArregloPacientes(arrPacientes2,v2);



    return 0;
}

int cargaArregloPacientes(stPaciente arrPaciente[], int v, int dim)
{
    int i = v;
    char option = 's';

    while( i < dim && option != 27)
    {
        arrPaciente[i] = cargaUnPaciente();

        printf("Quiere continuar? ESC para salir");
        fflush(stdin);
        option = getch();

        i++;
        system("cls");

    }

    return i;
}



void muestraArregloPacientes(stPaciente arr[], int v)
{

    for(int i = 0; i < v; i++)
    {
        muestraUnPaciente(arr[i]);
    }
}


/// FUNCIONES CON ARCHIVOS

void arregloPacientesHaciaArchivo(stPaciente arr[], int v, char nombreArchivo[]){

    FILE * buffer = NULL;
    buffer = fopen(nombreArchivo,"wb");

    stPaciente aux;

    if(buffer != NULL)
    {
        for(int i = 0; i < v; i++){
            aux = arr[i];
            fwrite(&aux,sizeof(stPaciente),1,buffer);
        }

        fclose(buffer);
    }
    else {
        printf("No se abrio correctamente");

    }

}

int archivoHaciaArreglo(char nombreArchivo[], stPaciente arr[], int dim){

    FILE * buffer = fopen(nombreArchivo, "rb");
    stPaciente aux;
    int i = 0;

    if(buffer != NULL){

        while(fread(&aux,sizeof(stPaciente),1, buffer) > 0){
            arr[i] = aux;
            i++;
        }

        fclose(buffer);
    }

    return i;

}
























/// Funciones con Arreglo Dinámicos
stPaciente * reservarEspacioEnMemoriaDevolviendoPtr(stPaciente *ptr, int dim)
{
    // La funcion declara que devuelve un puntero.
    ptr = (stPaciente*) malloc(sizeof(stPaciente) * dim);
    if (ptr == NULL)
    {
        puts("\nError de memoria");
        exit(1);
    }
    else
        printf("\nHe reservado en %p", ptr);

    return ptr;
}


void reservar(stPaciente **ptr, int num)
{
    // La funcion declara un doble puntero

    // Acceso al contenido del puntero para reservar el bloque de memoria.
    *ptr = (stPaciente *) malloc(sizeof(stPaciente) * num);
    if (*ptr == NULL)
    {
        puts("\nError de memoria");
        exit(1);
    }
    else
        printf("\nHe reservado en %p", *ptr);
}


stPaciente * redefinirDimensionArreglo(stPaciente * ptr, int nuevaDim)
{

    stPaciente * nuevoPtr = (stPaciente *) realloc(ptr, (sizeof(stPaciente)*nuevaDim));

    if(nuevoPtr && nuevoPtr != ptr)
    {
        free(ptr);
    }
    return nuevoPtr;
}









