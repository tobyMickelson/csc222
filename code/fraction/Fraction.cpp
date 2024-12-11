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

bool Fraction::operator>(Fraction other) {
    return this->numerator * other.denominator > other.numerator * this->denominator;
}

bool Fraction::operator==(Fraction other) {
    return this->numerator * other.denominator == other.numerator * this->denominator;
}

bool Fraction::operator<(Fraction other) {
    return this->numerator * other.denominator < other.numerator * this->denominator;
}

bool Fraction::operator!=(Fraction other) {
    return this->numerator * other.denominator != other.numerator * this->denominator;
}

bool Fraction::operator>=(Fraction other) {
    return this->numerator * other.denominator >= other.numerator * this->denominator;
}

bool Fraction::operator<=(Fraction other) {
    return this->numerator * other.denominator <= other.numerator * this->denominator;
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

