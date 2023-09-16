#include "database.h"
#include <iostream>

Database::Database(std::string nome, std::string email) : nome(nome), email(email) {

         }
void Database::exibir() {
    std::cout << "Nome: " << nome << "\n";
    std::cout << "Email: " << email << "\n";
 }
