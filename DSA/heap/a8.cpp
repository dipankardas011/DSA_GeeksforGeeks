/*Heap Sort for decreasing order using min heap
*/
#include <bits/stdc++.h>

// min-heap

void heapify(int arr[], int i, int size)
{
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<size && arr[left] < arr[smallest])
        smallest=left;
    if(right<size && arr[right]<arr[smallest])
        smallest=right;
    
    if(smallest != i)
    {
        std::swap(arr[smallest], arr[i]);
        heapify(arr, smallest, size);
    }
}

void MinHeap(int arr[], int n)
{
    for(int i = (n-1)/2; i>=0; i--)
        heapify(arr, i, n);
    
    for(int i=n-1; i>0; i--)
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, 0 ,i);
    }
}

void display(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        std::cout<<a[i]<<"\t";
    }
    std::cout<<std::endl;
}

void exec()
{
    int arr[] = {5, 3, 10, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    MinHeap(arr, size);
    display(arr, size);

    int arr1[] = {1, 50, 100, 25};
    size== sizeof(arr1)/sizeof(arr1[0]);
    MinHeap(arr1, size);
    display(arr1, size);
}

int main()
{
    exec();
    return 0;
}