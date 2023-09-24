#ifndef COMMANDLINE_H
#define COMMANDLINE_
#include <ncurses.h>
#include <string>

class CommandLine {
 public:
  CommandLine();
  void render(int startX, int startY, int width, int height);
  void InputEvent(int ch);
  WINDOW *win;

 private:
  std::string textCommand;
};
#endif
