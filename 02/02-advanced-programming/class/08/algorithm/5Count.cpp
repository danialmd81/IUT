#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec;
    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
    }

    // count
    auto n = count(vec.begin(), vec.end(), 2);
    cout << n;

    // count_if
    auto p = count_if(vec.begin(), vec.end(), [](int x) { return x / 2 == 1; });
    cout << p;
}