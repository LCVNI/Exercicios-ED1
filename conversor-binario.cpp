#include <iostream>
#include <cstdlib>

using namespace std;

class Nodo {
public:
    int info;
    Nodo* prox;
};

class Pilha{
    private:
    Nodo *topo;
    public:
    Pilha();
    void empilhar(int n);
    int desempilhar();
    void imprimir();
};

Pilha::Pilha(){
    topo = nullptr;
}

void Pilha::empilhar(int n) {
    Nodo *novo = new Nodo;
    if (novo == nullptr) {
        cout << "Sem memoria";
        exit(1);
    }
    novo->info = n;
    novo->prox = topo;
    topo = novo;
}

int Pilha::desempilhar() {
    if (topo == nullptr) {
        cout << "Pilha vazia";
        return -1;
    }
    Nodo *aux = topo;
    int n = aux->info;
    topo = topo->prox;
    delete aux;
    return n;
}

void Pilha::imprimir() {
    if (topo == nullptr) {
        cout << "Pilha vazia" << endl;
        return;
    }
    Nodo *atual = topo;
    cout << "\nTOPO -> ";
    while (atual != nullptr) {
        cout << atual->info << " -> ";
        atual = atual->prox;
    }
    cout << "NULL" << endl;
}

int main() {
    Pilha p;
    int n, rest;

    cout << "Informe um numero: ";
    cin >> n;

    while (n > 0) {
        rest = n % 2;
        n /= 2;
        p.empilhar(rest);
    }

    char entr;
    cout << "Imprimir pilha? (s/n): ";
    cin >> entr;

    if (entr == 's') {
        p.imprimir();
    } else {
        cout << "Encerrando programa...";
    }

    return 0;
}