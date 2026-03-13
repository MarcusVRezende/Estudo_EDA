#include <stdio.h>

// *v = veotor
//  n = tamnho do vetor;
void insercao (int *vetor, int tamanho){

    for(int i = 1; i < tamanho; i++){

        int x = vetor[i];
        int j = i - 1;

        while(j >= 0 && vetor[j] > x){
            vetor[j + 1] = vetor[j]; 
            j--;

        }
        vetor[j + 1] = x;
    }
}


int main()
{

    int vetor[] = {2, 4, 8, 2, -1, 9, 2, 11, -2, 0};

    int tamanho = 10;

    int k;

    printf("\nINSERTION SORT\n\n");
    printf("Lista Original: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d, ", vetor[i]);
    }
    insercao(vetor, tamanho);

    printf("\nLista Ordenada: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d, ", vetor[i]);
    }
    printf("\n\n");

    return 0;
}