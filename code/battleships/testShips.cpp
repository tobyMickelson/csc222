#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include "ships.h"
using namespace std;

TEST_CASE("No bombs away") {
    CHECK(Ship(0, 0, 1, false).explode (6,7) == false);
}
TEST_CASE("Yes bombs away") {
    CHECK(Ship(4, 5, 6, false).explode(6, 5) == true);
}

/*
int xbomb;
    cin >> xbomb;
    int ybomb;
    cin >> ybomb;
*/
