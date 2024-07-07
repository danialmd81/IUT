// SINA-JAHANGIR 40120693
// MEHDI-VAKILI 40133013

#include <iostream>
using namespace std;

#include <unordered_map>
#include <vector>

int calculate(const vector<int> &input)
{
    unordered_map<int, bool> container;

    for (int element : input)
        container[element] = false;

    int maxLength = 0;

    for (int element : input)
    {
        if (container.find(element - 1) == container.end())
        {
            int currentNum = element;
            int currentLength = 1;

            while (container.find(currentNum + 1) != container.end())
            {
                currentNum++;
                currentLength++;
            }

            maxLength = max(maxLength, currentLength);
        }
    }

    return maxLength;
}

int main()
{
    vector<int> input;
    int n, temp;
    cin >> n;
    if (n == 0)
        return 0;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        input.push_back(temp);
    }

    cout << calculate(input) << endl;

    return 0;
}
