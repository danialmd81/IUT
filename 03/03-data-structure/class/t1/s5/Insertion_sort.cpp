// Danial Mobini  40130023
//  Sadegh Hatefi

#include <cstdlib>
#include <iostream>

using namespace std;

void insertionSort(int array[], int size)
{
    int i, key, j;
    for (i = 1; i < size; i++)
    {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    srand((unsigned)time(NULL));
    int n = 0;
    cout << "how many number do you want to generate?(at least 5 number)";
    cin >> n;
    while (n < 5)
    {
        cout << "how many number do you want to generate?(at least 5 number)";
        cin >> n;
    }

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
    printArray(arr, n);
    insertionSort(arr, n);
    printArray(arr, n);
}
