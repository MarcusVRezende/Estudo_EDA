#include <stdio.h>


// Melhor caso: O(N)
// Pior caso: O(^2)
void insertionSort(int *vetor, int tamanho){

    int i, j, aux;

    for(i = 0; i < tamanho - 1; i++){
        if(vetor[i] > vetor[i + 1]){

            aux = vetor[i + 1];
            vetor[i + 1] = vetor[i]; 
            vetor[i] = aux;
            j = i - 1;
            
            while (j >= 0){
                
                if(aux < vetor[j]){
                    vetor[j + 1] = vetor[j];
                    vetor[j] = aux;
                    
                }else{
                    break;
                }
                j = j - 1;
            }
        }
    }
}


int main(){

    int vetor[] = {2, 4, 8, 2, -1, 9, 2, 11, -2, 0};

    int tamanho = 10;

    int k;

    printf("\nINSERTION SORT\n\n");
    printf("Lista Original: ");
    for(int i = 0; i < tamanho; i++){
        printf("%d, ", vetor[i]);
    }
    insertionSort(vetor, tamanho);

    printf("\nLista Ordenada: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d, ", vetor[i]);
    }
    printf("\n\n");

    return 0;
}

void insercao(int *lista, int tamanho)
{

    for (int i = 1; i < tamanho; i++)
    {

        int x = lista[i];

        int j = i - 1;

        while (j >= 0 && lista[j] > x)
        {
            lista[j + 1] = lista[j];
            j--;
        }
        lista[j + 1] = x;
    }
}