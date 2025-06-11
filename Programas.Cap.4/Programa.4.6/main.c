#include <stdio.h>

void f1(int *);  // Prototipo

int main(void)
{
    int I, K = 5;
    for (I = 1; I <= 3; I++)
    {
        printf("\n\nValor de K antes de llamar a la función: %d", K);

        f1(&K);  // Llamada por referencia

        printf("\nValor de K después de llamar a la función: %d", K);
    }

    return 0;
}

void f1(int *R)
{
    /* La función recibe un parámetro por referencia.
       Se modifica directamente el valor de la variable original. */
    *R *= 2;
}

