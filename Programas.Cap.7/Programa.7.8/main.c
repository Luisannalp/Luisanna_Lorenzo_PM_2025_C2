#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Minúsculas y mayúsculas.
   El programa recibe un arreglo unidimensional de cadenas y determina el
   número de minúsculas y mayúsculas que hay en cada cadena. */

/* Prototipo de función */
void minymay(char *cadena);

int main(void)
{
    int i, n;
    char FRA[20][50];  /* Arreglo de 20 cadenas, cada una de hasta 49 caracteres + '\0' */

    printf("\nIngrese el número de filas del arreglo (máximo 20): ");
    scanf("%d", &n);
    if (n > 20) n = 20; // evitar overflow

    getchar(); // limpiar el buffer de entrada después de scanf

    for (i = 0; i < n; i++)
    {
        printf("Ingrese la línea %d de texto: ", i + 1);
        fgets(FRA[i], sizeof(FRA[i]), stdin);

        // eliminar salto de línea
        size_t len = strlen(FRA[i]);
        if (len > 0 && FRA[i][len - 1] == '\n')
            FRA[i][len - 1] = '\0';
    }

    printf("\n\n");

    for (i = 0; i < n; i++)
        minymay(FRA[i]);

    return 0;
}

void minymay(char *cadena)
{
    /* Esta función calcula el número de minúsculas y mayúsculas en la cadena */
    int i = 0, mi = 0, ma = 0;

    while (cadena[i] != '\0')
    {
        if (islower((unsigned char)cadena[i]))
            mi++;
        else if (isupper((unsigned char)cadena[i]))
            ma++;
        i++;
    }

    printf("\nCadena: \"%s\"", cadena);
    printf("\nNúmero de letras minúsculas: %d", mi);
    printf("\nNúmero de letras mayúsculas: %d\n", ma);
}
