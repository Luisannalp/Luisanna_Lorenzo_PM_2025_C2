#include <stdio.h>

/* Prueba de variables globales, locales y estáticas.
   El programa muestra el comportamiento en las que se usan diferentes tipos de variables.
*/

int f1(void);  // Usa variable global
int f2(void);  // Usa variable local
int f3(void);  // Usa variable estática
int f4(void);  // Usa variable local y global con nombres distintos

int X = 2;     // Variable global
int K_glob = 3; // Variable global distinta a la local de f4

int main(void)
{
    int I;
    for (I = 1; I <= 3; I++)
    {
        printf("\n\nResultado de la función f1(): %d", f1());
        printf("\nResultado de la función f2(): %d", f2());
        printf("\nResultado de la función f3(): %d", f3());
        printf("\nResultado de la función f4(): %d", f4());
    }

    return 0;
}

int f1(void)
{
    // Esta función utiliza la variable global X
    X = X + 5;
    return (X);
}

int f2(void)
{
    // Esta función utiliza una variable local
    int X = 1;
    X += 7;
    return (X);
}

int f3(void)
{
    // Esta función utiliza una variable estática
    static int X = 0;
    X += 2;
    return (X);
}

int f4(void)
{
    // Esta función utiliza una variable local y una global (con nombre distinto)
    int K = 5;           // Variable local
    int resultado = K + K_glob;  // Usa local y global
    return resultado;
}

