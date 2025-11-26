#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *dados;
    int u, p, N;
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

    f -> N = n;

    return f;
}

int fila_cheia(fila *f){
    return (f -> u + 1) % f -> N == f -> p;
}

int fila_vazia(fila *f){
    return f -> p == f -> u;
}
void enfileira(fila *f, int x){
    if (fila_cheia(f)){
        return;
    }
    f -> dados[f -> u] = x;
    f -> u = (f -> u + 1) % f -> N;

}
int desinfileira(fila *f){

    if(fila_vazia(f)){
        return 0;
    }
    int y = f -> dados[f -> p];

    f -> p = (f -> p + 1) % f -> N;

    return y;
}
void destroi_fila(fila *f){
    free(f -> dados);
    free(f);
}

int main(){

    fila *f =cria_fila(9);

    enfileira(f, 5);
    enfileira(f, 6);
    enfileira(f, 7);
    enfileira(f, 0);
    enfileira(f, 512);
    enfileira(f, 233);

    while (!fila_vazia(f)){

        int resultado = desinfileira(f);

        printf("%d ", resultado);
    }

    printf("\n");
    
    destroi_fila(f);
    
    return 0;
}
