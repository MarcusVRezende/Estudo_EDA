#include <stdio.h>

int conta7(long long n){

    if (n == 0){
        return 0;
    }

    int ultimoDigito = n % 10;
    long long restoNumero = n / 10;    
    
    if (ultimoDigito == 7){
        return 1 + conta7(restoNumero);
    }
    else{
        return 0 + conta7(restoNumero);
    }
    
}

int main(){

    long long numero;

    scanf("%lld", &numero);

    int resultado = conta7(numero);

    printf("%d\n", resultado);

    return 0;
}