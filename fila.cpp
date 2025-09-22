#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> fila;

    // Inserindo elementos
    fila.push(10);
    fila.push(20);
    fila.push(30);

    cout << "Frente da fila: " << fila.front() << endl;
    cout << "Fim da fila: " << fila.back() << endl;   

    fila.pop(); 

    cout << "Novo frente da fila: " << fila.front() << endl;

    // Percorrendo a fila
    cout << "\nPercorrendo fila: ";
    while (!fila.empty()) {
        cout << fila.front() << " ";
        fila.pop();
    }
}