#pragma once

#include <vector>
#include "cards.hpp"


struct Blackjack {
  std::vector<std::vector<Card> > players;
  std::vector<Card> deck;
  std::vector<int> scores;

  Blackjack(int players);
  void hit(std::vector<bool> hits);
  int player_total(int player);
};
