#ifndef ARREGLOSDINAMICOS_H_INCLUDED
#define ARREGLOSDINAMICOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "stPaciente.h"


stPaciente * reservarEspacioEnMemoriaDevolviendoPtr(stPaciente *ptr, int dim);
void reservar(stPaciente **ptr, int num);
stPaciente * redefinirDimensionArreglo(stPaciente * ptr, int nuevaDim);


#endif // ARREGLOSDINAMICOS_H_INCLUDED
