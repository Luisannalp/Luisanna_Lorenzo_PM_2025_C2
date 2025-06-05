#include <stdio.h>
#include <stdlib.h>
#define menu_ninguno 0
#define menu_salir 1
#define menu_sumar 2
#define menu_dividir 3


int main()
{
    float n1 = 0.0, n2 = 0.0, result = 0.0;
    int menu = menu_ninguno;

    do
    {
        printf("\n1-sali \n2-Sumar \n3-Dividir");
        scanf("%i", &menu);

        if(menu == menu_sumar)
        {
            printf("\nPrimer sumando:");
            scanf("%f", &n1);
            printf("\nSegundo sumando:");
            scanf("%f", &n2);
            result = n1+n2;
            printf("\nSuma de %f y %f es:%f", n1, n2, result);
        }
        if (menu == menu_dividir)
        {
            printf("\nDividendo:");
            scanf("%f", &n1);
            printf("\nSegundo divisor:");
            scanf("%f", &n2);
            result = n1/n2;
            printf("\nResiduo de %f y %f es:%f", n1, n2, result);
        }
        if (menu < 1 || menu >3)
        {
            printf("\nMenu no valido 1-3");
        }
    }while (menu != menu_salir);
    return 0;
}
