#include "database.h"
#include <iostream>
#include <ncurses.h>
#include <ostream>

Database::Database(std::string nome, std::string email)
    : nome(nome), email(email) {
  createSessions();
  sessaoSelecionada = 0;
  cardSelecionado = 0;
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
  // sessions[0]->cards[0]->selecionado = true;
}
void Database::MoveUp() {

  sessions[sessaoSelecionada]->cards[cardSelecionado]->selecionado = false;
  cardSelecionado--;
  if (cardSelecionado < 0) {
    cardSelecionado = sessions[sessaoSelecionada]->cards.size() - 1;
  }
  sessions[sessaoSelecionada]->cards[cardSelecionado]->selecionado = true;
}
void Database::MoveDown() {
  sessions[sessaoSelecionada]->cards[cardSelecionado]->selecionado = false;
  cardSelecionado++;
  if (cardSelecionado >= sessions[sessaoSelecionada]->cards.size()) {
    cardSelecionado = 0;
  }
  sessions[sessaoSelecionada]->cards[cardSelecionado]->selecionado = true;
}
void Database::MoveLeft() {
  if (sessions[sessaoSelecionada]->cards.size() == 0) {
    bool proxSession = false;
    while (!proxSession) {
      sessaoSelecionada--;
      if (sessaoSelecionada >= sessions.size()) {
        sessaoSelecionada = 0;
      }
      if (sessions[sessaoSelecionada]->cards.size() > 0) {
        proxSession = true;
      }
    }
  }
  sessions[sessaoSelecionada]->cards[cardSelecionado]->selecionado = false;
  sessaoSelecionada--;
  if (sessaoSelecionada < 0) {
    sessaoSelecionada = sessions.size() - 1;
  }
  cardSelecionado = 0;
  sessions[sessaoSelecionada]->cards[cardSelecionado]->selecionado = true;
}
void Database::MoveRight() {
  if (sessions[sessaoSelecionada]->cards.size() == 0) {
    bool proxSession = false;
    while (!proxSession) {
      sessaoSelecionada++;
      if (sessaoSelecionada >= sessions.size()) {
        sessaoSelecionada = 0;
      }
      if (sessions[sessaoSelecionada]->cards.size() > 0) {
        proxSession = true;
      }
    }
  }

  sessions[sessaoSelecionada]->cards[cardSelecionado]->selecionado = false;
  sessaoSelecionada++;
  if (sessaoSelecionada >= sessions.size()) {
    sessaoSelecionada = 0;
  }
  cardSelecionado = 0;
  sessions[sessaoSelecionada]->cards[cardSelecionado]->selecionado = true;
}
void Database::MoveCardRight() {
  if (sessions[sessaoSelecionada]->cards.size() == 0) {
    bool proxSession = false;
    while (!proxSession) {
      sessaoSelecionada++;
      if (sessaoSelecionada >= sessions.size()) {
        sessaoSelecionada = 0;
      }
      if (sessions[sessaoSelecionada]->cards.size() > 0) {
        proxSession = true;
      }
    }
  }

  Card *card = sessions[sessaoSelecionada]->cards[cardSelecionado];
  sessions[sessaoSelecionada]->cards[cardSelecionado] = nullptr;
  sessaoSelecionada++;
  if (sessaoSelecionada >= sessions.size()) {
    sessaoSelecionada = 0;
  }

  sessions[sessaoSelecionada]->cards.push_back(card);
  int positionCardSelected = sessions[sessaoSelecionada]->cards.size() - 1;
  cardSelecionado = positionCardSelected;
}
void Database::MoveCardLeft() {
  if (sessions[sessaoSelecionada]->cards.size() == 0) {
    bool proxSession = false;
    while (!proxSession) {
      sessaoSelecionada--;
      if (sessaoSelecionada >= sessions.size()) {
        sessaoSelecionada = 0;
      }
      if (sessions[sessaoSelecionada]->cards.size() > 0) {
        proxSession = true;
      }
    }
  }

  Card *card = sessions[sessaoSelecionada]->cards[cardSelecionado];
  sessions[sessaoSelecionada]->cards[cardSelecionado] = nullptr;
  sessaoSelecionada--;
  if (sessaoSelecionada >= sessions.size()) {
    sessaoSelecionada = 0;
  }

  sessions[sessaoSelecionada]->cards.push_back(card);
  int positionCardSelected = sessions[sessaoSelecionada]->cards.size() - 1;
  cardSelecionado = positionCardSelected;
}

void Database::render() {

  initscr();
  noecho();
  cbreak();
  curs_set(0);

  int altura, largura;
  getmaxyx(stdscr, altura, largura);
  int largura_secao = largura / sessions.size();
  int altura_borda = 2;

  while (1) {

    for (int i = 0; i < sessions.size(); ++i) {
      int startX = i * largura / sessions.size();
      int width = largura / sessions.size();
      int height = altura;
      sessions[i]->render(startX, 0, width, height);
    }
    refresh();
  }

  endwin();

  getch();
}
