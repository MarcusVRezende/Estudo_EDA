// Pilha com lista encadeada
#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

celula *cria_pilha();
void empilha(celula *p, int x);
int desempilha(celula *p);
int pilha_vazia(celula *p);
void destroi_fila(celula *p;);

celula *cria_pilha(){

    celula *p = malloc(sizeof(celula));
    
    p -> prox = NULL;
    
    return p;
}

void empilha(celula *p, int x){

    celula *novo = malloc(sizeof(celula));

    novo -> dado = x;

    novo -> prox = p -> prox;

    p -> prox = novo;
}

int desempilha(celula *p){

    if(pilha_vazia(p)){
        return 0;
    }

    celula *lixo = p -> prox;

    int y = lixo -> dado;

    p -> prox = lixo -> prox;

    free(lixo);

    return y;
}

int pilha_vazia(celula *p){
    return p -> prox == NULL;
}

int destroi_pilha(celula *p){
    while(!pilha_vazia(p)){
        desempilha(p);
    }
    free(p);
}
int main(){

    celula *p = cria_pilha();

    empilha(p, 3);
    empilha(p, 5);
    empilha(p, 7);
    empilha(p, 9);

    while (!pilha_vazia(p)){
        int resultado = desempilha(p);
        printf("%d ", resultado);
    }
    
    return 0;
}



