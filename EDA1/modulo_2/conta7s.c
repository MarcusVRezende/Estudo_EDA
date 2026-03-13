#include <stdio.h>

int contaSetes(long long n) {
    if (n == 0) {
        return 0;
    }

    int ultimoDigito = n % 10;
    
    long long restoDoNumero = n / 10;

    if (ultimoDigito == 7) {
        return 1 + contaSetes(restoDoNumero);
    } else {
        return 0 + contaSetes(restoDoNumero);
    }
}

int main() {
    long long numero; 

    scanf("%lld", &numero);

    int resultado = contaSetes(numero);

    printf("%d\n", resultado);

    return 0;
}

// Busca Binaria

#include <stdio.h>

// n  = tamanho do vetor
// x  = numero que queremos achar
int busca(int *vetor, int n, int x)
{

    int esquerda = -1, direita = n;

    int meio = (esquerda + direita) / 2;

    while (esquerda < direita - 1)
    {
        if (vetor[meio] == x)
        {
            return meio;
        }
        else if (vetor[meio] < x)
        {

            esquerda = meio;
        }
        else
        {
            direita = meio;
        }
        meio = (esquerda + direita) / 2;
    }
    return -1;
}

int main()
{

    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int n = 10;

    int elemento = 6;
    int resultado = busca(vetor, n, elemento);

    if (resultado != -1)
    {
        printf("Elemento: %d, encontrado no indice %d do vetor", elemento, resultado);
    }
    else
    {
        printf("Elemento: %d, nao encontrado no vetor", elemento);
    }

    return 0;
}