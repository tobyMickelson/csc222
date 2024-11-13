#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <string>
#include <vector>

#include "num_vector_utils.h"
using namespace std;

TEST_CASE("Testing render_num_vector") {
    vector<int> nums = {1, 3, 7};
    string numstr = render_num_vector(nums);
    string expected = "1 3 7";
    CHECK(numstr == expected);
}

TEST_CASE("Testing render_num_vector no inputs") {
    vector<int> nums = {};
    string numstr = render_num_vector(nums);
    string expected = "";
    CHECK(numstr == expected);
}

TEST_CASE("Testing render_num_vector 3+ inputs") {
    vector<int> nums = {1, 7, 3, 6, 9};
    string numstr = render_num_vector(nums);
    string expected = "1 7 3 6 9";
    CHECK(numstr == expected);
}

TEST_CASE("Testing num_vector_sum") {
    vector<int> nums = {1, 3, 7};
    CHECK(11 == num_vector_sum(nums));
}

TEST_CASE("Testing num_vector_product") {
    vector<int> nums = {2, 3, 7};
    CHECK(42 == num_vector_product(nums));
}

TEST_CASE("Testing only_evens") {
    vector<int> nums = {1, 2, 3, 4, 6, 7, 8, 11, 12, 14, 27, 22};
    vector<int> evens = only_evens(nums);
    string expected = "2 4 6 8 12 14 22";
    CHECK(render_num_vector(evens) == expected);
}
