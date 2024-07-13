/*
In a farm, there is a cow that can eat n kilos of two types of grass (alfalfa and clover).
This cow cannot eat more than m kg of one type of grass and must change its type of grass.
But he can only change the type of grass k times. Cows start with alfalfa first.
Using dynamic programming, determine how many ways this cow can eat n kg of grass?
Example: m = 2, k = 2, n = 4.
In this example, a cow can eat 4 kilos of grass in 4 ways.

2 kilos of alfalfa, 2 kilos of clover
2 kilos of alfalfa, 1 kilo of clover, 1 kilo of alfalfa
1 kilo of alfalfa, 1 kilo of clover, 2 kilos of alfalfa
1 kilo of alfalfa, 2 kilos of clover, 1 kilo of alfalfa
 */

#include <iostream>
#include <vector>

using namespace std;

int countWays(int n, int m, int k)
{
    std::vector<std::vector<std::vector<int>>> dp(n + 1, std::vector<std::vector<int>>(k + 1, std::vector<int>(m + 1, 0)));
    dp[0][0][1] = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            for (int l = 1; l <= m; ++l)
            {
                if (i >= l)
                    dp[i][j][l] += dp[i - l][j][l - 1];
                if (j > 0)
                {
                    for (int p = 0; p <= m; ++p)
                    {
                        if (i >= l)
                            dp[i][j][l] += dp[i - l][j - 1][p];
                    }
                }
            }
        }
    }

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            for (int l = 0; l <= m; ++l)
            {
                cout << dp[i][j][l] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    int total = 0;
    for (int l = 0; l <= m; ++l)
    {
        total += dp[n][k][l];
    }

    return total;
}

int main()
{
    std::cout << countWays(4, 2, 2);
}