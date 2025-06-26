#include <stdio.h>

#define TAM 10
#define AGUA 0
#define NAVIO 3
#define ACERTO 4
#define ERRO 5
#define AREA_HABILIDADE 6

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tab[TAM][TAM]) {
    printf("   ");
    for (int c = 0; c < TAM; c++)
        printf("%d ", c);
    printf("\n");
    for (int l = 0; l < TAM; l++) {
        printf("%d  ", l);
        for (int c = 0; c < TAM; c++) {
            switch(tab[l][c]) {
                case AGUA: printf("~ "); break;
                case NAVIO: printf("N "); break;
                case ACERTO: printf("O "); break;
                case ERRO: printf("X "); break;
                case AREA_HABILIDADE: printf("* "); break;
                default: printf("? "); break;
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Função para validar se coordenadas estão dentro do tabuleiro
int validaCoord(int linha, int coluna) {
    return linha >=0 && linha < TAM && coluna >= 0 && coluna < TAM;
}

// Função para aplicar ataque normal
void ataqueNormal(int tab[TAM][TAM], int linha, int coluna) {
    if (!validaCoord(linha, coluna)) {
        printf("Coordenadas inválidas!\n");
        return;
    }
    if (tab[linha][coluna] == ACERTO || tab[linha][coluna] == ERRO) {
        printf("Posição já atacada!\n");
        return;
    }
    if (tab[linha][coluna] == NAVIO) {
        tab[linha][coluna] = ACERTO;
        printf("Acertou o navio!\n");
    } else {
        tab[linha][coluna] = ERRO;
        printf("Água...\n");
    }
}

// Função para aplicar a área de efeito da habilidade no tabuleiro
void aplicarArea(int tab[TAM][TAM], int area[5][5], int origemLinha, int origemColuna) {
    int meio = 2; // centro da matriz 5x5

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (area[i][j] == 1){
                int linha = origemLinha + (i - meio);
                int coluna = origemColuna + (j - meio);
                if (validaCoord(linha, coluna)){
                    // Só marca como área se não for navio, acerto ou erro já marcado
                    if (tab[linha][coluna] == AGUA) {
                        tab[linha][coluna] = AREA_HABILIDADE;
                    } else if (tab[linha][coluna] == NAVIO) {
                        // Marca como acertado diretamente
                        tab[linha][coluna] = ACERTO;
                    }
                }
            }
        }
    }
}

// Função para aplicar habilidade Cone (área tipo cone apontando para baixo)
void aplicarCone(int tab[TAM][TAM], int linha, int coluna) {
    int cone[5][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };
    aplicarArea(tab, cone, linha, coluna);
    printf("Habilidade Cone usada!\n");
}

// Função para aplicar habilidade Cruz
void aplicarCruz(int tab[TAM][TAM], int linha, int coluna) {
    int cruz[5][5] = {
        {0,0,1,0,0},
        {0,0,1,0,0},
        {1,1,1,1,1},
        {0,0,1,0,0},
        {0,0,1,0,0}
    };
    aplicarArea(tab, cruz, linha, coluna);
    printf("Habilidade Cruz usada!\n");
}

// Função para aplicar habilidade Octaedro (losango)
void aplicarOctaedro(int tab[TAM][TAM], int linha, int coluna) {
    int octaedro[5][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1},
        {0,1,1,1,0},
        {0,0,1,0,0}
    };
    aplicarArea(tab, octaedro, linha, coluna);
    printf("Habilidade Octaedro usada!\n");
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // Posicionar navios fixos (exemplo simplificado)
    // Navio horizontal (linha 1, col 2 a 4)
    for (int i = 2; i < 5; i++)
        tabuleiro[1][i] = NAVIO;

    // Navio vertical (linha 5 a 7, col 7)
    for (int i = 5; i < 8; i++)
        tabuleiro[i][7] = NAVIO;

    // Navio diagonal
    for (int i = 0; i < 3; i++)
        tabuleiro[6+i][1+i] = NAVIO;

    int opcao, linha, coluna;
    while (1) {
        imprimirTabuleiro(tabuleiro);
        printf("Escolha a ação:\n");
        printf("1 - Ataque normal\n");
        printf("2 - Usar habilidade especial\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        if (opcao == 0) {
            printf("Saindo do jogo...\n");
            break;
        } else if (opcao == 1) {
            printf("Digite linha e coluna para atacar (0-%d): ", TAM-1);
            scanf("%d %d", &linha, &coluna);
            ataqueNormal(tabuleiro, linha, coluna);
        } else if (opcao == 2) {
            int hab;
            printf("Escolha habilidade:\n1 - Cone\n2 - Cruz\n3 - Octaedro\n");
            scanf("%d", &hab);
            printf("Digite posição de origem (linha e coluna 0-%d): ", TAM-1);
            scanf("%d %d", &linha, &coluna);

            switch (hab) {
                case 1: aplicarCone(tabuleiro, linha, coluna); break;
                case 2: aplicarCruz(tabuleiro, linha, coluna); break;
                case 3: aplicarOctaedro(tabuleiro, linha, coluna); break;
                default: printf("Habilidade inválida!\n");
            }
        } else {
            printf("Opção inválida!\n");
        }
        printf("\n");
    }

    return 0;
}
