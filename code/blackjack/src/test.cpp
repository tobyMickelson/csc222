#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include "cards.hpp"
#include "prettycli.hpp"
#include "logic.hpp"


TEST_CASE("Test creation of game from state") {
  std::vector<std::vector<Card> > state;
  std::vector<Card> hand;
  hand.push_back(Card(Spades, Ace));
  state.push_back(hand);

  Blackjack game = Blackjack(state);

  CHECK(pretty_to_string(game.players) == "A♠");
}

TEST_CASE("Test hitting") {
  Blackjack game = Blackjack(2);
  int prev_len = pretty_to_string(game.players).length();
  game.hit(std::vector<bool> (2, true));
  CHECK(pretty_to_string(game.players).length() > prev_len);
}
