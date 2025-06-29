#include <string>
#include <iostream>
#include <stdio.h>
#include "time.h"

using namespace std;

Time::Time() {
    hours = 0;
    minutes = 0;
    seconds = 0;
}

Time::Time(int seconds_) {
    hours = 0;
    minutes = 0;
    seconds = seconds_;
}

string Time::toString() {
    string output;

    output += to_string(seconds);
    output += ":";
    if (minutes < 10)
        output += "0";
    output += minutes;
    output += ":";
    if (seconds < 10)
        output += "0";
    output += seconds;

    return output;
}
