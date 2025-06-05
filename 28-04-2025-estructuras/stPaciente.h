#ifndef STPACIENTE_H_INCLUDED
#define STPACIENTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/// stPaciente.h

typedef struct {
    int id;
    char dni[10];
    char nombre[20];
    char apellidos[40];
    char nroAfiliado[30];
    int idEspecialidad;
} stPaciente;

void muestraUnPaciente(stPaciente p);
stPaciente cargaUnPaciente();
stPaciente cargaUnPacienteRandom();

int arregloPacientesHaciaArchivoPro(stPaciente arr[], int v, char nombreArchivo[]);
void arregloPacientesHaciaArchivo(stPaciente arr[], int v, char nombreArchivo[]);
void muestraDesdeArchivoPacientes(char nombreArchivo[]);
int archivoPacientesHaciaArreglo(char nombreArchivo[], stPaciente arr[], int dim);

#endif // STPACIENTE_H_INCLUDED
