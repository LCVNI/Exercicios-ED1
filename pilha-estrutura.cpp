/*
Codigo padrao de uma estutura de pilha
com metodos de empilhar, desempilhar
e imprimir implementados
*/

#include <iostream>
#include <cstdlib>
using namespace std;

class Nodo{
    public:
    int info;
    Nodo *prox;
};

class Pilha {
private:
    Nodo *topo;
public:
    Pilha();           
    void empilhar(int n);
    int desempilhar();
    void imprimir();
}; 


Pilha::Pilha() {
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
        //cout << "Pilha vazia";
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
        //cout << "Pilha vazia" << endl;
        return;
    }
    Nodo *atual = topo;
    //cout << "\nTOPO -> ";
    while (atual != nullptr) {
        cout << atual->info << " -> ";
        atual = atual->prox;
    }
    //cout << "NULL" << endl;
}