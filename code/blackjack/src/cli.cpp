#include <algorithm>
#include <iostream>
#include <vector>
#include "cards.hpp"
#include "logic.hpp"


void cheap_print(std::vector<std::vector<Card> > players) {
  for (std::vector<Card> player : players) {
    for (Card card : player)
      std::cout << card.initials() << " ";
    std::cout << " :  ";
  }
  std::cout << std::endl;
}

std::vector<bool> cheap_hit() {
  std::vector<bool> hits;
  char character;
  bool do_loop = true;
  
  while (do_loop) {
    std::cin >> character;
    switch (character) {
      case '1':
      case 'Y':
      case 'y':
        hits.push_back(true);
        break;
      case '\n':
      case ';':
        do_loop = false;
        break;
      default:
        hits.push_back(false);
    }
  }

  return hits;
}

void run_cheap_cli(int players) {
  Blackjack game = Blackjack(players);
  std::vector<bool> hits;

  while (true) {
    cheap_print(game.players);
    hits = cheap_hit();
    if (std::none_of(hits.begin(), hits.end(), [](bool b) {return b;}))
      break;
  }
}
