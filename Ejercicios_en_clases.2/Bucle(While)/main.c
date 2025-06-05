#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cnt = 0;
    cnt = -10;
    while (cnt <= 10)
    {
        if (cnt != 0)
        {
            printf("Print valor cnt: %i\n", cnt);
        }
        cnt++;
    }
    printf("Fin\n");
    return 0;
}
