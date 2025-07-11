#include <stdio.h>
#include <string.h>

void cambia(FILE *ap1, FILE *ap2);

int main(void)
{
    FILE *ar;
    FILE *ap;

    ar = fopen("arc.txt", "r");
    ap = fopen("arc1.txt", "w");

    if ((ar != NULL) && (ap != NULL))
    {
        cambia(ar, ap);
        fclose(ar);
        fclose(ap);
    }
    else
    {
        printf("No se pueden abrir los archivos\n");
    }

    return 0;
}

void cambia(FILE *ap1, FILE *ap2)
{
    char cad[100];
    char *pos;

    while (fgets(cad, sizeof(cad), ap1))
    {
        while ((pos = strstr(cad, "méxico")) != NULL)
        {
            pos[0] = 'M';  // Solo se cambia la primera letra
        }
        fputs(cad, ap2);
    }
}
