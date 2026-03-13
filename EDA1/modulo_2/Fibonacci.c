#include <stdio.h>

long long cache[81];

long long fibonacci(int n) {
    if (n <= 2) {
        return 1;
    }
    if (cache[n] != 0) {
        return cache[n]; 
    }

    long long resultado = fibonacci(n - 1) + fibonacci(n - 2);
    cache[n] = resultado;

    return resultado;
}

/*
int main() {
    int n;

    scanf("%d", &n);
    printf("%lld\n", fibonacci(n));

    return 0;
}*/