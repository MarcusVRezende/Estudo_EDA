// ABB = Arvore Binaria de Busca
#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *esq, *dir; 
}celula;

celula *buscar(celula *raiz, int x);
celula *inserir(celula *raiz, int x);
celula *remover(celula *raiz, int x);
celula *cria_abb(int x);
void remove_sucessor(celula *raiz);
void destroi_abb(celula *raiz);

celula *cria_abb(int x){
    celula *raiz = malloc(sizeof(celula));
    
    raiz->esq = NULL;
    raiz->dir = NULL;
    raiz->dado = x;

    return raiz;
}

celula *inserir(celula *raiz, int x){
    if(raiz != NULL){
        if(x < raiz->dado){
            raiz->esq = inserir(raiz->esq, x);
        }
        else if(x > raiz->dado){
            raiz->dir = inserir(raiz->dir, x);
        }
        return raiz;
    }
    else{
        return cria_abb(x);
    }
}

celula *buscar(celula *raiz, int x){

    if(raiz != NULL){

        if(x < raiz->dado){
            return buscar(raiz->esq, x);
        }
        else if (x > raiz->dado){
            return buscar(raiz->dir, x);
        }
        else{
            return raiz;
        }
    }
    else{
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
    }
    return raiz;
}

void remove_sucessor(celula *raiz){
    celula *filho = raiz->dir;
    celula *pai = raiz;
    while (filho->esq != NULL){
        pai = filho;
        filho = filho->esq;
    }
    int tmp = raiz->dado;
    raiz->dado = filho->dado;
    filho->dado = tmp;
    if(pai == raiz){
        pai->dir = filho->dir;
    }
    else{
        pai->esq = filho->dir;
    }
    free(filho);
}

void destroi_abb(celula *raiz){
    if(raiz != NULL){
        destroi_abb(raiz->esq);
        destroi_abb(raiz->dir);
        free(raiz);
    }
}

void imprimir_arvore(celula *raiz){
    if(raiz != NULL){
        imprimir_arvore(raiz->esq);
        printf("%d ", raiz->dado);
        imprimir_arvore(raiz->dir);
    }
}
celula *minimo(celula *r){

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
int main(){

    celula *arv;
    arv = NULL;
    celula *menor;
    int opcao, valor;

    do {
        printf("\n1 Para adicionar numero a Arvore \n2 Para mostrar arvore \n3 Para remover numero da arvore \n4 Para mostrar o menor numero da arvore \n0 Para encerrar programa \n");
        scanf("%d", &opcao);
        
        switch (opcao)
        {
        case 0:
            printf("\nEncerrando...\n");
            destroi_abb(arv);
            break;
        case 1:
            printf("\nInsira um numero: ");
            scanf("%d", &valor);
            arv = inserir(arv, valor);
            break;
        case 2:
            imprimir_arvore(arv);
            break;
        case 3:
            printf("\nDigite um numero para remover: ");
            scanf("%d", &valor);
            arv = remover(arv, valor);
            break;
        case 4:
            menor = minimo(arv);
            printf("\nMenor numero da arvore: %d", menor->dado);
            break;
        default:
            printf("Opcao nao aceita, tente novamente:");
            break;
        }
        
    }while(opcao != 0);

    

    return 0;
}