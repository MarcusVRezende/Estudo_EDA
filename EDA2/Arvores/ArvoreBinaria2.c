#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *erq, *dir;
}celula;

typedef struct arvoreBinaria{
    celula *raiz;
}arvoreBinaria;

void inserir(arvoreBinaria *arv, int valor);
void inserirEsquerda(celula *no, int valor);
void inserirDireita(celula *no, int valor);
void imprimirArvore(celula *raiz);

void inserir(arvoreBinaria *arv, int valor){

    if(arv->raiz == NULL){
        celula *novo = (celula*)malloc(sizeof(celula));
        
        novo->dado = valor;
        novo->dir = NULL;
        novo->erq = NULL;

        arv->raiz = novo;
    }
    else{
        if(arv->raiz->dado > valor){
            inserirEsquerda(arv->raiz, valor);
        }
        if(arv->raiz->dado < valor){
            inserirDireita(arv->raiz, valor);
        }
    }
}

void inserirEsquerda(celula *no, int valor){

    if(no->erq== NULL){
        celula *novo = (celula*)malloc(sizeof(celula));
        
        novo->dado = valor;
        novo->dir = NULL;
        novo->erq = NULL;

        no->erq = novo;
    }
    else{
        if(no->erq->dado > valor){
            inserirEsquerda(no->erq, valor);
        }
        if(no->erq->dado < valor){
            inserirDireita(no->erq, valor);
        }
    }
}
void inserirDireita(celula *no, int valor){
    if(no->dir == NULL){
        celula *novo = (celula*)malloc(sizeof(celula));
        
        novo->dado = valor;
        novo->dir = NULL;
        novo->erq = NULL;

        no->dir = novo;
    }
    else{
        if(no->dir->dado > valor){
            inserirEsquerda(no->dir, valor);
        }
        if(no->dir->dado < valor){
            inserirDireita(no->dir, valor);
        }
    }
}

void imprimirArvore(celula *raiz){

    if(raiz != NULL){
    
        imprimirArvore(raiz->erq);
        printf("%d ", raiz->dado);
        imprimirArvore(raiz->dir);
    
    }
}

int main(){

    int opcao, valor;
    
    arvoreBinaria arv;
    arv.raiz = NULL;

    
    do{
       printf("\nDigite 1 para adicionar Numero \nDigite 2 para ver Lista de Numeros \nDigite 0 Para encerrar programa\n");
       scanf("%d", &opcao); 

       switch (opcao)
       {
        case 0:
            printf("\nEncerrando...\n");
        break;
        case 1:
            printf("Digite um numero para adicionar a lista: ");
            scanf("%d", &valor);
            inserir(&arv, valor);
        break;
        case 2:
            imprimirArvore(arv.raiz);
        break;
        default:
            printf("\nOpcao Invalida, tente outra: ");
        break;
       }
    }while (opcao != 0);

    imprimirArvore(arv.raiz);
    
    return 0;
}