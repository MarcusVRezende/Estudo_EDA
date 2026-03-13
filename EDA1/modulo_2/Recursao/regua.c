#include <stdio.h>

void regua(int n){

    printf(".");
    for(int i = 0; i < n; i++){
        printf("-");
    }
    printf("\n");
}

void imprimiRegua(int n){
    if(n <= 0){
        return;
    }

    imprimiRegua(n -1);

    regua(n);

    imprimiRegua(n - 1);
}

int main(){

    int numero;

    scanf("%d", &numero);

    imprimiRegua(numero);

    return 0;
}