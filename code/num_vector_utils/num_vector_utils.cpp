#include <map>
#include "num_vector_utils.h"

using namespace std;

string render_num_vector(const vector<int>& numbers) {
    string output = "";

    if (numbers.size() == 0)
        return output;

    for (int number : numbers)
        output += to_string(number) + " ";

    output.pop_back();

    return output;
}

int num_vector_sum(const vector<int>& numbers) {
    int sum = 0;

    for (int number : numbers)
      sum += number;

    return sum;
}

int num_vector_product(const vector<int>& numbers) {
    int product = 1;

    for (int number : numbers)
        product *= number;

    return product;
}

vector<int> only_evens(const vector<int>& numbers) {
    vector<int> output;

    for (int number : numbers)
        if (number % 2 == 0)
            output.push_back(number);

    return output;
}

double get_mean(const vector<int>& numbers) {
    int sum = num_vector_sum(numbers);
    return sum / (double) numbers.size();
}

double get_median(const vector<int>& numbers) {
    vector<int> sorted_numbers = sorted(numbers);

    int middle = sorted_numbers.size() / 2;

    if (sorted_numbers.size() % 2 == 1)
        return ((double) sorted_numbers[middle]);
    else
        return (((double) sorted_numbers[middle - 1] + sorted_numbers[middle]) / 2);
}

vector<int> get_mode(const vector<int>& numbers) {
    if (numbers.size() == 0)
        return vector<int> {};

    map<int, int> number_map = {};

    for (int number : numbers)
        if (number_map.find(number) == number_map.end())
            number_map[number] = 1;
        else
            number_map[number]++;

    int highest_count = 0;
    vector<int> mode = {};

    for (map<int, int>::iterator pair = number_map.begin(); pair != number_map.end(); pair++) {
        if (pair->second > highest_count) {
            highest_count = pair->second;
            mode.clear();
            mode.push_back(pair->first);
        } else if (pair->second == highest_count) {
            mode.push_back(pair->first);
        }
    }

    return sorted(mode);
}

vector<int> sorted(const vector<int>& numbers) {
    vector<int> sorting(numbers);
    bool sorted = false;

    while (!sorted) {
        sorted = true;
        for (int index = 1; index < sorting.size(); index++)
            if (sorting[index - 1] > sorting[index]) {
                swap(sorting[index - 1], sorting[index]);
                sorted = false;
            }
    }

    return sorting;
}
