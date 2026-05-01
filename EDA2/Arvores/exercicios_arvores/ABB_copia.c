// ABB - arvore binaria de busca (apenas uma copia para aprender mais sobre a estrutura )

#include <stdlib.h>
#include <stdio.h>

typedef struct celula{
    int dado;
    struct celula *esq, *dir;
}celula;


celula *cria_abb(int x);
celula *inserir(celula *raiz, int x);
celula *buscar(celula *raiz, int x);
celula *remover(celula *raiz, int x);
void remove_sucessor(celula *raiz);
void destroi_arv(celula *raiz);

celula *cria_abb(int x){

    celula *raiz = malloc(sizeof(celula));
    raiz->esq =NULL;
    raiz->dir = NULL;

    raiz->dado = x;
    
    return raiz;
}

celula *inserir(celula *raiz, int x){
    if(raiz != NULL){

        if(x < raiz->dado){
            raiz->esq = inserir(raiz->esq, x);
        }
        else if (x > raiz->dado){
            raiz->dir = inserir(raiz->dir, x);
        }
        return raiz;
    
    }else{
        return cria_abb(x);
    }
}

celula *buscar(celula *raiz, int x){
    if(raiz != NULL){

        if(x < raiz->dado){
            return buscar(raiz->esq, x);
        }
        else if(x > raiz->dado){
            return buscar(raiz->dir, x);
        }
        else{
            return raiz;
        }
    }else{
        return NULL;
    }
}

celula *remover(celula *raiz, int x){

    if(raiz != NULL){
        if(x < raiz->dado){
            raiz->esq = remover(raiz->esq, x);
        }
        else if(x > raiz->dado){
            raiz->dir = remover(raiz->dir, x);
        }
        else if(raiz->esq == NULL){
            celula *ptr = raiz->dir;
            free(raiz);
            return ptr;
        }
        else if(raiz->dir == NULL){
            celula *ptr = raiz->esq;
            free(raiz);
            return ptr;
        }
        else{
            remove_sucessor(raiz);
        }
        return raiz;
    }
}

void remove_sucessor(celula *raiz){
    celula *filho = raiz->dir;
    celula *pai = raiz;

    while(filho->esq != NULL){
        pai = filho;
        filho = filho->esq;
    }
    int tmp = raiz->dado;
    raiz->dado = filho->dado;
    filho->dado = tmp;

    if(pai != raiz){
        pai->dir = filho->dir;
    }
    else{
        pai->esq = filho->dir;
    }
    free(filho);
}

void destroi_arv(celula *raiz){
    if(raiz != NULL){
        destroi_arv(raiz->esq);
        destroi_arv(raiz->dir);
        free(raiz);
    }
}

int main(){

    return 0;
}

