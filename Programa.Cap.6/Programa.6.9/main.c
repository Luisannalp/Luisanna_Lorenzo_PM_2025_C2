#include <stdio.h>

#define MAX 10

// Prototipos de funciones
void Lectura(int A[][MAX], int N);
void Calcula(int A[][MAX], float B[], int N);
float Mod0(int A[][MAX], int K, int M);
float Mod1(int A[][MAX], int N);
float Mod2(int A[][MAX], int N, int M);
void Imprime(float B[], int N);

int main(void)
{
    int MAT[MAX][MAX], TAM;
    float VEC[MAX];

    do {
        printf("Ingrese el tamaño de la matriz: ");
        scanf("%d", &TAM);
    } while (TAM > MAX || TAM < 1);

    Lectura(MAT, TAM);
    Calcula(MAT, VEC, TAM);
    Imprime(VEC, TAM);

    return 0;
}

void Lectura(int A[][MAX], int N)
{
    int I, J;
    for (I = 0; I < N; I++) {
        for (J = 0; J < N; J++) {
            printf("Ingrese el elemento [%d][%d]: ", I + 1, J + 1);
            scanf("%d", &A[I][J]);
        }
    }
}

void Calcula(int A[][MAX], float B[], int N)
{
    int I;
    for (I = 0; I < N; I++) {
        switch (I % 3) {
            case 1:
                B[I] = Mod1(A, I);
                break;
            case 2:
                B[I] = Mod2(A, I, N);
                break;
            default:
                B[I] = Mod0(A, I, N);
                break;
        }
    }
}

float Mod0(int A[][MAX], int K, int M)
{
    int I;
    float PRO = 1.0, SUM = 0.0;
    for (I = 0; I < M; I++) {
        PRO *= A[I][K];
        SUM += A[I][K];
    }
    if (SUM == 0) return 0; // evitar división por cero
    return PRO / SUM;
}

float Mod1(int A[][MAX], int N)
{
    int I;
    float SUM = 0.0;
    for (I = 0; I <= N; I++) {
        SUM += A[N][I];
    }
    return SUM;
}

float Mod2(int A[][MAX], int N, int M)
{
    int I;
    float PRO = 1.0;
    for (I = N; I < M; I++) {
        PRO *= A[I][N];
    }
    return PRO;
}

void Imprime(float B[], int N)
{
    int I;
    for (I = 0; I < N; I++) {
        printf("Elemento %d: %.2f\n", I, B[I]);
    }
}
