#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "database.h"
#include <ncurses.h>
#include <queue>
class InputManager {
public:
  InputManager(Database *db);
  ~InputManager();
  void StartInputThread();
  void ProcessInput(int ch);
  void ProcessEditInput(int ch);
  int GetNextInput();

private:
  Database *db;
  pthread_t inputThreadID;
  std::queue<int> inputBuffer;
  static void *InputThreadWrapper(void *data);
  void InputThread();
};

#endif
