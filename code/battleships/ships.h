#pragma once
#include <string>
using namespace std;

struct Ship {
    //vars
    int x, y;
    int length;
    bool is_up;
    vector<bool> exploded_bits;

    //constructors
    Ship(int, int, int, bool);

    //method functions (this is definatnly the correct name)
    bool explode(int, int);
    
//i wrote this
};
