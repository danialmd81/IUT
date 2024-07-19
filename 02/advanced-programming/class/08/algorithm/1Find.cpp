#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec;
    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
    }

    // find
    vector<int>::iterator p = find(vec.begin(), vec.end(), 2);
    cout << *p;

    // find_if
    auto a = find_if(vec.begin(), vec.end(), [](int x) { return x / 2 == 1; });
    cout << *a;
}
