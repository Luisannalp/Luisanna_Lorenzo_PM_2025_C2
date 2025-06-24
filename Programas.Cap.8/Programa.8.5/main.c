#include <stdio.h>
#include <string.h>

/* Uniones.
El programa muestra cómo se declara una unión, y cómo acceder a sus campos
para lectura y escritura, dentro de una estructura.
*/

union datos
{
    char celular[15];
    char correo[20];
};

typedef struct
{
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    union datos personales;
} alumno;

/* Prototipo de función */
void Lectura(alumno *a);

void main(void)
{
    alumno a1 = {120, "María", "Contabilidad", 8.9, {"5-158-40-50"}};
    alumno a2, a3;

    printf("Alumno 2\n");
    printf("Ingrese la matrícula: ");
    scanf("%d", &a2.matricula);
    fflush(stdin);
    printf("Ingrese el nombre: ");
    gets(a2.nombre);
    printf("Ingrese la carrera: ");
    gets(a2.carrera);
    printf("Ingrese el promedio: ");
    scanf("%f", &a2.promedio);
    fflush(stdin);
    printf("Ingrese el correo electrónico: ");
    gets(a2.personales.correo);

    printf("Alumno 3\n");
    Lectura(&a3);

    /* Impresión de resultados */
    printf("\nDatos del alumno 1\n");
    printf("%d\n", a1.matricula);
    puts(a1.nombre);
    puts(a1.carrera);
    printf("%.2f\n", a1.promedio);
    puts(a1.personales.celular); // Mostrará el celular
    // puts(a1.personales.correo); // Esto imprimiría basura si se activa

    printf("\nDatos del alumno 2\n");
    printf("%d\n", a2.matricula);
    puts(a2.nombre);
    puts(a2.carrera);
    printf("%.2f\n", a2.promedio);
    puts(a2.personales.correo); // Imprime correo, celular estaría sobrescrito

    printf("Ingrese el teléfono celular del alumno 2: ");
    fflush(stdin);
    gets(a2.personales.celular); // Sobrescribe el campo correo
    puts(a2.personales.celular); // Imprime el nuevo celular
    puts(a2.personales.correo);  // Imprime basura

    printf("\nDatos del alumno 3\n");
    printf("%d\n", a3.matricula);
    puts(a3.nombre);
    puts(a3.carrera);
    printf("%.2f\n", a3.promedio);
    puts(a3.personales.celular);  // Se ingresó por la función
    puts(a3.personales.correo);   // Mostrará basura
}

void Lectura(alumno *a)
{
    printf("\nIngrese la matrícula: ");
    scanf("%d", &a->matricula);
    fflush(stdin);
    printf("Ingrese el nombre: ");
    gets(a->nombre);
    printf("Ingrese la carrera: ");
    gets(a->carrera);
    printf("Ingrese el promedio: ");
    scanf("%f", &a->promedio);
    fflush(stdin);
    printf("Ingrese el teléfono celular: ");
    gets(a->personales.celular);
}
