/**
 * Find median in row wise sorted matrix
Difficulty Level : Hard
Last Updated : 30 Oct, 2020
We are given a row-wise sorted matrix of size r*c, we need to find the median of the matrix given. It is assumed that r*c is always odd.
Examples: 

Input : 1 3 5
        2 6 9
        3 6 9
Output : Median is 5
If we put all the values in a sorted 
array A[] = 1 2 3 3 5 6 6 9 9)

Input: 1 3 4
       2 5 6
       7 8 9
Output: Median is 5
Simple Method: The simplest method to solve this problem is to store all the elements of the given matrix in an array of size r*c. Then we can either sort the array and find the median element in O(r*clog(r*c)) or we can use the approach discussed here to find the median in O(r*c). Auxiliary space required will be O(r*c) in both cases.
An efficient approach for this problem is to use a binary search algorithm. The idea is that for a number to be median there should be exactly (n/2) numbers which are less than this number. So, we try to find the count of numbers less than all the numbers. Below is the step by step algorithm for this approach: 
Algorithm:  

First, we find the minimum and maximum elements in the matrix. The minimum element can be easily found by comparing the first element of each row, and similarly, the maximum element can be found by comparing the last element of each row.
Then we use binary search on our range of numbers from minimum to maximum, we find the mid of the min and max and get a count of numbers less than our mid. And accordingly change the min or max.
For a number to be median, there should be (r*c)/2 numbers smaller than that number. So for every number, we get the count of numbers less than that by using upper_bound() in each row of the matrix, if it is less than the required count, the median must be greater than the selected number, else the median must be less than or equal to the selected number. 
*/
// C++ program to find median of a matrix
// sorted row wise
#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;

// function to find median in the matrix
int binaryMedian(int m[][MAX], int r ,int c)
{
	int min = INT_MAX, max = INT_MIN;
	for (int i=0; i<r; i++)
	{
		// Finding the minimum element
		if (m[i][0] < min)
			min = m[i][0];

		// Finding the maximum element
		if (m[i][c-1] > max)
			max = m[i][c-1];
	}

	int desired = (r * c + 1) / 2;
	while (min < max)
	{
		int mid = min + (max - min) / 2;
		int place = 0;

		// Find count of elements smaller than mid
		for (int i = 0; i < r; ++i)
			place += upper_bound(m[i], m[i]+c, mid) - m[i];
		if (place < desired)
			min = mid + 1;
		else
			max = mid;
	}
	return min;
}

// driver program to check above functions
int main()
{
	int r = 3, c = 3;
	int m[][MAX]= { {1,3,5}, {2,6,9}, {3,6,9} };
	cout << "Median is " << binaryMedian(m, r, c) << endl;
	return 0;
}
