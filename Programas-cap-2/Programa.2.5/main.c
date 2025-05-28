#include <stdio.h>
#include <math.h>

/* Función matemática
El programa obtiene el resultado de una función.

OP y T: variable de tipo entero.
Res: variable de tipo real.*/

void main(void)
{
    int OP, T;
    float Res;
    printf("Ingrese la opción del cálculo y el valor entero:");
    scanf("%d %d", &OP, &T);

    if(OP== 1)
        Res = T/ 5;
    else if (OP == 2)
        Res = pow(T,T);
    else if (OP==3)
        Res = (6*T/2);
    else
        Res=1;

    printf("\nResultado> %7.2f", Res);
}
