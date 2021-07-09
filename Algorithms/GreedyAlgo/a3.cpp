#include <algorithm>
#include <iostream>

int findPlatform(int arr[], int dep[] , int n)
{
    std::sort(arr, arr+n);
    std::sort(dep,dep+n);

    int Noplatform=1;
    int result=1;
    int i=1,j=0;

    while(i<n && j<n)
    {
        // If next event in sorted order is arrival,
        // increment count of platforms needed
        if(arr[i]<=dep[j])
        {
            Noplatform++;
            i++;
        }
        // Else decrement count of platforms needed
        else if(arr[i]>dep[j])
        {
            Noplatform--;
            j++;
        }
        // Update result if needed
        if(Noplatform  >result)
            result=Noplatform;
    }

    return result;
}

int main(int argc, char const *argv[])
{
    int arr[] = { 900, 940, 950, 1100, 1500, 1800 };
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 };
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Minimum Number of Platforms Required = " << findPlatform(arr, dep, n) <<std::endl;
    remove(argv[0]);
    return 0;
}
