// ABB_RNE = Arvore Binaria de Busca Rubro Negra Esquerdista
#include <stdio.h>
#include <stdlib.h>

enum cor {VERMELHO, PRETO};

typedef struct celula{
    int dado;
    enum cor cor;
    struct celula *esq, *dir;
}celula;

celula *cria_abb(int x);
celula *inserir_rne(celula *raiz, int x);
celula *insere(celula *raiz, int x);
int ehVermelho(celula *no);
int ehPreto(celula *no);
void sobe_cor(celula *r);
celula *rotacao_esquerda(celula *r);
celula *rotacao_direita(celula *r);


celula *cria_abb(int x){

    celula *raiz = malloc(sizeof(celula));
    raiz->dado = x;
    raiz->esq = NULL;
    raiz->dir = NULL;

    raiz->cor = PRETO;

    return raiz;

}
celula *inserir_rne(celula *raiz, int x){

    if(raiz != NULL){

        if(x < raiz->dado){
            raiz->esq = inserir_rne(raiz->esq, x);
        }
        else if(x > raiz->dado ){
            raiz->dir = inserir_rne(raiz->dir, x);
        }
        if(ehPreto(raiz->esq) && ehVermelho(raiz->dir)){
            raiz = rotacao_esquerda(raiz);
        }
        if(ehVermelho(raiz->esq) && ehVermelho(raiz->esq->esq)){
            raiz = rotacao_direita(raiz);
        }
        if(ehPreto(raiz) && ehVermelho(raiz->esq) && ehVermelho(raiz->dir)){
            sobe_cor(raiz);
        }
        return raiz;
    }else{

        celula *novo = malloc(sizeof(celula));
        
        novo->dado = x;

        novo->esq = NULL;
        novo->dir = NULL;

        novo->cor = VERMELHO;

        return novo;
    }
}
celula *insere(celula *raiz, int x){
    raiz = inserir_rne(raiz, x);
    raiz->cor = PRETO;
    return raiz;
}

// Funçoes auxiliares 

int ehVermelho(celula *no){
    if(no != NULL){
        return no->cor == VERMELHO;
    }
    else{
        return 0;
    }
}
int ehPreto(celula *no){
    if(no != NULL){
        return no->cor == PRETO;
    }else{
        return 1;
    }
}

//Operadores de correção 

void sobe_cor(celula *r){
    if(r != NULL){
        r->cor = VERMELHO;
        r->esq->cor = PRETO;
        r->dir->cor = PRETO;
    }
}

celula *rotacao_esquerda(celula *r){

    celula *a = r->dir;
    r->dir = a->esq;
    a->esq = r;
    a->cor = r->cor;
    r->cor = VERMELHO;
    return a;

}
celula *rotacao_direita(celula *r){
    celula *a = r->esq;
    r->esq = a->dir;
    a->dir = r;
    a->cor = r->cor;
    r->cor = VERMELHO;
    return a;
}

// função main

int main(){


    return 0;
}