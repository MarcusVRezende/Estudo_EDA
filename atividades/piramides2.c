#include <stdio.h>

int main()
{

    int n, i, j;

    scanf("%d", &n);
    int espaco = n;
    char cara = ' ';

    for (i = 0; i < n; i++)
    {

        for (int k = 0; k < espaco; k++)
        {
            printf("%c", cara);
        }

        for(j = 0; j <= i * 2; j++)
        {

            printf("*");
        }
        espaco--;

        printf("\n");
    }
    return 0;
}