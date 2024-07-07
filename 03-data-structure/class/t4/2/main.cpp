// Danial Mobini Dehkordy 40130023
// Mohammad Sadegh Hatefi 40133073
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int maxLength(int *input, int n)
{
    unordered_map<int, bool> container;
    for (int i = 0; i < n; i++)
    {
        container[input[i]] = false;
    }
    int maxL = 0;

    for (int i = 0; i < n; i++)
    {
        if (container.find(input[i] - 1) == container.end())
        {
            int currentNum = input[i];
            int currentLength = 1;

            while (container.find(currentNum + 1) != container.end())
            {
                currentNum++;
                currentLength++;
            }

            maxL = max(maxL, currentLength);
        }
    }

    return maxL;
}

int main()
{
    int *input;
    int n, temp;
    cin >> n;
    if (n <= 0)
        return 0;
    input = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    cout << maxLength(input, n) << endl;

    return 0;
}
