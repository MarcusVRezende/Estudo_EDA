#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 


typedef struct celula {
    char cidade[27]; 
    struct celula *prox;
} celula;

typedef struct {
    celula *inicio;
    celula *fim;
} fila;

fila *cria_fila() {
    fila *f = malloc(sizeof(fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void enfileira(fila *f, char *x) {
    celula *novo = malloc(sizeof(celula));
    if (novo == NULL) return;
    
    strcpy(novo->cidade, x);
    novo->prox = NULL;

    if (f->inicio == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

int desenfileira(fila *f, char *buffer) {
    if (f->inicio == NULL) return 0;

    celula *lixo = f->inicio;
    strcpy(buffer, lixo->cidade); 

    f->inicio = f->inicio->prox;
    
    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(lixo);
    return 1; 
}

int fila_vazia(fila *f) {
    return f->inicio == NULL;
}


int main() {
    fila *f = cria_fila();
    char cidade_temp[30];

    while (scanf("%s", cidade_temp) != EOF) {
        enfileira(f, cidade_temp);
    }

    char cidade_atual[30];
    
    char cidade_anterior[30];

    if (desenfileira(f, cidade_atual)) {
        printf("%s\n", cidade_atual);
        strcpy(cidade_anterior, cidade_atual); 
    }

    while (!fila_vazia(f)) {
        
        desenfileira(f, cidade_atual);

        int len_anterior = strlen(cidade_anterior);
        char ultima_letra = tolower(cidade_anterior[len_anterior - 1]);

        char primeira_letra = tolower(cidade_atual[0]);

        if (ultima_letra == primeira_letra) {
            enfileira(f, cidade_atual);
            
            if (desenfileira(f, cidade_atual)) {
                printf("%s\n", cidade_atual);
                strcpy(cidade_anterior, cidade_atual); 
            }
        } 
        else {
            printf("%s\n", cidade_atual);
            strcpy(cidade_anterior, cidade_atual); 
        }
    }

    free(f);

    return 0;
}