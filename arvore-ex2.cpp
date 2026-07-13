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

/*Questao 2, Lista de arvore:
Escreva uma função recursiva, em C, para imprimir
todos os nós ascendentes de um certo nó
de uma árvore binária de pesquisa. */

void imprimirAncestrais(Nodo *raiz){
    

}