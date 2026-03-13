#include <stdio.h>
#include <stdlib.h>

int compara(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int total = 0;
    int *todos = NULL;

    for (int i = 0; i < 8; i++) {
        int s;
        scanf("%d", &s);

        if (s == 0) continue; 

        int *v = malloc(s * sizeof(int));
        for (int j = 0; j < s; j++)
            scanf("%d", &v[j]);

            todos = realloc(todos, (total + s) * sizeof(int));
        for (int j = 0; j < s; j++)
            todos[total + j] = v[j];

        total += s;
        free(v);
    }

    qsort(todos, total, sizeof(int), compara);

    for (int i = 0; i < total; i++) {
        printf("%d", todos[i]);
        if (i < total - 1) printf(" ");
    }
    printf("\n");

    free(todos);
    return 0;
}
