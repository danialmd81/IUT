#include <bits/stdc++.h>

using namespace std;

bool binarySearch(int A[], int low, int high, int searchKey)
{
    while (low <= high)
    {
        int m = low + (high - low) / 2;

        if (A[m] == searchKey)
            return true;

        if (A[m] < searchKey)
            low = m + 1;

        else
            high = m - 1;
    }

    return false;
}

bool checkTwoSum(int A[], int arr_size, int sum)
{
    int l, r;
    sort(A, A + arr_size);

    for (int i = 0; i < arr_size - 1; i++)
    {
        int searchKey = sum - A[i];
        if (binarySearch(A, i + 1, arr_size - 1, searchKey) == true)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n, k, *arr;
    cin >> n >> k;
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (checkTwoSum(arr, n, k))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}