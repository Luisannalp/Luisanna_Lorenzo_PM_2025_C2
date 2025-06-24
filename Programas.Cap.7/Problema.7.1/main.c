#include <stdio.h>

int main(void)
{
    char p1, p2, p3 = '$';  // Se usa comilla simple ' para caracteres

    // Lectura y escritura de un caracter con getchar y putchar
    printf("\nIngrese un caracter: ");
    p1 = getchar();         // Lee un carácter desde la entrada
    putchar(p1);            // Imprime el carácter leído

    printf("\n");

    fflush(stdin);          // Limpia el búfer de entrada

    // Mostrar el contenido de p3
    printf("\nEl caracter p3 es: ");
    putchar(p3);            // Imprime el símbolo '$'

    printf("\n");

    // Leer un segundo carácter usando scanf
    printf("\nIngrese otro caracter: ");
    fflush(stdin);          // Limpia el búfer antes de leer otro caracter
    scanf("%c", &p2);       // Lee un carácter con scanf
    printf("%c\n", p2);     // Imprime el carácter leído

    return 0;               // Buen hábito finalizar con return
}
