#include <bits/stdc++.h>

using namespace std;

void solve(vector<bool> &tree, int i_ball)
{
    int index = 1;
    while (index < tree.size())
    {
        if (tree[index] == true)
        {
            tree[index] = false;
            index = 2 * index + 1;
        }
        else
        {
            tree[index] = true;
            index = 2 * index;
        }
    }
    if (index % 2 == 0)
    {
        index = index / 2;
    }
    else
    {
        index = (index - 1) / 2;
    }
    if (i_ball == 1)
    {
        cout << index << "\n";
    }
    else
    {
        solve(tree, i_ball - 1);
    }
}

int main()
{

    int T; // testcase num
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int depth, i_ball;
        cin >> depth >> i_ball;
        vector<bool> tree(pow(2, depth), false); // make tree with 2 power depth nodes and all false
        solve(tree, i_ball);
    }
    cin >> T;

    return 0;
}