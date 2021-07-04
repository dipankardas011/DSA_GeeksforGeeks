#include <iostream>
using namespace std;

void cycleSort(int arr[], int n){
    int writes=0; // counts the memory writes done

    for(int cycleStart=0;cycleStart<=n-2; cycleStart++)
    {
        int item=arr[cycleStart];
        int pos=cycleStart;

        for(int i=cycleStart+1;i<n;i++)
            if(arr[i] < item)
                pos++;

        // if it returns back to the original pos then no need to change
        if(pos==cycleStart) continue;

        // ignore duplicates
        while(item==arr[pos])
            pos++;

        // put the item to it's rigth position
        if(pos!=cycleStart){
            std::swap(item,arr[pos]);
            writes++;
        }
        // rotate rest of the cycle
        while(pos!=cycleStart){
            pos=cycleStart;
            // find position where we put the element
            for(int i=cycleStart+1;i<n;i++)
                if(item == arr[pos])
                    pos+=1;
            //ignore duplicates
            while(item==arr[pos])
                pos++;

            if(item!=arr[pos]){
                std::swap(item,arr[pos]);
                writes++;
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    int arr[]={1,8,3,9,10,10,2,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    cycleSort(arr,n);
    cout<<"sorted: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    remove(argv[0]);
    return 0;
}
