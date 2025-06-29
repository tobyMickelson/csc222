#include "member_function.h"
#include <iostream>

void Time::print() {
    std::cout << hour << ":" << minute << ":" << second;
}

void Time::println() {
    print();
    std::cout << std::endl;
}

void Time::incriment(double secs) {
    second += secs;

    while (second >= 60.0) {
        second -= 60.0;
        minute += 1;
    }
    while (minute >= 60) {
        minute -= 60;
        hour += 1;
    }
}

double Time::to_seconds() {
    return second + (minute * 60) + (hour * 60 * 60);
}
