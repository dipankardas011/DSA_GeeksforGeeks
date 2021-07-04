# Linear Search

Problem: Given an array arr[] of n elements, write a function to search a given element x in arr[].

    Examples :  

    Input : arr[] = {10, 20, 80, 30, 60, 50, 
                        110, 100, 130, 170}
            x = 110;
    Output : 6
    Element x is present at index 6

    Input : arr[] = {10, 20, 80, 30, 60, 50, 
                        110, 100, 130, 170}
            x = 175;
    Output : -1
Element x is not present in arr[].
Recommended: Please solve it on “PRACTICE ” first, before moving on to the solution. 
 
A simple approach is to do a linear search, i.e  

Start from the leftmost element of arr[] and one by one compare x with each element of arr[]
If x matches with an element, return the index.
If x doesn’t match with any of elements, return -1.


Example: 

```C++

// C++ code to linearly search x in arr[]. If x
// is present then return its location, otherwise
// return -1
 
#include <iostream>
using namespace std;
 
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
 
// Driver code
int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
   
    // Function call
    int result = search(arr, n, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;
}
```

> to improve the complexity 
1. if element found at last O(n) to O(1)
2. if element not found O(n) to O(n/2)

```c++
// C++ program for linear search
#include<bits/stdc++.h>
using namespace std;

void search(vector<int> arr, int search_Element)
{
	int left = 0;
	int length = arr.size();
	int position = -1;
	int right = length - 1;
	
	// Run loop from 0 to right
	for(left = 0; left <= right;)
	{
		
		// If search_element is found with
		// left variable
		if (arr[left] == search_Element)
		{
			
			position = left;
			cout << "Element found in Array at "
				<< position + 1 << " Position with "
				<< left + 1 << " Attempt";
				
			break;
		}
	
		// If search_element is found with
		// right variable
		if (arr[right] == search_Element)
		{
			position = right;
			cout << "Element found in Array at "
				<< position + 1 << " Position with "
				<< length - right << " Attempt";
				
			break;
		}
		left++;
		right--;
	}

	// If element not found
	if (position == -1)
		cout << "Not found in Array with "
			<< left << " Attempt";
}

// Driver code
int main()
{
	vector<int> arr{ 1, 2, 3, 4, 5 };
	int search_element = 5;
	
	// Function call
	search(arr, search_element);
}
```

# Binary Search
Difficulty Level : Easy
Last Updated : 28 Jun, 2021
Given a sorted array arr[] of n elements, write a function to search a given element x in arr[].
A simple approach is to do a linear search. The time complexity of the above algorithm is O(n). Another approach to perform the same task is using Binary Search. 
Binary Search: Search a sorted array by repeatedly dividing the search interval in half. Begin with an interval covering the whole array. If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half. Otherwise, narrow it to the upper half. Repeatedly check until the value is found or the interval is empty.
 

Example : 

The idea of binary search is to use the information that the array is sorted and reduce the time complexity to O(Log n). 

Recommended: Please solve it on “PRACTICE ” first, before moving on to the solution. 
 
We basically ignore half of the elements just after one comparison.



Compare x with the middle element.
If x matches with the middle element, we return the mid index.
Else If x is greater than the mid element, then x can only lie in the right half subarray after the mid element. So we recur for the right half.
Else (x is smaller) recur for the left half.
Recursive implementation of Binary Search 
```cpp
// C++ program to implement recursive Binary Search
#include <bits/stdc++.h>
using namespace std;

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}

int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
    return 0;
}
```
Output : 

Element is present at index 3
Here you can create a check function for easier implementation.

Here is recursive implementation with check function which I feel is a much easier implementation:

```cpp
#include <bits/stdc++.h>
using namespace std;

//define array globally
const int N = 1e6 +4;

int a[N];
int n;//array size

//elememt to be searched in array
   int k;

bool check(int dig)
{
    //element at dig position in array
    int ele=a[dig];

    //if k is less than
    //element at dig position 
    //then we need to bring our higher ending to dig
    //and then continue further
    if(k<=ele)
    {
        return 1;
    }
    else
    {
    return 0;
    }
}
void binsrch(int lo,int hi)
{
    while(lo<hi)
    {
        int mid=(lo+hi)/2;
        if(check(mid))
        {
            hi=mid;
        }
        else
        {
            lo=mid+1;
        }
    }
    //if a[lo] is k
    if(a[lo]==k)
        cout<<"Element found at index "<<lo;// 0 based indexing
    else
        cout<<"Element doesnt exist in array";//element was not in our array

}


int main()
{   
    cin>>n;
   for(int i=0; i<n; i++)
   {
    cin>>a[i];
   }
   cin>>k;

   //it is being given array is sorted
   //if not then we have to sort it

   //minimum possible point where our k can be is starting index
   //so lo=0 
   //also k cannot be outside of array so end point
   //hi=n

   binsrch(0,n);

    return 0;
}
 ```

Iterative implementation of Binary Search 
```cpp
// C++ program to implement recursive Binary Search
#include <bits/stdc++.h>
using namespace std;

// A iterative binary search function. It returns
// location of x in given array arr[l..r] if present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[m] == x)
            return m;

        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // if we reach here, then element was
    // not present
    return -1;
}

int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
    return 0;
}
```
    Output : 

    Element is present at index 3
Time Complexity: 
The time complexity of Binary Search can be written as 



    T(n) = T(n/2) + c 
The above recurrence can be solved either using the Recurrence Tree method or Master method. It falls in case II of the Master Method and the solution of the recurrence is 

    Theta(Logn)
Auxiliary Space: O(1) in case of iterative implementation. In the case of recursive implementation, O(Logn) recursion call stack space.
Algorithmic Paradigm: Decrease and Conquer.

Note:

Here we are using 

    int mid = low + (high – low)/2;

Maybe, you wonder why we are calculating the middle index this way, we can simply add the lower and higher index and divide it by 2.

    int mid = (low + high)/2;

But if we calculate the middle index like this means our code is not 100% correct, it contains bugs.

That is, it fails for larger values of int variables low and high. Specifically, it fails if the sum of low and high is greater than the maximum positive int value(231 – 1 ).

The sum overflows to a negative value and the value stays negative when divided by 2. In java, it throws ArrayIndexOutOfBoundException.

    int mid = low + (high – low)/2;

So it’s better to use it like this. This bug applies equally to merge sort and other divide and conquer algorithms.

# Interpolation Search
Difficulty Level : Easy
Last Updated : 28 Jun, 2021
Given a sorted array of n uniformly distributed values arr[], write a function to search for a particular element x in the array. 
Linear Search finds the element in O(n) time, Jump Search takes O(√ n) time and Binary Search take O(Log n) time. 
The Interpolation Search is an improvement over Binary Search for instances, where the values in a sorted array are uniformly distributed. Binary Search always goes to the middle element to check. On the other hand, interpolation search may go to different locations according to the value of the key being searched. For example, if the value of the key is closer to the last element, interpolation search is likely to start search toward the end side.
To find the position to be searched, it uses following formula. 

    // The idea of formula is to return higher value of pos
    // when element to be searched is closer to arr[hi]. And
    // smaller value when closer to arr[lo]
    pos = lo + [ (x-arr[lo])*(hi-lo) / (arr[hi]-arr[Lo]) ]

    arr[] ==> Array where elements need to be searched
    x     ==> Element to be searched
    lo    ==> Starting index in arr[]
    hi    ==> Ending index in arr[]
    The formula for pos can be derived as follows.

    Let's assume that the elements of the array are linearly distributed. 

    General equation of line : y = m*x + c.
    y is the value in the array and x is its index.

    Now putting value of lo,hi and x in the equation
    arr[hi] = m*hi+c ----(1)
    arr[lo] = m*lo+c ----(2)
    x = m*pos + c     ----(3)

    m = (arr[hi] - arr[lo] )/ (hi - lo)

    subtracting eqxn (2) from (3)
    x - arr[lo] = m * (pos - lo)
    lo + (x - arr[lo])/m = pos
    pos = lo + (x - arr[lo]) *(hi - lo)/(arr[hi] - arr[lo])
Algorithm 
Rest of the Interpolation algorithm is the same except the above partition logic. 
Step1: In a loop, calculate the value of “pos” using the probe position formula. 
Step2: If it is a match, return the index of the item, and exit. 
Step3: If the item is less than arr[pos], calculate the probe position of the left sub-array. Otherwise calculate the same in the right sub-array. 
Step4: Repeat until a match is found or the sub-array reduces to zero.
Below is the implementation of algorithm. 

```C++
// C++ program to implement interpolation search
#include<bits/stdc++.h>
using namespace std;

// If x is present in arr[0..n-1], then returns
// index of it, else returns -1.
int interpolationSearch(int arr[], int n, int x)
{
    // Find indexes of two corners
    int lo = 0, hi = (n - 1);

    // Since array is sorted, an element present
    // in array must be in range defined by corner
    while (lo <= hi && x >= arr[lo] && x <= arr[hi])
    {
        if (lo == hi)
        {
            if (arr[lo] == x) return lo;
            return -1;
        }
        // Probing the position with keeping
        // uniform distribution in mind.
        int pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));

        // Condition of target found
        if (arr[pos] == x)
            return pos;

        // If x is larger, x is in upper part
        if (arr[pos] < x)
            lo = pos + 1;

        // If x is smaller, x is in the lower part
        else
            hi = pos - 1;
    }
    return -1;
}

// Driver Code
int main()
{
    // Array of items on which search will
    // be conducted.
    int arr[] = {10, 12, 13, 16, 18, 19, 20, 21,
                 22, 23, 24, 33, 35, 42, 47};
    int n = sizeof(arr)/sizeof(arr[0]);

    int x = 18; // Element to be searched
    int index = interpolationSearch(arr, n, x);

    // If element was found
    if (index != -1)
        cout << "Element found at index " << index;
    else
        cout << "Element not found.";
    return 0;
}
```

```C++
// C++ program to implement interpolation
// search with recursion
#include <bits/stdc++.h>
using namespace std;

// If x is present in arr[0..n-1], then returns
// index of it, else returns -1.
int interpolationSearch(int arr[], int lo, int hi, int x)
{
    int pos;

    // Since array is sorted, an element present
    // in array must be in range defined by corner
    if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {

        // Probing the position with keeping
        // uniform distribution in mind.
        pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo]) * (x - arr[lo]));

        // Condition of target found
        if (arr[pos] == x)
            return pos;

        // If x is larger, x is in right sub array
        if (arr[pos] < x)
            return interpolationSearch(arr, pos + 1, hi, x);

        // If x is smaller, x is in left sub array
        if (arr[pos] > x)
            return interpolationSearch(arr, lo, pos - 1, x);
    }
    return -1;
}

// Driver Code
int main()
{

    // Array of items on which search will
    // be conducted.
    int arr[] = { 10, 12, 13, 16, 18, 19, 20, 21,
                  22, 23, 24, 33, 35, 42, 47 };

    int n = sizeof(arr) / sizeof(arr[0]);

    // Element to be searched
    int x = 18;
    int index = interpolationSearch(arr, 0, n - 1, x);

    // If element was found
    if (index != -1)
        cout << "Element found at index " << index;
    else
        cout << "Element not found.";

    return 0;
}
```
# Fibonacci Search

Given a sorted array arr[] of size n and an element x to be searched in it. Return index of x if it is present in array else return -1. 
Examples: 

Input:  arr[] = {2, 3, 4, 10, 40}, x = 10
Output:  3
Element x is present at index 3.

Input:  arr[] = {2, 3, 4, 10, 40}, x = 11
Output:  -1
Element x is not present.
Fibonacci Search is a comparison-based technique that uses Fibonacci numbers to search an element in a sorted array.
Similarities with Binary Search:  

Works for sorted arrays
A Divide and Conquer Algorithm.
Has Log n time complexity.
Differences with Binary Search: 

Fibonacci Search divides given array into unequal parts
Binary Search uses a division operator to divide range. Fibonacci Search doesn’t use /, but uses + and -. The division operator may be costly on some CPUs.
Fibonacci Search examines relatively closer elements in subsequent steps. So when the input array is big that cannot fit in CPU cache or even in RAM, Fibonacci Search can be useful.
Background: 
Fibonacci Numbers are recursively defined as F(n) = F(n-1) + F(n-2), F(0) = 0, F(1) = 1. First few Fibinacci Numbers are 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, …
Observations: 
Below observation is used for range elimination, and hence for the O(log(n)) complexity.  

    F(n - 2) &approx; (1/3)*F(n) and 
    F(n - 1) &approx; (2/3)*F(n).
Algorithm: 
Let the searched element be x.
The idea is to first find the smallest Fibonacci number that is greater than or equal to the length of the given array. Let the found Fibonacci number be fib (m’th Fibonacci number). We use (m-2)’th Fibonacci number as the index (If it is a valid index). Let (m-2)’th Fibonacci Number be i, we compare arr[i] with x, if x is same, we return i. Else if x is greater, we recur for subarray after i, else we recur for subarray before i.
Below is the complete algorithm 
Let arr[0..n-1] be the input array and the element to be searched be x.  



Find the smallest Fibonacci Number greater than or equal to n. Let this number be fibM [m’th Fibonacci Number]. Let the two Fibonacci numbers preceding it be fibMm1 [(m-1)’th Fibonacci Number] and fibMm2 [(m-2)’th Fibonacci Number].
While the array has elements to be inspected: 
Compare x with the last element of the range covered by fibMm2
If x matches, return index
Else If x is less than the element, move the three Fibonacci variables two Fibonacci down, indicating elimination of approximately rear two-third of the remaining array.
Else x is greater than the element, move the three Fibonacci variables one Fibonacci down. Reset offset to index. Together these indicate the elimination of approximately front one-third of the remaining array.
Since there might be a single element remaining for comparison, check if fibMm1 is 1. If Yes, compare x with that remaining element. If match, return index.
```cpp
// C program for Fibonacci Search
#include <stdio.h>

// Utility function to find minimum of two elements
int min(int x, int y) { return (x <= y) ? x : y; }

/* Returns index of x if present, else returns -1 */
int fibMonaccianSearch(int arr[], int x, int n)
{
	/* Initialize fibonacci numbers */
	int fibMMm2 = 0; // (m-2)'th Fibonacci No.
	int fibMMm1 = 1; // (m-1)'th Fibonacci No.
	int fibM = fibMMm2 + fibMMm1; // m'th Fibonacci

	/* fibM is going to store the smallest Fibonacci
	Number greater than or equal to n */
	while (fibM < n) {
		fibMMm2 = fibMMm1;
		fibMMm1 = fibM;
		fibM = fibMMm2 + fibMMm1;
	}

	// Marks the eliminated range from front
	int offset = -1;

	/* while there are elements to be inspected. Note that
	we compare arr[fibMm2] with x. When fibM becomes 1,
	fibMm2 becomes 0 */
	while (fibM > 1) {
		// Check if fibMm2 is a valid location
		int i = min(offset + fibMMm2, n - 1);

		/* If x is greater than the value at index fibMm2,
		cut the subarray array from offset to i */
		if (arr[i] < x) {
			fibM = fibMMm1;
			fibMMm1 = fibMMm2;
			fibMMm2 = fibM - fibMMm1;
			offset = i;
		}

		/* If x is greater than the value at index fibMm2,
		cut the subarray after i+1 */
		else if (arr[i] > x) {
			fibM = fibMMm2;
			fibMMm1 = fibMMm1 - fibMMm2;
			fibMMm2 = fibM - fibMMm1;
		}

		/* element found. return index */
		else
			return i;
	}

	/* comparing the last element with x */
	if (fibMMm1 && arr[offset + 1] == x)
		return offset + 1;

	/*element not found. return -1 */
	return -1;
}

int main(void)
{
	int arr[]
		= { 10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100,235};
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 235;
	int ind = fibMonaccianSearch(arr, x, n);
    if(ind>=0)
        printf("Found at index: %d",ind);
    else
        printf("%d isn't present in the array",x);
	return 0;
}
```

Output
Found at index: 11
Illustration: 
Let us understand the algorithm with the below example:  

![pic](https://media.geeksforgeeks.org/wp-content/cdn-uploads/pic2-1024x136.png)

Illustration assumption: 1-based indexing. Target element x is 85. Length of array n = 11.
Smallest Fibonacci number greate than or equal to 11 is 13. As per our illustration, fibMm2 = 5, fibMm1 = 8, and fibM = 13.
Another implementation detail is the offset variable (zero-initialized). It marks the range that has been eliminated, starting from the front. We will update it from time to time.
Now since the offset value is an index and all indices including it and below it have been eliminated, it only makes sense to add something to it. Since fibMm2 marks approximately one-third of our array, as well as the indices it marks, are sure to be valid ones, we can add fibMm2 to offset and check the element at index i = min(offset + fibMm2, n). 

![fibSearch](https://media.geeksforgeeks.org/wp-content/cdn-uploads/fibSearch-1024x303.png)

Visualization:  

![fibSearch3](https://media.geeksforgeeks.org/wp-content/cdn-uploads/fibSearch31.png)

Time Complexity analysis: 
The worst-case will occur when we have our target in the larger (2/3) fraction of the array, as we proceed to find it. In other words, we are eliminating the smaller (1/3) fraction of the array every time. We call once for n, then for(2/3) n, then for (4/9) n, and henceforth.

![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/fibSearch2-1024x257.png)


# The Ubiquitous Binary Search | Set 1

We all aware of binary search algorithm. Binary search is easiest difficult algorithm to get it right. I present some interesting problems that I collected on binary search. There were some requests on binary search.

I request you to honor the code, “I sincerely attempt to solve the problem and ensure there are no corner cases”. After reading each problem minimize the browser and try solving it.

Problem Statement: Given a sorted array of N distinct elements. Find a key in the array using least number of comparisons. (Do you think binary search is optimal to search a key in sorted array?)

Without much theory, here is typical binary search algorithm.

```cpp
// Returns location of key, or -1 if not found
int BinarySearch(int A[], int l, int r, int key)
{
    int m;
  
    while( l <= r )
    {
        m = l + (r-l)/2;
  
        if( A[m] == key ) // first comparison
            return m;
  
        if( A[m] < key ) // second comparison
            l = m + 1;
        else
            r = m - 1;
    }
  
    return -1;
}
```
Theoretically we need log N + 1 comparisons in worst case. If we observe, we are using two comparisons per iteration except during final successful match, if any. In practice, comparison would be costly operation, it won’t be just primitive type comparison. It is more economical to minimize comparisons as that of theoretical limit.

See below figure on initialize of indices in the next implementation.

The following implementation uses fewer number of comparisons.

```cpp
// Invariant: A[l] <= key and A[r] > key
// Boundary: |r - l| = 1
// Input: A[l .... r-1]
int BinarySearch(int A[], int l, int r, int key)
{
    int m;

    while( r - l > 1 )
    {
        m = l + (r-l)/2;
  
        if( A[m] <= key )
            l = m;
        else
            r = m;
    }
  
    if( A[l] == key )
        return l;
    if( A[r] == key )
        return r;
    else
        return -1;
}
```
In the while loop we are depending only on one comparison. The search space converges to place l and r point two different consecutive elements. We need one more comparison to trace search status.

You can see sample test case http://ideone.com/76bad0. (C++11 code)

Problem Statement: Given an array of N distinct integers, find floor value of input ‘key’. Say, A = {-1, 2, 3, 5, 6, 8, 9, 10} and key = 7, we should return 6 as outcome.

We can use the above optimized implementation to find floor value of key. We keep moving the left pointer to right most as long as the invariant holds. Eventually left pointer points an element less than or equal to key (by definition floor value). The following are possible corner cases,

—> If all elements in the array are smaller than key, left pointer moves till last element.


—> If all elements in the array are greater than key, it is an error condition.

—> If all elements in the array equal and <= key, it is worst case input to our implementation.

Here is implementation,

```cpp
// largest value <= key
// Invariant: A[l] <= key and A[r] > key
// Boundary: |r - l| = 1
// Input: A[l .... r-1]
// Precondition: A[l] <= key <= A[r]
int Floor(int A[], int l, int r, int key)
{
    int m;
  
    while( r - l > 1 )
    {
        m = l + (r - l)/2;
  
        if( A[m] <= key )
            l = m;
        else
            r = m;
    }
  
    return A[l];
}
  
// Initial call
int Floor(int A[], int size, int key)
{
    // Add error checking if key < A[0]
    if( key < A[0] )
        return -1;
  
    // Observe boundaries
    return Floor(A, 0, size, key);
}
```
You can see some test cases http://ideone.com/z0Kx4a.

Problem Statement: Given a sorted array with possible duplicate elements. Find number of occurrences of input ‘key’ in log N time.

The idea here is finding left and right most occurrences of key in the array using binary search. We can modify floor function to trace right most occurrence and left most occurrence. Here is implementation,
```cpp

// Input: Indices Range [l ... r)
// Invariant: A[l] <= key and A[r] > key
int GetRightPosition(int A[], int l, int r, int key)
{
    int m;
  
    while( r - l > 1 )
    {
        m = l + (r - l)/2;
  
        if( A[m] <= key )
            l = m;
        else
            r = m;
    }
  
    return l;
}
  
// Input: Indices Range (l ... r]
// Invariant: A[r] >= key and A[l] > key
int GetLeftPosition(int A[], int l, int r, int key)
{
    int m;
  
    while( r - l > 1 )
    {
        m = l + (r - l)/2;
  
        if( A[m] >= key )
            r = m;
        else
            l = m;
    }
  
    return r;
}
  
int CountOccurances(int A[], int size, int key)
{
    // Observe boundary conditions
    int left = GetLeftPosition(A, -1, size-1, key);
    int right = GetRightPosition(A, 0, size, key);
  
    // What if the element doesn't exists in the array?
    // The checks helps to trace that element exists
    return (A[left] == key && key == A[right])?
           (right - left + 1) : 0;
}
```
Sample code http://ideone.com/zn6R6a.

Problem Statement: Given a sorted array of distinct elements, and the array is rotated at an unknown position. Find minimum element in the array.

We can see  pictorial representation of sample input array in the below figure.


![](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/localminimum.png)


We converge the search space till l and r points single element. If the middle location falls in the first pulse, the condition A[m] < A[r] doesn’t satisfy, we converge our search space to A[m+1 … r]. If the middle location falls in the second pulse, the condition A[m] < A[r] satisfied, we converge our search space to A[1 … m]. At every iteration we check for search space size, if it is 1, we are done.

Given below is implementation of algorithm. Can you come up with different implementation?

```cpp
int BinarySearchIndexOfMinimumRotatedArray(int A[], int l, int r)
{
    // extreme condition, size zero or size two
    int m;
  
    // Precondition: A[l] > A[r]
    if( A[l] <= A[r] )
        return l;
  
    while( l <= r )
    {
        // Termination condition (l will eventually falls on r, and r always
        // point minimum possible value)
        if( l == r )
            return l;
  
        m = l + (r-l)/2; // 'm' can fall in first pulse,
                        // second pulse or exactly in the middle
  
        if( A[m] < A[r] )
            // min can't be in the range
            // (m < i <= r), we can exclude A[m+1 ... r]
            r = m;
        else
            // min must be in the range (m < i <= r),
            // we must search in A[m+1 ... r]
            l = m+1;
    }
  
    return -1;
}
  
int BinarySearchIndexOfMinimumRotatedArray(int A[], int size)
{
    return BinarySearchIndexOfMinimumRotatedArray(A, 0, size-1);
}
```
See sample test cases http://ideone.com/KbwDrk.

Exercises:

1. A function called signum(x, y) is defined as,

signum(x, y) = -1 if x < y
             =  0 if x = y
             =  1 if x > y
Did you come across any instruction set in which a comparison behaves like signum function? Can it make first implementation of binary search optimal?

2. Implement ceil function replica of floor function.

3. Discuss with your friends on “Is binary search optimal (results in least number of comparisons)? Why not ternary search or interpolation search on sorted array? When do you prefer ternary or interpolation search over binary search?”

# Unbounded Binary Search Example (Find the point where a monotonically increasing function becomes positive first time)

Given a function ‘int f(unsigned int x)’ which takes a non-negative integer ‘x’ as input and returns an integer as output. The function is monotonically increasing with respect to the value of x, i.e., the value of f(x+1) is greater than f(x) for every input x. Find the value ‘n’ where f() becomes positive for the first time. Since f() is monotonically increasing, values of f(n+1), f(n+2),… must be positive and values of f(n-2), f(n-3), … must be negative. 
Find n in O(logn) time, you may assume that f(x) can be evaluated in O(1) time for any input x. 

Recommended: Please try your approach on {IDE} first, before moving on to the solution.
A simple solution is to start from i equals to 0 and one by one calculate the value of f(i) for 1, 2, 3, 4 … etc until we find a positive f(i). This works but takes O(n) time.
Can we apply Binary Search to find n in O(Logn) time? We can’t directly apply Binary Search as we don’t have an upper limit or high index. The idea is to do repeated doubling until we find a positive value, i.e., check values of f() for following values until f(i) becomes positive.

  f(0) 
  f(1)
  f(2)
  f(4)
  f(8)
  f(16)
  f(32)
  ....
  ....
  f(high)
Let 'high' be the value of i when f() becomes positive for first time.
Can we apply Binary Search to find n after finding ‘high’? We can apply Binary Search now, we can use ‘high/2’ as low and ‘high’ as high indexes in binary search. The result n must lie between ‘high/2’ and ‘high’.
The number of steps for finding ‘high’ is O(Logn). So we can find ‘high’ in O(Logn) time. What about the time taken by Binary Search between high/2 and high? The value of ‘high’ must be less than 2*n. The number of elements between high/2 and high must be O(n). Therefore, the time complexity of Binary Search is O(Logn) and the overall time complexity is 2*O(Logn) which is O(Logn). 
 

```cpp
#include <stdio.h>
int binarySearch(int low, int high); // prototype
 
// Let's take an example function as f(x) = x^2 - 10*x - 20
// Note that f(x) can be any monotonocally increasing function
int f(int x) { return (x*x - 10*x - 20); }
 
// Returns the value x where above function f() becomes positive
// first time.
int findFirstPositive()
{
    // When first value itself is positive
    if (f(0) > 0)
        return 0;
 
    // Find 'high' for binary search by repeated doubling
    int i = 1;
    while (f(i) <= 0)
        i = i*2;
 
    //  Call binary search
    return binarySearch(i/2, i);
}

// Searches first positive value of f(i) where low <= i <= high
int binarySearch(int low, int high)
{
    if (high >= low)
    {
        int mid = low + (high - low)/2; /* mid = (low + high)/2 */
 
        // If f(mid) is greater than 0 and one of the following two
        // conditions is true:
        // a) mid is equal to low
        // b) f(mid-1) is negative
        if (f(mid) > 0 && (mid == low || f(mid-1) <= 0))
            return mid;
 
        // If f(mid) is smaller than or equal to 0
        if (f(mid) <= 0)
            return binarySearch((mid + 1), high);
        else // f(mid) > 0
            return binarySearch(low, (mid -1));
    }
 
    /* Return -1 if there is no positive value in given range */
    return -1;
}
 
/* Driver program to check above functions */
int main()
{
    printf("The value n where f() becomes positive first is %d", findFirstPositive());
    return 0;
}
```
    Output : 

    The value n where f() becomes positive first is 12