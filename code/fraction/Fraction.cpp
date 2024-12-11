#include "Fraction.h"

using namespace std;

Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(int number) {
    numerator = number;
    denominator = 1;
}

Fraction::Fraction(int numerator, int denominator) {
    int divisor = gcd(numerator, denominator);
    this->numerator = numerator / divisor;
    this->denominator = denominator / divisor;
}

Fraction::Fraction(string fraction) {
    string delimiter = "/";
    if (fraction.find(delimiter) == -1)  {
        numerator = stoi(fraction);
        denominator = 1;
    } else {
        numerator = stoi(fraction.substr(0, fraction.find(delimiter)));
        fraction.erase(0, fraction.find(delimiter) + delimiter.length());
        denominator = stoi(fraction);
    }
}

#warning operator> not implimented
bool Fraction::operator>(Fraction other) {
    return false;
}

bool Fraction::operator==(Fraction other) {
    return numerator == other.numerator && denominator == other.denominator;
}

#warning operator< not implimented
bool Fraction::operator<(Fraction other) {
    return false;
}

bool Fraction::operator!=(Fraction other) {
    return !this->operator==(other);
}

#warning operator>= not implimented
bool Fraction::operator>=(Fraction other) {
    return false;
}

#warning operator<= not implimented
bool Fraction::operator<=(Fraction other) {
    return false;
}

std::string Fraction::toString() {
    if (denominator == 1)
        return to_string(numerator);
    else
        return to_string(numerator) + "/" + to_string(denominator);
}

int gcd(int numerator, int denominator) {
    int remainder = 0;
    while (denominator != 0) {
        remainder = numerator % denominator;

        numerator = denominator;
        denominator = remainder;
    }
    return numerator;
}

