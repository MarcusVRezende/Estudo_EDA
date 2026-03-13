#include <stdlib.h>
#include <stdio.h> 

typedef struct{
    int *dado;
    int topo;
    int n;
}pilha;

pilha *cria_pilha (int n);
int empilha(pilha *p, int x);
int desempilha (pilha *p, int *y);
int pilha_vazia(pilha *p);
void destroi_pilha(pilha *p);
int pilha_cheia(pilha *p);

pilha *cria_pilha(int n){

    pilha *p = malloc(sizeof(pilha));             // criando a caixinha
    p -> dado = malloc(n * sizeof(int));          // criando o "conteudo" da caixinha

    p -> topo = 0;                                // inicializando o topo (colocando o primeiro livro 0)
    p -> n = n;                                   // tamanho da caixa ( quantos livros cabem)

    return p;
}

int empilha(pilha *p, int x){

    if(pilha_cheia(p)){                                              // verifica se a caixa está cheia
        p -> dado = realloc(p -> dado, 2 * p -> n * sizeof(int));    // dobrando o tamanho da caixa caso precise
        
        if(p -> dado == NULL){
            return 1;
        }
        p -> n = p -> n * 2;
    }

    p -> dado[p -> topo] = x;
    p -> topo++;
    return 0;
}

int desempilha (pilha *p, int *y){
  if(pilha_vazia(p)){
    return 1;
  }
  p -> topo--;
  *y = p -> dado[p -> topo];
  return 0;
}

int pilha_vazia(pilha *p){
    return p -> topo == 0;
}
int pilha_cheia(pilha *p){
    return p -> topo == p -> n;
}
void destroi_pilha (pilha *p){
    free (p ->dado);
    free (p);
}

int main(){

    pilha *p = cria_pilha(5);

    empilha(p, 3);
    empilha(p, 7);
    empilha(p, 9);
    empilha(p, 1);

    int resultado;

    while (!pilha_vazia(p)){
        desempilha(p, &resultado);
        printf("%d ", resultado);
    }
    return 0;
}