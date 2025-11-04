#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include <string>
#include "livro.hpp"
using std::string;

class Biblioteca {
private:
    Livro** livros;     // array de ponteiros para Livro
    int tamanho;        // número atual de livros
    int capacidade;     // capacidade do array

    void redimensionar(int novaCapacidade);

    // retorna índice do livro com o ISBN; -1 se não encontrado
    int indicePorISBN(const string& isbn) const;

public:
    Biblioteca();
    ~Biblioteca();

    // proibir cópia simples (para segurança)
    Biblioteca(const Biblioteca&) = delete;
    Biblioteca& operator=(const Biblioteca&) = delete;

    void adicionarLivro(const string& titulo,
                        const string& autor,
                        const string& isbn,
                        const string& data,
                        const string& categoria);

    void removerLivro(const string& isbn);

    void listarLivros() const;

    int obterTamanho() const { return tamanho; }
};

#endif // BIBLIOTECA_HPP
