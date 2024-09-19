//Discente: Antonio Roger Sousa de Morais - 202311140022
//Discente: Pedro Ferreira Brandão - 202311140001

#ifndef AVIAO_H
#define AVIAO_H

#include <iostream>
#include <string>

using namespace std;

class Aviao {
private:
    int id;
    string nome;

public:
    Aviao(int id, string nome);  // Construtor
    int getId() const;  // Retorna o ID do avião
    string getNome() const;  // Retorna o nome do avião
    void exibirInfo() const;  // Exibe as características do avião
};

// Classe Pista que vai controlar a fila de aviões
class Pista {
private:
    struct No {
        Aviao* aviao;
        No* prox;
    };

    No* inicio;
    No* fim;
    int tamanho;

public:
    Pista();  // Construtor da Pista
    ~Pista();  // Destrutor da Pista

    void adicionarAviao(Aviao* aviao);  // Adiciona avião à fila
    void autorizarDecolagem();  // Autoriza decolagem do primeiro avião
    void listarAvioes();  // Lista todos os aviões na fila
    void exibirPrimeiro();  // Exibe as características do primeiro avião
    int totalAvioes() const;  // Retorna o número de aviões na fila
};

#endif
