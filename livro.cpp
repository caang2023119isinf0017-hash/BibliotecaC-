#include "livro.hpp"

Livro::Livro(const string& t, const string& a, const string& i, const string& d, const string& c)
    : titulo(t), autor(a), isbn(i), dataPublicacao(d), categoria(c) {}

string Livro::getTitulo() const { return titulo; }
string Livro::getAutor() const { return autor; }
string Livro::getISBN() const { return isbn; }
string Livro::getDataPublicacao() const { return dataPublicacao; }
string Livro::getCategoria() const { return categoria; }
