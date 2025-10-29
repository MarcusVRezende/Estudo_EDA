#include <stdio.h>

int BuscaBinaria(int *vetor, int tamanho, int x){

    int esquerda = -1;
    int direita = tamanho;

    int meio = (esquerda + direita) / 2;

    while(esquerda < direita -1){
        if(vetor[meio] == x){
            return meio;
        }
        if(vetor[meio] > x){
            direita = meio;
        }
        else{
            esquerda = meio;
        }
        meio = (esquerda + direita) / 2;
    }
    return -1;
}

void troca(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

int particiona(int *vet, int esquerda, int direita)
{

    int j = esquerda, p = vet[direita];
    for (int k = esquerda; k < direita; k++)
    {

        if (vet[k] < p)
        {
            troca(&vet[k], &vet[j]);
            j++;
        }
    }

    troca(&vet[j], &vet[direita]);

    return j;
}
void quickSort(int *vet, int esquerda, int direita)
{

    if (esquerda < direita)
    {

        int meio = (esquerda + direita) / 2;

        if (vet[meio] < vet[esquerda])
        {
            troca(&vet[meio], &vet[esquerda]);
        }
        if (vet[direita] < vet[esquerda])
        {
            troca(&vet[direita], &vet[esquerda]);
        }
        if (vet[meio] < vet[direita])
        {
            troca(&vet[meio], &vet[direita]);
        }

        int j = particiona(vet, esquerda, direita);

        quickSort(vet, esquerda, j - 1);
        quickSort(vet, j + 1, direita);
    }
}

int main()
{

    int n;
    scanf("%d", &n);

    int vetor[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }

    quickSort(vetor, 0, n - 1);


    int j = 0;
    int consulta;

    while (scanf("%d", &consulta) != EOF)
    {

        int resultado = BuscaBinaria(vetor, n, consulta);
        
        if(resultado != -1){
            printf("sim\n");
        }
        else{
            printf("nao\n");
        }
    }
    return 0;
}