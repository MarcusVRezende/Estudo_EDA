#include <stdio.h>
#include <string.h> 
                 
int main() {
 
    char nome_aeroporto[100006];
    char sigla[5];
    scanf("%s", nome_aeroporto);
    scanf("%s", sigla);

    int letras_a_procurar = 3;
    if (sigla[2] == 'X') {
        letras_a_procurar = 2;
    }

    int letras_encontradas = 0;
    int indice_de_busca = 0;
    for (int i = 0; i < letras_a_procurar; i++) {
        
        char letra_da_sigla = sigla[i];
        int encontrou_letra_nesta_rodada = 0; 

        for (int j = indice_de_busca; nome_aeroporto[j] != '\0'; j++) {
            
            char letra_do_nome = nome_aeroporto[j];
            char letra_do_nome_maiuscula;

            if (letra_do_nome >= 'a' && letra_do_nome <= 'z') {
                letra_do_nome_maiuscula = letra_do_nome - 32;
            } else {
                letra_do_nome_maiuscula = letra_do_nome; 
            }

            if (letra_do_nome_maiuscula == letra_da_sigla) {
                letras_encontradas++;
                indice_de_busca = j + 1;
                encontrou_letra_nesta_rodada = 1;
                break; 
            }
        }

        if (encontrou_letra_nesta_rodada == 0) {
            break; 
        }
    }

    if (letras_encontradas == letras_a_procurar) {
        printf("Sim\n");
    } else {
        printf("Nao\n");
    }

    return 0;
}