/*Count number of occurrences (or frequency) in a sorted array
Difficulty Level : Medium
Last Updated : 28 May, 2021
 
Given a sorted array arr[] and a number x, write a function that counts the occurrences of x in arr[]. Expected time complexity is O(Logn) 

Examples: 

  Input: arr[] = {1, 1, 2, 2, 2, 2, 3,},   x = 2
  Output: 4 // x (or 2) occurs 4 times in arr[]

  Input: arr[] = {1, 1, 2, 2, 2, 2, 3,},   x = 3
  Output: 1 

  Input: arr[] = {1, 1, 2, 2, 2, 2, 3,},   x = 1
  Output: 2 

  Input: arr[] = {1, 1, 2, 2, 2, 2, 3,},   x = 4
  Output: -1 // 4 doesn't occur in arr[] */
// C++ program to count occurrences of an element
// in a sorted array.
#include <bits/stdc++.h>
using namespace std;

/* if x is present in arr[] then returns the count
	of occurrences of x, otherwise returns 0. */
int count(int arr[], int x, int n)
{
    /* get the index of first occurrence of x */
    int *low = lower_bound(arr, arr + n, x);

    // If element is not present, return 0
    if (low == (arr + n) || *low != x)
        return 0;

    /* Else get the index of last occurrence of x. Note that we are only looking in the subarray after first occurrence */
    int *high = upper_bound(low, arr + n, x);

    /* return count */
    return high - low;
}

int main()
{
    int arr[] = {1, 2, 2, 3, 3, 3, 3};
    int x = 3; // Element to be counted in arr[]
    int n = sizeof(arr) / sizeof(arr[0]);
    int c = count(arr, x, n);
    printf(" %d occurs %d times ", x, c);
    return 0;
}
