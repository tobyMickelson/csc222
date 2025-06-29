#pragma once
#include <string>
using namespace std;

struct Time {
    int hours;
    int minutes;
    int seconds;

    Time();
    Time(int);

    string toString();
};
