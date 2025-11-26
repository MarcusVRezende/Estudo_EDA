#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dado;
    int topo;
    int n;
}pilha;

pilha *cria_pilha(int n);
int empilha(pilha *p, int x);
int desempilha(pilha *p, int *y);
int pilha_vazia(pilha *p);
int pilha_cheia(pilha *p);
void destroi_pilha(pilha *p);

pilha *cria_pilha(int n){

    pilha *p = malloc(sizeof(pilha));
    p -> dado = malloc(n * sizeof(int));

    p -> topo = 0;
    p -> n = n;

    return p;
}
int empilha(pilha *p, int x){
    if(pilha_cheia(p)){
        p -> dado = realloc(p -> dado, 2*  p -> n * sizeof(int));
        if(p -> dado ==NULL){
            return 1;
        }
        p -> n = p -> n * 2; 
    } 

    p -> dado[p -> topo] = x;
    p -> topo++;
    
    return 0;
}
int desempilha(pilha *p, int  *y){
    if(pilha_vazia(p)){
        return 1;
    }
    p -> topo--;
    *y = p -> dado[p -> topo];

    return 0;
}
int pilha_cheia(pilha *p){
    return p -> topo == p -> n; 
}
int pilha_vazia(pilha *p){
    return p -> topo == 0;
}
void destroi_pilha(pilha *p){
    free(p -> dado);
    free(p);
}

int palindromo(char *palavra, int n){

    pilha *p = cria_pilha(n);
    
    int valor;

    for(int i = 0; i < n; i++){
        empilha(p, palavra[i]); 
    }

    int meio = n / 2;

    int j = 0;

    while(j < meio){
        desempilha(p, &valor);

        if(palavra[j] != valor){
            destroi_pilha(p);
            return 0;
        }
        j++;
    }

    destroi_pilha(p);
    return 1;
}

int main(){

    int n;

    scanf("%d", &n);

    char palavra[n + 1];

    scanf("%s", palavra);

    int resultado = palindromo(palavra, n);

    printf("%d", resultado);
    return 0;
}
