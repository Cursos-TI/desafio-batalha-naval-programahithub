#include <stdio.h>

    // Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.



    // Definições constantes
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

    // Função para inicializar o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

    // Função para verificar se o navio cabe no tabuleiro
int verificaLimite(int linha, int coluna, char orientacao) {
    if (orientacao == 'H') { // Horizontal
        return (coluna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO);
    } else if (orientacao == 'V') { // Vertical
        return (linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO);
    }
    return 0;
}

    // Função para verificar sobreposição de navios
int verificaSobreposicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] != 0) {
                return 1; // Está sobrepondo
            }
        }
    } else if (orientacao == 'V') {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != 0) {
                return 1;
            }
        }
    }
    return 0; // Não há sobreposição
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha][coluna + i] = 3;
        }
    } else if (orientacao == 'V') {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna] = 3;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n=== TABULEIRO ===\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água (0)
    inicializarTabuleiro(tabuleiro);

    // Dados dos navios
    // Navio 1 - Horizontal
    int linha1 = 2;
    int coluna1 = 3;
    char orientacao1 = 'H';

    // Navio 2 - Vertical
    int linha2 = 5;
    int coluna2 = 7;
    char orientacao2 = 'V';

    // Verifica e posiciona Navio 1
    if (verificaLimite(linha1, coluna1, orientacao1) &&
        !verificaSobreposicao(tabuleiro, linha1, coluna1, orientacao1)) {
        posicionarNavio(tabuleiro, linha1, coluna1, orientacao1);
    } else {
        printf("Erro: Navio 1 fora dos limites ou sobrepondo!\n");
    }

    // Verifica e posiciona Navio 2
    if (verificaLimite(linha2, coluna2, orientacao2) &&
        !verificaSobreposicao(tabuleiro, linha2, coluna2, orientacao2)) {
        posicionarNavio(tabuleiro, linha2, coluna2, orientacao2);
    } else {
        printf("Erro: Navio 2 fora dos limites ou sobrepondo!\n");
    }

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}


    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0


