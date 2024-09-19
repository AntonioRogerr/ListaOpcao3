//Discente: Antonio Roger Sousa de Morais - 202311140022
//Discente: Pedro Ferreira Brandão - 202311140001

#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

struct Node {
    int valor;
    Node* prox;
};

class Fila {
private:
    Node* inicio;
    Node* fim;

public:
    Fila();
    ~Fila();
    void enfileirar(int valor);
    int desenfileirar();
    bool vazia() const;
};

class Pilha {
private:
    Node* topo;

public:
    Pilha();
    ~Pilha();
    void empilhar(int valor);
    int desempilhar();
    bool vazia() const;
    void exibir() const;
};

#endif
