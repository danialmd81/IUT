#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    string mes;
    cin >> mes;
    deque<char> result;
    int reverse = 1;
    while (!mes.empty())
    {
        if (reverse == 1)
        {
            result.push_front(mes.back());
            mes.pop_back();
        }
        else if (reverse == -1)
        {
            result.push_front(mes.front());
            mes.erase(mes.begin());
        }
        if (result.front() == 'x')
        {
            reverse *= -1;
        }
    }
    while (!result.empty())
    {
        cout << result.front();
        result.pop_front();
    }
}