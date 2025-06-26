#include <stdio.h>

#define TAM 10

void mostrarTabuleiro(int tab[TAM][TAM]) {
    int i, j;
    printf("\nTabuleiro:\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            // Mostrar 0 para água, 3 para navio, X para ataque já feito
            if (tab[i][j] == 4) // ataque errado
                printf("X ");
            else if (tab[i][j] == 5) // ataque certo
                printf("O ");
            else
                printf(". "); // não mostrar navio para o jogador
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

    // Define navios tamanho 3
    // Navio horizontal em (1,1)
    for (i = 0; i < 3; i++)
        tabuleiro[1][1+i] = 3;

    // Navio vertical em (4,5)
    for (i = 0; i < 3; i++)
        tabuleiro[4+i][5] = 3;

    int acertos = 0;
    int totalNavio = 6; // 2 navios x 3 posições
    int linha, coluna;

    printf("Bem-vindo ao Batalha Naval - Nível Novato!\n");

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