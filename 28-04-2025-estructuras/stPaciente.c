#include "stPaciente.h"

/// stPaciente.c

void muestraUnPaciente(stPaciente p)
{
    printf("Id.......................%d \n", p.id);
    printf("DNI......................%s \n", p.dni);
    printf("Nombre ........%s \n", p.nombre);
    printf("Apellido........%s \n", p.apellidos);
    printf("Nro Afiliado.............%s \n", p.nroAfiliado);
    printf("\n-----------------------------\n");
}

stPaciente cargaUnPaciente()
{

    stPaciente aux;

    printf("Ingrese el ID del usuario: \n");
    scanf("%d", &aux.id);

    printf("Ingrese el DNI \n:");
    fflush(stdin);
    scanf("%s", aux.dni);

    printf("Ingrese el Nombre  \n:");
    fflush(stdin);
    gets(aux.nombre);

    printf("Ingrese el Apellido \n:");
    fflush(stdin);
    gets(aux.apellidos);

    printf("Ingrese el NRO - Afiliado \n:");
    fflush(stdin);
    scanf("%s", aux.nroAfiliado);


    return aux;
}

int randomRango(int min, int max){
    return  min +  rand()% (max - min +1);
}

void setNombreRandom(char nombre[])
{
    char arregloNombres[][20] = {
    "Alejandro", "Bruno", "Carlos", "Daniel",
    "Eduardo", "Fernando", "Gabriel", "Hugo",
    "Ignacio", "Javier", "Alicia", "Beatriz",
    "Carla", "Diana", "Elena", "Fernanda",
    "Gabriela", "Helena", "Isabel", "Julieta",
    "Lucas", "Valentina", "Mateo", "Camila",
    "Santiago", "Martina", "Benjamín", "Sofía",
    "Thiago", "Emma", "Dylan", "Mía", "Joaquín",
    "Isabella", "Gael", "Catalina", "Leo", "Zoe",
    "Liam", "Abril", "Bautista", "Renata", "Iván",
    "Julieta", "Emilio", "Olivia", "Andrés", "Amanda",
    "Gabriel", "Clara", "Felipe", "Lola", "Tomás",
    "Elena", "Bruno", "Salma", "Alejo", "Julia",
    "Noah", "Antonia", "Simón", "Agustina", "Franco",
    "Malena", "Iker", "Lia", "Luciano"
    };
    strcpy(nombre, arregloNombres[randomRango(0,sizeof(arregloNombres)/30)]);
}

void setApellidoRandom(char apellido[]){

    char arreglosApellido[][40] = {"Rojas", "Alvarez",
                "Pintos" , "Gomez", "Garcia", "Romero"};

    strcpy(apellido,arreglosApellido[randomRango(0,sizeof(arreglosApellido)/30)]);

}



void setDniRandom(char dni[]){

    int dato = randomRango(1000000, 99999999);
    itoa(dato, dni, 10);
}


stPaciente cargaUnPacienteRandom(){

    stPaciente paciente;

    setNombreRandom(paciente.nombre);
    setApellidoRandom(paciente.apellidos);
    setDniRandom(paciente.dni);

    return paciente;

}






















/// FUNCIONES ARCHIVOS CON PACIENTES

int archivoPacientesHaciaArreglo(char nombreArchivo[], stPaciente arr[], int dim)
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


void arregloPacientesHaciaArchivo(stPaciente arr[], int v, char nombreArchivo[])
{

    FILE * buffer = NULL;
    buffer = fopen(nombreArchivo,"ab");

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








