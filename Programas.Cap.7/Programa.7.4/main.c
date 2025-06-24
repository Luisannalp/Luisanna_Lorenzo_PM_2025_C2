#include <stdio.h>
#include <stdlib.h>  // para atoi, atof, strtod, etc.

/* Declaración y uso correcto de cadenas y funciones */

int main(void)
{
    // Uso correcto de punteros a cadenas literales (constantes)
    const char *cad0;
    cad0 = "Argentina";   // Usar comillas dobles normales
    puts(cad0);
    cad0 = "Brasil";
    puts(cad0);

    // Para usar gets (no recomendado en C moderno, mejor fgets), la cadena
    // debe ser un arreglo o memoria reservada
    char cad1[100];  // Reservamos espacio para la cadena
    printf("Ingrese una cadena: ");
    fgets(cad1, sizeof(cad1), stdin);
    // fgets incluye el salto de línea, para eliminarlo:
    size_t len = 0;
    while (cad1[len] != '\0') len++;
    if (len > 0 && cad1[len-1] == '\n') cad1[len-1] = '\0';
    puts(cad1);

    // Declarar arreglo con tamaño y asignar cadena
    char cad2[20] = "México";
    puts(cad2);

    // Leer cadena para modificar cad2 (cuidado con el tamaño)
    printf("Ingrese otra cadena: ");
    fgets(cad2, sizeof(cad2), stdin);
    // Eliminar salto de línea si existe
    len = 0;
    while (cad2[len] != '\0') len++;
    if (len > 0 && cad2[len-1] == '\n') cad2[len-1] = '\0';
    puts(cad2);

    // Ejemplo uso de funciones atoi, atof, strtod
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

    // NO es posible asignar cadenas a una posición específica de arreglo, por eso esta línea es incorrecta:
    // cad2[10] = "Guatemala";  // ERROR

    return 0;
}
