// Danial Mobini Dehkordy 40130023
// Mohammad Sadegh Hatefi 40133073

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n = 0, power2 = 1, arr[50], i = 0;

    while (cin >> arr[i])
    {
        n = i + 1;
        i++;
    }
    int t = (log10(n) / log10(2));
    for (int i = 0; i < t; i++, power2 *= 2)
    {
        make_heap(arr + power2 - 1, arr + power2 * 2 - 1);
        sort_heap(arr + power2 - 1, arr + power2 * 2 - 1);
        for (int j = power2 - 1; j < power2 * 2 - 1; j++)
        {
            cout << arr[j] << " ";
        }
        cout << endl;
    }
    make_heap(arr + power2 - 1, arr + n);
    sort_heap(arr + power2 - 1, arr + n);
    for (int j = power2 - 1; j < n; j++)
    {
        cout << arr[j] << " ";
    }
}