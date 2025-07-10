#include <stdio.h>

#define PROD 15
#define MESES 12

void Lectura1(int ventas[PROD][MESES]);
void Lectura2(float costos[], int n);
void Funcion1(int ventas[][MESES], int f, int c, float costos[], float totales[]);
void Funcion2(float totales[], int n);
void Funcion3(float totales[], int n);

int main(void)
{
    int FAB[PROD][MESES] = {0};  
    float COS[PROD], VEN[PROD];

    Lectura1(FAB);
    Lectura2(COS, PROD);
    Funcion1(FAB, PROD, MESES, COS, VEN);
    Funcion2(VEN, PROD);
    Funcion3(VEN, PROD);

    return 0;
}

void Lectura1(int A[][MESES])
{
    int MES, PRO, CAN;

    printf("\nIngrese mes (1-12), tipo de producto (1-15) y cantidad vendida (use -1 -1 -1 para terminar):\n");
    scanf("%d %d %d", &MES, &PRO, &CAN);

    while (MES != -1 && PRO != -1 && CAN != -1)
    {
        if (MES >= 1 && MES <= 12 && PRO >= 1 && PRO <= 15)
            A[PRO - 1][MES - 1] += CAN;
        else
            printf("Datos fuera de rango. Intente nuevamente.\n");

        printf("Ingrese mes, tipo de producto y cantidad vendida: ");
        scanf("%d %d %d", &MES, &PRO, &CAN);
    }
}

void Lectura2(float A[], int N)
{
    for (int I = 0; I < N; I++)
    {
        printf("Ingrese costo del producto %d: ", I + 1);
        scanf("%f", &A[I]);
    }
}

void Funcion1(int A[][MESES], int F, int C, float V1[], float V2[])
{
    int I, J, SUM;

    printf("\nTotal de ventas por producto:\n");

    for (I = 0; I < F; I++)
    {
        SUM = 0;
        for (J = 0; J < C; J++)
            SUM += A[I][J];

        V2[I] = V1[I] * SUM;
        printf("Producto %2d: %8.2f\n", I + 1, V2[I]);
    }
}

void Funcion2(float A[], int C)
{
    float SUM = 0.0;
    for (int I = 0; I < C; I++)
        SUM += A[I];

    printf("\nTotal de ventas de la fábrica: %.2f\n", SUM);
}

void Funcion3(float A[], int C)
{
    int TPR = 0;
    float VEN = A[0];

    for (int I = 1; I < C; I++)
    {
        if (VEN < A[I])
        {
            TPR = I;
            VEN = A[I];
        }
    }

    printf("\nProducto más vendido: %d\tVentas: %.2f\n", TPR + 1, VEN);
}
