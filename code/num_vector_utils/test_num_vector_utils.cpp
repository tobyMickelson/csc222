#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

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

TEST_CASE("Test mean") {
    vector<int> nums = {1, 2, 3, 22, 4, 4, 6, 7, 4, 8, 11, 12, 14, 27, 22};
    double mean = get_mean(nums);
    double expected_mean = 9.8;
    CHECK(std::abs(mean - expected_mean) < 0.01);
}

TEST_CASE("Test median") {
    vector<int> nums = {1, 2, 3, 22, 4, 4, 6, 7, 4, 8, 11, 12, 14, 27, 22};
    double median = get_median(nums);
    double expected_median = 7;
    CHECK(std::abs(median - expected_median) < 0.01);
}

TEST_CASE("Test median again") {
    vector<int> nums = {3, 1, 7, 5};
    double median = get_median(nums);
    double expected_median = 4;
    CHECK(std::abs(median - expected_median) < 0.01);
}

TEST_CASE("Test median again again") {
    vector<int> nums = {3, 1, 7, 5, 9};
    double median = get_median(nums);
    double expected_median = 5;
    CHECK(std::abs(median - expected_median) < 0.01);
}

TEST_CASE("Test mode") {
    vector<int> nums = {1, 2, 3, 22, 4, 4, 6, 7, 4, 8, 11, 12, 14, 27, 22};
    vector<int> mode = get_mode(nums);
    CHECK(render_num_vector(mode) == "4");
}

TEST_CASE("Test mode multiple") {
    vector<int> nums = {1, 2, 11, 3, 22, 4, 4, 6, 7, 4, 8, 11, 12, 14, 27, 22, 11};
    vector<int> mode = get_mode(nums);
    CHECK(render_num_vector(mode) == "4 11");
}

TEST_CASE("Test sorting") {
    vector<int> nums = {3, 1, 7 ,5};
    vector<int> sorted2 = sorted(nums);
    CHECK(render_num_vector(sorted2) == "1 3 5 7");
}
