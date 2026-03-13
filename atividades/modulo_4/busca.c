// Lista encadeada - Busca 
#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

celula *busca (celula *le, int x){
    
    le = le -> prox;
    while(le != NULL){

        if(le->dado == x){
            return le;
        }
        le = le -> prox;
    }
    return NULL;
}
celula *busca_rec (celula *le, int x){

    le = le -> prox;
    if(le == NULL){
        return NULL;
    }

    if(le -> dado == x){
        return le;
    }
    return busca_rec(le, x);
}
/* int main(){
    
    celula *no_cabeca = (celula *)malloc(sizeof(celula));
    celula *no1 = (celula *)malloc(sizeof(celula));
    celula *no2 = (celula *)malloc(sizeof(celula));
    celula *no3 = (celula *)malloc(sizeof(celula));
    celula *no4 = (celula *)malloc(sizeof(celula));
    celula *no5 = (celula *)malloc(sizeof(celula));

    no1 -> dado = 1;
    no2 -> dado = 2;
    no3 -> dado = 3;
    no4 -> dado = 4;
    no5 -> dado = 5;

    no_cabeca -> prox = no1;
    no1 -> prox = no2;
    no2 -> prox = no3;
    no3 -> prox = no4;
    no4 -> prox = no5;
    no5 -> prox = NULL; 

    int x = 5;

    printf("Busca normal:\n");
    celula *resultado1 = busca(no_cabeca, x);

    if(resultado1 != NULL){
        printf("Achou, aqui esta: %d\n", resultado1->dado);
    }else{
        printf("Nao achou\n");
    }
   
    printf("Busca recursiva:\n");
    celula *resultado2 = busca(no_cabeca, x);

    if(resultado2 != NULL){
        printf("Achou, aqui esta: %d\n", resultado2->dado);
    }else{
        printf("Nao achou\n");
    }

    return 0;
}*/