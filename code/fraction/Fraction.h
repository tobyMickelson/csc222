#ifndef CSC_222_FRACTION_H
#define CSC_222_FRACTION_H

#include <string>

class Fraction {
    public:
        int numerator;
        int denominator;

        Fraction();
        Fraction(int number);
        Fraction(int numerator, int denominator);
        Fraction(std::string fraction);

        bool operator>(const Fraction other) const;
        bool operator==(const Fraction other) const;
        bool operator<(const Fraction other) const;
        bool operator!=(const Fraction other) const;
        bool operator>=(const Fraction other) const;
        bool operator<=(const Fraction other) const;
        Fraction operator+(const Fraction other) const;
        Fraction operator-(const Fraction other) const;
        Fraction operator*(const Fraction other) const;
        Fraction operator/(const Fraction other) const;

        std::string toString();
};

int gcd(int, int);


#endif //CSC_222_FRACTION_H
