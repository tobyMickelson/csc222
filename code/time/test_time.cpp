//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//
//#include <doctest/doctest.h>
//#include "time.h"
//
//using namespace std;
//
//TEST_CASE("Test can create and render Times") {
//    Time t1;
//    CHECK(t1.toString() == "0:00:00");
//    Time t2(7);
//    CHECK(t2.toString() == "0:00:07");
//    Time t3(72);
//    CHECK(t3.toString() == "0:01:12");
//    Time t4(7 * 3600 + 11 * 60 + 19);
//    CHECK(t4.toString() == "7:11:19");
//}

#include <iostream>
using namespace std;

int main() {
    int num = 42;

    cout << "The answer to the ultimate question of life, ";
    cout << "the universe and everything is (of course) ";
    cout << num << "." << endl;

    return 0;
}
