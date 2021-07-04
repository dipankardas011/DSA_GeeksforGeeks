/*K’th Smallest/Largest Element in Unsorted Array | Set 1
Given an array and a number k where k is smaller than size of array, we need to find the k’th smallest element in the given array. It is given that all array elements are distinct.

Examples:  

Input: arr[] = {7, 10, 4, 3, 20, 15} 
k = 3 
Output: 7

Input: arr[] = {7, 10, 4, 3, 20, 15} 
k = 4 
Output: 10 
*/
#include <iostream>

// make a max heap
// as it is sorted in ascending order
void heapfy(int arr[], int i, int n)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if (left<n && arr[left] > arr[largest])    largest = left;
    if (right<n && arr[right] > arr[largest])  largest = right;

    if (largest != i)
    {
        std::swap(arr[largest], arr[i]);
        heapfy (arr, largest, n);
    }
}


int main(){
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = (n-1)/2 ; i>=0; i--)
        heapfy (arr, i, n);
    
    int k1 = 3;
    int k = k1;
    for(int i=n-1; i>0; i--)
    {
        if(k==0)    std::cout<<"the "<<k1<<" th smallest element = "
            << arr[0]<<std::endl;
        k--;
        std::swap(arr[0], arr[i]);
        heapfy(arr, 0, i);
    }
    return 0;
}