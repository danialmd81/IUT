#include <bits/stdc++.h>

using namespace std;

void longestPalSubstr(string str)
{
    int n = str.size();
    bool table[n][n];
    memset(table, 0, sizeof(table));
    int maxLength = 1;
    for (int i = 0; i < n; ++i)
        table[i][i] = true;

    int start = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (str[i] == str[i + 1])
        {
            table[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    for (int k = 3; k <= n; ++k)
    {
        for (int i = 0; i < n - k + 1; ++i)
        {
            int j = i + k - 1;
            if (table[i + 1][j - 1] && str[i] == str[j])
            {
                table[i][j] = true;
                if (k > maxLength)
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
    cout << maxLength << endl;
    for (int i = start; i <= start + maxLength - 1; ++i)
        cout << str[i];
    cout << endl;
}

int main()
{
    string str;
    cin >> str;
    longestPalSubstr(str);
    return 0;
}

/*
    forgeeksskeegfor
    Output:
    10
    geeksskeeg
 */