#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> vec;
  for (int i = 0; i < 10; i++) {
    vec.push_back(i);
  }

  // replace
  for (auto x : vec) {
    cout << x << " ";
  }
  cout << endl;
  replace(vec.begin(), vec.end(), 5, 22);
  for (auto x : vec) {
    cout << x << " ";
  }

  // replace_if
  for (auto x : vec) {
    cout << x << " ";
  }
  cout << endl;
  replace_if(
      vec.begin(), vec.end(), [](int x) { return x / 2 == 1; }, 22);
  for (auto x : vec) {
    cout << x << " ";
  }
}