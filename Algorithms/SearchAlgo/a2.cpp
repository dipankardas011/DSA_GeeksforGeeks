/*Two elements whose sum is closest to zero
Difficulty Level : Easy
Last Updated : 23 Apr, 2021
Question: An Array of integers is given, both +ve and -ve. You need to find the two elements such that their sum is closest to zero.
For the below array, program should print -80 and 85.*/
#include <bits/stdc++.h>
using namespace std;
 
// Modified to sort by abolute values
bool compare(int x, int y)
{
    return abs(x) < abs(y);
}
 
void findMinSum(int arr[], int n)
{
    sort(arr, arr + n, compare);
    int min = INT_MAX, x, y;
    for (int i = 1; i < n; i++) {
 
        // Absolute value shows how close it is to zero
        if (abs(arr[i - 1] + arr[i]) <= min) {
 
            // if found an even close value update min and store the index
            min = abs(arr[i - 1] + arr[i]);
            x = i - 1;
            y = i;
        }
    }
    cout << "The two elements whose sum is minimum are "
         << arr[x] << " and " << arr[y];
}
 
int main()
{
 
    int arr[] = { 1, 60, -10, 70, -80, 85 };
    int n = sizeof(arr) / sizeof(arr[0]);
    findMinSum(arr, n);
    return 0;
}