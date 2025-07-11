#include <stdio.h>
#include <stdlib.h>  

void main(void)
{
    const char *cad0;
    cad0 = "Argentina"; 
    puts(cad0);
    cad0 = "Brasil";
    puts(cad0);

    char cad1[100];  
    printf("Ingrese una cadena: ");
    fgets(cad1, sizeof(cad1), stdin);
    size_t len = 0;
    while (cad1[len] != '\0') len++;
    if (len > 0 && cad1[len-1] == '\n') cad1[len-1] = '\0';
    puts(cad1);
    char cad2[20] = "México";
    puts(cad2);
    printf("Ingrese otra cadena: ");
    fgets(cad2, sizeof(cad2), stdin);
    len = 0;
    while (cad2[len] != '\0') len++;
    if (len > 0 && cad2[len-1] == '\n') cad2[len-1] = '\0';
    puts(cad2);
    char cad3[20], *ptr;
    int i;
    double d;
    printf("\nIngrese una cadena numérica para atoi: ");
    fgets(cad3, sizeof(cad3), stdin);
    len = 0;
    while (cad3[len] != '\0') len++;
    if (len > 0 && cad3[len-1] == '\n') cad3[len-1] = '\0';
    i = atoi(cad3);
    printf("%s \t %d\n", cad3, i+3);
    printf("Ingrese una cadena numérica para atof y strtod: ");
    fgets(cad3, sizeof(cad3), stdin);
    len = 0;
    while (cad3[len] != '\0') len++;
    if (len > 0 && cad3[len-1] == '\n') cad3[len-1] = '\0';
    d = atof(cad3);
    printf("%s \t %.2lf\n", cad3, d+1.50);
    d = strtod(cad3, &ptr);
    printf("strtod conversion: %s, resto: %s\n", cad3, ptr);


    return 0;
}
