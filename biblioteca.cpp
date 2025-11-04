#include "biblioteca.hpp"
#include <iostream>

using std::cout;
using std::endl;

Biblioteca::Biblioteca()
    : livros(nullptr), tamanho(0), capacidade(0) {}

// destrutor: liberar cada Livro e o array
Biblioteca::~Biblioteca() {
    if (livros != nullptr) {
        for (int i = 0; i < tamanho; ++i) {
            delete livros[i];
        }
        delete[] livros;
    }
}

void Biblioteca::redimensionar(int novaCapacidade) {
    if (novaCapacidade <= capacidade) return;

    Livro** novo = new Livro*[novaCapacidade];
    for (int i = 0; i < tamanho; ++i) {
        novo[i] = livros[i]; // copiar ponteiros
    }
    // inicializar o restante com nullptr (opcional)
    for (int i = tamanho; i < novaCapacidade; ++i) novo[i] = nullptr;

    delete[] livros;
    livros = novo;
    capacidade = novaCapacidade;
}

int Biblioteca::indicePorISBN(const string& isbn) const {
    for (int i = 0; i < tamanho; ++i) {
        if (livros[i] != nullptr && livros[i]->getISBN() == isbn) return i;
    }
    return -1;
}

void Biblioteca::adicionarLivro(const string& titulo,
                                const string& autor,
                                const string& isbn,
                                const string& data,
                                const string& categoria) {
    // impedir duplicata pelo ISBN
    if (indicePorISBN(isbn) != -1) {
        cout << "Já existe um livro com esse ISBN na biblioteca." << endl;
        return;
    }

    if (capacidade == 0) {
        redimensionar(2);
    } else if (tamanho >= capacidade) {
        redimensionar(capacidade * 2);
    }

    livros[tamanho] = new Livro(titulo, autor, isbn, data, categoria);
    ++tamanho;
    cout << "Livro adicionado com sucesso!" << endl;
}

void Biblioteca::removerLivro(const string& isbn) {
    int idx = indicePorISBN(isbn);
    if (idx == -1) {
        cout << "Livro com esse ISBN não encontrado!" << endl;
        return;
    }

    // apagar o objeto Livro
    delete livros[idx];

    // mover elementos para preencher o buraco (shift left)
    for (int i = idx; i < tamanho - 1; ++i) {
        livros[i] = livros[i + 1];
    }
    livros[tamanho - 1] = nullptr;
    --tamanho;

    cout << "Livro removido com sucesso!" << endl;

    // opcional: reduzir capacidade se muito espaço ocioso
    if (tamanho > 0 && tamanho <= capacidade / 4) {
        int novaCap = capacidade / 2;
        if (novaCap < 2) novaCap = 2;
        // realoca para novaCap apenas se for menor que capacidade atual
        if (novaCap < capacidade) {
            Livro** novo = new Livro*[novaCap];
            for (int i = 0; i < tamanho; ++i) novo[i] = livros[i];
            for (int i = tamanho; i < novaCap; ++i) novo[i] = nullptr;
            delete[] livros;
            livros = novo;
            capacidade = novaCap;
        }
    }
}

void Biblioteca::listarLivros() const {
    if (tamanho == 0) {
        cout << "Nenhum livro cadastrado." << endl;
        return;
    }

    cout << "\nLivros na biblioteca:\n";
    for (int i = 0; i < tamanho; ++i) {
        const Livro* l = livros[i];
        cout << "\nLivro " << (i + 1) << ":\n";
        cout << "Título: " << l->getTitulo() << endl;
        cout << "Autor: " << l->getAutor() << endl;
        cout << "ISBN: " << l->getISBN() << endl;
        cout << "Data de Publicação: " << l->getDataPublicacao() << endl;
        cout << "Categoria: " << l->getCategoria() << endl;
    }
}
