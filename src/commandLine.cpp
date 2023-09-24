#include "commandLine.h"
#include <curses.h>
#include <string>

CommandLine::CommandLine() {}

void CommandLine::render(int startX, int startY, int width, int height) {
  this->win = newwin(height, width, startY, startX);
  werase(win);
  box(win, 0, 0);
  mvwprintw(win, 1, 1, this->textCommand.c_str());

  wrefresh(win);
}

bool startsWith(const std::string &str, const std::string &prefix) {
  return str.substr(0, prefix.length()) == prefix;
}

void CommandLine::InputEvent(int ch) {
  if (ch == '\n') {
    if (startsWith(textCommand, ":add")) {
      std::string Idsession = textCommand.substr(4 + textCommand.length());
    }
    textCommand.clear();
  }
  if (ch == KEY_BACKSPACE || ch == 127 || ch == 8) {
    if (!textCommand.empty()) {
      textCommand.pop_back();
    }
  } else {
    textCommand += static_cast<char>(ch);
  }
}
