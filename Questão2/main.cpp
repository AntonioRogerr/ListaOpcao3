//Discente: Antonio Roger Sousa de Morais - 202311140022
//Discente: Pedro Ferreira Brandão - 202311140001

#include "Estruturas.h"
#include <iostream>
#include <cstdlib> //Biblioteca para gerar números aleatórios, está no enunciado da questão
#include <ctime>

int main() {
    Fila filaPar, filaImpar;
    Pilha pilha;
    int valor;

    // Gerando valores aleatórios e enfileirando
    std::srand(std::time(nullptr)); 
    std::cout << "Gerando valores aleatórios. Valor 0 finaliza.\n";

    // Gerando números aleatórios entre -100 e 100
    while (true) {
        valor = std::rand() % 201 - 100;
        std::cout << "Valor gerado: " << valor << std::endl;
        if (valor == 0) break;

        if (valor % 2 == 0) {
            filaPar.enfileirar(valor);
        } else {
            filaImpar.enfileirar(valor);
        }
    }

    // Processando as filas e manipulando a pilha
    std::cout << "Processando filas...\n";
    bool impar = true;  // Começa pela fila impar

    while (!filaPar.vazia() || !filaImpar.vazia()) {
        if (impar && !filaImpar.vazia()) {
            valor = filaImpar.desenfileirar();
        } else if (!impar && !filaPar.vazia()) {
            valor = filaPar.desenfileirar();
        } else {
            impar = !impar;  // Alterna entre as filas
            continue;
        }

        std::cout << "Elemento processado: " << valor << std::endl;
        
        if (valor > 0) {
            pilha.empilhar(valor);

        } else {
            if (!pilha.vazia()) {
                std::cout << "Desempilhando: " << pilha.desempilhar() << std::endl;
            }
        }
        impar = !impar; 
    }

    // Exibindo a pilha final
    std::cout << "Conteúdo final da pilha: ";
    pilha.exibir();

    return 0;
}