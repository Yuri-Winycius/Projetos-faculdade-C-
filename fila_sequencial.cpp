#include <iostream>
using namespace std;

#define MAX 5 // tamanho máximo da fila

struct Fila {
    int itens[MAX];
    int frente, tras;

    // inicializa fila
    Fila() {
        frente = 0;
        tras = -1;
    }

    bool cheia() {
        return tras == MAX - 1;
    }

    bool vazia() {
        return frente > tras;
    }

    void enfileirar(int valor) {
        if (cheia()) {
            cout << "Fila cheia!\n";
        } else {
            itens[++tras] = valor;
            cout << valor << " entrou na fila.\n";
        }
    }

    void desenfileirar() {
        if (vazia()) {
            cout << "Fila vazia!\n";
        } else {
            cout << itens[frente++] << " saiu da fila.\n";
        }
    }

    void mostrar() {
        if (vazia()) {
            cout << "Fila vazia!\n";
        } else {
            cout << "Fila: ";
            for (int i = frente; i <= tras; i++) {
                cout << itens[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Fila f;

    f.enfileirar(10);
    f.enfileirar(20);
    f.enfileirar(30);
    f.mostrar();

    f.desenfileirar();
    f.mostrar();

    f.enfileirar(40);
    f.enfileirar(50);
    f.enfileirar(60); // estoura limite
    f.mostrar();

    return 0;
}
