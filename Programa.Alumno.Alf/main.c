#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int matricula;
    char nombre[50];
    float promedio;
} alumno;

#define MAX_ALUMNOS 100

// Función para intercambiar dos alumnos
void swap(alumno *a, alumno *b)
{
    alumno temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort por nombre (alfabético)
void ordenarPorNombre(alumno arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-1-i; j++)
            if (strcmp(arr[j].nombre, arr[j+1].nombre) > 0)
                swap(&arr[j], &arr[j+1]);
}

// Bubble Sort por promedio (de mayor a menor)
void ordenarPorPromedio(alumno arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-1-i; j++)
            if (arr[j].promedio < arr[j+1].promedio)
                swap(&arr[j], &arr[j+1]);
}

// Guardar alumnos en archivo binario
void guardarAlumnos(const char *filename, alumno alumnos[], int n)
{
    FILE *fp = fopen(filename, "wb");
    if (!fp)
    {
        printf("Error al abrir archivo para guardar.\n");
        return;
    }
    fwrite(alumnos, sizeof(alumno), n, fp);
    fclose(fp);
}

// Leer alumnos desde archivo binario
int leerAlumnos(const char *filename, alumno alumnos[])
{
    FILE *fp = fopen(filename, "rb");
    int n = 0;
    if (!fp)
    {
        printf("Archivo no encontrado, empezando con lista vacía.\n");
        return 0;
    }
    n = fread(alumnos, sizeof(alumno), MAX_ALUMNOS, fp);
    fclose(fp);
    return n;
}

// Imprimir lista de alumnos
void imprimirAlumnos(alumno alumnos[], int n)
{
    printf("\nLista de alumnos:\n");
    printf("%-10s %-20s %-10s\n", "Matrícula", "Nombre", "Promedio");
    for (int i = 0; i < n; i++)
    {
        printf("%-10d %-20s %-10.2f\n", alumnos[i].matricula, alumnos[i].nombre, alumnos[i].promedio);
    }
}

// Función para ingresar alumnos desde teclado
int ingresarAlumnos(alumno alumnos[])
{
    int n;
    printf("¿Cuántos alumnos deseas ingresar? (máx %d): ", MAX_ALUMNOS);
    scanf("%d", &n);
    if (n > MAX_ALUMNOS) n = MAX_ALUMNOS;

    for (int i = 0; i < n; i++)
    {
        printf("Alumno %d\n", i+1);
        printf("Matrícula: ");
        scanf("%d", &alumnos[i].matricula);
        printf("Nombre: ");
        scanf(" %[^\n]", alumnos[i].nombre);
        printf("Promedio: ");
        scanf("%f", &alumnos[i].promedio);
    }
    return n;
}

int main()
{
    alumno alumnos[MAX_ALUMNOS];
    int n;

    // Intentamos cargar archivo si existe
    n = leerAlumnos("alumnos.dat", alumnos);

    // Si archivo vacío o no existe, pedimos ingresar alumnos
    if (n == 0)
    {
        n = ingresarAlumnos(alumnos);
        guardarAlumnos("alumnos.dat", alumnos, n);
    }

    int opcion;
    printf("\n¿Cómo quieres ordenar los alumnos?\n");
    printf("1. Ordenar por nombre (alfabético)\n");
    printf("2. Ordenar por promedio (mayor a menor)\n");
    printf("Elige opción (1 o 2): ");
    scanf("%d", &opcion);

    if (opcion == 1)
    {
        ordenarPorNombre(alumnos, n);
    }
    else if (opcion == 2)
    {
        ordenarPorPromedio(alumnos, n);
    }
    else
    {
        printf("Opción no válida. Mostrando sin ordenar.\n");
    }

    imprimirAlumnos(alumnos, n);

    return 0;
}
