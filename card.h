#ifndef card_h
#define card_h
#include <ctime>
#include <string>
class Card {
public:
  Card(std::string cardName);
  std::string cardName;

private:
  std::string titulo;
  std::string observacao;
  std::time_t date;
};

#endif
