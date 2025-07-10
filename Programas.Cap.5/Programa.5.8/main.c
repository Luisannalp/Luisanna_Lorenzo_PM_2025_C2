#include <stdio.h>

const int TAM = 100;

void Imprime(int[], int);  
void Primo(int, int *);

void main(void)
{
    int P[TAM] = {1, 2};  
    int FLA, J = 2, PRI = 3;

    while (J < TAM) 
    {
        FLA = 1;
        Primo(PRI, &FLA);  

        if (FLA) 
        {
            P[J] = PRI;
            J++;
        }

        PRI += 2; 
    }

    Imprime(P, TAM);
}

void Primo(int A, int *B)
// Esta función determina si A es primo, en cuyo caso el valor de *B se mantiene en 1.
// Si no es primo, *B se pone en 0.
{
    int DI = 3;
    while (*B && (DI <= A / 2))  // Se puede optimizar a sqrt(A), pero se mantiene así.
    {
        if ((A % DI) == 0)
            *B = 0;
        DI++;
    }
}

void Imprime(int Primos[], int T)
// Esta función imprime el arreglo unidimensional de números primos.
{
    int I;
    for (I = 0; I < T; I++)
        printf("Primos[%d]: %d\n", I, Primos[I]);
}
