#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int binomial_coeficient(int n, int r)
{
    if (r > n)
        return 0;
    long long int m = MOD;
    long long int inv[r + 1] = {0};
    inv[0] = 1;
    if (r + 1 >= 2)
        inv[1] = 1;

    for (int i = 2; i <= r; i++)
    {
        inv[i] = m - (m / i) * inv[m % i] % m;
    }

    int ans = 1;

    for (int i = 2; i <= r; i++)
    {
        ans = ((ans % m) * (inv[i] % m)) % m;
    }

    for (int i = n; i >= (n - r + 1); i--)
    {
        ans = ((ans % m) * (i % m)) % m;
    }

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    long long int n, k;
    cin >> n >> k;
    long long int sum = 0, dp[k + 1];

    dp[k] = 1;
    int turn = 1;
    for (long long int i = k - 1, a = k, b = 1; i >= 0; i--)
    {
        if (turn == 1)
        {
            dp[i] = dp[i + 1] + binomial_coeficient(k, a);
            a--;
        }
        else if (turn == -1)
        {
            dp[i] = dp[i + 1] + binomial_coeficient(k, b);
            b++;
        }
        dp[i] = dp[i] % MOD;
        turn *= -1;
    }
    for (long long int i = 0; i < n; i++)
    {
        long long int x;
        cin >> x;
        x = abs(x);
        if (x <= k)
        {
            sum += dp[x];
            sum = sum % MOD;
        }
    }
    cout << sum;
    return 0;
}
