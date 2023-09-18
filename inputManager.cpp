#include "inputManager.h"

#include <ncurses.h>
InputManager::InputManager(Database *db) : db(db) {}

InputManager::~InputManager() {}

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
      ProcessInput(ch);
    } else {
      ProcessEditInput(ch);
    }
  }
}
void InputManager::ProcessInput(int ch) {
  switch (ch) {
  case KEY_UP:
    db->MoveUp();
    break;
  case KEY_DOWN:
    db->MoveDown();
    break;
  case KEY_LEFT:
    db->MoveLeft();
    break;
  case KEY_RIGHT:
    db->MoveRight();
    break;
  }
}
void InputManager::ProcessEditInput(int ch) {
  switch (ch) {
  case KEY_LEFT:
    db->MoveCardLeft();
    break;
  case KEY_RIGHT:
    db->MoveCardRight();
    break;
  }
}
int InputManager::GetNextInput() {
  if (inputBuffer.empty()) {
    return -1;
  }
  int ch = inputBuffer.front();
  inputBuffer.pop();
  return ch;
}
