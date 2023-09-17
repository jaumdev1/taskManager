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
  refresh();
  wprintw(win, nome.c_str());

  int y = 1;
  for (size_t i = 0; i < cards.size(); ++i) {

    if (cards[i]->selecionado == true) {
      wattron(win, A_REVERSE);
      start_color(); // Inicie o modo de cores

      init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    }

    mvwprintw(win, y, 1, cards[i]->cardName.c_str());
    wattroff(win, A_REVERSE);
    y++;
  }

  wrefresh(win);
}
