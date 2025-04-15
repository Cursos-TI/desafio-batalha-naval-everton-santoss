#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define TAM_HABILIDADE 5

void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    tabuleiro[2][2] = 3;
    tabuleiro[3][3] = 3;
    tabuleiro[4][4] = 3;
    tabuleiro[5][5] = 3;
    tabuleiro[6][6] = 3;
}

void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            switch (tabuleiro[i][j]) {
                case 0: printf("0 "); break; 
                case 3: printf("3 "); break; 
                case 5: printf("5 "); break; 
                default: printf("? "); break;
            }
        }
        printf("\n");
    }
}



void preencherCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        int inicio = 2 - i;
        int fim = 2 + i;
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= inicio && j <= fim) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}





void preencherCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == 2 || j == 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}



void preencherOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - centro) + abs(j - centro) <= 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origemX, int origemY) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int x = origemX + i - 2;
            int y = origemY + j - 2;

            if (x >= 0 && x < TAM && y >= 0 && y < TAM) {
                if (habilidade[i][j] == 1 && tabuleiro[x][y] != 3) {
                    tabuleiro[x][y] = 5; // Marca como área de habilidade
                }
            }
        }
    }
}


void imprimirMatrizHabilidade(int matriz[TAM_HABILIDADE][TAM_HABILIDADE], const char* nome) {
    printf("\nMatriz de habilidade: %s\n", nome);
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    inicializarTabuleiro(tabuleiro);

    preencherCone(cone);
    preencherCruz(cruz);
    preencherOctaedro(octaedro);

    imprimirMatrizHabilidade(cone, "Cone");
    aplicarHabilidade(tabuleiro, cone, 2, 5);
    imprimirTabuleiro(tabuleiro);

    preencherCruz(cruz); 
    aplicarHabilidade(tabuleiro, cruz, 5, 5);
    imprimirMatrizHabilidade(cruz, "Cruz");
    imprimirTabuleiro(tabuleiro);

    preencherOctaedro(octaedro);
    aplicarHabilidade(tabuleiro, octaedro, 7, 3);
    imprimirMatrizHabilidade(octaedro, "Octaedro");
    imprimirTabuleiro(tabuleiro);

    return 0;
}
