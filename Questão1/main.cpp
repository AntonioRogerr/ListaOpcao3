//Discente: Antonio Roger Sousa de Morais - 202311140022
//Discente: Pedro Ferreira Brandão - 202311140001

#include "Aviao.h"

int main() {
    Pista pista;  // Cria uma pista de decolagem
    int opcao;

    do {
        cout << "\n--- Controle de Pista de Decolagem ---\n";
        cout << "1. Listar o número de aviões aguardando na fila\n";
        cout << "2. Autorizar decolagem do primeiro avião\n";
        cout << "3. Adicionar um avião à fila\n";
        cout << "4. Listar todos os aviões na fila\n";
        cout << "5. Exibir características do primeiro avião\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Aviões na fila de espera: " << pista.totalAvioes() << endl;
                break;
            case 2:
                pista.autorizarDecolagem();
                break;
            case 3: {
                int id;
                string nome;
                cout << "Digite o ID do avião: ";
                cin >> id;
                cout << "Digite o nome do avião: ";
                cin >> nome;
                Aviao* novoAviao = new Aviao(id, nome);
                pista.adicionarAviao(novoAviao);
                cout << "Avião adicionado à fila." << endl;
                break;
            }
            case 4:
                pista.listarAvioes();
                break;
            case 5:
                pista.exibirPrimeiro();
                break;
            case 0:
                cout << "Encerrando o programa..." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
        }

    } while (opcao != 0);

    return 0;
}
