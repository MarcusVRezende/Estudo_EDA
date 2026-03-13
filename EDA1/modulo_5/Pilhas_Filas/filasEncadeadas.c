// Filas com Listas Encadeadas
#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

celula *cria_fila();
int fila_vazia(celula *f);
celula *enfileira(celula *f, int x);
int desinfileira(celula *f);
void destroi_fila(celula *f);

celula *cria_fila(){

    celula *f = malloc(sizeof(celula));

    f -> prox = f;

    return f;
}
celula *enfileira(celula *f, int x){
    celula *novo = malloc(sizeof(celula));
    
    if (novo == NULL){ 
        return NULL;
    }

    novo->prox = f->prox;
    f->prox = novo;

    f->dado = x;

    return novo;   
}

int desinfileira(celula *f){
    if(fila_vazia(f)){
        return 0;
    }
    celula *lixo = f -> prox;
    int y = lixo -> dado;

    f -> prox = lixo -> prox;

    free(lixo);

    return y;
}

int fila_vazia(celula *f){
    return f -> prox == f;
}

void destroi_fila(celula *f){
    while (!fila_vazia(f)){
        desinfileira(f);
    }
    free(f);
    
}
int main(){

    celula *f = cria_fila();
    
    f = enfileira(f, 7);
    f = enfileira(f, 8);
    f = enfileira(f, 9);
    f = enfileira(f, 10);

    while (!fila_vazia(f)){
        int resultado = desinfileira(f);
        printf ("%d ", resultado);
    }
    destroi_fila(f);
    
    return 0;
}