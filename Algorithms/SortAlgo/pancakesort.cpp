#include <iostream>
using namespace std;

void flip(int arr[], int i){
    int start=0;
    while(start<i){
        std::swap(arr[start],arr[i]);
        start++;
        i--;
    }
}

int findMax(int arr[], int n){
    int mi,i;
    for(mi=0,i=0 ; i<n ; ++i)
        if(arr[i]>arr[mi])
            mi=i;
    return mi;
}

void pancakeSort(int *arr, int n){
    for(int currSize=n;currSize>1;--currSize)
    {
        int mi=findMax(arr,currSize);

        if(mi!=currSize-1){
            flip(arr,mi);
            flip(arr,currSize-1);
        }
    }
}

void printArray(int arr[], int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    int arr[]={23,10,20,11,12,6,7};
    int n=sizeof arr / sizeof arr[0];
    pancakeSort(arr, n);
    cout<<"sorted: ";

    printArray(arr,n);
    remove(argv[0]);
    return 0;
}
