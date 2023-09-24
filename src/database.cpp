#include "database.h"
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <ncurses.h>
#include <ostream>

Database::Database(std::string nome, std::string email)
    : nome(nome), email(email) {
  createSessions();
  sessaoSelecionada = 0;
  cardSelecionado = 0;
  this->commandLine = new CommandLine();
}

Database::~Database() {}

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

void Database::addCardToSession(std::string sessionName, std::string cardName,
                                std::string titulo, std::string observacao,
                                std::time_t date) {
  for (auto session : sessions) {
    if (session->nome == sessionName) {
      session->addCard(cardName, titulo, observacao, date);
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
  sessions[sessaoSelecionada]->cards[cardSelecionado]->selecionado = false;

  NextSession(KEY_LEFT);

  cardSelecionado = 0;
  sessions[sessaoSelecionada]->cards[cardSelecionado]->selecionado = true;
}

void Database::MoveRight() {
  sessions[sessaoSelecionada]->cards[cardSelecionado]->selecionado = false;

  NextSession(KEY_RIGHT);
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

  sessions[sessaoSelecionada]->cards.erase(
      sessions[sessaoSelecionada]->cards.begin() + cardSelecionado);

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

  sessions[sessaoSelecionada]->cards.erase(
      sessions[sessaoSelecionada]->cards.begin() + cardSelecionado);

  sessaoSelecionada--;
  if (sessaoSelecionada >= sessions.size()) {
    sessaoSelecionada = 0;
  }

  sessions[sessaoSelecionada]->cards.push_back(card);
  int positionCardSelected = sessions[sessaoSelecionada]->cards.size() - 1;
  cardSelecionado = positionCardSelected;
}

void Database::NextSession(int arrowCode) {
  if (arrowCode == KEY_LEFT) {
    do {
      if ((sessaoSelecionada - 1) < 0) {
        sessaoSelecionada = sessions.size() - 1;

      } else {
        sessaoSelecionada--;
      }
    } while (sessions[sessaoSelecionada]->cards.size() == 0);

  } else if (arrowCode == KEY_RIGHT) {
    do {
      if ((sessaoSelecionada + 1) > (sessions.size() - 1)) {
        sessaoSelecionada = 0;

      } else {
        sessaoSelecionada++;
      }
    } while (sessions[sessaoSelecionada]->cards.size() == 0);
  }
}

// method is override
void Database::onInputEvent(int input) {
  switch (input) {
  case KEY_UP:
    MoveUp();
    break;
  case KEY_DOWN:
    MoveDown();
    break;
  case KEY_LEFT:
    MoveLeft();
    break;
  case KEY_RIGHT:
    MoveRight();
    break;
  }
}

// method is override too
void Database::onInputEventEditMode(int input) {
  switch (input) {
  case KEY_LEFT:
    MoveCardLeft();
    break;
  case KEY_RIGHT:
    MoveCardRight();
    break;
  }
}

void Database::onInputEventCommand(int input) {
  commandLine->InputEvent(input);
};

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
      sessions[i]->render(startX, 0, width, (height - 3));
    }
    commandLine->render(0, altura - 3, largura, 3);
    refresh();
  }

  endwin();

  getch();
}
