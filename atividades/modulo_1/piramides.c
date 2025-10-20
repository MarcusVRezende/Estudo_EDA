#include <stdio.h>

int main()
{

    int i, n, j;

    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            if (i <= 9)
            {
                printf("0%0d ", i);
            }
            else
            {
                printf("%d ", i);
            }
        }
        printf("\n");
    }

    printf("\n");

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            if (j <= 9)
            {
                printf("0%d ", j);
            }
            else
            {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
    return 0;
}