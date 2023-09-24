#ifndef InputObserver_H
#define InputObserver_H

class InputObserver {
 public:
  InputObserver();
  virtual void onInputEvent(int input);
  virtual void onInputEventEditMode(int input);
  virtual void onInputEventCommand(int input);
};
#endif
