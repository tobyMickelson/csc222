#include "member_function.h"
#include <iostream>

int main() {
    Time my_time = {1, 2, 3};
    my_time.incriment(1.5);
    my_time.println();
    std::cout << my_time.to_seconds() << std::endl;

    return 0;
}
