#include <bits/stdc++.h>

using namespace std;

#define MAX 100001
#define ll long long int

/*
It calculates the minimum cost to reach each possible value by iterating over the dp and val arrays.
It updates the dp array in-place and returns the minimum cost to reach the value k.
*/
ll check_count(ll dp[], ll val[], ll c[], int n, int k)
{

    ll temp;
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = k; j >= 0; j--)
        {
            if (j - val[i] > 0)
                temp = j - val[i];

            else
                temp = 0;

            if ((dp[temp] != -1) && ((dp[j] == -1) || (dp[temp] + c[i] < dp[j])))
                dp[j] = dp[temp] + c[i];
        }
    }
    return dp[k];
}

/*
It initializes the dp array to -1 and sets the val array to be one less than the set array, or 0 if set[i] - 1 is less than 0.
 */
void func_set(ll dp[], ll val[], ll set[], int n)
{
    memset(dp, -1, MAX * sizeof(ll));

    for (int i = 0; i < n; i++)
    {
        if (set[i] - 1 > 0)
            val[i] = set[i] - 1;

        else
            val[i] = 0;
    }
}

/*
It initializes a dynamic programming array dp and a val array.
It then calls func_set and check_count functions for each of the arrays a, b, and a+b.
It keeps track of the minimum cost found so far in ans.
*/
ll solve(ll a[], ll b[], ll c[], int n, int k)
{
    ll dp[MAX];  // dp stores the minimum cost to reach each possible value
    ll val[n];   // val stores the current values being considered
    ll ans = -1; // indicating that no solution has been found yet.

    // a[]
    func_set(dp, val, a, n);
    ll temp = check_count(dp, val, c, n, k);
    ans = temp;

    // b[]
    func_set(dp, val, b, n);
    temp = check_count(dp, val, c, n, k);
    if ((ans == -1) || ((ans > temp) && (temp != -1)))
        ans = temp;

    // a[]+b[]
    memset(dp, -1, MAX * sizeof(ll));
    for (int i = 0; i < n; i++)
        val[i] = a[i] + b[i];
    int t = 2 * k - 1;
    temp = check_count(dp, val, c, n, t);
    if ((ans == -1) || ((ans > temp) && (temp != -1)))
        ans = temp;

    return ans;
}

int main()
{
    int n; // bundles of wool in market
    int k; // number of friends
    cin >> n >> k;

    ll a[n], b[n], c[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    cout << solve(a, b, c, n, k);

    return 0;
}
