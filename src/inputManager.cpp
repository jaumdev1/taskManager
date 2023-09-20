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
  noecho();
  bool navegationMode = true;

  while (true) {
    keypad(stdscr, TRUE);
    int ch = getch();
    if (ch == 'n' && !navegationMode) {
      navegationMode = true;

    } else if (ch == 27 && navegationMode) {
      navegationMode = false;
    }
    if (navegationMode) {
      InputManager::notifyObservers(ch);
    } else if (!navegationMode) {
      InputManager::notifyObserversEditMode(ch);
    }
  }
}
