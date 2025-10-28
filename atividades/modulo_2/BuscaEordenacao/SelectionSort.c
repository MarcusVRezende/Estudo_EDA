#include <stdio.h>

// complexidade: O(n^2) melhor e pior caso
void selectionSort(int *vetor, int tamanho){

    for(int i = 0; i < tamanho - 1; i++){

        int menor = i;

        for(int j = i + 1; j < tamanho; j++){

            if(vetor[j] < vetor[menor]){
                menor = j;
            }
        }
        int aux = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux;
    }
}


int main(){

    int vetor[] = {8, -3, 9, -5, 0, 2, 4, 1, 5, 7};

    int tamanho = 10;

    printf("\nvetor nao ordenado: ");
    for(int i = 0; i < tamanho; i++){
        printf("%d, ", vetor[i]);
    }
    selectionSort(vetor, tamanho);

    printf("\nvetor ordenado: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d, ", vetor[i]);
    }

    return 0;
}