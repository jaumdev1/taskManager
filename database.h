#ifndef database_h
#define database_h

#include "session.h"
#include <curses.h>
#include <string>
#include <vector>

class Database {
public:
  Database(std::string nome, std::string email);
  void createSessions();
  void newSession(std::string sessionName);
  void addCardToSession(std::string sessionName, std::string cardName);
  void render();
  std::string nome;
  void MoveUp();
  void MoveDown();
  void MoveLeft();
  void MoveRight();
  void MoveCardRight();
  void MoveCardLeft();
  WINDOW *window;

private:
  std::string email;
  std::vector<Session *> sessions;
  int sessaoSelecionada;
  int cardSelecionado;
};

#endif
