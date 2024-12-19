#include "Deck.h"

#include <algorithm>
#include <random>

Deck::Deck() {
    for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 13; b++) {
            push_back(Card(static_cast<Suit>(a), static_cast<Rank>(b)));
        }
    }
}

Deck::Deck(int numCards) {
    for (int a = 0; a < numCards; a++) {
        push_back(Card(Suit::None, Rank::Joker));
    }
}

int Deck::find(Card card) {
    int index = std::distance(begin(), std::find(begin(), end(), card));
    return (index == 52) ? -1 : index;
}

void Deck::shuffle() {
    std::default_random_engine rng = std::default_random_engine();
    std::shuffle(begin(), end(), rng);
}

void Deck::swap_cards(int index1, int index2) {
    std::swap(this->operator[](index1), this->operator[](index2));
}

Card Deck::remove_card() {
    Card card = back();
    pop_back();
    return card;
}

void Deck::add_card(Card card) {
    push_back(card);
}
