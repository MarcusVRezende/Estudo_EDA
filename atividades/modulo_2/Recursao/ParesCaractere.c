#include <stdio.h>

int paresCaractere(char *str){

    if(*str == '\0'){
        return 0;
    }
    else if(*str == *(str + 2)){
        return 1 + paresCaractere(str + 1);
    }
    else{
        return 0 + paresCaractere(str + 1);
    }

}

int  main(){

    char palavra[201];

    scanf("%s", palavra);

    int resultado = paresCaractere(palavra);

    printf("%d", resultado);

    return 0;
}