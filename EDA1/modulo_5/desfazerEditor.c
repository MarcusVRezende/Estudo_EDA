#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula{
    char dado[101];
    struct celula *prox;
}celula;

celula *cria_pilha();
void empilha(celula *p, char *x);
void desempilha(celula *p);
int pilha_vazia(celula *p);

celula *cria_pilha(){
    celula *p = malloc(sizeof(celula));

    p -> prox = NULL;

    return p;
}

void empilha(celula *p, char *x){
    
    celula *novo = malloc(sizeof(celula));

    strcpy(novo -> dado, x);

    novo -> prox = p -> prox;
    p -> prox = novo;
}
void desempilha(celula *p){
    if(pilha_vazia(p)){
        printf("NULL\n");
        return;
    }
    celula *topo = p -> prox;

    printf("%s\n", topo -> dado);

    p -> prox = topo -> prox;

    free(topo);
}
int pilha_vazia(celula *p){
    return p -> prox == NULL;
}
int main(){

    celula *topo = cria_pilha();

    char comando[50];
    char texto[105];

    while(scanf("%s", comando) != EOF){

        if(strcmp(comando, "inserir") == 0){
            
            getchar();
            
            scanf("%[^\n]", texto);

            empilha(topo, texto);
        }
        else if(strcmp(comando, "desfazer") == 0){
            
            desempilha(topo);

        }
    }
    return 0;
}