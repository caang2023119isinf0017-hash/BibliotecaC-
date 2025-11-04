#ifndef LIVRO_HPP
#define LIVRO_HPP

#include <string>
using std::string;

class Livro {
private:
    string titulo;
    string autor;
    string isbn;
    string dataPublicacao;
    string categoria;

public:
    Livro(const string& t = "",
          const string& a = "",
          const string& i = "",
          const string& d = "",
          const string& c = "");

    // getters
    string getTitulo() const;
    string getAutor() const;
    string getISBN() const;
    string getDataPublicacao() const;
    string getCategoria() const;
};

#endif // LIVRO_HPP
