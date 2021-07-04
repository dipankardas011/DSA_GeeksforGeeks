#include <iostream>
using namespace std;

void cockTailSort(int a[], int n)
{
    bool swapped=true;
    int start=0;
    int end=n-1;

    while(swapped){
        // reset the swapped
        swapped=false;
        for(int i=start;i<end;i++){
            if(a[i]>a[i+1]){
                std::swap(a[i],a[i+1]);
                swapped=true;
            }
        }
        if(!swapped)
            break;
        // reset it again
        swapped=false;
        // move the end point back by one because item at then end is in rightful spot
        --end;
        for(int i=end-1;i>=start;i--){
            if(a[i]>a[i+1]){
                std::swap(a[i],a[i+1]);
                swapped=true;
            }
        }

        // move the start as the last stage would have moved the next smallest number to tis rightful spot
        ++start;
    }
}

void printArray(int a[], int n){
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int a[]={5,1,4,2,8,0,2};
    int n=(sizeof a) / (sizeof a[0]);
    cockTailSort(a,n);
    cout<<"sorted arr: ";
    printArray(a,n);
    remove(argv[0]);
    return 0;
}
