#include "cards.hpp"
#include <iostream>
#include <vector>

using namespace Cards;

int main() {
  std::vector<Card> deck = build_deck();
  print_deck(deck);
  std::cout << Card(Spades, Ace).to_string() << std::endl;
  std::cout << find_card_in_deck(build_deck(), Card(Hearts, Queen)) << std::endl;
  std::cout << binary_search_deck(build_deck(), Card(Hearts, Queen)) << std::endl;
  return 0;
}
