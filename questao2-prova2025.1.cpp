#include <iostream>
#include <stdio.h>
using namespace std;

class Nodo{
    public:
    int info;
    Nodo *prox, *ant;
};
class ListaDupl{
    private:
    Nodo *cabeca;
    Nodo *cauda;
    public:
    ListaDupl();
    void inserir(int n);
};
ListaDupl::ListaDupl(){
    cabeca = nullptr;
    cauda = nullptr;
}

void ListaDupl::inserir(int n){
    Nodo *novo = new Nodo;
    if(novo == nullptr){
        cout<<"Sem memoria"<<endl;
        exit(1);
    }
    novo->prox = nullptr;
    novo->ant = nullptr;
    novo->info = n;
    if(cabeca == nullptr){
        cabeca = cauda = novo;
        return;
    }
    cauda->prox = novo;
    novo->ant = cauda;
    cauda = novo;
    return;
}

void removerVizinhos(Nodo *&inicio, int n){
    if(inicio == nullptr){
        cout<<"Lista vazia"<<endl;
        return;
    }
    Nodo *atual = inicio;
    while(atual != nullptr){
        if(atual->info == n){
            if(atual == inicio){ //1. Se n for o primeiro elemento
                Nodo *delProx = atual->prox;
                inicio->prox = delProx->prox;
                if(delProx->prox != nullptr){
                    delProx->prox->ant = inicio;
                }
                delete delProx;
            }
            else if(atual->ant == inicio){ //2. Se o inicio tiver que ser deletado
                Nodo *delInicio = inicio;
                atual->ant = nullptr;
                inicio = atual;
            }
            else if(atual->prox == nullptr){//3. Se o n for o ultimo elemento
                Nodo* delAnt = atual->ant;
                delAnt->ant->prox = atual;
                atual->ant = delAnt->ant;
                delete delAnt;
            }
            else if(atual->prox->prox == nullptr){ // 4. Se o fim tiver que sser deletado
                Nodo* delFim = atual->prox;
                atual->prox = nullptr;
                delete delFim;
            }
            else{ // 5. elemento esta no meio da lista
                Nodo* delAnt = atual->ant;
                Nodo* delProx = atual->prox;
                atual->ant = delAnt->ant;
                atual->prox = delProx->prox;
                delProx->prox->ant = atual;
                delAnt->ant->prox = atual;
                delete delProx;
                delete delAnt;
            }
        }
        atual = atual->prox;
    }
    return;
}