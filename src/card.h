#ifndef card_h
#define card_h
#include <ctime>
#include <string>

class Card {
 public:
  Card(std::string cardName, std::string titulo, std::string observacao,
       std::time_t date);
  std::string cardName;
  bool selecionado;
  std::string titulo;
  std::string observacao;
  std::time_t date;

 private:
};

#endif
