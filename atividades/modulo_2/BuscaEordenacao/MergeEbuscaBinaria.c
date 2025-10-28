#include <stdio.h>
#include <stdlib.h>

void intercala(int *vetor, int esquerda, int meio, int direita);
void MergeSort(int *vetor, int inicio, int fim);
int BuscaBinaria(int *vetor, int tamanho, int x);

int main()
{
    int vetor[] = {2, 4, 8, 2, -1, 9, 2, 11, -2, 0};
    int x = 1;
    int tamanho = 10;

    printf("\nMERGE SORT + BUSCA BINARIA \n\n");
    printf("Lista Original: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d, ", vetor[i]);
    }

    MergeSort(vetor, 0, tamanho - 1);

    printf("\nLista Ordenada: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d, ", vetor[i]);
    }
    printf("\n");

    int resultado = BuscaBinaria(vetor, tamanho, x);

    if (resultado != -1)
    {
        printf("\nO numero: %d, esta na posicao %d do vetor", x, resultado);
    }
    else
    {
        printf("\nO numero: %d, nao esta no vetor", x);
    }

    return 0;
}

void intercala(int *vetor, int esquerda, int meio, int direita)
{

    int i = esquerda;
    int j = meio + 1;
    int k = 0;

    int *aux = malloc((direita - esquerda + 1) * sizeof(int));

    while (i <= meio && j <= direita)
    {

        if (vetor[i] < vetor[j])
        {
            aux[k++] = vetor[i++];
        }
        else
        {
            aux[k++] = vetor[j++];
        }
    }
    while (i <= meio)
    {
        aux[k++] = vetor[i++];
    }
    while (j <= direita)
    {
        aux[k++] = vetor[j++];
    }
    for (i = esquerda, k = 0; i <= direita; i++, k++)
    {
        vetor[i] = aux[k];
    }
    free(aux);
}

void MergeSort(int *vetor, int inicio, int fim)
{
    if (inicio >= fim)
    {
        return;
    }
    int meio = (inicio + fim) / 2;
    MergeSort(vetor, inicio, meio);
    MergeSort(vetor, meio + 1, fim);

    intercala(vetor, inicio, meio, fim);
}

int BuscaBinaria(int *vetor, int tamanho, int x)
{

    int esquerda = -1;
    int direita = tamanho;

    int meio = (esquerda + direita) / 2;

    while (esquerda < direita - 1)
    {

        if (vetor[meio] == x)
        {
            return meio;
        }
        else if (vetor[meio] > x)
        {
            direita = meio;
        }
        else
        {
            esquerda = meio;
        }
        meio = (direita + esquerda) / 2;
    }
    return -1;
}