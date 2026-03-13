#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

celula *cria_pilha();
void empilha(celula *p, int x);
int desempilha(celula *p);
int pilha_vazia(celula *p);
void destroi_pilha(celula *p);

celula *cria_pilha(){
    celula *p = malloc(sizeof(celula));
    p -> prox = NULL;
    return p;
}

void empilha(celula *p, int x){
    
    celula *novo = malloc(sizeof(celula));

    novo -> dado = x;
    
    novo -> prox = p -> prox;
    
    p -> prox = novo;

}

int desempilha(celula *p){

    if(!pilha_vazia(p)){
        
        celula *topo = p -> prox;

        int x = topo -> dado;

        p -> prox = topo -> prox;
        
        free(topo);
        
        return x;
    }

    return 0;

}

int pilha_vazia(celula *p){
    return p -> prox == NULL;
}

void destroi_pilha(celula *p){
    while(!pilha_vazia(p)){
        desempilha(p);
    }
    free (p);
}

void resolvar(char *str){
    celula *topo = cria_pilha();

    int contador = 0;
    for(int i = 0; str[i] != '\0'; i++){
        char c= str[i];
        
        if(c == '['){
            empilha(topo, 1);
        }
        else if(c == 'x'){
            if(!pilha_vazia(topo)){
                topo -> prox -> dado = 0;
            }
        }
        else if(c == ']'){
            int estado = desempilha(topo);

            if (estado == 1){
                contador++;
            }else{
                if(!pilha_vazia(topo)){
                    topo -> prox -> dado = 0;
                }
            }
        }
    }
    printf("%d\n", contador);
    destroi_pilha(topo);
}

int main(){

    char palavra[10005];

    while(scanf("%s", palavra) != EOF){
        resolvar(palavra);
    }

    return 0;
}