#include <stdio.h>
#include <stdlib.h>

//lista encadeada
/*
typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

celula *cria_fila();
celula *enfileira(celula *f, int x);
int desinfileira(celula *f);
int fila_vazia(celula *f);
void destroi_fila(celula *f);

celula *cria_fila(){
    
    celula *f = malloc(sizeof(celula));
    
    f -> prox = f; 
    
    return f;
}

celula *enfileira(celula *f, int x){

    celula *novo = malloc(sizeof(celula));

    novo -> prox = f -> prox;
    
    f -> prox = novo;

    f -> dado = x;

    return novo;
}

int desinfileira(celula *f){

    if(fila_vazia(f)){
        return 0;
    }

    celula *lixo = f -> prox;

    f -> prox = lixo -> prox;

    int y = lixo -> dado;

    free(lixo);

    return y;
}

int fila_vazia(celula *f){
    return f -> prox == f;
}

void destroi_fila(celula *f){
    while(!fila_vazia(f)){
        desinfileira(f);
    }
    free(f);
}

int main(){

    celula *f = cria_fila();

    f = enfileira(f, 8);
    f = enfileira(f, 6);
    f = enfileira(f, 7);
    f = enfileira(f, 23);

    while(!fila_vazia(f)){
        int resultado = desinfileira(f);
        printf("%d ", resultado);
    }
    return 0;
}

//pilha com lista encadeada -- expressão matematica(parentização)
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

    if(pilha_vazia(p)){
        return 0;
    }

    celula *lixo = p -> prox;

    int y = lixo -> dado;

    p -> prox = lixo -> prox;

    free(lixo);

    return y;
}

int pilha_vazia(celula *p){
    return p -> prox == NULL;
}

void destroi_pilha(celula *p){
    while(!pilha_vazia(p)){
        desempilha(p);
    }
    free(p);
}
int verifica(char primeiro, char ultimo){

    if(primeiro == '(' && ultimo == ')') return 1; 
    if(primeiro == '[' && ultimo == ']') return 1; 
    if(primeiro == '{' && ultimo == '}') return 1;

    return 0; // erro;
}

int parentizacao(char *str){

    celula *p = cria_pilha();

    int temp;
    for(int i = 0; str[i] != '\0'; i++){

        char c = str[i];      
    
        if(c == '(' || c == '[' || c == '{'){

            empilha(p, c);
        }
        else if(c == ')' || c == ']' || c == '}'){
            
            if(pilha_vazia(p)){
                destroi_pilha(p);
                return 0;
            }
            
            temp = desempilha(p);

            if(!verifica(temp, c)){
                destroi_pilha(p);
                return 0;
            }
        }
    }

    if(pilha_vazia(p)){

        destroi_pilha(p);    
        return 1;
    
    }else{
        
        destroi_pilha(p);
        return 0;
    }
}

int main(){

    char expressao[501];

    scanf("%s", expressao);

    if(parentizacao(expressao)){
        
        printf("Sim\n");
    
    }else{
        
        printf("Nao\n");
    }

    return 0;
}*/

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

    if(pilha_vazia(p)){
        return 0;
    }

    celula *lixo = p -> prox;

    int y = lixo -> dado;

    p -> prox = lixo -> prox;

    free(lixo);

    return y;
}

int pilha_vazia(celula *p){
    return p -> prox == NULL;
}

void destroi_pilha(celula *p){
    while(!pilha_vazia(p)){
        desempilha(p);
    }
    free(p);
}
int verifica(char primeiro, char ultimo){

    if(primeiro == '(' && ultimo == ')') return 1; 
    if(primeiro == '[' && ultimo == ']') return 1; 
    if(primeiro == '{' && ultimo == '}') return 1;

    return 0; // erro;
}

int resolve(char *str){

    celula *p = cria_pilha();

    int contador = 0;

    for(int i = 0; str[i] != '\0'; i++){
        char c = str[i];

        if(c == '[' || c == 'x'){
            empilha(p, c);
        }
        else if (c == ']'){
            int temp = desempilha(p);

            if(temp == '[' && c == ']'){
                contador++;
            }
            else if(temp == '[' && c == 'x'){
                destroi_pilha(p);
                contador--;
            }
        }
    }
    return contador;
}

int main(){

    char frase[200];

    scanf("%s", frase);

    int d = resolve(frase);

    printf("%d", d);

    return 0;
}