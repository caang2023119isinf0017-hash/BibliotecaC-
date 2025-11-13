#include <iostream>
#include <string>
#include "biblioteca.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    Biblioteca biblioteca;
    int opcao;
    string titulo, autor, isbn, data, categoria;

    do {
        cout << "\n===== MENU BIBLIOTECA =====" << endl;
        cout << "1. Cadastrar livro" << endl;
        cout << "2. Remover livro pelo ISBN" << endl;
        cout << "3. Listar livros" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        if (!(cin >> opcao)) {
            cout << "Entrada inválida. Tente novamente." << endl;
            return 0;
        }
        cin.ignore(); // limpar newline

        switch (opcao) {
        case 1:
            cout << "Título: ";
            std::getline(cin, titulo);
            cout << "Autor: ";
            std::getline(cin, autor);
            cout << "ISBN: ";
            std::getline(cin, isbn);
            cout << "Data de publicação: ";
            std::getline(cin, data);
            cout << "Categoria: ";
            std::getline(cin, categoria);

            biblioteca.adicionarLivro(titulo, autor, isbn, data, categoria);
            break;

        case 2:
            cout << "Digite o ISBN do livro para remover: ";
            std::getline(cin, isbn);
            biblioteca.removerLivro(isbn);
            break;

        case 3:
            biblioteca.listarLivros();
            break;

        case 0:
            cout << "Saindo..." << endl;
            break;

        default:
            cout << "Opção inválida!" << endl;
        }

    } while (opcao != 0);

    return 0;
}

