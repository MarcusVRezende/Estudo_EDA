#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int conteudo;
    struct no *esquerda, *direita;
} No;

typedef struct
{
    No *raiz;
} arvore_binaria;

void inserirEsquerda(No *no, int valor);
void inserirDireita(No *no, int valor);
void inserir(arvore_binaria *arv, int valor);
void imprimirArvore(No *raiz);

void inserirEsquerda(No *no, int valor)
{
    if (no->esquerda == NULL)
    {

        No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;

        no->esquerda = novo;
    }
    else
    {
        if (no->esquerda->conteudo < valor)
        {
            inserirDireita(no->esquerda, valor);
        }
        else
        {
            inserirEsquerda(no->esquerda, valor);
        }
    }
}
void inserirDireita(No *no, int valor)
{
    if (no->direita == NULL)
    {
        No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->direita = NULL;
        novo->esquerda = NULL;

        no->direita = novo;
    }
    else
    {
        if (no->direita->conteudo > valor)
        {
            inserirEsquerda(no->direita, valor);
        }
        else
        {
            inserirDireita(no->direita, valor);
        }
    }
}

void inserir(arvore_binaria *arv, int valor)
{

    if (arv->raiz == NULL)
    {
        No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        arv->raiz = novo;
    }
    else
    {
        if (arv->raiz->conteudo > valor)
        {
            inserirEsquerda(arv->raiz, valor);
        }
        else{
            inserirDireita(arv->raiz, valor);
        }
    }
}
void imprimirArvore(No *raiz)
{
    if (raiz != NULL)
    {
        imprimirArvore(raiz->esquerda); // (*raiz).esquerda ----> mesma coisa

        printf("%d ", raiz->conteudo);
        
        imprimirArvore(raiz->direita);
    }
}

int main()
{

    int opcao, valor;
    arvore_binaria arv;
    arv.raiz = NULL;

    do
    {

        printf("\nO - sair\n1 - inserir\n2 - imprimir\n");
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 0:
            printf("\n Saindo...\n");
            break;
        case 1:
            printf("Digite um valor ");
            scanf("%d", &valor);
            inserir(&arv, valor);
            break;
        case 2:
            printf("\nImpressao da Arvore Binaria:\n");
            imprimirArvore(arv.raiz);
            break;

        default:
            printf("\nOpcao invalida...\n");
        }

    } while (opcao != 0);
}