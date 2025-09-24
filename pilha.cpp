#include <iostream>
#include <string>
using namespace std;

struct No {
    string nome;
    float nota;
    No* embaixo;
};

struct Pilha {
    No* topo;
    No* segundo;
    
    Pilha() {
        topo = nullptr;
        segundo = nullptr;
    }
    
    bool vazia() {
        return topo == nullptr;
    }

    void push(string nome, float nota) {
        No* novo = new No;
        novo->nome = nome;
        novo->nota = nota;
        novo->embaixo = nullptr;

        if (vazia()) {
            topo = novo;
        } else {
            segundo = topo;
            topo = novo;
            novo->embaixo = segundo;
        }
    }

    void pop() {
        if (vazia()) {
            return;
        } else {
            No* atual = topo;
            topo = topo->embaixo;
            if (topo == nullptr) segundo = nullptr;
            delete atual;
        }
    }

     void mostrar() {
        if (vazia()) {
            cout << "Fila vazia!\n";
            return;
        }
        cout << "Pilha: ";
        No* atual = topo;
        while (atual != nullptr) {
            cout << " Aluno: " << atual->nome << " Nota: " << atual->nota << endl;
            atual = atual->embaixo;
        }
        cout << endl;
    }
};

int main() {
    Pilha p;

    p.push("Yuri", 9.9);
    p.push("Winycius", 10);
    p.push("Oliveira", 9.9);
    p.mostrar();

    p.pop();
    p.mostrar();
}