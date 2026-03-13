#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char id[5];
    int nivel;
    int status;
} Pokemon;

int compara(const void *a, const void *b) {
    Pokemon *p1 = (Pokemon *)a;
    Pokemon *p2 = (Pokemon *)b;

    if (p1->nivel != p2->nivel)
        return p2->nivel - p1->nivel; 
    else
        return p2->status - p1->status; 
}

int main() {
    int N;
    scanf("%d", &N);

    Pokemon p[N];
    for (int i = 0; i < N; i++)
        scanf("%s %d %d", p[i].id, &p[i].nivel, &p[i].status);

    qsort(p, N, sizeof(Pokemon), compara);

    for (int i = 0; i < N; i++)
        printf("%s | %d | %d\n", p[i].id, p[i].nivel, p[i].status);

    return 0;
}
