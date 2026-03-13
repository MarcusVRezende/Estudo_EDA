#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void divide_lista(celula *l, celula *l1, celula *l2) {
    celula *current = l->prox;  
    l1->prox = NULL;
    l2->prox = NULL;

    celula *ultimo_impar = l1;
    celula *ultimo_par = l2;

    while (current != NULL) {
        if (current->dado % 2 != 0) {
            ultimo_impar->prox = current;
            ultimo_impar = current;
        } else {
            ultimo_par->prox = current;
            ultimo_par = current;
        }
       
        current = current->prox;
    }

    ultimo_impar->prox = NULL;
    ultimo_par->prox = NULL;
}

void imprimir_lista(celula *l) {
    celula *current = l->prox;  
    while (current != NULL) {
        printf("%d -> ", current->dado);
        current = current->prox;
    }
    printf("NULL\n");
}
/*
int main() {
    celula *lista = malloc(sizeof(celula));
    celula *lista_impares = malloc(sizeof(celula));
    celula *lista_pares = malloc(sizeof(celula));

    lista->prox = NULL;
    lista_impares->prox = NULL;
    lista_pares->prox = NULL;

    celula *n1 = malloc(sizeof(celula));
    n1->dado = 1;
    lista->prox = n1;

    celula *n2 = malloc(sizeof(celula));
    n2->dado = 10;
    n1->prox = n2;

    celula *n3 = malloc(sizeof(celula));
    n3->dado = 4;
    n2->prox = n3;

    celula *n4 = malloc(sizeof(celula));
    n4->dado = -9;
    n3->prox = n4;

    celula *n5 = malloc(sizeof(celula));
    n5->dado = 2;
    n4->prox = n5;

    celula *n6 = malloc(sizeof(celula));
    n6->dado = 7;
    n5->prox = n6;

    celula *n7 = malloc(sizeof(celula));
    n7->dado = 10;
    n6->prox = n7;
    n7->prox = NULL;

    divide_lista(lista, lista_impares, lista_pares);

    printf("Lista de ímpares: ");
    imprimir_lista(lista_impares);

    printf("Lista de pares: ");
    imprimir_lista(lista_pares);

    return 0;
}
*/