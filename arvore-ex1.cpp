#include<iostream>
#include<cstdlib>
using namespace std;

//"Interruptor global"
bool irEsq = false;
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
    void folhasExtremas(Nodo *raiz);
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
void Arvore::folhasExtremas(Nodo *raiz){
    if(raiz == nullptr) return;
    if(irEsq == false){
        folhasExtremas(raiz->dir);
        if(raiz->dir == nullptr){
            cout<< "Folha mais a direita: "<<raiz->info<<endl;
            irEsq = true;
            return;
        }
    }

    folhasExtremas(raiz->esq);
    if(raiz->esq == nullptr){
        cout<<"Folha mais a esquerda: "<<raiz->info<<endl;
        return;
    }
}

int main(){
    Arvore a;
    int n;
    a.raiz =nullptr;
    for(int i=0; i<5; i++){
        cout<<"Inserir na arvore: ";
        cin>>n;
        a.raiz = a.inserir(a.raiz, n);
    }
    a.folhasExtremas(a.raiz);
    return 0;
}
