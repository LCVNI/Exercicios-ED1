/*
Codigo de uma estrutura padrao
de lista simplesmente encadeada
*/
#include <iostream>
using namespace std;

class Nodo{
    public:
    int info;
    Nodo *prox, *ant;
};
class ListaDupl{
    private:
    Nodo *inicio;
    Nodo *fim;
    public:
    ListaDupl(){
        inicio = nullptr;
        fim = nullptr;
    }
};