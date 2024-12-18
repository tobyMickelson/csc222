#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "Cards.h"
using namespace std;

TEST_CASE("Test can create and render Cards") {
    Card c1(Suit::Diamonds, Rank::Jack);
    CHECK(c1.to_string() == "Jack of Diamonds");
    Card c2;
    CHECK(c2.to_string() == "Joker");
    Card c3(Suit::Hearts, Rank::Queen);
    CHECK(c3.to_string() == "Queen of Hearts");
    Card c4(Suit::Spades, Rank::Seven);
    CHECK(c4.to_string() == "7 of Spades");
}

TEST_CASE("Test for comparison of Cards") {
    Card c1(Hearts, Queen);
    Card c2(Hearts, Queen);
    Card c3(Spades, Ace);
    Card c4(Hearts, Five);
    Card c5(Hearts, Four);
    Card c6(Diamonds, Four);
    CHECK((c1 == c2) == true);
    CHECK((c1 == c3) == false);
    CHECK((c1 > c5) == true);
    CHECK((c1 <= c5) == false);
}
