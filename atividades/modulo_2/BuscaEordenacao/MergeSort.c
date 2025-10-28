#include <stdio.h>
#include <stdlib.h>

void intercala(int *v, int e, int m, int d)
{
    int i = e, j = m + 1, k = 0;

    int *aux = malloc((d - e + 1) * sizeof(int));
    while (i <= m && j <= d)
    {
        if (v[i] < v[j])
        {
            aux[k++] = v[i++];
        }
        else
        {
            aux[k++] = v[j++];
        }
    }
    while (i <= m)
    {
        aux[k++] = v[i++];
    }
    while (j <= d)
    {
        aux[k++] = v[j++];
    }
    for (i = e, k = 0; i <= d; i++, k++)
    {
        v[i] = aux[k];
    }

    free(aux);
}

void mergeSort(int *vetor, int inicio, int fim){
    if( inicio >= fim ){
        return;
    }
    int meio =(fim - inicio + fim) / 2;

    mergeSort(vetor, inicio, meio);
    mergeSort(vetor, meio + 1, fim);
    intercala(vetor, inicio, meio, fim);

}

int main(){

    int vetor[] = {2, -1, -8, -3, 5, 10, 6, 0, 2, 3, 6, 3};

    int tamanho = 12;

    printf("Lista Original: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d, ", vetor[i]);
    }
    mergeSort(vetor, 0, 11);

    printf("\nLista Ordenada: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d, ", vetor[i]);
    }

    return 0;
}