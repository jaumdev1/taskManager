#include "card.h"

Card::Card(std::string cardName, std::string titulo, std::string observacao,
           std::time_t date)
    : cardName(cardName), titulo(titulo), observacao(observacao), date(date) {}
