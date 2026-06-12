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
        if(novo == nullptr) exit(1);
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
    preOrdem(raiz->dir);
    cout << raiz->info;
}
void Arvore::posOrdem(Nodo *raiz){
    if(raiz == nullptr) return;
    cout << raiz->info;
    posOrdem(raiz->esq);
    posOrdem(raiz->dir);
}

int main(){
    Arvore a;
    int n;
    for(int i = 0; i < 6; i++){
        cout<< "Inserir na arvore: ";
        cin>>n;
        a.raiz = a.inserir(a.raiz, n);
    }
    a.posOrdem(a.raiz);
    return 0;
}