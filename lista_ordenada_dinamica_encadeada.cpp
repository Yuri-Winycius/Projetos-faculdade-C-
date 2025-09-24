#include <iostream>

// Implementação de uma lista ordenada simples, com nós encadeados dinamicamente
class ListaOrdenada {
private:
    // Estrutura que representa cada nó da lista
    struct No {
        int valor;   
        No* proximo; 
        No(int v) : valor(v), proximo(nullptr) {} 
    };

    No* cabeca; 
    int qtd;    

    // Função auxiliar que apaga todos os nós 
    void limpar() {
        while (cabeca) {
            No* temp = cabeca;
            cabeca = cabeca->proximo;
            delete temp;
        }
        qtd = 0;
    }

public:
    // Construtor padrão 
    ListaOrdenada() : cabeca(nullptr), qtd(0) {}

    // Destrutor -> libera a memória
    ~ListaOrdenada() { limpar(); }

    // Construtor de cópia 
    ListaOrdenada(const ListaOrdenada& outra) : cabeca(nullptr), qtd(0) {
        No* atual = outra.cabeca;
        while (atual) {
            inserir(atual->valor); 
            atual = atual->proximo;
        }
    }

    // Operador de atribuição 
    ListaOrdenada& operator=(const ListaOrdenada& outra) {
        if (this == &outra) return *this; 
        limpar();
        No* atual = outra.cabeca;
        while (atual) {
            inserir(atual->valor);
            atual = atual->proximo;
        }
        return *this;
    }

    // Retorna o tamanho atual da lista
    int tamanho() const { return qtd; }

    // Insere um valor na posição correta (ordem crescente)
    void inserir(int v) {
        No* novo = new No(v);

        // Caso especial: lista vazia ou inserir antes da cabeça
        if (!cabeca || v < cabeca->valor) {
            novo->proximo = cabeca;
            cabeca = novo;
            ++qtd;
            return;
        }

        // Percorre a lista até achar a posição correta
        No* anterior = cabeca;
        No* atual = cabeca->proximo;
        while (atual && atual->valor <= v) {
            anterior = atual;
            atual = atual->proximo;
        }

        // Insere o novo nó entre "anterior" e "atual"
        anterior->proximo = novo;
        novo->proximo = atual;
        ++qtd;
    }

    // Remove a primeira ocorrência de um valor; retorna true se conseguiu remover
    bool remover(int v) {
        if (!cabeca) return false;

        // Caso especial: valor está logo na cabeça
        if (cabeca->valor == v) {
            No* temp = cabeca;
            cabeca = cabeca->proximo;
            delete temp;
            --qtd;
            return true;
        }

        No* anterior = cabeca;
        No* atual = cabeca->proximo;

        // Como a lista é ordenada, podemos parar se encontrar valor maior
        while (atual && atual->valor < v) {
            anterior = atual;
            atual = atual->proximo;
        }

        if (atual && atual->valor == v) {
            anterior->proximo = atual->proximo;
            delete atual;
            --qtd;
            return true;
        }

        return false; // valor não encontrado
    }

    // Verifica se a lista contém um valor
    bool contem(int v) const {
        No* atual = cabeca;
        while (atual && atual->valor < v) atual = atual->proximo;
        return (atual && atual->valor == v);
    }

    // Imprime a lista no formato [a, b, c]
    void imprimir() const {
        No* atual = cabeca;
        std::cout << "[";
        while (atual) {
            std::cout << atual->valor;
            if (atual->proximo) std::cout << ", ";
            atual = atual->proximo;
        }
        std::cout << "]\n";
    }
};

// Exemplo de uso
int main() {
    ListaOrdenada lista;
    lista.inserir(5);
    lista.inserir(2);
    lista.inserir(9);
    lista.inserir(1);
    lista.inserir(7);
    lista.inserir(5); 

    std::cout << "Depois de inserir: ";
    lista.imprimir(); 

    std::cout << "A lista contem 5? " << (lista.contem(5) ? "sim" : "não") << "\n";

    lista.remover(5); 
    std::cout << "Depois de remover um 5: ";
    lista.imprimir(); 

    std::cout << "Tamanho da lista: " << lista.tamanho() << "\n";
    return 0;
}
