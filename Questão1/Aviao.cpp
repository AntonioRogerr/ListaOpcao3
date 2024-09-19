//Discente: Antonio Roger Sousa de Morais - 202311140022
//Discente: Pedro Ferreira Brandão - 202311140001

#include "Aviao.h"

// Implementação da classe Aviao

Aviao::Aviao(int id, string nome) : id(id), nome(nome) {}

int Aviao::getId() const {
    return id;
}

string Aviao::getNome() const {
    return nome;
}

void Aviao::exibirInfo() const {
    cout << "Avião ID: " << id << ", Nome: " << nome << endl;
}

// Implementação da classe Pista

Pista::Pista() : inicio(nullptr), fim(nullptr), tamanho(0) {}

Pista::~Pista() {
    while (inicio != nullptr) {
        No* temp = inicio;
        inicio = inicio->prox;
        delete temp->aviao; // Libera cada avião
        delete temp;  // Libera cada nó
    }
}

void Pista::adicionarAviao(Aviao* aviao) {
    No* novoNo = new No{aviao, nullptr};
    if (fim != nullptr) {
        fim->prox = novoNo;
    }
    fim = novoNo;
    if (inicio == nullptr) {
        inicio = fim;
    }
    tamanho++;
}

void Pista::autorizarDecolagem() {
    if (inicio == nullptr) {
        cout << "Não há aviões na fila de decolagem." << endl;
        return;
    }

    No* temp = inicio;
    cout << "Autorizando decolagem do avião: " << endl;
    temp->aviao->exibirInfo();

    inicio = inicio->prox;
    if (inicio == nullptr) {
        fim = nullptr;
    }

    delete temp->aviao; // Desaloca dinamicamente o avião
    delete temp; // Desaloca dinamicamente o nó
    tamanho--;
}

void Pista::listarAvioes() {
    if (inicio == nullptr) {
        cout << "Não há aviões na fila." << endl;
        return;
    }

    No* atual = inicio;
    while (atual != nullptr) {
        atual->aviao->exibirInfo();
        atual = atual->prox;
    }
}

void Pista::exibirPrimeiro() {
    if (inicio != nullptr) {
        cout << "Primeiro avião na fila: " << endl;
        inicio->aviao->exibirInfo();
    } else {
        cout << "Não há aviões na fila." << endl;
    }
}

int Pista::totalAvioes() const {
    return tamanho;
}
