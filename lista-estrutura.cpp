/*
Codigo de uma estrutura padrao
de lista simplesmente encadeada
*/

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
};