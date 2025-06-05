#ifndef STESPECIALIDAD_H_INCLUDED
#define STESPECIALIDAD_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int idEspecialidad;
    char nombreEspecialidad[30];
}stEspecialidad;

stEspecialidad cargaUnaEspecialidad();
void muestraUnaEspecialidad();

void guardarEspecialidadesEnArchivo(char nombreArchivo[]);
void mostrarEspecialidadesDesdeArchivo(char nombreArchivo[]);

int cargarArregloEspecialidadesDesdeArchivo(char nombreArchivo[], stEspecialidad arr[], int DIM);


#endif // STESPECIALIDAD_H_INCLUDED
