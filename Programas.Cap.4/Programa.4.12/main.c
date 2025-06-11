# include <stdio.h>

/* Máximo común divisor.
El programa, al recibir como datos dos números enteros, calcula el máximo
común divisor de dichos números. */

int mcd(int, int);
void main(void)
{
    int NU1, NU2, RES;
    printf("\nIngresa los dos números enteros: ");
    scanf("%d %d", &NU1, &NU2);
    RES = mcd (NU1, NU2);
    printf("\nEl máximo común divisor de %d y %d es: %d", NU1, NU2, RES);
}
int  mcd(int  N1, int  N2)
/* Esta función calcula el máximo común divisor de los números NN11
y NN22. */
{
    int I;
    if  (N1 < N2)
        I = N1 / 2;
    else
    I = N2 / 2;
    /* II  se inicializa con el máximo valor posible que puede ser divisor
    de NN11 y NN22. */

    while ((N1 % I)|| (N2 % I))
        /* El ciclo se mantiene activo mientras ((NN11  %%  II)) o ((NN22  %%  II)) sean
        distintos de cero. Cuando el resultado de la evaluación sea 0, el
        ciclo se detiene ya que se habrá encontrado el máximo común divisor. */
        I--;
    return I;
}

