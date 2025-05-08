#ifndef STPACIENTE_H_INCLUDED
#define STPACIENTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/// stPaciente.h

typedef struct {
    int id;
    char dni[10];
    char nombreApellido[100];
    char nroAfiliado[30];
} stPaciente;

void muestraUnPaciente(stPaciente p);
stPaciente cargaUnPaciente();

#endif // STPACIENTE_H_INCLUDED
