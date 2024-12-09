#pragma once
#include <string>
#include <vector>

struct Ship {
    //vars
    int x, y;
    int length;
    bool is_up;
    std::vector<bool> exploded_bits;

    //constructors
    Ship(int, int, int, bool);

    //method functions (this is definatnly the correct name)
    bool explode(int, int);
    
    //i [alessandra,] wrote this
};
