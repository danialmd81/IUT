#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec;
    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
    }
    // sort
    sort(vec.begin(), vec.end());

    // sort if
    sort(vec.begin(), vec.end(), [](int a, int b) { return b < a; });
    for (auto x : vec) {
        cout << x << " ";
    }
}