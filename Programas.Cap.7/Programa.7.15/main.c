#include <stdio.h>
#include <ctype.h>

/* Decodifica.
   El programa decodifica una cadena de caracteres compuesta por números y letras. */

void interpreta(char *);  /* Prototipo de función */

int main(void)
{
    char cad[50];
    printf("\nIngrese la cadena de caracteres: ");
    gets(cad);
    interpreta(cad);
}

void interpreta(char *cadena)
/* Esta función se utiliza para decodificar la cadena de caracteres. */
{
    int i = 0, j, k;
    while (cadena[i] != '\0')
    {
        if (isalpha(cadena[i]))  /* Verifica si es una letra */
        {
            k = cadena[i - 1] - 48;
            /* Se resta 48 al valor ASCII del dígito anterior para convertirlo a entero */

            for (j = 0; j < k; j++)
                putchar(cadena[i]);
        }
        i++;
    }
}
