#include<iostream>
#include<cstdlib>
using namespace std;
class Nodo{
    public:
    int info;
    Nodo *esq, *dir;
};

class Arvore{
    public:
    Nodo *raiz;
    Nodo *inserir(Nodo *raiz, int n);
    void emOrdem(Nodo *raiz);
    void posOrdem(Nodo *raiz);
    void preOrdem(Nodo *raiz);
};

Nodo* Arvore:: inserir(Nodo *raiz, int n){
    if(raiz == nullptr){
        if(!(raiz = new Nodo())) exit(1);
        raiz->info = n;
        raiz->esq = nullptr;
        raiz->dir = nullptr;
        return(raiz);
    }
    else{
        if(n < raiz->info) raiz->esq = inserir(raiz->esq, n);
        else{
            if(n > raiz->info) raiz->dir = inserir(raiz->dir, n);
            else{
                cout<<"Valor ja inserido"<<endl;
            }
        }
        return(raiz);
    }
}

void Arvore::emOrdem(Nodo *raiz){
    if(raiz == nullptr) return;
    emOrdem(raiz->esq);
    cout << raiz->info;
    emOrdem(raiz->dir);
}
void Arvore::preOrdem(Nodo *raiz){
    if(raiz == nullptr) return;
    preOrdem(raiz->esq);
    cout << raiz->info;
    preOrdem(raiz->dir);
}
void Arvore::posOrdem(Nodo *raiz){
    if(raiz == nullptr) return;
    cout << raiz->info;
    posOrdem(raiz->esq);
    posOrdem(raiz->dir);
}