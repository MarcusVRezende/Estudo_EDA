#include <stdio.h>

int stringsiguais(char str1[], char str2[])
{

    int i = 0;
    while (str1[i] == str2[i])
    {
        if (str1[i] == '\0')
        {
            return 1; //iguais
        }
        i++;
    }

    return 0; //diferente
}
int main()
{

    char triagem[100];
    int contador = 0;
    int verificar = 0;

    while (scanf("%s", triagem) != EOF)
    {
        contador++;
        if (stringsiguais(triagem, "nao") && contador < 10)
        {
            verificar++;
            
        }
    }
    contador = 0;

    printf("contador = %d, quantos nao = %d", contador, verificar);

    return 0;
}
