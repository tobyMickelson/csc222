#pragma once

struct Time {
    int hour;
    int minute;
    double second;

    void print();
    void println();
    void incriment(double);
    double to_seconds();
};
