#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include <string>
#include "Deck.h"
#include "Cards.h"
using namespace std;

TEST_CASE("Test create Deck with two constructors") {
    Deck d1(10);
    CHECK(d1.size() == 10);
    CHECK(d1[0].to_string() == "Joker");
    Deck d2;
    CHECK(d2.size() == 52);
    CHECK(d2[0].to_string() == "2 of Clubs");
    CHECK(d2[51].to_string() == "Ace of Spades");
}

TEST_CASE("Test find Card in Deck") {
    Deck d;
    Card c(Suit::Hearts, Rank::Queen);
    int pos = d.find(c);
    CHECK(d[pos].to_string() == "Queen of Hearts");
    // Create non-existant card to confirm it isn't in the deck
    Card c2(Suit::None, Rank::Queen);
    int pos2 = d.find(c2);
    CHECK(pos2 == -1);
}

TEST_CASE("Test swap_cards in Deck") {
    Deck d;
    d.swap_cards(0, 51);
    CHECK(d[0].to_string() == "Ace of Spades");
    CHECK(d[51].to_string() == "2 of Clubs");
}

TEST_CASE("Test remove_card and add_card") {
    Deck deck;
    deck.shuffle();
    CHECK(deck.size() == 52);
    Card c = deck.remove_card();
    CHECK(deck.size() == 51);
    Deck deck2(0);
    CHECK(deck2.size() == 0);
    deck2.add_card(c);
    CHECK(deck2.size() == 1);
    CHECK((deck2[0] == c) == true);
}

TEST_CASE("Test can swap two random cards") {
    Card c1(Hearts, Queen);
    Card c2(Diamonds, Jack);
    swap_cards(&c1, &c2);
    CHECK(c1.to_string() == "Jack of Diamonds");
    CHECK(c2.to_string() == "Queen of Hearts");
}

TEST_CASE("Test create subdecks") {
    Deck deck;
    Deck subdeck = deck.subdeck(2, 10);
    CHECK(subdeck.size() == 9);
    CHECK(subdeck[0].to_string() == "4 of Clubs");
}
