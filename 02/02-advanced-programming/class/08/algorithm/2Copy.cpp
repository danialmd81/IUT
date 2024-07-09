#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec;
    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
    }

    // copy
    vector<int>;
    myvector(7);
    auto p = find(vec.begin(), vec.end(), 6);
    copy(vec.begin(), p, myvector.begin());
    for (auto x : myvector) {
        cout << x << " ";
    }

    // copy_if
    vector<int> myvector1(7);
    auto p1 = find(vec.begin(), vec.end(), 6);
    copy_if(vec.begin(), p1, myvector1.begin(),
            [](int x) { return x / 2 == 1; });
    for (auto x : myvector1) {
        cout << x << " ";
    }

    // Unique copy
    vector<int> myvector2(7);
    // vec[4] = 3;
    auto p2 = find(vec.begin(), vec.end(), 7);

    unique_copy(vec.begin(), p2, myvector2.begin());
    for (auto x : myvector2) {
        cout << x << " ";
    }
}