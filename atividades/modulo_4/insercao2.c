#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

void insere_inicio (celula *le, int x){

    celula *novoNo = malloc(sizeof(celula));
    novoNo -> dado = x;

    novoNo -> prox = le ->prox;
    le -> prox = novoNo; 
}

void insere_antes (celula *le, int x, int y){

    celula *novo_no = malloc(sizeof(celula));
    novo_no -> dado = x;

    while (le -> prox != NULL){

        if(le -> prox -> dado == y){
            novo_no -> prox = le -> prox;
            le -> prox = novo_no;
            return;
        }

        le = le -> prox;
    }

    novo_no -> prox = NULL;
    le -> prox = novo_no;
}

void imprime(celula *le){

    celula *p = le -> prox;
    if (p == NULL){

        printf("NULL \n");
        return;
    }
    while(p != NULL){
        printf("%d -> ", p -> dado);
        p = p -> prox;
    }
    printf("NULL\n");
}


int main(){

    celula *no_cabeca = malloc(sizeof(celula));
    no_cabeca -> prox = NULL;

    insere_inicio(no_cabeca, 9);
    insere_inicio(no_cabeca, 7);
    insere_inicio(no_cabeca, 18);
    insere_inicio(no_cabeca, 3);
    insere_inicio(no_cabeca, 8);
    insere_inicio(no_cabeca, 1);

    printf("inserindo numeros: \n");
    imprime(no_cabeca);
    printf("\n");


    printf("inserindo o numero 5 antes do 7 numero:\n");
    insere_antes(no_cabeca, 5, 7);
    imprime(no_cabeca);
    printf("\n");

    printf("inserindo o numero 777 antes do 18 numero:\n");
    insere_antes(no_cabeca, 777, 18);
    imprime(no_cabeca);
    printf("\n");


    printf("inserindo o numero 10 antes do 89 numero:\n");
    insere_antes(no_cabeca, 10, 89);
    imprime(no_cabeca);
    printf("\n");
}