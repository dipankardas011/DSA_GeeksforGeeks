#include <iostream>

void heapify(int arr[], int i, int size)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[largest] < arr[left])
        largest = left;

    if (right < size && arr[largest] < arr[right])
        largest = right;

    if (largest != i)
    {
        std::swap(arr[largest], arr[i]);
        heapify(arr, largest, size);
    }
}

void HeapSort(int arr[], int N)
{
    for (int i = (N-1)/2; i >= 0; i--)
        heapify(arr, i, N);

    for (int i = N - 1; i > 0; i--)
    {
        // swap element from end and start
        std::swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
}

void display(int arr[], int N)
{
    for (int i = 0; i < N; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main()
{
    int arr[] = {3, 7, 4, 9, 5, 2, 8};
    int N = sizeof(arr) / sizeof(arr[0]);
    HeapSort(arr, N);
    display(arr, N);
    return 0;
}