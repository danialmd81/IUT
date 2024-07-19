// Danial Mobini  40130023
// Mohammad Sadegh Hatefi  40133073

#include <algorithm>
#include <iostream>

using namespace std;

int mergeSort_t = 0;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void mergeSort(int *array, int const begin, int const end)
{
    mergeSort_t++;
    if (is_sorted(array + begin, array + end))
    {
        return;
    }
    else
    {
        if (begin >= end)
        {
            return;
        }
        else
        {
            int mid = (begin + end) / 2;
            mergeSort(array, begin, mid - 1);
            mergeSort(array, mid, end);
        }
    }
}

void array_testing(int n, int t)
{
    int array[n];
    int c_array[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = i + 1;
    }
    do
    {
        mergeSort_t = 0;
        copy(array, array + n, c_array);
        mergeSort(c_array, 0, n);
        if (mergeSort_t == t)
        {
            printArray(array, n);
            return;
        }
    } while (next_permutation(array, array + n));

    cout << -1;
}
int main()
{

    int n, t;
    cin >> n >> t;
    array_testing(n, t);
}