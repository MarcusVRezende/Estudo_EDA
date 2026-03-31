#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *esq, *dir;
}celula;

typedef struct arvoreBinaria{
    celula *raiz;
}arvoreBinaria;

celula* inserir(celula *raiz, int valor);
void imprimirArvore(celula *raiz);
void limparArvore(celula *raiz);

celula *inserir(celula *raiz, int valor){
    if(raiz == NULL){
        celula *novo = (celula*)malloc(sizeof(celula));
    
        if(novo == NULL){
            return NULL;
        }

        novo->dado = valor;
        novo->esq = NULL;
        novo->dir = NULL;

        return novo;
    }

    else{
        if(valor < raiz->dado){
            raiz->esq = inserir(raiz->esq, valor);
        }
        if(valor > raiz->dado){
            raiz->dir = inserir(raiz->dir, valor);
        }

        return raiz;
    }
}
void imprimirArvore(celula *raiz){
    if(raiz != NULL){
        imprimirArvore(raiz->esq);
        printf("%d ", raiz->dado);
        imprimirArvore(raiz->dir);
    }
}
void limparArvore(celula *raiz){
    if(raiz != NULL){
        limparArvore(raiz->esq);
        limparArvore(raiz->dir);
        free(raiz);
    }
}
int main(){

    arvoreBinaria arv;
    arv.raiz = NULL;

    int opcao, valor;

    do{
      
        printf("\n0 Para encerrar \n1 Para adicionar numero \n2 Para ver lista de numeros\n");
        scanf("%d", &opcao);

        switch (opcao){
        case 0:
            printf("encerrando...");
            limparArvore(arv.raiz);
            break;
        case 1:
            printf("\nDigite um numero: ");
            scanf("%d", &valor);
            arv.raiz = inserir(arv.raiz, valor);

            printf("\nNumero registrado com sucesso");
            break;
        case 2:
            imprimirArvore(arv.raiz);
            break;
        default:
        printf("\nOpcao nao aceita, tente novamente:  ");
            break;
        }
        

    } while (opcao != 0);
    
    return 0;
}