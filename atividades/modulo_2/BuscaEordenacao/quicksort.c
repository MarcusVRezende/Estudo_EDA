// Complexidade: 
// Melhor caso: O(nlogn)
// Pior caso: O(n^2)

#include <stdio.h>

void troca(int *i, int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

int particiona(int *vet, int esquerda, int direita){

    int j = esquerda, p = vet[direita];
    for(int k = esquerda; k < direita; k++){

        if(vet[k] < p){
            troca(&vet[k], &vet[j]);
        j++;
        }
    }

    troca(&vet[j], &vet[direita]);
    
    return j;
}

void quickSort(int *vet, int esquerda, int direita){

    if(esquerda < direita){

        int meio = (esquerda + direita) / 2;

        if(vet[meio] < vet[esquerda]){
            troca(&vet[meio], &vet[esquerda]);
        }
        if(vet[direita] < vet[esquerda]){
            troca(&vet[direita], &vet[esquerda]);
        }
        if(vet[meio] < vet[direita]){
            troca(&vet[meio], &vet[direita]);
        }

        int j = particiona(vet, esquerda, direita);

        quickSort(vet, esquerda, j - 1);
        quickSort(vet, j + 1, direita);
    }

}

int main()
{

    int vetor[] = {8, -3, 9, -5, 0, 2, 4, 1, 5, 7};

    int tamanho = 10;

    printf("\nvetor nao ordenado: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d, ", vetor[i]);
    }
    quickSort(vetor, 0, tamanho - 1);

    printf("\nvetor ordenado: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d, ", vetor[i]);
    }

    return 0;
}