#include "session.h"
#include "card.h"
#include <ctime>
#include <iostream>
#include <ncurses.h>

Session::Session(std::string sessionName) : nome(sessionName) {}

Session::~Session() {}

void Session::addCard(std::string cardName, std::string titulo,
                      std::string observacao, std::time_t date) {
  cards.push_back(new Card(cardName, titulo, observacao, date));
}

void Session::render(int startX, int startY, int width, int height) {
  WINDOW *win = newwin(height, width, startY, startX);
  werase(win);
  wbkgd(win, COLOR_PAIR(2));
  box(win, 0, 0);
  refresh();
  std::string nomeSession = nome;

  for (char c : nomeSession) {
    wprintw(win, "%c", c);
  }
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_BLUE, COLOR_BLACK);
  int y = 1;
  if (cards.size() > 0) {
    for (size_t i = 0; i < cards.size(); ++i) {
      if (cards[i]) {
        if (cards[i]->selecionado == true) {
          wattron(win, A_REVERSE);
        }
        mvwprintw(win, y, 1, cards[i]->cardName.c_str());
        y++;
        mvwprintw(win, y, 1, cards[i]->titulo.c_str());
        y++;
        mvwprintw(win, y, 1, cards[i]->observacao.c_str());
        y++;
        std::string dateString = ctime(&cards[i]->date);
        mvwprintw(win, y, 1, dateString.c_str());
        y++;
        if (cards[i]->selecionado == true) {
          wattroff(win, A_REVERSE);
        }
        y++;
      }
    }
  }

  wrefresh(win);
}
