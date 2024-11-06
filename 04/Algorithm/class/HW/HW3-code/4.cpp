#include <bits/stdc++.h>

using namespace std;

int longest_decresing_substring(int arr[], int n)
{
    int dp[n];
    int i, j, max = 0;
    for (i = 0; i < n; i++)
        dp[i] = 1;

    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (arr[i] < arr[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;

    for (i = 0; i < n; i++)
        if (max < dp[i])
            max = dp[i];

    return max;
}

int main()
{

    int arr[] = {15, 27, 14, 38, 63, 55, 46, 65, 85};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Length of LDS is " << longest_decresing_substring(arr, n);

    return 0;
}