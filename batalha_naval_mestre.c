#include <stdio.h>

#define TAM 10

int main() {
    // Declara o tabuleiro 10x10 e inicializa
    int tabuleiro[TAM][TAM];
    int i, j;

    // inicializa todo o tabuleiro com água (0)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // navios de tamanho 3
    int n1[3] = {3,3,3};
    int n2[3] = {3,3,3};
    int n3[3] = {3,3,3};
    int n4[3] = {3,3,3};

    // coordenadas fixas dos navios
    int lh = 1, ch = 1;
    int lv = 4, cv = 5;
    int ld1 = 6, cd1 = 1;
    int ld2 = 2, cd2 = 7;

    // posiciona navio horizontal
    for (i = 0; i < 3; i++) {
        tabuleiro[lh][ch+i] = n1[i];
    }

    // posiciona navio vertical
    for (i = 0; i < 3; i++) {
        tabuleiro[lv+i][cv] = n2[i];
    }

    // posiciona navio na diagonal principal
    for (i = 0; i < 3; i++) {
        tabuleiro[ld1+i][cd1+i] = n3[i];
    }

    // posiciona navio na diagonal secundária
    for (i = 0; i < 3; i++) {
        tabuleiro[ld2+i][cd2-i] = n4[i];
    }

    // matrizes de habilidades
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

    int octa[5][5] = {
        {0,0,1,0,0},
        {0,1,0,1,0},
        {1,0,0,0,1},
        {0,1,0,1,0},
        {0,0,1,0,0}
    };

    // pontos de origem das habilidades no tabuleiro
    int ocx = 0, ocy = 2;
    int ccx = 5, ccy = 5;
    int oox = 7, ooy = 7;

    // sobrepor área do cone no tabuleiro
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int x = ocx + i - 2;  // ajusta origem
            int y = ocy + j - 2;
            if (x >= 0 && x < TAM && y >= 0 && y < TAM) {
                if (cone[i][j]==1 && tabuleiro[x][y]==0) {
                    tabuleiro[x][y] = 5;
                }
            }
        }
    }

    // sobrepor área da cruz no tabuleiro
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int x = ccx + i - 2;
            int y = ccy + j - 2;
            if (x >= 0 && x < TAM && y >= 0 && y < TAM) {
                if (cruz[i][j]==1 && tabuleiro[x][y]==0) {
                    tabuleiro[x][y] = 5;
                }
            }
        }
    }

    // sobrepor área do octaedro no tabuleiro
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int x = oox + i - 2;
            int y = ooy + j - 2;
            if (x >= 0 && x < TAM && y >= 0 && y < TAM) {
                if (octa[i][j]==1 && tabuleiro[x][y]==0) {
                    tabuleiro[x][y] = 5;
                }
            }
        }
    }

    // imprime tabuleiro final
    printf("Tabuleiro nivel mestre (0=água, 3=navio, 5=habilidade):\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}