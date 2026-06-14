/*
Codigo padrao de uma estrutura de fila, com
metodos de inserir, retirar e imprimir
implementaados
*/

#include <iostream>
#include <cstdlib>
using namespace std;

class Nodo{
    public:
    int info;
    Nodo *prox;
};

class Fila{
    Nodo *inicio;
    Nodo *fim;
public:
    Fila(){
        inicio = nullptr;
        fim = nullptr;
        }
    void inserir(int n);
    int retirar();
    void imprimir();
    };

void Fila:: inserir(int n){
    Nodo *novo;
    novo =new Nodo;
    if (novo == nullptr) exit(1);
    novo->info = n;
    novo->prox = nullptr;
    if (inicio == nullptr){
        inicio = novo;
    }
    else{
        fim->prox = novo;
    }
    fim = novo;
}

int Fila::retirar() {
   
    if (inicio == nullptr) {
        //cout << "Erro: Fila vazia!" << endl;
        return -1; 
    }
    int valor = inicio->info;
    Nodo *temp = inicio;
    inicio = inicio->prox;
    if (inicio == nullptr) {
        fim = nullptr;
    }
    delete temp;
    return valor;
}

void Fila::imprimir() {
    
    if (inicio == nullptr) {
        //cout << "Fila vazia!" << endl;
        return;
    }
    Nodo *aux = inicio;
    //cout << "Elementos da fila: ";
    while (aux != nullptr) {
        cout << aux->info << " ";
        aux = aux->prox;         
    }
    cout << endl;
}