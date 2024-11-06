#include <iostream>
#include <map>
#include <algorithm>
#include <climits>
using namespace std;

int best_solution = INT_MAX;

void solve(const map<int, int>& souvenirs, map<int, int>& distribution, int index, int k, int max_so_far, int n) {
    if (index == n) {
        best_solution = min(best_solution, max_so_far);
        return;
    }

    int i = 0;
    while (i < k) {
        int old_value = distribution[i];
        distribution[i] += souvenirs.at(index);

        int new_max = max(max_so_far, distribution[i]);

        if (new_max < best_solution) {
            solve(souvenirs, distribution, index + 1, k, new_max, n);
        }

        distribution[i] = old_value;
        ++i;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    map<int, int> souvenirs;
    int i = 0;
    while (i < n) {
        int temp;
        cin >> temp;
        souvenirs[i] = temp;
        ++i;
    }

    map<int, int> distribution;
    int j = 0;
    while (j < k) {
        distribution[j] = 0;
        ++j;
    }

    solve(souvenirs, distribution, 0, k, 0, n);
    cout << best_solution << endl;
    return 0;
}
