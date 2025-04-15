#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3


int podePosicionar(int tabuleiro[TAM][TAM], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + (direcao == 1 ? i : 0) + (diagonal == 1 ? i : 0) - (diagonal == 2 ? i : 0);
        int c = coluna + (direcao == 2 ? i : 0) + (diagonal == 1 ? i : 0) + (diagonal == 2 ? -i : 0);

        if (l < 0 || l >= TAM || c < 0 || c >= TAM || tabuleiro[l][c] == 3) {
            return 0; 
        }
    }
    return 1;
}

void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + (direcao == 1 ? i : 0) + (diagonal == 1 ? i : 0) - (diagonal == 2 ? i : 0);
        int c = coluna + (direcao == 2 ? i : 0) + (diagonal == 1 ? i : 0) + (diagonal == 2 ? -i : 0);

        tabuleiro[l][c] = 3;
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0}; 

    int linha1 = 0, coluna1 = 0;
    if (podePosicionar(tabuleiro, linha1, coluna1, 2, 0)) {
        posicionarNavio(tabuleiro, linha1, coluna1, 2, 0);
    }

    int linha2 = 0, coluna2 = 5;
    if (podePosicionar(tabuleiro, linha2, coluna2, 1, 0)) {
        posicionarNavio(tabuleiro, linha2, coluna2, 1, 0);
    }

    int linha3 = 3, coluna3 = 3;
    if (podePosicionar(tabuleiro, linha3, coluna3, 0, 1)) {
        posicionarNavio(tabuleiro, linha3, coluna3, 0, 1);
    }

    int linha4 = 5, coluna4 = 7;
    if (podePosicionar(tabuleiro, linha4, coluna4, 0, 2)) {
        posicionarNavio(tabuleiro, linha4, coluna4, 0, 2);
    }

    printf("Tabuleiro de Batalha Naval (3 = navio, 0 = água):\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 3) {
                printf("(3) ");
            } else {
                printf(" 0  ");
            }
        }
        printf("\n");
    }

    return 0;
}