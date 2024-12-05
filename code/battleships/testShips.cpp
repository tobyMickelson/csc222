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
TEST_CASE("Yes (vertical) bombs away") {
    CHECK(Ship(4, 5, 3, true).explode(4, 7) == true);
}
TEST_CASE("No (vertical) bombs away") {
    CHECK(Ship(4, 5, 3, true).explode(4, 9) == false);
}
