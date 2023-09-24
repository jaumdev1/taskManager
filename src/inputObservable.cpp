#include "inputObservable.h"
#include "inputObserver.h"
#include <iostream>
#include <vector>

InputObservable::InputObservable() {}

void InputObservable::addObserver(InputObserver *observer) {
  observers.push_back(observer);
}

void InputObservable::removeObserver(InputObserver *observer) {
  for (auto it = observers.begin(); it != observers.end(); ++it) {
    if (*it == observer) {
      observers.erase(it);
      break;
    }
  }
}

void InputObservable::notifyObservers(int input) {
  for (InputObserver *observer : observers) {
    observer->onInputEvent(input);
  }
}

void InputObservable::notifyObserversEditMode(int input) {
  for (InputObserver *observer : observers) {
    observer->onInputEventEditMode(input);
  }
}

void InputObservable::notifyObserversCommand(int input) {
  for (InputObserver *observer : observers) {
    observer->onInputEventCommand(input);
  }
}
