#include <stdio.h>

#define TAM 10
#define NAVIO 3

int main() {
    // matriz do tabuleiro 10x10
    int tabuleiro[TAM][TAM];

    // inicializa todo o tabuleiro com 0 (água)
    for(int i=0; i<TAM; i++) {
        for(int j=0; j<TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // dois vetores representando os navios
    int navioH[NAVIO] = {3, 3, 3}; // horizontal
    int navioV[NAVIO] = {3, 3, 3}; // vertical

    // coordenadas iniciais fixas
    int linhaH = 2, colunaH = 4; // para o navio horizontal
    int linhaV = 5, colunaV = 6; // para o navio vertical

    // validar se cabem no tabuleiro
    if (colunaH + NAVIO <= TAM && linhaV + NAVIO <= TAM) {
        // posiciona navio horizontal
        for(int i=0; i<NAVIO; i++) {
            tabuleiro[linhaH][colunaH+i] = navioH[i];
        }
        // posiciona navio vertical
        for(int i=0; i<NAVIO; i++) {
            tabuleiro[linhaV+i][colunaV] = navioV[i];
        }
    } else {
        printf("Coordenadas inválidas para os navios.\n");
        return 1;
    }

    // imprime o tabuleiro
    printf("Tabuleiro:\n");
    for(int i=0; i<TAM; i++) {
        for(int j=0; j<TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}