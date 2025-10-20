#include <stdio.h>
#include <string.h>
void moveXs(char *str) {
    if (*str == '\0') {
        return;
    }
    if (*str == 'x') {
        moveXs(str + 1);
        printf("x");
    } 
    else {
        printf("%c", *str);
        moveXs(str + 1);
    }
}

int main() {
    char entrada[101];
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada, "\n")] = '\0';

    moveXs(entrada);

    printf("\n");

    return 0;
}