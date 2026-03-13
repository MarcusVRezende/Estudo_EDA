#include <stdio.h>

void trocaXporY(char *str){

    if(*str == '\0'){
        return;
    }   

    if (*str == 'x' ){
        *str = 'y';
    }
    else  if(*str == 'X'){
        *str = 'Y';
    }
    
    trocaXporY(str + 1);

}

int main(){

    char palavra[81];

    scanf("%s", palavra);

    trocaXporY(palavra);
    printf(palavra);

    return 0;
}