#include<iostream>
#include<cstdlib>
using namespace std;
class Nodo{
    public:
    int info;
    Nodo *esq, *dir;
};

class Nodo2{
    public:
    Nodo *info;
    Nodo2 *prox;
};

class Fila{
    private:
    Nodo2 *inicio;
    Nodo2 *fim;
    public:
    Fila(){
        inicio = nullptr;
        fim = nullptr;
    }
    void inserir(Nodo *raiz);
    Nodo* retirar();
    Nodo2* getInicio();
};
Nodo2* Fila::getInicio(){
    return inicio;
}

void Fila:: inserir(Nodo *raiz){
    Nodo2 *novo;
    novo =new Nodo2;
    if (novo == nullptr) exit(1);
    novo->info = raiz;
    novo->prox = nullptr;
    if (inicio == nullptr){
        inicio = novo;
    }
    else{
        fim->prox = novo;
    }
    fim = novo;
}

Nodo* Fila::retirar() {
   
    if (inicio == nullptr) {
        //cout << "Erro: Fila vazia!" << endl;
        return nullptr; 
    }
    Nodo *valor = inicio->info;
    Nodo2 *temp = inicio;
    inicio = inicio->prox;
    if (inicio == nullptr) {
        fim = nullptr;
    }
    delete temp;
    return valor;
}

class Arvore{
    public:
    Nodo *raiz;
    Arvore(){
        raiz = nullptr;
    }
    Nodo *inserir(Nodo *raiz, int n);
    void imprimirNivel();
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

void Arvore::imprimirNivel(){
    if(raiz == nullptr){
        return;
    }
    Fila f;
    Nodo *atual = nullptr;
    f.inserir(raiz);
    while(f.getInicio()){
        atual = f.retirar();
        cout<<atual->info<< " ";
        if(atual->esq){
            f.inserir(atual->esq);
        }
        if(atual->dir){
            f.inserir(atual->dir);
        }
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
    cout<<"\n Impressao por nivel:"<<endl;
    a.imprimirNivel();
}