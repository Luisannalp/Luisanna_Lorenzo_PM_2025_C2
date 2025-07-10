#include <stdio.h>

int main() {
    int N;

    printf("Ingrese un número entero positivo: ");
    scanf("%d", &N);

    for (int fila = 0; fila < N; fila++) {
        for (int num = 1; num <= N - fila; num++) {
            printf("%d ", num);
        }
        int espacios = 2 * fila + 1;
        for (int e = 0; e < espacios; e++) {
            printf("  "); 
        }
        for (int num = N - fila; num >= 1; num--) {
            printf("%d ", num);
        }
        printf("\n"); 
    }

    return 0;
}
