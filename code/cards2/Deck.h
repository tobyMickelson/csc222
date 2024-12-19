//
// Created by jake on 12/19/2024.
//

#ifndef CSC_222_DECK_H
#define CSC_222_DECK_H

#include <vector>
#include "Cards.h"


class Deck : public std::vector<Card> {
    public:
        Deck();
        Deck(int numCards);
        Deck(Card * start, Card * end);

        int find(Card card);

        void swap_cards(int index1, int index2);
        void shuffle();
        Card remove_card();
        void add_card(Card card);
        Deck subdeck(size_t start, size_t end);
};

void swap_cards(Card * a, Card * b);


#endif //CSC_222_DECK_H

