#pragma once

#include <string>
#include <vector>
#include "cards.hpp"


struct Blackjack {
  std::vector<std::vector<Card> > players;
  std::vector<Card> deck;
  std::vector<int> scores;

  bool error;
  std::string error_message;

  Blackjack(int players);
  Blackjack(std::vector<std::vector<Card> > state);
  void hit(std::vector<bool> hits);
  int player_total(int player);
};
