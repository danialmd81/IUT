#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = n / 2; i <= n; i++)
    {
        for (int j = 2; j <= n; j = j * 5)
        {
            cout << "a";
        }
    }
}
