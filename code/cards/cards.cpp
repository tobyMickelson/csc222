#include "cards.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace Cards;

Card::Card(Suits suit, enum Numbers number) {
  this->suit = suit;
  this->number = number;
}

bool Card::operator==(const Card &other) {
  return (suit == other.suit && number == other.number);
}

bool Card::operator>(const Card &other) {
  if (suit > other.suit)
    return true;
  if (suit < other.suit)
    return false;
  if (number > other.number)
    return true;
  if (number < other.number)
    return false;
  return false;
}

bool Card::operator<=(const Card &other) { return !this->operator>(other); }

bool Card::operator<(const Card &other) {
  if (suit > other.suit)
    return false;
  if (suit < other.suit)
    return true;
  if (number > other.number)
    return false;
  if (number < other.number)
    return true;
  return false;
}

bool Card::operator>=(const Card &other) { return !this->operator>(other); }

std::string Card::to_string() {
  std::string name = "";

  switch (number) {

  case Joker:
    name += "Joker";
    break;
  case Ace:
    name += "Ace";
    break;
  case Two:
    name += "Two";
    break;
  case Three:
    name += "Three";
    break;
  case Four:
    name += "Four";
    break;
  case Five:
    name += "Five";
    break;
  case Six:
    name += "Six";
    break;
  case Seven:
    name += "Seven";
    break;
  case Eight:
    name += "Eight";
    break;
  case Nine:
    name += "Nine";
    break;
  case Ten:
    name += "Ten";
    break;
  case Jack:
    name += "Jack";
    break;
  case Queen:
    name += "Queen";
    break;
  case King:
    name += "King";
    break;
  }

  name += " of ";

  switch (suit) {
  case Clubs:
    name += "Clubs";
    break;
  case Diamonds:
    name += "Diamonds";
    break;
  case Hearts:
    name += "Hearts";
    break;
  case Spades:
    name += "Spades";
    break;
  }

  return name;
}

std::vector<Card> Cards::build_deck() {
  std::vector<Card> deck = std::vector<Card>();

  for (int suit = 0; suit < 4; suit++)
    for (int number = 1; number <= 13; number++)
      deck.push_back(
          Card(static_cast<Suits>(suit), static_cast<Numbers>(number)));

  return deck;
}

std::string Cards::deck_to_string(std::vector<Card> deck) {
  std::string output = "";

  if (deck.empty())
    return "";

  for (int index = 0; index < deck.size(); index++)
    output += deck[index].to_string() + ", ";

  deck.pop_back();
  deck.pop_back();

  return output;
}

void Cards::print_deck(std::vector<Card> deck) {
  std::cout << deck_to_string(deck) << std::endl;
}

int Cards::find_card_in_deck(std::vector<Card> deck, Card card) {
  for (int index = 0; index < deck.size(); index++)
    if (deck[index] == card)
      return index;

  return -1;
}

int Cards::binary_search_deck(std::vector<Card> deck, Card card) {
  return binary_search_deck_between(deck, card, 0, deck.size());
}

int Cards::binary_search_deck_between(std::vector<Card> deck, Card card,
                                      int low, int high) {
  if (low > high)
    return -1;

  int middle = (high + low) / 2;

  if (deck[middle] == card)
    return middle;

  if (deck[middle] > card)
    return binary_search_deck_between(deck, card, low, middle - 1);
  else
    return binary_search_deck_between(deck, card, middle + 1, high);
}
