#include <stdio.h>

// *v = Vetor
//  n = Tamanho do vetor
//  x = Elemento procurado
int BuscaBinaria(int *v, int n, int x){
    
    int esquerda = -1, direita = n;
    int meio = (esquerda + direita) / 2;

    while (esquerda < direita - 1 )
    {
        if(v[meio] == x){
            return meio;
        }
        else if (v[meio] > x)
        {
            direita = meio;
        }
        else{
            esquerda = meio;
        }
        meio = (esquerda + direita) / 2;

    }
    return -1;
}

int main(){

    int vetor[] = {-7, -3, -1, 0, 3, 4, 5, 6, 7, 10, 12, 18, 20};

    int tamanho = 13;

    int elemento = 18;

    int resultado = BuscaBinaria(vetor, tamanho, elemento);

    if(resultado != -1){
        printf("Elemento %d encontrado no indice: %d", elemento, resultado);
    }
    else {
        printf("Elemento: %d, nao encontrado", elemento);
    }
    return 0;
}