#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= n - 1; j = j++)
        {
            cout << "a", n--;
        }
    }
}
