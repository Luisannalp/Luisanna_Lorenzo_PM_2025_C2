#include <stdio.h>

/* Universidad.
   El programa maneja el ingreso de alumnos en 8 carreras,
   2 semestres, durante 5 años. */

const int F = 8;  // Carreras (filas)
const int C = 2;  // Semestres (columnas)
const int P = 5;  // Años (profundidad)

/* Prototipos de funciones */
void Lectura(int A[][C][P], int FI, int CO, int PR);
void Funcion1(int A[][C][P], int FI, int CO, int PR);
void Funcion2(int A[][C][P], int FI, int CO, int PR);
void Funcion3(int A[][C][P], int FI, int CO, int PR);

int main(void)
{
    int UNI[F][C][P];

    Lectura(UNI, F, C, P);
    Funcion1(UNI, F, C, P);
    Funcion2(UNI, F, C, P);
    Funcion3(UNI, 6, C, P);  // Ingeniería en Computación (índice 6)

    return 0;
}

void Lectura(int A[][C][P], int FI, int CO, int PR)
{
    int K, I, J;
    for (K = 0; K < PR; K++)
        for (I = 0; I < FI; I++)
            for (J = 0; J < CO; J++)
            {
                printf("Año: %d\tCarrera: %d\tSemestre: %d: ", K + 1, I + 1, J + 1);
                scanf("%d", &A[I][J][K]);
            }
}

void Funcion1(int A[][C][P], int FI, int CO, int PR)
{
    int K, I, J, MAY = 0, AO = -1, SUM;

    for (K = 0; K < PR; K++)
    {
        SUM = 0;
        for (I = 0; I < FI; I++)
            for (J = 0; J < CO; J++)
                SUM += A[I][J][K];

        if (SUM > MAY)
        {
            MAY = SUM;
            AO = K;
        }
    }
    printf("\n\nAño con mayor ingreso de alumnos: %d    Alumnos: %d\n", AO + 1, MAY);
}

void Funcion2(int A[][C][P], int FI, int CO, int PR)
{
    int I, J, MAY = 0, CAR = -1, SUM;

    for (I = 0; I < FI; I++)
    {
        SUM = 0;
        for (J = 0; J < CO; J++)
            SUM += A[I][J][PR - 1];  // Último año

        if (SUM > MAY)
        {
            MAY = SUM;
            CAR = I;
        }
    }
    printf("\n\nCarrera con mayor número de alumnos el último año: %d  Alumnos: %d\n", CAR + 1, MAY);
}

void Funcion3(int A[][C][P], int FI, int CO, int PR)
{
    int K, J, MAY = 0, AO = -1, SUM;

    for (K = 0; K < PR; K++)
    {
        SUM = 0;
        for (J = 0; J < CO; J++)
            SUM += A[FI - 1][J][K];  // Carrera Ingeniería en Computación (índice FI-1)

        if (SUM > MAY)
        {
            MAY = SUM;
            AO = K;
        }
    }
    printf("\n\nAño con mayor ingreso en Ingeniería en Computación: %d   Alumnos: %d\n", AO + 1, MAY);
}
