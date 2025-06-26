#include <stdio.h>

#define TAM 10

void mostrarTabuleiro(int tab[TAM][TAM]) {
    int i, j;
    printf("\nTabuleiro:\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            if (tab[i][j] == 4)       // ataque errado
                printf("X ");
            else if (tab[i][j] == 5)  // ataque certo
                printf("O ");
            else if (tab[i][j] == 6)  // área de habilidade
                printf("* ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

void aplicarHabilidade(int tab[TAM][TAM], int habilidade[5][5], int origemX, int origemY) {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int x = origemX + i - 2;
            int y = origemY + j - 2;
            if (x >= 0 && x < TAM && y >= 0 && y < TAM) {
                if (habilidade[i][j] == 1 && tab[x][y] == 0) {
                    tab[x][y] = 6;  // marca área de habilidade
                }
            }
        }
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
    // horizontal em (1,1)
    for (i = 0; i < 3; i++)
        tabuleiro[1][1+i] = 3;

    // vertical em (4,5)
    for (i = 0; i < 3; i++)
        tabuleiro[4+i][5] = 3;

    // diagonal principal em (6,1)
    for (i = 0; i < 3; i++)
        tabuleiro[6+i][1+i] = 3;

    // diagonal secundária em (2,7)
    for (i = 0; i < 3; i++)
        tabuleiro[2+i][7-i] = 3;

    // Definindo matrizes de habilidades
    int cone[5][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };

    int cruz[5][5] = {
        {0,0,1,0,0},
        {0,0,1,0,0},
        {1,1,1,1,1},
        {0,0,1,0,0},
        {0,0,1,0,0}
    };

    int octaedro[5][5] = {
        {0,0,1,0,0},
        {0,1,0,1,0},
        {1,0,0,0,1},
        {0,1,0,1,0},
        {0,0,1,0,0}
    };

    // Aplica áreas de habilidade no tabuleiro (posições fixas)
    aplicarHabilidade(tabuleiro, cone, 0, 2);
    aplicarHabilidade(tabuleiro, cruz, 5, 5);
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);

    int acertos = 0;
    int totalNavio = 12; // 4 navios x 3 posições
    int linha, coluna;

    printf("Bem-vindo ao Batalha Naval - Nível Mestre!\n");

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
            tabuleiro[linha][coluna] = 5; // marca acerto
            acertos++;
        } else if (tabuleiro[linha][coluna] == 0 || tabuleiro[linha][coluna] == 6) {
            // água ou área de habilidade sem navio
            printf("Água.\n");
            tabuleiro[linha][coluna] = 4; // marca erro
        } else if (tabuleiro[linha][coluna] == 4 || tabuleiro[linha][coluna] == 5) {
            printf("Posição já atacada! Tente outro lugar.\n");
        }
    }

    printf("\nParabéns! Você afundou todos os navios!\n");
    mostrarTabuleiro(tabuleiro);

    return 0;
}
