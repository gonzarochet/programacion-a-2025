#include "arreglosDinamicos.h"

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
