#include <bits/stdc++.h>

using namespace std;

#define re 1000000007

long long int power(long long int x, int y)
{
    long long int temp = (x * x) % re;
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    if (y % 2 == 0)
        return power(temp, y / 2);
    else
        return x * power(temp, y / 2) % re;
}

int main()
{
    int n_sal, T;
    int sum = 0;
    cin >> n_sal >> T;
    for (int i = 0; i < n_sal; i++)
    {
        int temp;
        cin >> temp;
        sum += temp;
    }
    for (int i = 0; i < T; i++)
    {
        int sal_i;
        cin >> sal_i;
        sal_i -= n_sal + 1;
        int javab = sum * power(2, sal_i) % re;
        cout << javab << endl;
    }

    return 0;
}