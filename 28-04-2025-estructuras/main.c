#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "stPaciente.h"

#define AR_PACIENTES "pacientes.dat"
#define AR_PACIENTES_MAYORES "pacientesMayores.dat"


/// PROTOTIPADOS
int cargaArregloPacientes(stPaciente arrPaciente[], int v, int dim);
void muestraUnPaciente(stPaciente p);
void muestraArregloPacientes(stPaciente arr[], int v);

stPaciente * reservarEspacioEnMemoriaDevolviendoPtr(stPaciente *ptr, int dim);
stPaciente * redefinirDimensionArreglo(stPaciente * ptr, int nuevaDim);


int arregloPacientesHaciaArchivoPro(stPaciente arr[], int v, char nombreArchivo[]);
void muestraDesdeArchivoPacientes(char nombreArchivo[]);
int cantElementosArchivos(char nombreArchivo[], int tamanioEstructura);

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

   //v = cargaArregloPacientes(arrPacientes,v,10);

   //int cant = arregloPacientesHaciaArchivoPro(arrPacientes,v,AR_PACIENTES_MAYORES);

    /*
    if(cant == v)
    {
        printf("Escribi en el archivo %d datos \n ", cant);
    }*/

    muestraDesdeArchivoPacientes(AR_PACIENTES_MAYORES);


   // int cantArchivo = cantElementosArchivos(AR_PACIENTES_MAYORES,sizeof(stPaciente));

    //printf("La cantidad de elementos en el archivo es %d", cantArchivo);


    system("pause");
    system("cls");

    v2 = archivoHaciaArreglo(AR_PACIENTES_MAYORES ,arrPacientes2, 10);

    ordenacionPorSeleccionDniPacientes(arrPacientes2,v2);

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


/// 4. bis Buscar un paciente por dni
int buscaPosicionPacientePorDni (stPaciente arr[], int v, char dniABuscar[10])
{
    int pos = -1;
    int i = 0;

    while(i < v && pos == -1)
    {
        if(strcmpi(arr[i].dni, dniABuscar) == 0)
        {
            pos = i;
        }

        i++;
    }
    return pos;
}


// 4. Ordenacion por Seleccion

void ordenacionPorSeleccionDniPacientes(stPaciente arr[], int v)
{
    int inicio = 0;
    int posMenor;
    stPaciente aux;

    for(inicio; inicio < v; inicio ++)
    {
        posMenor = inicio;

        for(int i = inicio +1; i < v; i++)
        {
            if(atoi(arr[i].dni) < atoi(arr[posMenor].dni))
            {
                posMenor = i;
            }
        }

        intercambio2Pacientes(&arr[inicio], &arr[posMenor]);
        /*
        aux = arr[inicio];
        arr[inicio] = arr[posMenor];
        arr[posMenor] = aux;*/
    }

}


void intercambio2Pacientes(stPaciente * a, stPaciente * b){

    stPaciente aux = *a;
    *a = *b;
    *b = aux;


}






/// FUNCIONES CON ARCHIVOS

void arregloPacientesHaciaArchivo(stPaciente arr[], int v, char nombreArchivo[])
{

    FILE * buffer = NULL;
    buffer = fopen(nombreArchivo,"wb");

    stPaciente aux;

    if(buffer != NULL)
    {
        for(int i = 0; i < v; i++)
        {
            aux = arr[i];
            fwrite(&aux,sizeof(stPaciente),1,buffer);
        }

        fclose(buffer);
    }
    else
    {
        printf("No se abrio correctamente");

    }

}


/// esta función pasa de arreglo al archivo sin recorrer el arreglo.
int arregloPacientesHaciaArchivoPro(stPaciente arr[], int v, char nombreArchivo[])
{

    FILE * archi = fopen(nombreArchivo, "ab");

    int cantDatos = 0;

    if(archi)
    {
        cantDatos = fwrite(arr, sizeof(stPaciente),v,archi);
        fclose(archi);
    }

    return cantDatos;

}


void muestraDesdeArchivoPacientes(char nombreArchivo[])
{

    FILE * archi = fopen(nombreArchivo, "rb");
    stPaciente aux;

    if(archi)
    {

        while(fread(&aux,sizeof(stPaciente),1,archi)> 0)
        {
            muestraUnPaciente(aux);
        }
        fclose(archi);
    }

}

int cantElementosArchivos(char nombreArchivo[], int tamanioEstructura)
{

    FILE * archi = fopen(nombreArchivo, "rb");
    int cant = -1;

    if(archi) /// archi != NULL
    {
        cant = 0;

        /// muevo el indicador de posición al final
        fseek(archi,0,SEEK_END);


        /// la totalidad de bytes lo divido por el tamaño de un registro.
        cant = ftell(archi) / tamanioEstructura;

        fclose(archi);
    }

    return cant;

}



int archivoHaciaArreglo(char nombreArchivo[], stPaciente arr[], int dim)
{

    FILE * buffer = fopen(nombreArchivo, "rb");
    stPaciente aux;
    int i = 0;

    if(buffer != NULL)
    {

        while(fread(&aux,sizeof(stPaciente),1, buffer) > 0)
        {
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









