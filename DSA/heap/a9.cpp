// K’th largest element in a stream
// Given an infinite stream of integers, find the k’th largest element at any point of time.
// Example: 

// Input:
// stream[] = {10, 20, 11, 70, 50, 40, 100, 5, ...}
// k = 3

// Output:    {_,   _, 10, 11, 20, 40, 50,  50, ...}
// Extra space allowed is O(k).
#include <bits\stdc++.h>
using std::cout;
using std::cin;
using std::endl;
using std::vector;

// min
void heapify(vector<int>&arr, int i, int size)
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

void MinHeap(vector<int>& arr, int n)
{
    for(int i = (n-1)/2; i>=0; i--)
        heapify(arr, i, n);
    
    for(int i=n-1; i>0; i--)
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, 0 ,i);
    }
}

void display(vector<int> a)
{
    cout<<"\n[ ";
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
    cout<<"]\n";
}

int main()
{
    vector<int> arr;
    int ele;
    int k=3;
    while(true)
    {
        cout<<"\n******************************"<<endl;
        cout<<"enter the element: ";
        cin>>ele;
        arr.push_back(ele);
        MinHeap(arr, arr.size());
        display(arr);
        // cout<<"enter the value of K= ";
        // cin>>k;
        if(k-1<arr.size()){
            cout<<k<<"th largest element = "<<arr[k-1];
            continue;
        }
        cout<<"0x001"<<endl;
    }
}