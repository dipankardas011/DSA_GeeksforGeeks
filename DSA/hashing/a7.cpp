/*Find the first repeating element in an array of integers
Difficulty Level : Easy
Last Updated : 03 Mar, 2021
Given an array of integers, find the first repeating element in it. We need to find the element that occurs more than once and whose index of first occurrence is smallest. 

Examples: 

Input:  arr[] = {10, 5, 3, 4, 3, 5, 6}
Output: 5 [5 is the first element that repeats]

Input:  arr[] = {6, 10, 5, 4, 9, 120, 4, 6, 10}
Output: 6 [6 is the first element that repeats]*/

#include <bits\stdc++.h>
using std::cout;
using std::endl;
using std::unordered_set;

void FirstRepeatingElement(int a[], int n)
{
	unordered_set<int> x;
	int k = INT_MIN;
	for (int i = n - 1; i >= 0; i--)
	{
		if (x.find(a[i]) == x.end())
		{
			// absent
			x.insert(a[i]);
		}
		else
			k = i;
	}
	if(k==INT_MIN)	cout<<"not present unique elements"<<endl;
	else	cout<<"present "<<a[k]<<endl;
	return;
}

int main()
{
	int a[] = {6, 10, 5, 4, 9, 120, 4, 6, 10};
	int n = sizeof(a) / sizeof(a[0]);
	FirstRepeatingElement(a,n);
	return 0;
}