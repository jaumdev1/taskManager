#ifndef inputObservable_h
#define inputObservable_h
#include "inputObserver.h"
#include <vector>

class InputObservable {
 public:
  InputObservable();
  void addObserver(InputObserver *observer);
  void removeObserver(InputObserver *observer);
  void notifyObservers(int input);
  void notifyObserversEditMode(int input);
  void notifyObserversCommand(int input);

 private:
  std::vector<InputObserver *> observers;
};
#endif
