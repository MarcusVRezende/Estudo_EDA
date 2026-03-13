#include <stdio.h>
#include <string.h>

char inverte(char str[501], int tam){
    if(tam==0)
        return 0;
    printf("%c", str[tam-1]);
    return inverte(str, tam-1);
}

int main(void)
{
    char string[501]={};

    fgets(string, 501, stdin);
    int tamanho = strlen(string);

    inverte(string, tamanho);

    return 0;
}
