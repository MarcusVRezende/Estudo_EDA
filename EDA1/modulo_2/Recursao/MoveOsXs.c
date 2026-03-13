#include <stdio.h>

void moveOsX(char *str){
    
    
    if(*str == '\0'){
        return;
    }
    if(*str == 'x'){

        char c = *str;

        *str = c;
        *(str + 1) = 'x';
    }
    printf("%s", str);
    
}

int main(){

    char frase[101];

    scanf("%s", frase);
    
    moveOsX(frase);
    return 0;
}