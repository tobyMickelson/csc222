#pragma once

#include <vector>


enum Suit {
    Spades,
    Diamonds,
    Clubs,
    Hearts
};

enum Rank {
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

struct Card {
    Suit suit;
    Rank rank;

    Card(Suit suit, Rank rank);
};

std::vector<Card> new_deck();
std::vector<Card> shuffle(std::vector<Card> deck);
