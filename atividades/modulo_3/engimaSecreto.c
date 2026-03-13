#include <stdio.h>
#include <stdlib.h>

int compara(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int busca_binaria(int v[], int n, int x) {
    int ini = 0, fim = n - 1;
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        if (v[meio] == x) return meio;
        if (x < v[meio]) fim = meio - 1;
        else ini = meio + 1;
    }
    return -1;
}

int main() {
    int N, C;
    scanf("%d %d", &N, &C);

    int v[N], ordenado[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
        ordenado[i] = v[i];
    }

    qsort(ordenado, N, sizeof(int), compara);  // O(N log N)

    int indice = busca_binaria(ordenado, N, C);  // O(log N)
    printf("%d\n", indice);

    // Rotacionar a lista original
    for (int i = 0; i < N; i++) {
        int nova_pos = (i + indice) % N;
        printf("%d", v[nova_pos]);
        if (i < N - 1) printf(" ");
    }
    printf("\n");

    return 0;
}
