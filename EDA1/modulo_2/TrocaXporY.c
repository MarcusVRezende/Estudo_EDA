#include <stdio.h>


void trocaXporY(char *str){  //Função para trocar X poo Y
    
    if(*str == '\0'){   //Ja acresenta o \0 ao final
        
        return;

    }
    if(*str == 'x'){    //verifica se tem algum x
        
        *str = 'y';     //Se tiver x aconte a troca pelo y
    
    }
    trocaXporY(str + 1);     //chama ela mesma 

}
int main(){


    char palavra[81];

    scanf("%s", palavra);
    trocaXporY(palavra);

    printf("%s", palavra );
    return 0;
}
