#include <stdio.h>

void main(void)
{
    float PAG, SPA;
    SPA = 0;
    printf("Ingrese el primer pago:\t");
    scanf("%f", &PAG);
    while (PAG != 0)
        /* Observa que la condición es verdadera mientras el pago es diferente de cero. */
    {
        SPA = SPA + PAG;
        printf("Ingrese el siguiente pago:\t ");
        scanf("%f", &PAG);
        /* Observa que la proposición que modifica la condición es una lectura. */
    }
    printf("\nEl total de pagos del mes es: %.2f", SPA);
}
