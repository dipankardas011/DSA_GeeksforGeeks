/*Sort an array after applying the given equation
Difficulty Level : Hard
Last Updated : 26 Apr, 2021
Geek-O-Lympics
We have an integer array that is sorted in ascending order. We also have 3 integers A, B and C. We need to apply A*x*x + B*x + C for each element x in the array and sort the modified array. 
Example: 
 

Input : arr[] = {-1, 0, 1, 2, 3, 4} 
       A = -1, B = 2, C = -1
Output : {-9, -4, -4, -1, -1, 0}
Input array is {-1, 0, 1, 2, 3, 4}. After
applying the equation A*x*x + B*x + C on
every element x we get, {-4,-1, 0, -1, -4, -9}
After sorting, we get {-9, -4, -4, -1, -1, 0}*/
// C program to sort an array after applying equation
// A*x*x + B*x + C
#include<bits/stdc++.h>
using namespace std;

// Function to sort an array after applying given
// equation.
void sortArray(int arr[], int n, int A, int B, int C)
{
// Apply equation on all elements
	for (int i = 0; i < n; i++)
		arr[i] = A*arr[i]*arr[i] + B*arr[i] + C;

	// Find maximum element in resultant array
	int index, maximum = INT_MIN;
	for (int i = 0; i< n; i++)
	{
		if (maximum < arr[i])
		{
			index = i;
			maximum = arr[i];
		}
	}

	// Use maximum element as a break point
	// and merge both subarrays usin simple
	// merge function of merge sort
	int i = 0, j = n-1;
	int new_arr[n], k = 0;
	while (i < index && j > index)
	{
		if (arr[i] < arr[j])
			new_arr[k++] = arr[i++];
		else
			new_arr[k++] = arr[j--];
	}

	// Merge remaining elements
	while (i < index)
		new_arr[k++] = arr[i++];
	while (j > index)
		new_arr[k++] = arr[j--];

	new_arr[n-1] = maximum;

	// Modify original array
	for (int i = 0; i < n ; i++)
		arr[i] = new_arr[i];
}

int main(int argc, char const *argv[])
{
	int arr[] = {-21 ,-15, 12, 13, 14 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int A = -6, B =-7, C = 2;

	sortArray(arr, n, A, B, C);

	cout << "Array after sorting is : \n";
	for (int i=0; i<n; i++)
	cout << arr[i] << " ";
    cout<<endl;
    remove(argv[0]);
	return 0;
}
