#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct {

    int id;
    char dni[10];
    char nombreApellido[100];
    char nroAfiliado[30];
} stPaciente;

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
    stPaciente * arrDinPacientes = NULL;

    arrDinPacientes = reservarEspacioEnMemoriaDevolviendoPtr(arrDinPacientes,5);


    for(int i = 0; i<5; i++){
        arrDinPacientes[i] = pepe;
    }


    printf("\n");

    muestraArregloPacientes(arrDinPacientes,5);


    system("pause");
    system("cls");


    arrDinPacientes = redefinirDimensionArreglo(arrDinPacientes, 15);

    system("pause");


    for(int i = 0; i<10; i++){
        arrDinPacientes[i] = pepe;
    }


    printf("\n");

    muestraArregloPacientes(arrDinPacientes,15);


    return 0;
}

int cargaArregloPacientes(stPaciente arrPaciente[], int v, int dim){

    int i = v;
    char option = 's';

    while( i < dim && option != 27){

    printf("Ingrese el ID del usuario: \n");
    scanf("%d", &arrPaciente[i].id);

    printf("Ingrese el DNI \n:");
    fflush(stdin);
    scanf("%s",arrPaciente[i].dni);

    printf("Ingrese el Nombre y Apellido \n:");
    fflush(stdin);
    gets(arrPaciente[i].nombreApellido);

    printf("Ingrese el NRO - Afiliado \n:");
    fflush(stdin);
    scanf("%s",arrPaciente[i].nroAfiliado);

    printf("Quiere continuar? ESC para salir");
    fflush(stdin);
    option = getch();

    i++;
    system("cls");

    }

    v = i;
    return v;
}

void muestraUnPaciente(stPaciente p){
    printf("Id.......................%d \n", p.id);
    printf("DNI......................%s \n", p.dni);
    printf("Nombre y Apellido........%s \n", p.nombreApellido);
    printf("Nro Afiliado.............%s \n", p.nroAfiliado);
    printf("\n-----------------------------\n");
}

void muestraArregloPacientes(stPaciente arr[], int v){

    for(int i = 0; i < v; i++){
        muestraUnPaciente(arr[i]);
    }
}


/// Funciones con Arreglo Dinámicos
stPaciente * reservarEspacioEnMemoriaDevolviendoPtr(stPaciente *ptr, int dim){
	// La funcion declara que devuelve un puntero.
	ptr = (stPaciente*) malloc(sizeof(stPaciente) * dim);
	if (ptr == NULL){
		puts("\nError de memoria");
		exit(1);
	} else
		printf("\nHe reservado en %p", ptr);

	return ptr;
}


void reservar(stPaciente **ptr, int num){
	// La funcion declara un doble puntero

	// Acceso al contenido del puntero para reservar el bloque de memoria.
	*ptr = (stPaciente *) malloc(sizeof(stPaciente) * num);
	if (*ptr == NULL){
		puts("\nError de memoria");
		exit(1);
	} else
		printf("\nHe reservado en %p", *ptr);
}


stPaciente * redefinirDimensionArreglo(stPaciente * ptr, int nuevaDim){

    stPaciente * nuevoPtr = (stPaciente *) realloc(ptr, (sizeof(stPaciente)*nuevaDim));

    if(nuevoPtr && nuevoPtr != ptr){
        free(ptr);
    }
    return nuevoPtr;
}









