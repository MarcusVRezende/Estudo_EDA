#include <stdio.h>

int busca_binaria(int v[], int n, int x) {
    int ini = 0, fim = n - 1, meio;
    int j = n; 

    while (ini <= fim) {
        meio = (ini + fim) / 2;

        if (x <= v[meio]) {
            j = meio;
            fim = meio - 1;
        } else {
            ini = meio + 1;
        }
    }
    return j;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int v[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &v[i]);

    int resultados[M];
    for (int i = 0; i < M; i++) {
        int x;
        scanf("%d", &x);
        resultados[i] = busca_binaria(v, N, x);
    }

    for (int i = 0; i < M; i++)
        printf("%d\n", resultados[i]);

    return 0;
}
