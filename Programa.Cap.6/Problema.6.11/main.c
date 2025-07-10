#include <stdio.h>

#define FONDOS 5
#define MESES 12

void LecturaM(float [][MESES], int, int);
void LecturaV(float *, int);
void F1(float [][MESES], int, int, float *, float *);
void F2(float [][MESES], int, int);
void F3(float *, int);

int main(void)
{
    float FON[FONDOS][MESES], PRE[FONDOS], REN[FONDOS];

    LecturaM(FON, FONDOS, MESES);
    LecturaV(PRE, FONDOS);
    F1(FON, FONDOS, MESES, PRE, REN);
    F2(FON, FONDOS, MESES);
    F3(REN, FONDOS);

    return 0;
}

void LecturaM(float A[][MESES], int F, int C)
{
    int i, j;
    for (i = 0; i < F; i++) {
        for (j = 0; j < C; j++) {
            printf("Precio fondo %d, mes %d: ", i + 1, j + 1);
            scanf("%f", &A[i][j]);
        }
    }
}

void LecturaV(float A[], int T)
{
    int i;
    printf("\n");
    for (i = 0; i < T; i++) {
        printf("Precio Fondo %d al 31/12/2003: ", i + 1);
        scanf("%f", &A[i]);
    }
}

void F1(float A[][MESES], int F, int C, float B[], float V[])
{
    int i;
    printf("\nRENDIMIENTOS ANUALES DE LOS FONDOS\n");
    for (i = 0; i < F; i++) {
        V[i] = ((A[i][C - 1] - B[i]) / B[i]) * 100.0f;
        printf("Fondo %d: %.2f%%\n", i + 1, V[i]);
    }
}

void F2(float A[][MESES], int F, int C)
{
    int i, j;
    float suma, promedio;
    printf("\nPROMEDIO ANUALIZADO DE LAS ACCIONES DE LOS FONDOS\n");
    for (i = 0; i < F; i++) {
        suma = 0;
        for (j = 0; j < C; j++) {
            suma += A[i][j];
        }
        promedio = suma / C;
        printf("Fondo %d: %.2f\n", i + 1, promedio);
    }
}

void F3(float A[], int F)
{
    float mejor = A[0], peor = A[0];
    int im = 0, ip = 0, i;

    for (i = 1; i < F; i++) {
        if (A[i] > mejor) {
            mejor = A[i];
            im = i;
        }
        if (A[i] < peor) {
            peor = A[i];
            ip = i;
        }
    }

    printf("\nMEJOR Y PEOR FONDO DE INVERSION\n");
    printf("Mejor fondo: %d\tRendimiento: %.2f%%\n", im + 1, mejor);
    printf("Peor fondo: %d\tRendimiento: %.2f%%\n", ip + 1, peor);
}
