/*
Codigo padrao de uma estrutura de arvore
com funcoes de inserir, imprimir em ordem, pos-ordem
e pre-ordem
implementadas
*/
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
    Arvore(){
        raiz = nullptr;
    }
    Nodo *inserir(Nodo *raiz, int n);
    void emOrdem(Nodo *raiz);
    void posOrdem(Nodo *raiz);
    void preOrdem(Nodo *raiz);
};

Nodo* Arvore:: inserir(Nodo *raiz, int n){
    if(raiz == nullptr){
        Nodo * novo = new Nodo();
        if(novo == nullptr){
            cout << "Falha ao alocar memoria" << endl;
            exit(1);
        }
        novo->info = n;
        novo->esq = nullptr;
        novo->dir = nullptr;
        return(novo);
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