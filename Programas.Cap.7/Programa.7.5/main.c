#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    int i;
    double d;
    long l;
    char cad0[100], *cad1;
    char cad2[20] = "Ejemplo";

    printf("\nIngrese una cadena de caracteres: ");
    fgets(cad0, sizeof(cad0), stdin);
    size_t len = 0;
    while (cad0[len] != '\0') len++;
    if (len > 0 && cad0[len-1] == '\n') cad0[len-1] = '\0';

    i = atoi(cad0);
    printf("\n%s \t %d", cad0, i + 3);

    printf("\nIngrese una cadena de caracteres: ");
    fgets(cad0, sizeof(cad0), stdin);
    len = 0;
    while (cad0[len] != '\0') len++;
    if (len > 0 && cad0[len-1] == '\n') cad0[len-1] = '\0';

    d = atof(cad0);
    printf("\n%s \t %.2lf ", cad0, d + 1.50);

    d = strtod(cad0, &cad1);
    printf("\n%s \t %.2lf", cad0, d + 1.50);
    puts(cad1);

    l = atol(cad0);
    printf("\n%s \t %ld ", cad0, l + 10);

    l = strtol(cad0, &cad1, 0);
    printf("\n%s \t %ld", cad0, l + 10);
    puts(cad1);

    // Nota: La línea cad2[10] = "Guatemala"; es incorrecta y se elimina

    return 0;
}
