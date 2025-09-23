#include <stdio.h>

int main(void){
    int F, L;
    scanf("%d%d", &F, &L);

    int vetor[F][L];

    for(int fileira = 0 ; fileira<F ; fileira++)
        for(int lugares = 0 ; lugares<L ; lugares++)
            vetor[fileira][lugares] = 0;

    //--
    char letra;
    int numero;
    int a, b;
    while(scanf(" %c%d", &letra, &numero) != EOF){
            a= letra-65;
            b = numero-1;
        //printf("%d %d\n", a, b);
        vetor[a][b] = 1;
        //printf("%d\n", vetor[a][b]);
/*
        for(int i = 0 ; i < F ; i++){
            for(int j = 0 ; j<L ; j++){
                printf("%d", vetor[i][j]);

            }
            printf("\n");
        }
*/
    }
        //-- cardapio
        printf(" ");
        for(int i = 1 ; i<=L ; i++){
            printf(" %02d", i);
        }
        printf("\n");
        //--

        char posicao = 65+F-1;
        for(int i = F-1 ; i>=0 ; i--){
                printf("%c ", posicao);
            for(int j = 0 ; j<L ; j++){
              //  printf("%d %d\n", i, j);
              //  printf("%02d ", vetor[i][j]);
                if(vetor[i][j]==0)
                    printf("-- ");
                else
                    printf("XX ");
            }
            printf("\n");
            posicao-=1;
        }

    return 0;
}
