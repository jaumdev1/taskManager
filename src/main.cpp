#include "database.h"
#include "inputManager.h"
#include <iostream>

int main() {
  std::cout << "start main";
  struct tm date;
  date.tm_year = 2023; // Ano - 1900
  date.tm_mon = 10;    // Mês (0-11)
  date.tm_mday = 10;
  time_t timestamp = mktime(&date);
  Database *meuBancoDeDados =
      new Database("Nome do Banco de Dados", "email@exemplo.com");
  InputManager *inputManager = new InputManager(meuBancoDeDados);

  inputManager->addObserver(meuBancoDeDados);
  meuBancoDeDados->addCardToSession("To do", "task test", "titulo 1",
                                    "obs lorem impsum", timestamp);
  meuBancoDeDados->addCardToSession("To do", "task test e", "titulo 2",
                                    "obs lorem impsum", timestamp);

  meuBancoDeDados->addCardToSession("Doing", "task test", "titulo 3",
                                    "obs lorem impsum, test obs", timestamp);

  meuBancoDeDados->addCardToSession("Done", "task test", "titulo ter",
                                    "obs lorem impsum, test obs", timestamp);
  meuBancoDeDados->addCardToSession("Done", "task test 1", "titulo tEST",
                                    "obs lorem impsum, test obs", timestamp);

  inputManager->StartInputThread();

  meuBancoDeDados->render();

  return 0;
}
