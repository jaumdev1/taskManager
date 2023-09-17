#include "session.h"
#include "card.h"
#include <iostream>
#include <ncurses.h>
Session::Session(std::string sessionName) : nome(sessionName) {}

void Session::addCard(std::string cardName) {
  cards.push_back(new Card(cardName));
}

void Session::render(int startX, int startY, int width, int height) {

  WINDOW *win = newwin(height, width, startY, startX);
  box(win, 0, 0);

  mvprintw(0, width / 2 - nome.length() / 2, "nome session tes");

  int y = 1;
  for (const auto &card : cards) {
    mvwprintw(win, y, 1, card->cardName.c_str());
    y++;
  }

  wrefresh(win);
  delwin(win);
}
