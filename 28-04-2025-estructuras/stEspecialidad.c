#include "stEspecialidad.h"

stEspecialidad cargaUnaEspecialidad()
{
    stEspecialidad esp;

    printf("Ingrese ID de la especialidad: ");
    scanf("%d", &esp.idEspecialidad);
    fflush(stdin);

    printf("Ingrese nombre de la especialidad: ");
    fgets(esp.nombreEspecialidad, 30, stdin);

    return esp;
}

void muestraUnaEspecialidad(stEspecialidad esp)
{
    printf("ID Especialidad: %d\n", esp.idEspecialidad);
    printf("Nombre Especialidad: %s\n", esp.nombreEspecialidad);
}



/// ARCHIVOS CON ESPECIALIDAD

void guardarEspecialidadesEnArchivo(char nombreArchivo[])
{
    FILE *archivo = fopen(nombreArchivo, "wb");
    if (archivo)
    {
        stEspecialidad especialidades[10] =
        {
            {1, "Cardiología"},
            {2, "Pediatría"},
            {3, "Neurología"},
            {4, "Dermatología"},
            {5, "Ginecología"},
            {6, "Oftalmología"},
            {7, "Oncología"},
            {8, "Traumatología"},
            {9, "Psiquiatría"},
            {10, "Urología"}
        };

        fwrite(especialidades, sizeof(stEspecialidad), 10, archivo);
        fclose(archivo);
    }

}

void mostrarEspecialidadesDesdeArchivo(char nombreArchivo[])
{
    FILE *archivo = fopen(nombreArchivo, "rb");
    if (archivo)
    {
        stEspecialidad esp;
        printf("\n--- Especialidades ---\n");

        while (fread(&esp, sizeof(stEspecialidad), 1, archivo))
        {
            muestraUnaEspecialidad(esp);
        }

        fclose(archivo);
    }

}



/// ARREGLOS CON ESPECIALIDAD
int cargarArregloEspecialidadesDesdeArchivo(char nombreArchivo[], stEspecialidad arr[], int DIM){}





