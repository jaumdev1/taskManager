#include "inputManager.h"
#include <ncurses.h>

InputManager::InputManager(Database *db) : db(db) {}

InputManager::~InputManager() { delete db; }

void InputManager::StartInputThread() {
  pthread_create(&inputThreadID, nullptr, InputThreadWrapper, this);
}

void *InputManager::InputThreadWrapper(void *data) {
  InputManager *inputManager = static_cast<InputManager *>(data);
  inputManager->InputThread();
  return nullptr;
}

void InputManager::InputThread() {
  initscr();
  cbreak();

  bool navegationMode = true;
  bool commandLine = false;
  while (true) {
    keypad(stdscr, TRUE);
    int ch = getch();

    if (!commandLine) {
      switch (ch) {
      case 'n':
        navegationMode = true;
        break;
      case 27:
        navegationMode = false;
        break;
      }
    }
    // comandline
    if (ch == KEY_F(1))
      commandLine = !commandLine;

    if (commandLine) {
      InputManager::notifyObserversCommand(ch);
    } else {
      if (navegationMode)
        InputManager::notifyObservers(ch);
      else
        InputManager::notifyObserversEditMode(ch);
    }
  }
}
