#include "ships.h"
#include <cstdlib>
using namespace std;

Ship::Ship(int x, int y, int length, bool is_up){
        this -> x = x;
        this -> y = y;
        this -> length = length;
        this -> is_up = is_up;
        exploded_bits = vector<bool>();
        for (int i; i < length; i++)
            exploded_bits.push_back(false);
}

bool Ship::explode(int bx, int by){
    if (is_up && bx == x && (by - y >= 0) && (by - y <= length)) {
        exploded_bits[by - y] = true;
        return true;
    }
    if (!is_up && by == y && (bx - x >= 0) && (bx - x <= length)) {
        exploded_bits[bx - x] = true;
        return true;
    }
    return false;
}
