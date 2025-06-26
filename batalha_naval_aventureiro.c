#include <stdio.h>

#define TAM 10

void mostrarTabuleiro(int tab[TAM][TAM]) {
    int i, j;
    printf("\nTabuleiro:\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            if (tab[i][j] == 4) // ataque errado
                printf("X ");
            else if (tab[i][j] == 5) // ataque certo
                printf("O ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // Inicializa tabuleiro com 0 (água)
    for (i = 0; i < TAM; i++)
        for (j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;

    // Posiciona 4 navios tamanho 3
    // 1 horizontal em (1,1)
    for (i = 0; i < 3; i++)
        tabuleiro[1][1+i] = 3;

    // 1 vertical em (4,5)
    for (i = 0; i < 3; i++)
        tabuleiro[4+i][5] = 3;

    // 1 diagonal principal em (6,1)
    for (i = 0; i < 3; i++)
        tabuleiro[6+i][1+i] = 3;

    // 1 diagonal secundária em (2,7)
    for (i = 0; i < 3; i++)
        tabuleiro[2+i][7-i] = 3;

    int acertos = 0;
    int totalNavio = 12; // 4 navios x 3 posições
    int linha, coluna;

    printf("Bem-vindo ao Batalha Naval - Nível Aventureiro!\n");

    while (acertos < totalNavio) {
        mostrarTabuleiro(tabuleiro);

        printf("Digite linha e coluna para atacar (0-9): ");
        scanf("%d %d", &linha, &coluna);

        if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM) {
            printf("Coordenadas inválidas! Tente novamente.\n");
            continue;
        }

        if (tabuleiro[linha][coluna] == 3) {
            printf("Acertou um navio!\n");
            tabuleiro[linha][coluna] = 5; // marcou acerto
            acertos++;
        } else if (tabuleiro[linha][coluna] == 0) {
            printf("Água.\n");
            tabuleiro[linha][coluna] = 4; // marcou erro
        } else if (tabuleiro[linha][coluna] == 4 || tabuleiro[linha][coluna] == 5) {
            printf("Posição já atacada! Tente outro lugar.\n");
        }
    }

    printf("\nParabéns! Você afundou todos os navios!\n");
    mostrarTabuleiro(tabuleiro);

    return 0;
}