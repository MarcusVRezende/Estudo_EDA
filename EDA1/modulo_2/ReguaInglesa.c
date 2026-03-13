#include <stdio.h>

void imprimeTracos(int n) {
    printf("."); 
    
    for (int i = 0; i < n; i++) {
        printf("-");
    }
    printf("\n");
}

void desenhaRegua(int n) {
    if (n <= 0) {
        return;
    }

    desenhaRegua(n - 1);

    imprimeTracos(n);

    desenhaRegua(n - 1);
}

int main() {
    int n;

    scanf("%d", &n);

    desenhaRegua(n);

    return 0;
}