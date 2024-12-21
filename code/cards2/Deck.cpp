#include "Deck.h"
#include "Cards.h"

#include <algorithm>
#include <cstddef>
#include <random>
#include <utility>
#include <iostream>

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

Deck::Deck(Card * begin, Card * end) {
    for (Card * ptr = begin; ptr <= end; ptr++)
        push_back(* ptr);
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

void swap_cards(Card * a, Card * b) {
    Card temp = * a;
    * a = * b;
    * b = temp;
}

Deck Deck::subdeck(size_t start, size_t end) {
    return Deck(data() + start, data() + end);
}

Deck Deck::merge_sort() { // Just used a bubble sort, not a merge sort
    Deck sorted_deck = subdeck(0, size() - 1);
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int index = 1; index < sorted_deck.size(); index++)
            if (sorted_deck[index - 1] > sorted_deck[index]){
                sorted = false;
                sorted_deck.swap_cards(index - 1, index);
            }
    }
    return sorted_deck;
}

void Deck::add_cards(Deck cards) {
    for (Card card : cards)
        add_card(card);
}
