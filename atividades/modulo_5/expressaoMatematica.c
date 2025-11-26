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
    p -> n = n;                                    // tamanho da caixa ( quantos livros cabem)

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

int pares(char abertura, char fechamento){
    if (abertura == '(' && fechamento == ')') return 1; 
    if (abertura == '[' && fechamento == ']') return 1;
    if (abertura == '{' && fechamento == '}') return 1;

    return 0;
}
int verifica_expressao(char *expressao){

    pilha *p = cria_pilha(10);
    int temp;

    for(int i = 0; expressao[i] != '\0'; i++){
       
        char c = expressao[i];

        if (c == '(' || c == '[' || c == '{'){
            empilha(p, c);
        }
        else if (c == ')' || c == ']' || c == '}'){

            if (desempilha(p, &temp) == 1){
                destroi_pilha(p);
                return 0;
            }
            char topo = temp;
            if(!pares(topo, c)){
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

    if(verifica_expressao(expressao)){
        printf("sim\n");
    }else{
        printf("nao\n");
    }
    return 0;
}








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
    if (pilha_vazia(p)){
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

    while (scanf("%s", comando) != EOF){

        if (strcmp(comando, "inserir") == 0){

            getchar();

            scanf("%[^\n]", texto);
            
            empilha(topo, texto);
        }
        else if (strcmp(comando, "desfazer") == 0){

            desempilha(topo);
        }
    }
    return 0;
}