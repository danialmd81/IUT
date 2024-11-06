#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int dimensions[n + 1];
    int dp[n][n];

    int i = 0;
    while (i <= n) {
        cin >> dimensions[i];
        ++i;
    }

    int j = 0;
    while (j < n) {
        int k = 0;
        while (k < n) {
            dp[j][k] = 0;
            ++k;
        }
        ++j;
    }

    int len = 2;
    while (len <= n) {
        int i = 0;
        while (i <= n - len) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            int k = i;
            while (k < j) {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
                ++k;
            }
            ++i;
        }
        ++len;
    }

    cout << dp[0][n - 1] << endl;

    return 0;
}
