#ifndef SESSION_H
#define SESSION_H

#include "card.h"
#include <string>
#include <vector>

class Session {
 public:
  Session(std::string sessionName);
  ~Session();
  void addCard(std::string cardName, std::string titulo, std::string observacao,
               std::time_t date);
  void render(int startX, int startY, int width, int height);
  std::string nome;
  std::vector<Card *> cards;

 private:
};

#endif
