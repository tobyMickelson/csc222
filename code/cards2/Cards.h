#ifndef CSC_222_CARDS_H
#define CSC_222_CARDS_H

#include <string>

enum Suit {
    Hearts,
    Clubs,
    Diamonds,
    Spades,
    None
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
    King,
    Joker
};

class Card {

    Suit suit;
    Rank rank;

    inline static std::string rankStrings[14] = {
        "Ace",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9",
        "10",
        "Jack",
        "Queen",
        "King",
        "Joker"
    };

    inline static std::string suitStrings[4] = {
        "Hearts",
        "Clubs",
        "Diamonds",
        "Spades"
    };

    public:
        Card();

        Card(Suit suit, Rank rank);

        std::string to_string();
        bool const operator==(const Card other);
        bool const operator!=(const Card other);
        bool const operator<(const Card other);
        bool const operator>(const Card other);
        bool const operator<=(const Card other);
        bool const operator>=(const Card other);
};

#endif //CSC_222_CARDS_H
