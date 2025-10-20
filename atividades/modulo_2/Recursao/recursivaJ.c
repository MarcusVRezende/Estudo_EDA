#include <stdio.h>

int contaVogais(char *str){

    if(*str == '\0'){
        return 0;
    }
    if (*str == 'A' || *str == 'a' || 
        *str == 'E' || *str == 'e' || 
        *str == 'I' || *str == 'i' ||
        *str == 'O' || *str == 'o' || 
        *str == 'U' || *str == 'u'){
        return 1 + contaVogais(str + 1);
    }else{
        return 0 + contaVogais(str + 1);
    }
}

int main(){

    char palavra[101];

    printf("Digite a Palavra para saber a quantidade de VOGAIS nela\n");
    scanf("%s", palavra);

    int resultado = contaVogais(palavra);

    printf("Palavra: %s \nTotal de Vogais %d\n", palavra, resultado);
    
    return 0;
}