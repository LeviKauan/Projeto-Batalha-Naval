#include <stdio.h>

#define TAM 10
#define NAVIO 3

int main() {
    // Declaração do tabuleiro 10x10 inicializado com água (0)
    int tabuleiro[TAM][TAM];

    // Inicializa todas as posições com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Vetores representando os navios (3 posições)
    int navio1[NAVIO] = {3,3,3}; // horizontal
    int navio2[NAVIO] = {3,3,3}; // vertical
    int navio3[NAVIO] = {3,3,3}; // diagonal principal
    int navio4[NAVIO] = {3,3,3}; // diagonal secundária

    // Coordenadas iniciais pré-definidas para evitar sobreposição
    // (ajustadas manualmente para não colidir)
    int linhaH = 1, colunaH = 1;       // navio horizontal
    int linhaV = 4, colunaV = 5;       // navio vertical
    int linhaD1 = 6, colunaD1 = 1;     // diagonal principal
    int linhaD2 = 2, colunaD2 = 7;     // diagonal secundária

    // Validação simplificada: se cabem no tabuleiro
    if (colunaH + NAVIO <= TAM &&
        linhaV + NAVIO <= TAM &&
        linhaD1 + NAVIO <= TAM && colunaD1 + NAVIO <= TAM &&
        linhaD2 + NAVIO <= TAM && colunaD2 - (NAVIO-1) >= 0) 
    {
        // Posiciona navio horizontal
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linhaH][colunaH + i] = navio1[i];
        }

        // Posiciona navio vertical
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linhaV + i][colunaV] = navio2[i];
        }

        // Posiciona navio diagonal principal (linha e coluna crescem)
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linhaD1 + i][colunaD1 + i] = navio3[i];
        }

        // Posiciona navio diagonal secundária (linha cresce, coluna decresce)
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linhaD2 + i][colunaD2 - i] = navio4[i];
        }
    } else {
        printf("Coordenadas inválidas para os navios.\n");
        return 1;
    }

    // Impressão do tabuleiro
    printf("\n===== Tabuleiro (nível aventureiro) =====\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}