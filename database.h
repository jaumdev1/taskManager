#ifndef database_H
#define database_H

#include <string>

class Database {
public:
    Database(std::string nome, std::string email);

    void exibir();

private:
    std::string nome;
    std::string email;
};

#endif
