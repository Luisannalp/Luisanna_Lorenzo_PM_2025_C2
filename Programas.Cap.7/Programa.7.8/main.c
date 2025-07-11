#include <stdio.h>
#include <string.h>
#include <ctype.h>

void minymay(char *cadena);

int main(void)
{
    int i, n;
    char FRA[20][50];  

    printf("\nIngrese el número de filas del arreglo (máximo 20): ");
    scanf("%d", &n);
    if (n > 20) n = 20; 
    getchar();

    for (i = 0; i < n; i++)
    {
        printf("Ingrese la línea %d de texto: ", i + 1);
        fgets(FRA[i], sizeof(FRA[i]), stdin);

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
