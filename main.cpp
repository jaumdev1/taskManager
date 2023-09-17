#include "database.h"
#include <iostream>

int main() {
  std::cout << "start main";
  // Crie uma instância da classe Database
  Database meuBancoDeDados("Nome do Banco de Dados", "email@exemplo.com");
  meuBancoDeDados.render();
  // Adicione cards às sessões existentes
  meuBancoDeDados.addCardToSession("To do", "Fazer tarefa 1");
  meuBancoDeDados.addCardToSession("To do", "Fazer tarefa 2");

  meuBancoDeDados.addCardToSession("Doing", "Trabalhar na tarefa 3");

  meuBancoDeDados.addCardToSession("Done", "Concluir tarefa 4");

  // Renderize as sessões e cards

  return 0;
}
