#include <iostream>
using namespace std;

class Nodo {
public:
    int info;
    Nodo *prox;
};

class Lista {
private:
    Nodo *inicio;
    Nodo *fim;
public:
    
    Lista() {
        inicio = nullptr;
        fim = nullptr;
    }

    int tamanho();
    void append(int valor);
    void inserePos(int valor, int pos);
    int retira(int valor);
    void ordena();
    void imprime();
};

void Lista::append(int valor) {
    Nodo *novo = new Nodo;
    if (novo == nullptr) exit(1);
    novo->info = valor;
    novo->prox = nullptr;

    if (inicio == nullptr) { 
        inicio = novo;
        fim = novo;
    } else {
        fim->prox = novo;
        fim = novo;
    }
}

int Lista::retira(int valor) {
    if (inicio == nullptr) return -1;

    Nodo *atual = inicio;
    Nodo *ant = nullptr;

    
    while (atual != nullptr && atual->info != valor) {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == nullptr) return -1;

    if (ant == nullptr) { 
        inicio = atual->prox;
    } else {
        ant->prox = atual->prox;
    }

    if (atual == fim) fim = ant;

    int n = atual->info;
    delete atual;
    return n;
}

void Lista::ordena() {
    if (inicio == nullptr || inicio->prox == nullptr) return;

    bool trocou;
    do {
        trocou = false;
        Nodo *atual = inicio;
        while (atual->prox != nullptr) {
            if (atual->info > atual->prox->info) {
                int temp = atual->info;
                atual->info = atual->prox->info;
                atual->prox->info = temp;
                trocou = true;
            }
            atual = atual->prox;
        }
    } while (trocou);
}

void Lista::imprime() {
    Nodo *atual = inicio;
    cout << "Lista: ";
    while (atual != nullptr) {
        cout << atual->info << " -> ";
        atual = atual->prox;
    }
    cout << "NULL" << endl;
}

int main() {
    Lista l;
    for (int i = 10; i > 0; i--) {
        l.append(i);
    }

    l.imprime();
    l.ordena();
    cout << "Ordenada: " << endl;
    l.imprime();

    return 0;
}