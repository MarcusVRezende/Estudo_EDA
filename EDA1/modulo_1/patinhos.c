#include <stdio.h>

int main(){
    short int patinhos, linha = 0, coluna = 0;

    scanf("%d", &patinhos);
    getchar(); // Consumir o '\n' depois do número
        short int save = patinhos;
    char mapa[1000][1000] = {};
    short int c;
    short int inicio[2];
//------------------
    while((c = getchar()) != EOF){
        if(c == 'S'){

                inicio[0] = linha;
                inicio[1] = coluna;
        }
        if (c == '\n') {
                mapa[linha][coluna] = '\0'; // Termina a string da linha
                linha++; 
                coluna = 0; 
        } else {
                mapa[linha][coluna] = (char)c;
                coluna++; 
        }
}
//--------------
 /*  
    for(int i = 0; i <= linha; i++){
        printf("%s\n", mapa[i]);
    }
*/
//------------------
        int sucesso=0;
    while(sucesso!=1){

        if(mapa[inicio[0]-1][inicio[1]]== '_'){
                mapa[inicio[0]][inicio[1]] = '#';
                inicio[0]--;
        }
        else if(mapa[inicio[0]][inicio[1]-1]== '_')
        {
                mapa[inicio[0]][inicio[1]] = '#';
                inicio[1]--;
        }
        else if(mapa[inicio[0]+1][inicio[1]]== '_')
        {
                mapa[inicio[0]][inicio[1]] = '#';
                inicio[0]++;
        }
        else if(mapa[inicio[0]][inicio[1]+1]== '_')
        {
                mapa[inicio[0]][inicio[1]] = '#';
                inicio[1]++;
        }//----------------------------------------- 'o'
        else if(mapa[inicio[0]-1][inicio[1]]== 'o'){
                mapa[inicio[0]][inicio[1]] = '#';
                patinhos--;
                inicio[0]--;
                if(patinhos<1)
                break;
        }
        else if(mapa[inicio[0]][inicio[1]-1]== 'o'){
                mapa[inicio[0]][inicio[1]] = '#';
                patinhos--;
                inicio[1]--;
                if(patinhos<1)
                break;
        }
        else if(mapa[inicio[0]+1][inicio[1]]== 'o'){
                mapa[inicio[0]][inicio[1]] = '#';
                patinhos--;
                inicio[0]++;
                if(patinhos<1)
                break;
        }
        else if(mapa[inicio[0]][inicio[1]+1]== 'o'){
                mapa[inicio[0]][inicio[1]] = '#';
                patinhos--;
                inicio[1]++;
                if(patinhos<1)
                break;
        } else if(mapa[inicio[0]-1][inicio[1]]== 'E')
                sucesso=1;
        else if(mapa[inicio[0]][inicio[1]-1]== 'E')
                sucesso=1;
        else if(mapa[inicio[0]+1][inicio[1]]== 'E')
                sucesso=1;
        else if(mapa[inicio[0]][inicio[1]+1]== 'E')
                sucesso=1;
    }
//-----------------
    if(patinhos == save)
        printf("Nenhum morreu :(");
    else if(sucesso == 1)
        printf("%d encontraram o vovo", patinhos);
     else 
        printf("Todos morreram :)");

    return 0;
}
