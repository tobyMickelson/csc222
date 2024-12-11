#include "Fraction.h"
#include "doctest/doctest.h"

using namespace std;

Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(int numerator, int denominator) {
    int divisor = gcd(numerator, denominator);
    this->numerator = numerator / divisor;
    this->denominator = denominator / divisor;
}

Fraction::Fraction(string fraction) {
    string delimiter = "/";
    numerator = stoi(fraction.substr(0, fraction.find(delimiter)));
    fraction.erase(0, fraction.find(delimiter) + delimiter.length());
    denominator = stoi(fraction);
}

std::string Fraction::toString() {
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

