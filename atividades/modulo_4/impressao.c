// Listas encadeadas - Impressão
#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

void imprime (celula *le){

    if(le -> prox == NULL){
        printf("NULL\n");
        return;
    }

    celula *p = le;

    while(p -> prox != NULL){
        printf("%d -> ", p -> dado);
        p = p -> prox;
    }

    printf("%d -> NULL", p->dado);
}
void imprime_rec (celula *le){

    if(le == NULL){
        printf("NULL\n");
        return;
    }
    
    if(le->prox == NULL){
        printf("%d -> NULL\n", le->dado);
        return;
    }
    printf("%d -> ", le->dado);
    imprime_rec(le->prox);

}


int main(){

    celula *no_cabeca = (celula *) malloc(sizeof(celula));
    celula *n1 = (celula *) malloc(sizeof(celula));
    celula *n2 = (celula *) malloc(sizeof(celula));
    celula *n3 = (celula *) malloc(sizeof(celula));

    n1 -> dado = 1;
    n2 -> dado = 2;
    n3 -> dado = 3;

    no_cabeca -> prox = n1;
    n1 -> prox = n2;
    n2 -> prox = n3;
    n3 -> prox = NULL;

    imprime_rec(no_cabeca -> prox);

    return 0;
}



/*int main(){
    celula *no_cabeca = (celula *) malloc(sizeof(celula));
    celula *no1 = (celula *) malloc(sizeof(celula));
    celula *no2 = (celula *) malloc(sizeof(celula));
    celula *no3 = (celula *) malloc(sizeof(celula));

    no1 -> dado = 1;
    no2 -> dado = 5;
    no3 -> dado = 3;

    no_cabeca -> prox = no1;
    no1 -> prox = no2;
    no2 -> prox = no3;
    no3 -> prox = NULL;

    printf("Teste interativo: \n");
    imprime(no_cabeca -> prox);




    return 0;
}*/