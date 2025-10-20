#include <stdio.h>

int contaSetes(long long n) {
    if (n == 0) {
        return 0;
    }

    int ultimoDigito = n % 10;
    
    long long restoDoNumero = n / 10;

    if (ultimoDigito == 7) {
        return 1 + contaSetes(restoDoNumero);
    } else {
        return 0 + contaSetes(restoDoNumero);
    }
}

int main() {
    long long numero; 

    scanf("%lld", &numero);

    int resultado = contaSetes(numero);

    printf("%d\n", resultado);

    return 0;
}