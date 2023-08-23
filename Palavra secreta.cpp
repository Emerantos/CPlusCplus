#include <iostream>
#include <cstdlib> 
#include <cstring> 

using namespace std;

const int MAX_TENTATIVAS = 6;
const int MAX_PALAVRA = 30;

void limparTela() {
    system("cls");
}

void inicializarPalavraSecreta(char secreta[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        secreta[i] = '-';
    }
}

bool letraEstaNaPalavra(char palavra[], char letra, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (palavra[i] == letra) {
            return true;
        }
    }
    return false;
}

void atualizarPalavraSecreta(char palavra[], char letra, char secreta[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (palavra[i] == letra) {
            secreta[i] = letra;
        }
    }
}

bool palavraCompletada(char secreta[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (secreta[i] == '-') {
            return false;
        }
    }
    return true;
}

int main() {
    char palavra[MAX_PALAVRA], letra;
    int tamanho, acertos = 0;
    bool acerto;

    cout << "Digite a palavra secreta: ";
    cin >> palavra;
    limparTela();

    tamanho = strlen(palavra);

    char secreta[MAX_PALAVRA];
    inicializarPalavraSecreta(secreta, tamanho);

    int chances = MAX_TENTATIVAS;

    while (chances > 0 && !palavraCompletada(secreta, tamanho)) {
        cout << "Chances restantes: " << chances << "\n\n";
        cout << "Palavra secreta: " << secreta << "\n\n";
        cout << "Digite uma letra: ";
        cin >> letra;

        acerto = letraEstaNaPalavra(palavra, letra, tamanho);

        if (acerto) {
            atualizarPalavraSecreta(palavra, letra, secreta, tamanho);
            acertos++;
        } else {
            chances--;
        }

        limparTela();
    }

    if (palavraCompletada(secreta, tamanho)) {
        cout << "Parabens palavra correta!" << endl;
    } else {
        cout << "Que pena, palavra errada!" << endl;
        cout << "A palavra era: " << palavra << endl;
    }

    system("pause");
    return 0;
}
