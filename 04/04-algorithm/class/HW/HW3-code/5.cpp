#include <bits/stdc++.h>
using namespace std;

int minCostTriangulation(vector<pair<int, int>> &points)
{
    int n = points.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int gap = 2; gap < n; gap++)
    {
        for (int i = 0; i < n - gap; i++)
        {
            int j = i + gap;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++)
            {
                int cost = dp[i][k] + dp[k][j] +
                           abs(points[i].first - points[j].first) +
                           abs(points[i].second - points[j].second);
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[0][n - 1];
}

int main()
{
    vector<pair<int, int>> points = {{0, 0}, {1, 0}, {2, 1}, {1, 2}, {0, 2}};
    cout << minCostTriangulation(points) << endl;
    return 0;
}