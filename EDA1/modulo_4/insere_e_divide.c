#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

void divide_lista (celula *l, celula *l1, celula *l2){

    celula *p = l -> prox;
    celula *lista_impar = l1;
    celula *lista_par = l2;


    while (p != NULL){
        if(p -> dado % 2 != 0){
        
            lista_impar -> prox = p;
            lista_impar = p;
        
        }else{

            lista_par -> prox = p;
            lista_par = p;

        }

        p = p -> prox;

    }

    lista_impar -> prox = NULL;
    lista_par -> prox = NULL;
    
}

void insere_inicio (celula *le, int x){

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
    while(p != NULL){
        printf("%d -> ", p -> dado);
        p = p -> prox;
    }
    printf("NULL\n");
    
}
int main(){

    celula *no_cabeca = malloc(sizeof(celula));

    celula *lista_par = malloc(sizeof(celula));
    celula *lista_impar = malloc(sizeof(celula));
    
    no_cabeca -> prox = NULL;
    lista_impar -> prox = NULL;
    lista_par -> prox = NULL;
    
    insere_inicio(no_cabeca, 19);
    insere_inicio(no_cabeca, 17);
    insere_inicio(no_cabeca, 11);
    insere_inicio(no_cabeca, 8);
    insere_inicio(no_cabeca, 7);
    insere_inicio(no_cabeca, 5);
    insere_inicio(no_cabeca, 6);
    insere_inicio(no_cabeca, 2);
    insere_inicio(no_cabeca, 1);
    insere_inicio(no_cabeca, 0);
    insere_inicio(no_cabeca, 2);
    insere_inicio(no_cabeca, -7);
    
    printf("\n");
    
    printf("Lista completa: \n");
    imprime_lista(no_cabeca);

    divide_lista(no_cabeca, lista_impar, lista_par);
    
    printf("\n");

    printf("Lista Impar:\n");
    imprime_lista(lista_impar);
    
    printf("\n");


    printf("Lista Par:\n");
    imprime_lista(lista_par);
    
    printf("\n");

    return 0;
}
