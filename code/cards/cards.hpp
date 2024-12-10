#pragma once

#include <string>
#include <vector>

namespace Cards {

enum Suits { Clubs, Diamonds, Hearts, Spades };

enum Numbers {
  Joker,
  Ace,
  Two,
  Three,
  Four,
  Five,
  Six,
  Seven,
  Eight,
  Nine,
  Ten,
  Jack,
  Queen,
  King
};

class Card {
public:
  enum Suits suit;
  enum Numbers number;

  Card(Suits, Numbers);

  bool operator==(const Card &);
  bool operator>(const Card &);
  bool operator<=(const Card &);
  bool operator<(const Card &);
  bool operator>=(const Card &);

  std::string to_string();
};

std::vector<Card> build_deck();
std::string deck_to_string(std::vector<Card>);
void print_deck(std::vector<Card>);
int find_card_in_deck(std::vector<Card>, Card);
int binary_search_deck(std::vector<Card>, Card);
int binary_search_deck_between(std::vector<Card>, Card, int, int);
} // namespace Card
