#include <stdio.h>

int main() {
    int N;
    printf("Ingresa el valor de N: ");
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        for (int s = 0; s < N - i; s++) {
            printf("  ");
        }
        int num = i;
        for (int j = 0; j < i; j++) {
            printf("%d ", num % 10);
            num++;
        }
        num -= 2;
        for (int j = 0; j < i - 1; j++) {
            printf("%d ", num % 10);
            num--;
        }
        printf("\n");
    }
    return 0;
}
