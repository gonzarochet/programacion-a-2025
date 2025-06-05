#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "stPaciente.h"
#include "stEspecialidad.h"
#include "arreglosDinamicos.h"

#define AR_PACIENTES "pacientes.dat"
#define AR_ESPECIALIDADES "especialidades.dat"


/// PROTOTIPADOS
int cargaArregloPacientes(stPaciente arrPaciente[], int v, int dim);
void muestraUnPaciente(stPaciente p);
void muestraArregloPacientes(stPaciente arr[], int v);

int arregloPacientesHaciaArchivoPro(stPaciente arr[], int v, char nombreArchivo[]);
void muestraDesdeArchivoPacientes(char nombreArchivo[]);
int cantElementosArchivos(char nombreArchivo[], int tamanioEstructura);

int main()
{
    srand(time(NULL));
   subMenuPacientes();

    return 0;
}


void subMenuPacientes() {
    int opcion;

    stPaciente* arrDinPacientes = NULL;
    int vArrDin = 0;
    stPaciente pepe = {1, "Pepe", "12345678", 65, 'M'};
    stPaciente arrPacientes[10];
    int v = 0;

    do {
        printf("=== SUBMENU PACIENTES ===\n");
        printf("=== Arreglos Dinamicos ===\n");
        printf("1. Reservar arreglo dinámico (5)\n");
        printf("2. Rellenar con paciente 'pepe'\n");
        printf("3. Mostrar arreglo dinámico\n");
        printf("4. Redimensionar arreglo dinámico a 15\n");
        printf("5. Rellenar 10 más con 'pepe'\n");
        printf("\n=== ARCHIVOS ===\n");
        printf("6. HACER - Cargar un nuevo paciente al arreglo\n");
        printf("7. Mostrar desde arreglo de pacientes\n");
        printf("8. Cargar arreglo desde el archivo");
        printf("9. Mostrar arreglo pacientes \n");
        printf("10. Ordenar arreglo de pacientes\n");
        printf("11. HACER - Arreglo de pacientes hacia archivo \n");
        printf("12. HACER - Mostrar Pacientes por especialidad\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);
        system("cls");

        switch(opcion) {
            case 1:
                arrDinPacientes = reservarEspacioEnMemoriaDevolviendoPtr(arrDinPacientes, 5);
                printf("Espacio reservado.\n");
                break;

            case 2:
                for(int i = 0; i < 5; i++) {
                     arrPacientes[i] = cargaUnPacienteRandom();
                }

                vArrDin = 5;
                printf("Arreglo rellenado con 'pepe'.\n");
                break;

            case 3:
                muestraArregloPacientes(arrPacientes, vArrDin);
                break;

            case 4:
                arrDinPacientes = redefinirDimensionArreglo(arrDinPacientes, 15);

                printf("Arreglo redimensionado a 15.\n");
                break;

            case 5:
                for(int i = 0; i < 10; i++)
                    arrPacientes[i] = cargaUnPacienteRandom();
                    vArrDin = 10;
                break;

            case 6:
                muestraArregloPacientes(arrPacientes, vArrDin);
                break;

            case 7:
                arregloPacientesHaciaArchivo(arrPacientes, vArrDin, AR_PACIENTES);
                break;

            case 8:
                v = archivoPacientesHaciaArreglo(AR_PACIENTES, arrPacientes, 10);
                break;

            case 9:
                muestraDesdeArchivoPacientes(AR_PACIENTES);
                break;

            case 10:
                ordenacionPorSeleccionDniPacientes(arrPacientes, v);

            case 0:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opcion invalida.\n");
        }

        system("pause");
        system("cls");

    } while(opcion != 0);
}

 /// FUNCIONES CON ARREGLOS DE PACIENTES

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


/// 3.1. Buscar un paciente por dni
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


/// 4. Ordenacion por Seleccion

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






































