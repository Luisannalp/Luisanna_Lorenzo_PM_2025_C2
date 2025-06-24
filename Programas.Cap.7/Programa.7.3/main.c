#include <stdio.h>

int main(void)
{
    char *cad0 = "Buenos días";    // Cadena literal, constante
    char cad1[20] = "Hola";        // Cadena con espacio asignado
    char cad2[] = "México";        // Longitud determinada automáticamente
    char cad3[] = { 'B', 'i', 'e', 'n', 'v', 'e', 'n', 'i', 'd', 'o', '\0' };
    char cad4[20], cad5[20], cad6[20];
    char p;
    int i = 0;

    printf("\nLa cadena cad0 es: ");
    puts(cad0);  // puts agrega salto de línea automáticamente

    printf("\nLa cadena cad1 es: ");
    printf("%s\n", cad1);

    printf("\nLa cadena cad2 es: ");
    puts(cad2);

    printf("\nLa cadena cad3 es: ");
    puts(cad3);

    printf("\nIngrese una línea de texto —se lee con fgets—:\n");
    fgets(cad4, sizeof(cad4), stdin);  // reemplazo de gets por fgets (más seguro)
    printf("\nLa cadena cad4 es: ");
    puts(cad4);

    printf("\nIngrese una línea de texto —se lee con scanf—:\n");
    scanf("%s", cad5);  // lee solo la primera palabra
    printf("\nLa cadena cad5 es: ");
    printf("%s\n", cad5);

    while ((getchar()) != '\n');  // limpiar el búfer

    printf("\nIngrese una línea de texto —se lee cada caracter con getchar—:\n");
    while ((p = getchar()) != '\n' && i < sizeof(cad6) - 1)
    {
        cad6[i++] = p;
    }
    cad6[i] = '\0';

    printf("\nLa cadena cad6 es: ");
    puts(cad6);

    return 0;
}
