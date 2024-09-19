//Discente: Antonio Roger Sousa de Morais - 202311140022
//Discente: Pedro Ferreira Brandão - 202311140001

#include "Estruturas.h"
#include <iostream>

// Construtor da Fila
Fila::Fila() : inicio(nullptr), fim(nullptr) {}

// Destrutor da Fila
Fila::~Fila() {
    while (!vazia()) {
        desenfileirar();
    }
}

// Enfileirar na Fila
void Fila::enfileirar(int valor) {
    Node* novo = new Node{valor, nullptr};
    if (vazia()) {
        inicio = fim = novo;
    } else {
        fim->prox = novo;
        fim = novo;
    }
}

// Desenfileirar da Fila
int Fila::desenfileirar() {
    if (vazia()) {
        return -1;
    }
    Node* temp = inicio;
    int valor = temp->valor;
    inicio = inicio->prox;
    delete temp;
    return valor;
}

// Verificar se a Fila está vazia
bool Fila::vazia() const {
    return inicio == nullptr;
}

// Construtor da Pilha
Pilha::Pilha() : topo(nullptr) {}

// Destrutor da Pilha
Pilha::~Pilha() {
    while (!vazia()) {
        desempilhar();
    }
}

// Empilhar na Pilha
void Pilha::empilhar(int valor) {
    Node* novo = new Node{valor, topo};
    topo = novo;
}

// Desempilhar da Pilha
int Pilha::desempilhar() {
    if (vazia()) {
        return -1;
    }
    Node* temp = topo;
    int valor = temp->valor;
    topo = topo->prox;
    delete temp;
    return valor;
}

// Verificar se a Pilha está vazia
bool Pilha::vazia() const {
    return topo == nullptr;
}

// Exibir os elementos da Pilha
void Pilha::exibir() const {
    Node* atual = topo;
    while (atual != nullptr) {
        std::cout << atual->valor << " ";
        atual = atual->prox;
    }
    std::cout << std::endl;
}