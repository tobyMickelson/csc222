#include <vector>
#include "cards.hpp"
#include "logic.hpp"


Blackjack::Blackjack(int players) {
  if (players < 2) {
    error_message = "ERROR: GAME CANNOT BE PLAYED WITH FEWER THAN TWO PLAYERS";
    error = true;
    players = 1;
  };

  deck = shuffle(new_deck());

  for (int player = 0; player < players; player++) {
    std::vector<Card> hand;
    hand.push_back(deck.back()); deck.pop_back();
    hand.push_back(deck.back()); deck.pop_back();
    this->players.push_back(hand);
    scores.push_back(player_total(player));
  }
}

Blackjack::Blackjack(std::vector<std::vector<Card> > state) {
  for (std::vector<Card> hand : state)
    players.push_back(hand);
}

void Blackjack::hit(std::vector<bool> hits) {
  if (hits.size() != players.size()) {
    error_message = "ERROR: NUMBER OF HITS MUST EQUAL THE NUMBER OF PLAYERS";
    error = true;
    for (bool item : hits)
      hits.pop_back();
    for (int player = 0; player < players.size(); player++)
      hits.push_back(false);
  }

  for (int player = 0; player < players.size(); player++) {
    if (hits[player] && (player_total(player) <= 21)) {
      players[player].push_back(deck.back());
      deck.pop_back();
    }

    scores[player] = player_total(player);
  }
}

int Blackjack::player_total(int player) {
  int total = 0;

  for (Card card : players[player]) {
    switch (card.rank) {
      case Ace:
        total += 1;
        break;
      case Two:
        total += 2;
        break;
      case Three:
        total += 3;
        break;
      case Four:
        total += 4;
        break;
      case Five:
        total += 5;
        break;
      case Six:
        total += 6;
        break;
      case Seven:
        total += 7;
        break;
      case Eight:
        total += 8;
        break;
      case Nine:
        total += 9;
        break;
      case Ten:
      case Jack:
      case Queen:
      case King:
        total += 10;
        break;
    }
  }

  return total;
}
