#include "database.h"
#include "inputManager.h"
#include <iostream>
int main() {
  std::cout << "start main";

  Database *meuBancoDeDados =
      new Database("Nome do Banco de Dados", "email@exemplo.com");
  InputManager *inputManager = new InputManager(meuBancoDeDados);

  inputManager->addObserver(meuBancoDeDados);
  meuBancoDeDados->addCardToSession("To do", "Fazer tarefa 1");
  meuBancoDeDados->addCardToSession("To do", "Fazer tarefa 2");

  meuBancoDeDados->addCardToSession("Doing", "Trabalhar na tarefa 3");

  meuBancoDeDados->addCardToSession("Done", "Concluir tarefa 4");

  inputManager->StartInputThread();

  meuBancoDeDados->render();

  return 0;
}
