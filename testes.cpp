#include <stdio.h>
#include <iostream>
using namespace std;

// Função potencial
int potencia(int base, int expoente) { 
    int total = 1;

    for (int i = 0; i < expoente; i ++){
        total *= base;
    }
    return total;
}

// Função potencial recursiva
int potenciaRecursiva(int base, int expoente) {
    if (expoente == 0) {
        return 1;
    } 
    
    return base * potenciaRecursiva(base, expoente - 1);
}

// Função fatorial
int fatorial(int n) {
    int total = 1;

    for (int i = n; i > 0; i --) {
        total *= i;
    }

    return total;
}

// Função fatorial recursiva
int fatorialRecursiva(int n) {
    if (n == 0) {
        return 1;
    }

    return n * fatorialRecursiva(n - 1);
}

// Função termial 
int termial(int n) {
    int total = 0;

    for (int i = n; i > 0; i --) {
        total += i;
    }

    return total;
}

// Função termial recursiva
int termialRecursiva( int n) {
    if (n == 0) {
        return 0;
    }

    return n + termialRecursiva(n - 1);
}

int main () {
    // Usando função potencial comum
    cout << "Potencia: " << potencia(5, 5) << endl;

    // Usando potencial recursiva
    cout << "Potencial recursiva: " << potenciaRecursiva(5, 5) << endl;

    // Usando função fatorial comum
    cout << "Fatorial: " << fatorial(5) << endl;

    // Usando fatorial recursiva
    cout << "Fatorial recursiva: " << fatorialRecursiva(5) << endl;

    // Usando função termial comun
    cout << "Termial: " << termial(5) << endl;

    // Usando termial recursiva
    cout << "Termial recursiva: " << termialRecursiva(5) << endl;
}