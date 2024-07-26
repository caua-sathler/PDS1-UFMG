#include <stdio.h>
#include <string.h>

                                                                                                                // Função para comparar os tabuleiros
int compararTabuleiros(char tab1[100][100], char tab2[100][100], int tam) {
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            if (tab1[i][j] != tab2[i][j]) {
                return 0;                                                                                       // Tabuleiros são diferentes
            }
        }
    }
    return 1;                                                                                                   // Tabuleiros são iguais
}

void transformarTabuleiroGANHAR(char tabuleiroQuadrado1[100][100], char tabuleiroQuadrado2[100][100], int x, int y, int tam) {
                                                                                                                // Verifica se está fora dos limites ou não é um espaço vazio
    if (x < 0 || x >= tam || y < 0 || y >= tam || tabuleiroQuadrado1[x][y] != 'x') {
        return;
    }

                                                                                                                // Verifica se há bombas nas casas adjacentes
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int adjX = x + i;
            int adjY = y + j;
                                                                                                                // Ignora a verificação fora dos limites do tabuleiro
            if (adjX >= 0 && adjX < tam && adjY >= 0 && adjY < tam) {
                if (tabuleiroQuadrado1[adjX][adjY] == 'b') {
                                                                                                                // Se encontrar uma bomba, revela apenas a casa selecionada e retorna
                    tabuleiroQuadrado2[x][y] = '0';
                    return;
                }
            }
        }
    }

                                                                                                                // Se não encontrou bombas, revela a casa selecionada e todas as adjacentes
    tabuleiroQuadrado2[x][y] = '0';                                                                             // Revela a casa selecionada
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
                                                                                                                // Evita revelar novamente a casa central ou fora dos limites
            if (i == 0 && j == 0) continue;
            int adjX = x + i;
            int adjY = y + j;
            if (adjX >= 0 && adjX < tam && adjY >= 0 && adjY < tam && tabuleiroQuadrado1[adjX][adjY] == 'x') {
                tabuleiroQuadrado2[adjX][adjY] = '0';                                                           // Revela casas adjacentes seguras
            }
        }
    }
}
int main() {
    int qtdDeJogos;
    scanf("%d", &qtdDeJogos);                                                                                   // entrada da quantidade de jogos que serão jogados
    if (qtdDeJogos < 1 || qtdDeJogos > 10) return 0;                                                            // condicional para não permitir que a qtd de jogos saia do intervalo 1 a 10

    for (int jogo = 1; jogo <= qtdDeJogos; jogo++) {                                                            // esse laço for serve para aceitar mais de um jogo por programa
        int tamTabuleiro;
        char tabuleiroQuadrado1[100][100];                                                                      // declaração de um tabuleiro que comporte o máximo de jogos aceitos
        char tabuleiroDeBombas[100][100];
        char tabuleiroQuadrado2[100][100];
        int numDeJogadas;
        int ganhou = 0;
        int perdeu = 0;

        scanf("%d", &tamTabuleiro);                                                                             // entrada das dimensões do tabuleiro daquele jogo específico
        if (tamTabuleiro < 2 || tamTabuleiro > 100) return 0;                                                   // condicional para não permitir que o tamanho do tabuleiro saia do intervalo 2 a 100

        for (int i = 0; i < tamTabuleiro; i++) {                                                                // leitura e alocação do tabuleiro
            for (int j = 0; j < tamTabuleiro; j++) {
                scanf(" %c", &tabuleiroQuadrado1[i][j]);                                                        // entrada das linhas inseridas em uma matriz para jogar posteriormente
                tabuleiroQuadrado2[i][j] = tabuleiroQuadrado1[i][j];                                            // Inicializa tabuleiroQuadrado2 com os mesmos valores
            }
        }

        for (int i = 0; i < tamTabuleiro; i++) {
            for (int j = 0; j < tamTabuleiro; j++) {
                if (tabuleiroQuadrado1[i][j] == 'x') {
                    tabuleiroDeBombas[i][j] = '0';                                                              //cria o tabuleiroDeBombas para comparação final
                } else {
                    tabuleiroDeBombas[i][j] = tabuleiroQuadrado1[i][j];
                }
            }
        }

        scanf("%d", &numDeJogadas);                                                                             // entrada do número de jogadas a serem feitas naquela rodada

        int x, y;
        for (int i = 0; i < numDeJogadas; i++) {
            scanf("%d %d", &x, &y);
            if (tabuleiroQuadrado1[x][y] == 'b') { 
                perdeu = 1;
            } else {
                transformarTabuleiroGANHAR(tabuleiroQuadrado1, tabuleiroQuadrado2, x, y, tamTabuleiro);
            }
        }

        if (perdeu == 1) {                                                                                      //verifica as condições de vitória
            printf("PERDEU\n");
        } else if (compararTabuleiros(tabuleiroQuadrado2, tabuleiroDeBombas, tamTabuleiro)) {
            printf("GANHOU\n");
        } else {
            printf("FALTOU TERMINAR\n");
        }
    }
    return 0;
}