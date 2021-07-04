/*Find a permutation that causes worst case of Merge Sort
Difficulty Level : Hard
Last Updated : 11 Jun, 2021
Geek-O-Lympics
Given a set of elements, find which permutation of these elements would result in worst case of Merge Sort.
Asymptotically, merge sort always takes O(n Log n) time, but the cases that require more comparisons generally take more time in practice. We basically need to find a permutation of input elements that would lead to maximum number of comparisons when sorted using a typical Merge Sort algorithm.

Example: 

Consider the below set of elements 
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 
 13, 14, 15, 16}

Below permutation of the set causes 153
comparisons.
{1, 9, 5, 13, 3, 11, 7, 15, 2, 10, 6, 
 14, 4, 12, 8, 16}

And an already sorted permutation causes
30 comparisons. 

See this for a program that counts 
comparisons and shows above results.

In order to generate the worst case of merge sort, the merge operation that resulted in above sorted array should result in maximum comparisons. In order to do so, the left and right sub-array involved in merge operation should store alternate elements of sorted array. i.e. left sub-array should be {1,3,5,7} and right sub-array should be {2,4,6,8}. Now every element of array will be compared at-least once and that will result in maximum comparisons. We apply the same logic for left and right sub-array as well. For array {1,3,5,7}, the worst case will be when its left and right sub-array are {1,5} and {3,7} respectively and for array {2,4,6,8} the worst case will occur for {2,4} and {6,8}.



Complete Algorithm –
GenerateWorstCase(arr[]) 

Create two auxiliary arrays left and right and store alternate array elements in them.
Call GenerateWorstCase for left subarray: GenerateWorstCase (left)
Call GenerateWorstCase for right subarray: GenerateWorstCase (right)
Copy all elements of left and right subarrays back to original array.*/
// C++ program to generate Worst Case
// of Merge Sort
#include <bits/stdc++.h>
using namespace std;

// Function to print an array
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

// Function to join left and right subarray
int join(int arr[], int left[], int right[], int l, int m, int r)
{
    int i;
    for (i = 0; i <= m - l; i++)
        arr[i] = left[i];

    for (int j = 0; j < r - m; j++)
    {
        arr[i + j] = right[j];
    }
}

// Function to store alternate elements in
// left and right subarray
int split(int arr[], int left[], int right[], int l, int m, int r)
{
    for (int i = 0; i <= m - l; i++)
        left[i] = arr[i * 2];

    for (int i = 0; i < r - m; i++)
        right[i] = arr[i * 2 + 1];
}

// Function to generate Worst Case
// of Merge Sort
int generateWorstCase(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        // Create two auxiliary arrays
        int left[m - l + 1];
        int right[r - m];

        // Store alternate array elements
        // in left and right subarray
        split(arr, left, right, l, m, r);

        // Recurse first and second halves
        generateWorstCase(left, l, m);
        generateWorstCase(right, m + 1, r);

        // Join left and right subarray
        join(arr, left, right, l, m, r);
    }
}

// Driver code
int main()
{

    // Sorted array
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Sorted array is \n";
    printArray(arr, n);

    // Generate Worst Case of Merge Sort
    generateWorstCase(arr, 0, n - 1);

    cout << "\nInput array that will result "
         << "in worst case of merge sort is \n";

    printArray(arr, n);

    return 0;
}
