#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, int>> pi; //<cost,<x,y>>

#define ln "\n"

int is_better(int n, int m, int x, int y, vector<vector<int>> &field)
{
    int next_x = (x + 1) % n;
    int next_y = (y + 1) % m;
    int temp = field[next_x][y] + field[x][next_y];
    return temp < field[x][y] ? temp : -1;
}

int main()
{
    int n, m, k, cost = 0; // n*m farm field,weed number at first
    cin >> n >> m >> k;
    vector<vector<int>> field(n, vector<int>(m));
    vector<pi> field_cost;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp_cost;
            cin >> temp_cost;
            field[i][j] = temp_cost;
            field_cost.push_back({temp_cost, {i, j}});
        }
    }

    sort(field_cost.begin(), field_cost.end());
    int s = field_cost.size();
    for (int i = 0; i < s; i++)
    {
        int x, y, temp;

        x = (field_cost[i].second.first - 1) < 0 ? n - 1 : field_cost[i].second.first - 1;
        y = field_cost[i].second.second;

        temp = is_better(n, m, x, y, field);
        if (temp != -1)
        {
            field[x][y] = temp;
            field_cost.push_back({temp, {x, y}});
            s++;
        }

        x = field_cost[i].second.first;
        y = (field_cost[i].second.second - 1) < 0 ? m - 1 : field_cost[i].second.second - 1;

        temp = is_better(n, m, x, y, field);
        if (temp != -1)
        {
            field[x][y] = temp;
            field_cost.push_back({temp, {x, y}});
            s++;
        }
    }

    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        cost += field[x][y];
    }
    cout << cost << ln;
}
