#include <bits/stdc++.h>

using namespace std;

#define ln "\n"

/*
3

1
1
1
1

2
1
1
2

3
1
4
2
*/
int is_descending(const vector<int> &v)
{
    int sadness = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = i; j < 3; j++)
        {
            if (v[j] > v[i])
            {
                sadness++;
            }
        }
    }

    return sadness;
}

int sad_number(vector<int> taxi)
{
    int sadness = 3;
    for (int i = 0; i < taxi.size(); i++)
    {
        vector<int> temp = taxi;
        temp.erase(temp.begin() + i);
        sadness = min(sadness, is_descending(temp));
    }
    return sadness;
}

int main()
{
    int n; // number of taxi
    cin >> n;
    vector<vector<int>> passenger(n, vector<int>(4));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> passenger[i][j];
        }
        cout << sad_number(passenger[i]) << ln;
    }
}