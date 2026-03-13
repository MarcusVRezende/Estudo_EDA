#include <stdio.h>  
#include <stdlib.h> 

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void insere_inicio(celula *le, int x) {

    celula *novo_no = (celula *)malloc(sizeof(celula));
    
    novo_no->dado = x;
    novo_no->prox = le->prox;

    le->prox = novo_no;
}
void insere_antes(celula *le, int x, int y) {

    celula *novo_no = (celula *)malloc(sizeof(celula));
    novo_no->dado = x;

    celula *anterior = le;
    celula *atual = le->prox;

    while (atual != NULL) {
        
        if (atual->dado == y) {
            novo_no->prox = atual;
            anterior->prox = novo_no;
            
            return;
        }

        anterior = atual;
        atual = atual->prox;
    }

    novo_no->prox = NULL; 
    anterior->prox = novo_no;
}

void imprime(celula *le) {
    celula *p = le->prox; 
    if (p == NULL) {
        printf("NULL\n");
        return;
    }
    while (p != NULL) {
        printf("%d -> ", p->dado);
        p = p->prox;
    }
    printf("NULL\n");
}

/*
int main() {
    
    celula *no_cabeca = (celula *)malloc(sizeof(celula));
    no_cabeca->prox = NULL; 

    insere_inicio(no_cabeca, 10);
    insere_inicio(no_cabeca, 5);
    insere_inicio(no_cabeca, 1);
    
    printf("Lista apos 'insere_inicio':\n");
    imprime(no_cabeca); 
    printf("\n");

    printf("Inserindo 3 antes do 5...\n");
    insere_antes(no_cabeca, 3, 5);
    imprime(no_cabeca); 
    printf("\n");

    printf("Inserindo 0 antes do 1...\n");
    insere_antes(no_cabeca, 0, 1);
    imprime(no_cabeca);
    printf("\n");

    printf("Inserindo 20 antes do 99 (nao existe)...\n");
    insere_antes(no_cabeca, 20, 99);
    imprime(no_cabeca);
    printf("\n");
    return 0;
}*/