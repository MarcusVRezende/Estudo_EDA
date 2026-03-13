#include <stdio.h>

void insercao(int *vet, int tamanho){

    for(int i = 0; i < tamanho; i++){
        int x = vet[i];
        int j = i - 1;

        while(j >=  0 && vet[j] > x){
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = x;
    }
}

int main(){

    int vetor[] = {7, 3, 2, 5, 4, 3};
    int tamanho = 6;

    insercao(vetor, tamanho);

    for(int i = 0; i < tamanho; i++){
        printf("%d ",vetor[i]);
    }
    return 0;
}