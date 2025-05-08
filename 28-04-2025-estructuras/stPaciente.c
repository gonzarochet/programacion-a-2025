#include "stPaciente.h"

/// stPaciente.c

void muestraUnPaciente(stPaciente p){
    printf("Id.......................%d \n", p.id);
    printf("DNI......................%s \n", p.dni);
    printf("Nombre y Apellido........%s \n", p.nombreApellido);
    printf("Nro Afiliado.............%s \n", p.nroAfiliado);
    printf("\n-----------------------------\n");
}

stPaciente cargaUnPaciente(){

    stPaciente aux;

    printf("Ingrese el ID del usuario: \n");
    scanf("%d", &aux.id);

    printf("Ingrese el DNI \n:");
    fflush(stdin);
    scanf("%s", aux.dni);

    printf("Ingrese el Nombre y Apellido \n:");
    fflush(stdin);
    gets(aux.nombreApellido);

    printf("Ingrese el NRO - Afiliado \n:");
    fflush(stdin);
    scanf("%s", aux.nroAfiliado);


    return aux;

}
