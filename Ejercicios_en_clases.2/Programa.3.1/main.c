#include <stdio.h>
#include <stdlib.h>

int main()
{
    int I = 0;
    float SAL = 0.0, NOM = 0.0 ;

    for(I = 1, NOM = 0.0; I <= 5; I++)
    {
        printf("Ingrese el salario del profesor %d: \t", I);
        scanf("%f", &SAL);

        float impuesto = SAL * 0.12;
        float salario = SAL - impuesto;
        NOM = NOM + SAL;

        printf("Sueldo del profesor %d: %.2f\n", I, salario);

    }
    printf("\nTotal a pagar es: %.2f", NOM);
    printf("\nTotal a pagar a profesores: %.2f",NOM- (NOM *0.12) );
    printf("\nTotal a pagar en impuestos: %.2f",NOM *0.12 );

    /*Imprimir el sueldo a pagar a cada profesor menos el 12%
    Total a pagar a profesore y el total a pagar de impuestos*/

    return 0;
}
