#include <stdio.h>

void insertionSort(int *vet, int tamanho);

int main(){

    int vetor[1001];

    int i = 0;
    int tamanho = 0;
    while(scanf("%d", &vetor[i]) != EOF){
        i++;
        tamanho++;
    }

    insertionSort(vetor, tamanho);

    for (int j = 0; j < tamanho; j++)
    {
        printf("%d ", vetor[j]);
    }
}

void insertionSort(int *vet, int tamanho)
{

    for (int i = 1; i < tamanho; i++)
    {
        int x = vet[i];
        int j = i - 1;

        while (j >= 0 && vet[j] >= x)
        {
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = x;
    }
}