#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[50];
    int edad;
    float promedio;
} Alumno;

void guardarAlumnos(Alumno *alumnos, int n, const char *archivo) {
    FILE *f = fopen(archivo, "wb");
    fwrite(alumnos, sizeof(Alumno), n, f);
    fclose(f);
}

Alumno* leerAlumnos(int *n, const char *archivo) {
    FILE *f = fopen(archivo, "rb");
    if (!f) return NULL;

    fseek(f, 0, SEEK_END);
    long tam = ftell(f);
    rewind(f);

    *n = tam / sizeof(Alumno);
    Alumno *alumnos = (Alumno*)malloc(tam);
    fread(alumnos, sizeof(Alumno), *n, f);
    fclose(f);

    return alumnos;
}

int main() {
    int n = 2;
    Alumno *alumnos = (Alumno*)malloc(n * sizeof(Alumno));

    strcpy(alumnos[0].nombre, "Luis");
    alumnos[0].edad = 20;
    alumnos[0].promedio = 8.7;

    strcpy(alumnos[1].nombre, "Ana");
    alumnos[1].edad = 22;
    alumnos[1].promedio = 9.1;

    guardarAlumnos(alumnos, n, "alumnos.dat");
    free(alumnos);

    Alumno *leidos;
    leidos = leerAlumnos(&n, "alumnos.dat");

    for (int i = 0; i < n; i++) {
        printf("Nombre: %s\nEdad: %d\nPromedio: %.2f\n\n",
               leidos[i].nombre, leidos[i].edad, leidos[i].promedio);
    }

    free(leidos);
    return 0;
}

