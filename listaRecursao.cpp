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
    Nodo* getInicio();
    void append(int valor);
    int buscar(int valor, Nodo *atual);
    void imprime(Nodo* aux);
};
Nodo* Lista::getInicio(){
    return inicio;
}

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

int Lista::buscar(int valor, Nodo* atual) {
    if (!atual) return 0;
    if(atual->info == valor){
        return 1;
    }
    return buscar(valor, atual->prox);
}

void Lista::imprime(Nodo *aux) {
    if(!aux){
        cout << "NULL" << endl;
        return;
    }
    cout << aux->info << " -> ";
    return imprime(aux->prox);
}

int main() {
    Lista l;
    int n;
    for (int i = 10; i > 0; i--) {
        l.append(i);
    }
    cout<<"Lista:";
    l.imprime(l.getInicio());
    cout<<"buscar: ";
    cin>>n;
    if(l.buscar(n, l.getInicio())){
        cout<<"Encontrada"<<endl;
    }
    else{
        cout<<"Nao encontrada"<<endl;
    }

    return 0;
}
