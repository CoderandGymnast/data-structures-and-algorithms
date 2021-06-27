#include <iostream>

using namespace std;

void quickSort(int arr[], int start, int end, int len);

int partition(int arr[], int start, int end);
void swap(int arr[], int start, int end);
void print(int arr[], int len);
int main()
{
    const int len=10;
    int values[len] = {2, 1, 5, 4, 9, 8, 7, 3, 6, 0};
    //cout << sizeof(values)/sizeof(values[0]) << endl;
    quickSort(values, 0, len-1,len);
    print(values,len);
}

void quickSort(int arr[], int start, int end, int len)
{
    if (start >= end)
        return;

    int index = partition(arr, start, end);
    quickSort(arr, start, index - 1, len);
    quickSort(arr, index + 1, end, len);
}

int partition(int arr[], int start, int end)
{
    int pivotIndex = start, pivotValue = arr[end];
    for (int i = start; i < end; i++)
    {
        if (arr[i] < pivotValue)
        {
            swap(arr, i, pivotIndex);
            pivotIndex++;
        }
    }
    swap(arr, pivotIndex, end);
    return pivotIndex;
}

void swap(int arr[], int start, int end)
{
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
}

void print(int arr[], int len)
{
    for (int i = 0; i < len; ++i)
    {
        cout << arr[i] << " ";
    }
}