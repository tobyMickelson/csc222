//
// Created by jake on 12/17/2024.
//

#include "Cards.h"

Card::Card() {
    suit = Suit::None;
    rank = Rank::Joker;
}

Card::Card(Suit suit, Rank rank) {
    this->suit = suit;
    this->rank = rank;
}

std::string Card::to_string() {
    return rankStrings[rank] + ((suit == Suit::None) ? "" : (" of " + suitStrings[suit]));
}

bool const Card::operator==(const Card other) {
    return this->suit == other.suit && this->rank == other.rank;
}

bool const Card::operator!=(const Card other) {
    return !(*this == other);
}

bool const Card::operator<(const Card other) {
    if (this->suit != other.suit)
        return this->suit < other.suit;
    return this->rank < other.rank;
}

bool const Card::operator>(const Card other) {
    if (this->suit != other.suit)
        return this->suit > other.suit;
    return this->rank > other.rank;
}

bool const Card::operator<=(const Card other) {
    return !(*this > other);
}

bool const Card::operator>=(const Card other) {
    return !(*this < other);
}

