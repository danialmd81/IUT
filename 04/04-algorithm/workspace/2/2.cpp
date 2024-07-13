#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
If s1 is empty (n == 0), the distance is the length of s2 (m),
because we need to insert all characters of s2 into s1.

If s2 is empty (m == 0), the distance is the length of s1 (n),
because we need to delete all characters of s1.

If the current subproblem has already been solved (dp[n][m] != -1),
return the stored result.

If the last characters of s1 and s2 are the same, we don't need to do anything.
So, we just move to the next pair of characters (n - 1, m - 1).

If the last characters are different, we consider three operations:

Insert: Insert the last character of s2 into s1. So,
we move to the next character of s2 (n, m - 1).

Delete: Delete the last character of s1. So,
we move to the next character of s1 (n - 1, m).

Replace: Replace the last character of s1 with the last character of s2.
So, we move to the next pair of characters (n - 1, m - 1).

We take the minimum of these three operations
and add 1 (for the current operation), storing the result in dp[n][m].
*/

int minDis(string s1, string s2, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0)
        return m;

    if (m == 0)
        return n;

    if (dp[n][m] != -1)
        return dp[n][m];

    if (s1[n - 1] == s2[m - 1])
    {
        return dp[n][m] = minDis(s1, s2, n - 1, m - 1, dp);
    }
    else
    {
        int insert, del, replace;

        insert = minDis(s1, s2, n, m - 1, dp);
        del = minDis(s1, s2, n - 1, m, dp);
        replace = minDis(s1, s2, n - 1, m - 1, dp);
        return dp[n][m] = 1 + min(insert, min(del, replace));
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    string str1, str2;
    cin >> str1 >> str2;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    cout << minDis(str1, str2, n, m, dp);

    return 0;
}
