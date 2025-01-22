#include <algorithm>
#include <chrono>
#include <random>
#include <string>
#include <vector>
#include "cards.hpp"


Card::Card(Suit suit, Rank rank) {
  this->suit = suit;
  this->rank = rank;
}

std::string Card::initials() {
  std::string output = "";

  switch (rank) {
    case Ace:
      output += "A";
      break;
    case Two:
      output += "2";
      break;
    case Three:
      output += "3";
      break;
    case Four:
      output += "4";
      break;
    case Five:
      output += "5";
      break;
    case Six:
      output += "6";
      break;
    case Seven:
      output += "7";
      break;
    case Eight:
      output += "8";
      break;
    case Nine:
      output += "9";
      break;
    case Ten:
      output += "10";
      break;
    case Jack:
      output += "J";
      break;
    case Queen:
      output += "Q";
      break;
    case King:
      output += "K";
      break;
  }

  switch(suit) {

  case Spades:
    output += "♠";
    break;
  case Diamonds:
    output += "♦";
    break;
  case Clubs:
    output += "♣";
    break;
  case Hearts:
    output += "♥";
    break;
  }

  return output;
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

  std::default_random_engine rng = std::default_random_engine(
      std::chrono::system_clock::now().time_since_epoch().count());
  std::shuffle(shuffled.begin(), shuffled.end(), rng);

  return shuffled;
}
