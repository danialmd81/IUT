// Danial Mobini  40130023
// Mohammad Sadegh Hatefi  40133073

#include <iostream>

using namespace std;

int if_count = 0;

void merge(int array[], int const left, int const mid, int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    int *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];

    for (int i = 0; i < subArrayOne; i++)
    {
        leftArray[i] = array[left + i];
    }
    for (int j = 0; j < subArrayTwo; j++)
    {
        rightArray[j] = array[mid + 1 + j];
    }

    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }

    int leftIndex = subArrayOne - 1;
    int rightIndex = subArrayTwo - 1;

    while (leftIndex >= 0 && rightIndex >= 0)
    {
        if (leftArray[leftIndex] > (3 * rightArray[rightIndex] + 1))
        {
            if_count += rightIndex + 1;
            leftIndex--;
        }
        else
        {
            rightIndex--;
        }
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int *array, int const begin, int const end)
{
    if (begin >= end)
    {
        return;
    }
    else
    {
        int mid = (begin + end) / 2;
        mergeSort(array, begin, mid);
        mergeSort(array, mid + 1, end);
        merge(array, begin, mid, end);
    }
}

int main()
{
    int n, *arr;
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> *(arr + i);
    }
    mergeSort(arr, 0, n - 1);
    cout << if_count;
}