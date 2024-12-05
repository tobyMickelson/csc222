#include <string>
#include "ships.h"
//#include <bits/stdc++.h>
#include <vector>
#include <iostream>

using namespace std;

void loop();

int main(){
    while (1) loop();
}

/*
vector<Ship> init(vector<Ship> ships, int num_ships, int x_range, int y_range) {
    for (int i = 0; while i < num_ships; i++) {
        ships.push_back(Ship(rand(0,10), rand(0,10), rand(1,5), rand(0,1));
    }

    return ships;
}
*/

void loop() {
    int explode_x, explode_y;
    cout << "Enter an X: ";
    cin >> explode_x;
    cout << "Enter a Y:  ";
    cin >> explode_y;

    cout << "you exploded " << explode_x << ", " << explode_y << endl << endl;
}

