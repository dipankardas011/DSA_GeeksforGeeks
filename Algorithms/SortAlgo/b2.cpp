/*Sorting Big Integers
Difficulty Level : Easy
Last Updated : 23 Mar, 2017
Geek-O-Lympics
Given a array of n positive integers where each integer can have digits upto 106, print the array elements in ascending order.

Input: arr[] = {54, 724523015759812365462, 870112101220845, 8723} 
Output: 54 8723 870112101220845 724523015759812365462
Explanation:
All elements of array are sorted in non-descending(i.e., ascending)
order of their integer value

Input: arr[] = {3643641264874311, 451234654453211101231,
                4510122010112121012121}
Output: 3641264874311 451234654453211101231 4510122010112121012121*/
// Below is C++ code to sort the Big integers in
// ascending order
#include<bits/stdc++.h>
using namespace std;

// comp function to perform sorting
bool comp(const string &left, const string &right)
{
	// if length of both string are equals then sort
	// them in lexicographically order
	if (left.size() == right.size())
		return left < right;

	// Otherwise sort them according to the length
	// of string in ascending order
	else
		return left.size() < right.size();
}

// Function to sort arr[] elements according
// to integer value
void SortingBigIntegers(string arr[], int n)
{
	// Copy the arr[] elements to sortArr[]
	vector<string> sortArr(arr, arr + n);

	// Inbuilt sort function using function as comp
	sort(sortArr.begin(), sortArr.end(), comp);

	// Print the final sorted array
	for (auto &ele : sortArr)
		cout << ele << " ";

    cout<<endl;
}

int main(int argc, char const *argv[])
{
	string arr[] = {"54", "724523015759812365462", "870112101220845", "8723"};
	int n = sizeof(arr) / sizeof(arr[0]);
	SortingBigIntegers(arr, n);
    remove(argv[0]);
	return 0;
}
