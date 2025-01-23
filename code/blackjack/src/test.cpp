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

TEST_CASE("Test scores vector") {
  std::vector<std::vector<Card> > state;
  std::vector<Card> hand0;
  hand0.push_back(Card(Spades, Queen));
  hand0.push_back(Card(Hearts, Seven));
  state.push_back(hand0);
  std::vector<Card> hand1;
  hand1.push_back(Card(Clubs, Ten));
  hand1.push_back(Card(Diamonds, Two));
  state.push_back(hand1);


  Blackjack game = Blackjack(state);

  CHECK(pretty_to_string(game.players) == "Q♠ 7♥   :   10♣ 2♦");
  CHECK(game.scores[0] == 17);
  CHECK(game.scores[1] == 12);
}
