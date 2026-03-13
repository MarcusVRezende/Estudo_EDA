#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x; 
    int y; 
} Ponto;

typedef struct {
    Ponto itens[1000]; 
    int inicio;
    int fim;
} Fila;

void inicia_fila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

int fila_vazia(Fila *f) {
    return f->inicio == f->fim;
}

void enfileira(Fila *f, Ponto p) {
    f->itens[f->fim] = p;
    f->fim++;
}

Ponto desenfileira(Fila *f) {
    Ponto p = f->itens[f->inicio];
    f->inicio++;
    return p;
}

int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

int bfs(Ponto origem, Ponto destino) {
    
    if (origem.x == destino.x && origem.y == destino.y) return 0;

    int distancias[8][8];
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            distancias[i][j] = -1;
        }
    }

    Fila f;
    inicia_fila(&f);

    enfileira(&f, origem);
    distancias[origem.x][origem.y] = 0;

    while (!fila_vazia(&f)) {
        Ponto atual = desenfileira(&f);

        if (atual.x == destino.x && atual.y == destino.y) {
            return distancias[atual.x][atual.y];
        }

        for (int i = 0; i < 8; i++) {
            int nx = atual.x + dx[i];
            int ny = atual.y + dy[i];

            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
                if (distancias[nx][ny] == -1) {
                    distancias[nx][ny] = distancias[atual.x][atual.y] + 1;
                    
                    Ponto proximo = {nx, ny};
                    enfileira(&f, proximo);
                }
            }
        }
    }
    return -1; 
}

int main() {
    char s1[5], s2[5];

    while (scanf("%s %s", s1, s2) != EOF) {
        
        Ponto origem, destino;
        origem.y = s1[0] - 'a'; 
        origem.x = s1[1] - '1'; 

        destino.y = s2[0] - 'a';
        destino.x = s2[1] - '1';

        int movimentos = bfs(origem, destino);

        printf("To get from %s to %s takes %d knight moves.\n", s1, s2, movimentos);
    }

    return 0;
}