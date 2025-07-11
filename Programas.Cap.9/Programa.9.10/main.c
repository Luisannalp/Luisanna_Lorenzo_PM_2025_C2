#include <stdio.h>

typedef struct
{
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void modifica(FILE *);

void main(void)
{
    FILE *ar;

    if ((ar = fopen("ad1.dat", "r+b")) != NULL)
    {
        modifica(ar);
    }
    else
    {
        printf("\nEl archivo no se puede abrir\n");
        fclose(ar);
    }
}

void modifica(FILE *ap)
{
    int d;
    alumno alu;

    printf("\nIngrese el número de registro que desea modificar: ");
    scanf("%d", &d);
    fseek(ap, (d - 1) * sizeof(alumno), SEEK_SET);
    fread(&alu, sizeof(alumno), 1, ap);

    printf("\nIngrese el promedio correcto del alumno: ");
    scanf("%f", &alu.promedio);
    fseek(ap, (d - 1) * sizeof(alumno), SEEK_SET);
    fwrite(&alu, sizeof(alumno), 1, ap);
}
