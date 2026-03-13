#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

void mescla_listas (celula *l1, celula *l2, celula *l3){
    celula *lista1 = l1 -> prox;
    celula *lista2 = l2 -> prox;

    celula *p = l3;

    while (lista1 != NULL && lista2  != NULL)
    {
        if (lista1 -> dado < lista2 -> dado){
            p -> prox = lista1;
            lista1 = lista1 -> prox;
        }else{
            p -> prox = lista2;
            lista2 = lista2 -> prox;
        }

        p = p->prox;
    }

    if(lista1 != NULL){
        p -> prox = lista1;
    }else{
        p -> prox = lista2;
    }
}

void insere_inicio(celula *le, int x){
    celula *novo_no = malloc(sizeof(celula));
    novo_no -> dado = x;

    novo_no -> prox = le -> prox;
    le -> prox = novo_no;
}

void imprime_lista(celula *le){
    
    celula *p = le -> prox;
    if (p == NULL){
        printf("NULL\n");
        return;
    }

    while (p != NULL)
    {
        printf("%d -> ", p -> dado);
        p = p -> prox;
    }
    printf("NULL\n");
}

int main(){

    celula *no_cabeca = malloc(sizeof(celula));
    celula *lista_um= malloc(sizeof(celula));
    celula *lista_dois = malloc(sizeof(celula));

    no_cabeca -> prox = NULL;
    lista_um -> prox = NULL;
    lista_dois -> prox = NULL;

    insere_inicio(lista_um, 77);
    insere_inicio(lista_um, 7);
    insere_inicio(lista_um, 2);
    insere_inicio(lista_um, 1);

    insere_inicio(lista_dois, 11);
    insere_inicio(lista_dois, 9);
    insere_inicio(lista_dois, 7);

    imprime_lista(lista_um);

    printf("\n");

    imprime_lista(lista_dois);

    mescla_listas(lista_um, lista_dois, no_cabeca);

    printf("\n");
    imprime_lista(no_cabeca);
}
