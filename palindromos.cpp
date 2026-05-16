#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//As duas estruturas usarao essa estrutura
class Nodo{
    public:
    char info;
    Nodo *prox;
};
//Inicio da estrutura da fila
class Fila{
    Nodo *inicio;
    Nodo *fim;
public:
    Fila(){
        inicio = nullptr;
        fim = nullptr;
        }
    void inserir(char n);
    char retirar();
    void imprimir();
    };

void Fila:: inserir(char n){
    Nodo *novo;
    novo =new Nodo;
    if (novo == nullptr) exit(1);
    novo->info = n;
    novo->prox = nullptr;
    if (inicio == nullptr){
        inicio = novo;
    }
    else{
        fim->prox = novo;
    }
    fim = novo;
}

char Fila::retirar() {
   
    if (inicio == nullptr) {
        //cout << "Erro: Fila vazia!" << endl;
        return -1; 
    }
    char valor = inicio->info;
    Nodo *temp = inicio;
    inicio = inicio->prox;
    if (inicio == nullptr) {
        fim = nullptr;
    }
    delete temp;
    return valor;
}

void Fila::imprimir() {
    
    if (inicio == nullptr) {
        //cout << "Fila vazia!" << endl;
        return;
    }
    Nodo *aux = inicio;
    //cout << "Elementos da fila: ";
    while (aux != nullptr) {
        cout << aux->info << " ";
        aux = aux->prox;         
    }
    cout << endl;
}

//Inicio da estrutura da pilha
class Pilha {
private:
    Nodo *topo;
public:
    Pilha();           
    void empilhar(char n);
    char desempilhar();
    void imprimir();
}; 


Pilha::Pilha() {
    topo = nullptr;
}

void Pilha::empilhar(char n) {
    Nodo *novo = new Nodo;
    if (novo == nullptr) {
        cout << "Sem memoria";
        exit(1);
    }
    novo->info = n;
    novo->prox = topo;
    topo = novo;
}

char Pilha::desempilhar() {
    if (topo == nullptr) {
        //cout << "Pilha vazia";
        return -1;
    }
    Nodo *aux = topo;
    char n = aux->info;
    topo = topo->prox;
    delete aux;
    return n;
}

void Pilha::imprimir() {
    if (topo == nullptr) {
        //cout << "Pilha vazia" << endl;
        return;
    }
    Nodo *atual = topo;
    //cout << "\nTOPO -> ";
    while (atual != nullptr) {
        cout << atual->info << " -> ";
        atual = atual->prox;
    }
    //cout << "NULL" << endl;
}

int main(){
    Pilha p;
    Fila f;
    char palavra[40];
    cout <<"Insira uma palavra: ";
    cin >> palavra;
    int i=0;
    while(true){ // Inserir palavra nas estruturas
        p.empilhar(palavra[i]);
        f.inserir(palavra[i]);
        i++;
        if(palavra[i] == '\0') break;
    };
    cout << "Palavra em pilha: ";
    p.imprimir();
    cout << "\nPalavra em fila: ";
    f.imprimir();
    while(true){
        if(p.desempilhar() == -1 || f.retirar() == -1){
            break;
        }
       if(p.desempilhar() != f.retirar()){
           cout << "Palavra nao eh palindromo"<<endl;
           return 0;
       }
   };
    cout << "\nPalavra eh palindromo"<<endl;
    return 0;
}

