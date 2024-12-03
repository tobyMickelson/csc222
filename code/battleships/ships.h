#pragma once
#include <string>
using namespace std;

enum ship_type {
    motorboat;
    spaceship;
    bob;
    bobi_needs_a_friend;
    matilda;
}

enum ship_rotation {
    horazontal;
    vertical;
}

struct Ship {
    //vars
    int x, y;
    ship_type type;
    ship_rotation rotation;

    //constructors
    Ship(int, int, ship_type, ship_rotation);

    //method functions (this is definatnly the correct name)
    bool explode(int x, int y);
//i wrote this

