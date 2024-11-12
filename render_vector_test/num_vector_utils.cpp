#include <string>
#include <vector>
using namespace std;

string render_num_vector(const vector<int>& numbers) {
    string output = "";

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