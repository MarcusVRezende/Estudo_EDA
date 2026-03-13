#include <stdio.h>
#include <string.h> 

int contaPares(char *str) {
    if (*str == '\0' || *(str + 1) == '\0' || *(str + 2) == '\0') {
        return 0;
    }
    if (*str == *(str + 2)) {
        return 1 + contaPares(str + 1);
    } else {
        return contaPares(str + 1);
    }
}

int main() {
    char entrada[201]; 

    scanf("%s", entrada);

    int resultado = contaPares(entrada);

    printf("%d\n", resultado);

    return 0;
}
