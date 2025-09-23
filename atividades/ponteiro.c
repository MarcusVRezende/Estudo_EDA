#include <stdio.h>
#include <locale.h>

void display(int var, int *ptr);

int main()
{

    int variavel = 10;

    int *ponteiro;
    
    ponteiro = &variavel;

    display(variavel, ponteiro);

    *ponteiro = 253;

    display(variavel, ponteiro);

    
    return 0;
}

void display(int var, int *ptr)
{
    printf("Conteudo de var: %d \n", var);
    printf("Endereco de var: %p \n", &var);
    printf("Conteudo apontado de ptr: %d \n", *ptr);
    printf("Endereco apontado de ptr: %p \n", ptr);
    printf("Endereco de ptr:          %p \n", &ptr);

    printf("\n");
}
// ponteiros

// *ptr = Apontado para o conteudo do endereço da variavel que ptr aponta
//  ptr = O endereço da variavel (var)
// &ptr = O endereço do ponteiro (ptr)