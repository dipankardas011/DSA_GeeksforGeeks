/*Noble integers in an array (count of greater elements is equal to value)
Difficulty Level : Medium
Last Updated : 18 May, 2021
Geek-O-Lympics
Given an array arr[], find a Noble integer in it. An integer x is said to be Noble in arr[] if the number of integers greater than x is equal to x. If there are many Noble integers, return any of them. If there is no, then return -1.

Examples : 

Input  : [7, 3, 16, 10]
Output : 3  
Number of integers greater than 3
is three.

Input  : [-1, -9, -2, -78, 0]
Output : 0
Number of integers greater than 0
is zero.

Method 2 (Use Sorting)  

1. Sort the Array arr[] in ascending order. This step takes (O(nlogn)).
2. Iterate through the array. Compare the value of index i to the number of elements after index i. If arr[i] equals the number of elements after arr[i], it is a noble Integer. Condition to check: (A[i] == length-i-1). This step takes O(n)
.
Note: Array may have duplicate elements. So, we should skip the elements (adjacent elements in the sorted array) that are same.  */
// C++ program to find Noble elements
// in an array.
#include<bits/stdc++.h>
using namespace std;

// Returns a Noble integer if present,
// else returns -1.
int nobleInteger(int arr[], int n)
{
	sort(arr, arr + n);

	// Return a Noble element if present
	// before last.
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] == arr[i + 1])
			continue;

		// In case of duplicates, we
		// reach last occurrence here.
		if (arr[i] == n - i - 1)
			return arr[i];
	}
	if (arr[n - 1] == 0)
		return arr[n - 1];
	return -1;
}

int main(int argc, char const *argv[])
{
	int arr[] = {10, 3, 20, 40, 2};
	int res = nobleInteger(arr, 5);
	if (res != -1)
		cout << "The noble integer is " << res<<endl;
	else
		cout << "No Noble Integer Found"<<endl;
    remove(argv[0]);
	return 0;
}
