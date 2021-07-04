/*Check if an array represents Inorder of Binary Search tree or not
Given an array of N element. The task is to check if it is Inorder traversal of any Binary Search Tree or not. Print “Yes” if it is Inorder traversal of any Binary Search Tree else print “No”.

Examples:

Input : arr[] = { 19, 23, 25, 30, 45 }
Output : Yes

Input : arr[] = { 19, 23, 30, 25, 45 }
Output : No
*/
#include <iostream>

bool IsSorted(int arr[], int size)
{
    int temp;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
                return false;
        }
    }
    return true;
}


int main()
{
    // if it is sorted
    int arr1[]={ 19, 23, 25, 30, 45 };
    if(IsSorted(arr1, sizeof(arr1)/sizeof(arr1[0])))
        std::cout<<"YES\n";
    else
        std::cout<<"NO\n";
    int arr2[]={ 19, 23, 30, 25, 45 };
    if(IsSorted(arr2, sizeof(arr2)/sizeof(arr2[0])))
        std::cout<<"YES\n";
    else
        std::cout<<"NO\n";
    return 0;
}