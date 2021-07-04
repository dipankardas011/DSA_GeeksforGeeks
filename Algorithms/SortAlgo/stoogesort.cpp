#include <iostream>
using namespace std;

void stoogeSort(int arr[], int l, int h)
{
    if (l >= h)
        return;
    // if the first element is smaller than last
    if (arr[l] > arr[h])
        std::swap(arr[l], arr[h]);
    // there are >2 elements
    if (h - l + 1 > 2)
    {
        int t = (h - l + 1) / 3;

        // sort first 2/3rd elemetn
        stoogeSort(arr, l, h - t);
        // sort last 2/3rd ele
        stoogeSort(arr, l + t, h);

        // again sort 2/3 to conform
        stoogeSort(arr, l, h - t);
    }
}
int main(int argc, char const *argv[])
{
    int arr[] = {2, 4, 5, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Calling Stooge Sort function to sort
    // the array
    stoogeSort(arr, 0, n - 1);

    // Display the sorted array
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout<<endl;
    remove(argv[0]);
    return 0;
}
