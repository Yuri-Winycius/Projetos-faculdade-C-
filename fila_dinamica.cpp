#include <iostream>
using namespace std;

struct No {
    int dado;
    No* prox;
};

struct Fila {
    No* frente;
    No* tras;

    // Inicializa fila vazia
    Fila() {
        frente = nullptr;
        tras = nullptr;
    }

    // Verifica se está vazia
    bool vazia() {
        return frente == nullptr;
    }

    // Insere no fim
    void enfileirar(int valor) {
        No* novo = new No;
        novo->dado = valor;
        novo->prox = nullptr;

        if (vazia()) {
            frente = tras = novo;
        } else {
            tras->prox = novo;
            tras = novo;
        }
        cout << valor << " entrou na fila.\n";
    }

    // Remove do início
    void desenfileirar() {
        if (vazia()) {
            cout << "Fila vazia!\n";
            return;
        }
        No* temp = frente;
        cout << frente->dado << " saiu da fila.\n";
        frente = frente->prox;
        if (frente == nullptr) tras = nullptr; 
        delete temp;
    }

    void mostrar() {
        if (vazia()) {
            cout << "Fila vazia!\n";
            return;
        }
        cout << "Fila: ";
        No* atual = frente;
        while (atual != nullptr) {
            cout << atual->dado << " ";
            atual = atual->prox;
        }
        cout << endl;
    }

    // Libera toda memória
    ~Fila() {
        while (!vazia()) {
            desenfileirar();
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
    f.mostrar();

    return 0;
}