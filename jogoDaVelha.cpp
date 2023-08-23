#include <iostream>
#include <cstdlib>

using namespace std;

char tabuleiro[3][3];
char jogadorAtual = 'X';

void inicializarTabuleiro() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = '-';
        }
    }
}

void mostrarTabuleiro() {
    cout << "   0  1  2" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i << " ";
        for (int j = 0; j < 3; j++) {
            cout << tabuleiro[i][j] << "  ";
        }
        cout << endl;
    }
}

bool verificarVencedor() {
    // Verificar linhas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] != '-' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]) {
            return true;
        }
    }

    // Verificar colunas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[0][i] != '-' && tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i]) {
            return true;
        }
    }

    // Verificar diagonais
    if (tabuleiro[0][0] != '-' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) {
        return true;
    }
    if (tabuleiro[0][2] != '-' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) {
        return true;
    }

    return false;
}

void realizarJogada(int linha, int coluna) {

    if (tabuleiro[linha][coluna] != '-') {
        cout << "Jogada inválida. Tente novamente." << endl;
        return;
    }

    tabuleiro[linha][coluna] = jogadorAtual;

    if (verificarVencedor()) {
        cout << "Parabéns! Jogador " << jogadorAtual << " venceu o jogo!" << endl;
        exit(0);
    }

    if (jogadorAtual == 'X') {

        jogadorAtual = 'O';

    } else {

        jogadorAtual = 'X';

    }
}

int main() {
    inicializarTabuleiro();
    mostrarTabuleiro();

    while (true) {
        int linha, coluna;
        cout << "Jogador " << jogadorAtual << ", faça a sua jogada (linha coluna): ";
        cin >> linha >> coluna;
        realizarJogada(linha, coluna);
        mostrarTabuleiro();
    }

    return 0;
}

bool jogarNovamente() {
    char resposta;
    cout << "Deseja jogar novamente? (S/N) ";
    cin >> resposta;
    return resposta == 'S' || resposta == 's';
}