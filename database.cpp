#include "database.h"
#include <iostream>
#include <ncurses.h>
#include <ostream>

Database::Database(std::string nome, std::string email)
    : nome(nome), email(email) {
  createSessions();
}

void Database::createSessions() {
  Session *newSession1 = new Session("To do");
  Session *newSession2 = new Session("Doing");
  Session *newSession3 = new Session("Done");

  sessions.push_back(newSession1);
  sessions.push_back(newSession2);
  sessions.push_back(newSession3);
}

void Database::newSession(std::string sessionName) {
  sessions.push_back(new Session(sessionName));
}

void Database::addCardToSession(std::string sessionName, std::string cardName) {
  for (auto session : sessions) {
    if (session->nome == sessionName) {
      session->addCard(cardName);
      break;
    }
  }
}

void Database::render() {
  std::cout << "render datatebase" << std::endl;
  initscr();
  noecho();
  cbreak();
  curs_set(0); // Esconde o cursor

  int altura, largura;
  getmaxyx(stdscr, altura, largura);
  int largura_secao = largura / sessions.size();
  int altura_borda = 2;

  for (int i = 0; i < sessions.size(); ++i) {
    mvvline(0, (i + 1) * largura_secao, ACS_VLINE, altura);
    std::string sessionName = sessions[i]->nome;
  }
  for (int i = 0; i < sessions.size(); ++i) {

    int startX = i * largura_secao;
    int width = largura_secao;
    int height = altura;
    mvprintw(i, width / 2 - sessions[i]->nome.length() / 2, "nome session tes");
    // Renderiza a sessão atual
    sessions[i]->render(startX, 0, width, height);
  }

  getch();
  endwin();
}
