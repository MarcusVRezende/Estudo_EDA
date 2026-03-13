// Fila circular com vetores
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *dados;
    int p, u , n; // p = inicio, u = ultimo elemnto( a frente), n = tamanho do vetor 
}fila;

fila *cria_fila(int n);
int fila_vazia(fila *f);
int fila_cheia(fila *f);
void enfileira(fila *f, int x);
int desinfileira(fila *f);
void destroi_fila(fila *f);

fila *cria_fila(int n){

    fila *f = malloc(sizeof(fila));
    f -> dados = malloc(n * sizeof(int));

    f -> p = 0;
    f -> u = 0;
    f -> n = n;

    return f;
}

int fila_vazia(fila *f){
    return f -> p == f -> u;
}
int fila_cheia(fila *f){
    return(f -> u + 1) % f -> n == f -> p;
}

void enfileira(fila *f, int x){

    if (fila_cheia(f)){
        return;
    }

    f -> dados[f -> u] = x;
    f -> u = (f -> u + 1) % f -> n;
}
int desinfileira(fila *f){

    if(!fila_vazia(f)){
        int y = f -> dados[f -> p];
        f -> p = (f -> p + 1) % f -> n;
        return y;
    }
    return 0;
}
void destroi_fila(fila *f){
    free(f -> dados);
    free(f);
}

int main(){
    fila *f = cria_fila(5);

    enfileira(f, 6);
    enfileira(f, 9);
    enfileira(f, 10);
    enfileira(f, 20);
    enfileira(f, 13);

    while(!fila_vazia(f)){
        
        int resultado = desinfileira(f);
        
        printf("%d ", resultado);
    
    }

    return 0;
}