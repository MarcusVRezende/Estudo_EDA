#include <stdio.h>
int ehVogal(char c) {
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return 1;
    }
    return 0;
}

int contaVogais(char *str) {
    if (*str == '\0') {
        return 0;
    }

    return ehVogal(*str) + contaVogais(str + 1);
}

int main() {
    char palavra[101];
    scanf("%s", palavra);

    int totalDeVogais = contaVogais(palavra);

    printf("%d\n", totalDeVogais);

    return 0;
}