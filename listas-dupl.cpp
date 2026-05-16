#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class Nodo{
    public:
    string info;
    Nodo *prox, *ant;
};
class ListaDupl{
    private:
    Nodo *inicio;
    Nodo *fim;
    Nodo *atual;
    public:
    ListaDupl();
    void inserir(string palavra);
    void corrigir(string palavra);
    void retirar();
    void andar();
    void voltar();
    Nodo* getInicio();
    Nodo* getAtual();
};
Nodo* ListaDupl::getInicio(){
    return inicio;
}
Nodo* ListaDupl::getAtual(){
    return atual;
}
ListaDupl::ListaDupl(){
    inicio = nullptr;
    fim = nullptr;
}

void ListaDupl::inserir(string palavra){
    Nodo *novo = new Nodo;
    if(novo == nullptr){
        cout << "Sem memoria" << endl;
        exit(1);
    }
    novo->info = palavra;
    novo->prox = nullptr;
    novo->ant = nullptr;
    // Caso 1: A lista está vazia
    if(inicio == nullptr){
        inicio = fim = novo;
        inicio->prox = fim;
        inicio->ant = fim;
        fim->prox = inicio;
        atual = inicio;
        cout << novo->info << " inserido como primeiro elemento (lista vazia)." << endl;
        return;
    }
    //Inserir no meio ou no fim
    Nodo *aux = atual->prox; 
    novo->prox = aux;
    novo->ant = atual;
    atual->prox = novo;
    if(aux != inicio){
        // Se não era o fim da lista, ajusta o ponteiro de retorno do próximo
        aux->ant = novo;
    } else {
        // Se era o fim da lista, o novo nodo passa a ser o novo 'fim'
        fim = novo;
        fim->prox = inicio;
        inicio->ant = fim;
    }
    atual = novo;
    cout << novo->info << " inserido depois de " << atual->info << endl;
}

void ListaDupl::corrigir(string palavra){
    if(inicio == nullptr){
        cout<<"Nao ha elementos para corrigir"<<endl;
        return;
    }
    atual->info = palavra;
    cout<<"Palavra editada"<<endl;
    return;
}

void ListaDupl::retirar(){
    if(inicio == nullptr){
        cout<<"Nao ha o que sser retirado"<<endl;
        return;
    }
    
    Nodo *aux = atual;
    string palavra = atual->info;
    
    if(inicio == fim){
        inicio = nullptr;
        fim = nullptr;
        atual = nullptr;
    }
    else if(atual == fim){
        fim = atual->ant;
        fim->prox = inicio;
        inicio->ant = fim;
        atual = inicio;
    }
    else if(atual == inicio){
        inicio = atual->prox;
        inicio->ant = fim;
        fim->prox = inicio;
        atual = inicio;
    }
    else{
        atual->ant->prox = atual->prox;
        atual->prox->ant = atual->ant;
        atual = atual->prox;
    }
    
    delete aux;
    cout<<"Palavra "<<palavra<<" removida"<<endl;
    return;
}

void ListaDupl::andar(){
    if(inicio == nullptr){
        cout<< "Nao ha elementos"<<endl;
        return;
    }
    atual = atual->prox;
    return;
}
void ListaDupl::voltar(){
    if(inicio == nullptr){
        cout<<"Nao ha elementos"<<endl;
    }
    atual = atual->ant;
    return;
}

int main(){
    ListaDupl l;
    char opcao;
    do{
        cout<<"C : corrigir palavra atual"<<endl
        <<"I : inserir palavra (apos atual)"<<endl
        <<"R : retirar palavra atual"<< endl
        <<"< : palavra anterior"<<endl
        <<"> : proxima palavra"<<endl
        <<"S : sair"<<endl
        <<"Digite uma opcao: ";
        cin >> opcao;
        switch(opcao){
            case 'c':{
            string palavra;
            cout<<"Correcao: ";
            cin>>palavra;
            l.corrigir(palavra);
            break;
            }
            case 'i':{
            string palavra;
            cout<<"Digite a palavra: ";
            cin>>palavra;
            l.inserir(palavra);
            break;
            }
            case 'r':{
            l.retirar();
            break;
            }
            case '>':{
            l.andar();
            cout<<"Atual: "<<l.getAtual()->info<<endl;
            break;
            }
            case '<':{
            l.voltar();
            cout<<"Atual: "<<l.getAtual()->info<<endl;
            break;
            }
            case 'S':{
            cout<<"Saindo"<<endl;
            break;
            }
            default:{
            cout<<"OPCAO INVALIDA!"<<endl;
            }
        }
    } while(opcao != 's' && opcao != 'S');
}