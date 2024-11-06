#include <iostream>

using namespace std;

int solve(int d, int c, int node)
{
    if (d == 0)
    {
        cout << "a";
        return node;
    }
    cout << "a";
    return solve(--d, (c + 1) / 2, !(c % 2) ? node * 2 + 1 : node * 2);
}

int main()
{
    int l, d, node, c;
    cin >> l;
    for (int i = 0; i < l; i++)
    {
        node = 1;
        cin >> d >> c;
        cout << solve(--d, c, node) << "a" << endl;
    }
}