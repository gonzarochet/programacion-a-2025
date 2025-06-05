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
            {1, "Cardiolog�a"},
            {2, "Pediatr�a"},
            {3, "Neurolog�a"},
            {4, "Dermatolog�a"},
            {5, "Ginecolog�a"},
            {6, "Oftalmolog�a"},
            {7, "Oncolog�a"},
            {8, "Traumatolog�a"},
            {9, "Psiquiatr�a"},
            {10, "Urolog�a"}
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





