#include <stdio.h>
#include <string.h>

/* Otras funciones de la biblioteca string.h para el manejo de cadenas. */
int main(void)
{
    int i;
    char cad0[20] = "Hola México";
    char cad1[20] = "Hola Guatemala";
    char cad2[20] = "Hola Venezuela";
    char cad3[20] = "Hola México";
    char *c;
    char c3;

    i = strcmp(cad0, cad1);
    /* strcmp: devuelve >0 si cad0 > cad1, <0 si cad0 < cad1, 0 si iguales */
    printf("\nResultado de la comparación —cad0 y cad1—: %d", i);

    i = strcmp(cad0, cad2);
    printf("\nResultado de la comparación —cad0 y cad2—: %d", i);

    i = strcmp(cad0, cad3);
    printf("\nResultado de la comparación —cad0 y cad3—: %d", i);

    i = strlen(cad0);
    /* strlen: longitud de la cadena */
    printf("\nLongitud cadena cad0: %d", i);

    i = strlen(cad1);
    printf("\nLongitud cadena cad1: %d", i);

    c = strchr(cad1, 'G');  // busca caracter 'G' en cad1
    if (c != NULL)
    {
        c3 = *c;
        printf("\nEl valor de c3 es:  %c", c3);
    }

    c = strchr(cad2, 'V');  // busca caracter 'V' en cad2
    if (c != NULL)
    {
        c3 = *c;
        printf("\nEl valor de c3 es:  %c", c3);
    }

    return 0;
}
