#include <bits/stdc++.h>
#include <vector>

using namespace std;

// Function to pre-calculate the cumulative sum of the table
void calculateCumulativeSum(std::vector<std::vector<int>> &table, std::vector<std::vector<int>> &cumSum)
{
    int n = table.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cumSum[i + 1][j + 1] = cumSum[i + 1][j] + cumSum[i][j + 1] - cumSum[i][j] + table[i][j];
        }
    }
}

int main()
{
    int n;
    cin >> n;
    std::vector<std::vector<int>> table(n, std::vector<int>(n)); // Initialize a n*n table
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> table[i][j];
        }
    }

    std::vector<std::vector<int>> cumSum(n + 1, std::vector<int>(n + 1, 0)); // Initialize the cumulative sum table

    calculateCumulativeSum(table, cumSum); // Calculate the cumulative sum of the table

    // cout << endl;
    // for (int i = 0; i < n + 1; i++)
    // {
    //     for (int j = 0; j < n + 1; j++)
    //     {
    //         cout << cumSum[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    int q;
    cin >> q;
    for (int a = 0; a < q; a++)
    {
        int i, j, k, l;
        cin >> i >> j >> k >> l;
        cout << cumSum[j][l] - cumSum[j][k - 1] - cumSum[i - 1][l] + cumSum[i - 1][k - 1] << endl; // Get the sum of the sub-table from (i, k) to (j, l)
    }

    return 0;
}

/*
4
1 2 3 4
1 4 5 6
3 4 3 2
2 8 7 6
2
1 2 1 2
8
1 4 1 1
7
*/