#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;
// Exemplo 1
no *minimo(no *r) {
    if (r == NULL) {
        return NULL;
    }
    
    no *atual = r;
    while (atual->esq != NULL) {
        atual = atual->esq;
    }
    
    return atual;
}

// Exemplo 2
no *minimo(no *r){
    if(r != NULL){
        
        if(r->esq == NULL){
            return r;
        }
        else{
            return minimo(r->esq);
        }

    }
    else{
        return NULL;
    }
}