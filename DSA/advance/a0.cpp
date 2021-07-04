// Find the maximum subset XOR of a given set
// Difficulty Level : Expert
// Last Updated : 06 Apr, 2021
// Given an set of positive integers. find the maximum XOR subset value in the given set. Expected time complexity O(n).
// Examples:

// Input: set[] = {2, 4, 5}
// Output: 7
// The subset {2, 5} has maximum XOR value

// Input: set[] = {9, 8, 5}
// Output: 13
// The subset {8, 5} has maximum XOR value

// Input: set[] = {8, 1, 2, 12, 7, 6}
// Output: 15
// The subset {1, 2, 12} has maximum XOR value

// Input: set[] = {4, 6}
// Output: 6
// The subset {6} has maximum XOR value
// Note that this problem is different from the maximum subarray XOR. Here we need to find subset instead of subarray.
 

// Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.
// A Simple Solution is to generate all possible subsets of given set, find XOR of every subset and return the subset with maximum XOR.
// Below is an Efficient Algorithm that works in O(n) time. 
// The idea is based on below facts: 
 

// Number of bits to represent all elements is fixed which is 32 bits for integer in most of the compilers.
// If maximum element has Most Significant Bit MSB at position i, then result is at least 2i
 

// 1. Initialize index of chosen elements as 0. Let this index be 
//    'index'
// 2. Traverse through all bits starting from most significant bit. 
//    Let i be the current bit.
// ......(a) Find the maximum element with i'th bit set.  If there
//           is no element with i'th bit set, continue to smaller 
//           bit.  
// ......(b) Let the element with i'th bit set be maxEle and index
//           of this element be maxInd. Place maxEle at 'index' and
//           (by swapping set[index] and set[maxInd]) 
// ......(c) Do XOR of maxEle with all numbers having i'th  bit as set.
// ......(d) Increment index 
// 3. Return XOR of all elements in set[]. Note that set[] is modified
//    in step 2.c.
// Below is the implementation of this algorithm.
// C++ program to find
// maximum XOR subset
#include <bits/stdc++.h>
using namespace std;

// Number of bits to
// represent int
#define INT_BITS 32

// Function to return
// maximum XOR subset
// in set[]
int maxSubarrayXOR(int set[], int n)
{
	// Initialize index of
	// chosen elements
	int index = 0;

	// Traverse through all
	// bits of integer
	// starting from the most
	// significant bit (MSB)
	for (int i = INT_BITS-1; i >= 0; i--)
	{
		// Initialize index of
		// maximum element and
		// the maximum element
		int maxInd = index;
		int maxEle = INT_MIN;
		for (int j = index; j < n; j++)
		{
			// If i'th bit of set[j]
			// is set and set[j] is
			// greater than max so far.
			if ( (set[j] & (1 << i)) != 0
					&& set[j] > maxEle )
				maxEle = set[j], maxInd = j;
		}

		// If there was no
		// element with i'th
		// bit set, move to
		// smaller i
		if (maxEle == INT_MIN)
		continue;

		// Put maximum element
		// with i'th bit set
		// at index 'index'
		swap(set[index], set[maxInd]);

		// Update maxInd and
		// increment index
		maxInd = index;

		// Do XOR of set[maxIndex]
		// with all numbers having
		// i'th bit as set.
		for (int j=0; j<n; j++)
		{
			// XOR set[maxInd] those
			// numbers which have the
			// i'th bit set
			if (j != maxInd &&
			(set[j] & (1 << i)) != 0)
				set[j] = set[j] ^ set[maxInd];
		}

		// Increment index of
		// chosen elements
		index++;
	}

	// Final result is
	// XOR of all elements
	int res = 0;
	for (int i = 0; i < n; i++)
		res ^= set[i];
	return res;
}

// Driver program
int main()
{
	int set[] = {9, 8, 5};
	int n = sizeof(set) / sizeof(set[0]);
	
	cout << "Max subset XOR is ";
	cout << maxSubarrayXOR(set, n);
	return 0;
}
