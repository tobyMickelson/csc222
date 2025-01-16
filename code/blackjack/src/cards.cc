#include <algorithm>
#include <random>
#include <vector>
#include "cards.hh"


Card::Card(Suit suit, Rank rank) {
  this->suit = suit;
  this->rank = rank;
}

std::vector<Card> new_deck() {
  std::vector<Card> deck;
  
  for (int suit = 0; suit < 4; suit++)
    for (int rank = 0; rank < 13; rank++)
      deck.push_back(Card(static_cast<Suit>(suit), static_cast<Rank>(rank)));

  return deck;
}

std::vector<Card> shuffle(std::vector<Card> deck) {
  std::vector<Card> shuffled(deck);

  std::default_random_engine rng = std::default_random_engine();
  std::shuffle(shuffled.begin(), shuffled.end(), rng);

  return shuffled;
}
