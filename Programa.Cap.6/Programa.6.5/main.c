#include <stdio.h>

#define MAX 50
#define EXA 4

void Lectura(float A[MAX][EXA], int N);
void Funcion1(float A[MAX][EXA], int N); 
void Funcion2(float A[MAX][EXA], int N); 

int main(void)
{
    int NAL;
    float ALU[MAX][EXA];

    do {
        printf("Ingrese el número de alumnos del grupo: ");
        scanf("%d", &NAL);
    } while (NAL > MAX || NAL < 1); 

    Lectura(ALU, NAL);
    Funcion1(ALU, NAL);
    Funcion2(ALU, NAL);

    return 0;
}

void Lectura(float A[][EXA], int N)
{
    int I, J;
    for (I = 0; I < N; I++)
        for (J = 0; J < EXA; J++) {
            printf("Ingrese la calificación %d del alumno %d: ", J + 1, I + 1);
            scanf("%f", &A[I][J]);
        }
}

void Funcion1(float A[][EXA], int T)
{
    int I, J;
    float SUM, PRO;
    for (I = 0; I < T; I++) {
        SUM = 0;
        for (J = 0; J < EXA; J++)
            SUM += A[I][J];
        PRO = SUM / EXA;
        printf("\nEl promedio del alumno %d es: %5.2f", I + 1, PRO);
    }
}

void Funcion2(float A[][EXA], int T)
{
    int I, J, MAY = 0;
    float SUM, PRO, MPRO = 0;

    printf("\n");
    for (J = 0; J < EXA; J++) {
        SUM = 0;
        for (I = 0; I < T; I++)
            SUM += A[I][J];
        PRO = SUM / T;

        printf("El promedio del examen %d es: %5.2f\n", J + 1, PRO);

        if (PRO > MPRO) {
            MPRO = PRO;
            MAY = J;
        }
    }

    printf("\nEl examen con mayor promedio es: %d \t Promedio: %5.2f\n", MAY + 1, MPRO);
}
