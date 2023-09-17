#include "database.h"
#include <iostream>
#include <ncurses.h>
#include <ostream>

Database::Database(std::string nome, std::string email)
    : nome(nome), email(email) {
  createSessions();
}
int cardSelecionado = 0;
int sessaoSelecionada = 0;

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

  initscr();
  keypad(stdscr, TRUE);
  noecho();
  cbreak();
  curs_set(0); // Esconde o cursor

  int altura, largura;
  getmaxyx(stdscr, altura, largura);
  int largura_secao = largura / sessions.size();
  int altura_borda = 2;

  while (1) {
    clear();

    for (int i = 0; i < sessions.size(); ++i) {
      int startX = i * largura / sessions.size();
      int width = largura / sessions.size();
      int height = altura;
      sessions[i]->render(startX, 0, width, height);
    }

    int ch = getch();
    switch (ch) {
    case KEY_UP:
      sessions[sessaoSelecionada]->cards[cardSelecionado]->selecionado = false;
      cardSelecionado--;
      if (cardSelecionado < 0) {
        cardSelecionado = sessions[sessaoSelecionada]->cards.size() - 1;
      }
      sessions[sessaoSelecionada]->cards[cardSelecionado]->selecionado = true;
      break;
    case KEY_DOWN:
      sessions[sessaoSelecionada]->cards[cardSelecionado]->selecionado = false;
      cardSelecionado++;
      if (cardSelecionado >= sessions[sessaoSelecionada]->cards.size()) {
        cardSelecionado = 0;
      }
      sessions[sessaoSelecionada]->cards[cardSelecionado]->selecionado = true;
      break;
    case KEY_LEFT:
      sessions[sessaoSelecionada]->cards[cardSelecionado]->selecionado = false;
      sessaoSelecionada--;
      if (sessaoSelecionada < 0) {
        sessaoSelecionada = sessions.size() - 1;
      }
      cardSelecionado = 0;
      sessions[sessaoSelecionada]->cards[cardSelecionado]->selecionado = true;
      break;
    case KEY_RIGHT:
      sessions[sessaoSelecionada]->cards[cardSelecionado]->selecionado = false;
      sessaoSelecionada++;
      if (sessaoSelecionada >= sessions.size()) {
        sessaoSelecionada = 0;
      }
      cardSelecionado = 0;
      sessions[sessaoSelecionada]->cards[cardSelecionado]->selecionado = true;
      break;
    case 27:
      endwin();
    }
  }

  endwin();

  getch();
}
