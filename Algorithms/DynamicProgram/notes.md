# Overlapping Subproblems Property in Dynamic Programming | DP-1
Difficulty Level : Easy
Last Updated : 03 Apr, 2019
Dynamic Programming is an algorithmic paradigm that solves a given complex problem by breaking it into subproblems and stores the results of subproblems to avoid computing the same results again. Following are the two main properties of a problem that suggests that the given problem can be solved using Dynamic programming.

In this post, we will discuss first property (Overlapping Subproblems) in detail. The second property of Dynamic programming is discussed in next post i.e. Set 2.

1) Overlapping Subproblems
2) Optimal Substructure

1) Overlapping Subproblems:
Like Divide and Conquer, Dynamic Programming combines solutions to sub-problems. Dynamic Programming is mainly used when solutions of same subproblems are needed again and again. In dynamic programming, computed solutions to subproblems are stored in a table so that these don’t have to be recomputed. So Dynamic Programming is not useful when there are no common (overlapping) subproblems because there is no point storing the solutions if they are not needed again. For example, Binary Search doesn’t have common subproblems. If we take an example of following recursive program for Fibonacci Numbers, there are many subproblems which are solved again and again.

```cpp
/* simple recursive program for Fibonacci numbers */
int fib(int n)
{
   if ( n <= 1 )
      return n;
   return fib(n-1) + fib(n-2);
}
```
    Recursion tree for execution of fib(5)



                                
                            fib(5)
                        /             \
                fib(4)                fib(3)
                /      \                /     \
            fib(3)      fib(2)         fib(2)    fib(1)
            /     \        /    \       /    \
    fib(2)   fib(1)  fib(1) fib(0) fib(1) fib(0)
    /    \
    fib(1) fib(0)
We can see that the function fib(3) is being called 2 times. If we would have stored the value of fib(3), then instead of computing it again, we could have reused the old stored value. There are following two different ways to store the values so that these values can be reused:
a) Memoization (Top Down)
b) Tabulation (Bottom Up)

a) Memoization (Top Down): The memoized program for a problem is similar to the recursive version with a small modification that it looks into a lookup table before computing solutions. We initialize a lookup array with all initial values as NIL. Whenever we need the solution to a subproblem, we first look into the lookup table. If the precomputed value is there then we return that value, otherwise, we calculate the value and put the result in the lookup table so that it can be reused later.

Following is the memoized version for nth Fibonacci Number.

```C++

/* C++ program for Memoized version
for nth Fibonacci number */
#include <bits/stdc++.h>
using namespace std;
#define NIL -1 
#define MAX 100 
  
int lookup[MAX]; 
  
/* Function to initialize NIL 
values in lookup table */
void _initialize() 
{ 
    int i; 
    for (i = 0; i < MAX; i++) 
        lookup[i] = NIL; 
} 
  
/* function for nth Fibonacci number */
int fib(int n) 
{ 
    if (lookup[n] == NIL) 
    { 
        if (n <= 1) 
            lookup[n] = n; 
        else
            lookup[n] = fib(n - 1) + fib(n - 2); 
} 
  
return lookup[n]; 
} 
  
// Driver code
int main () 
{ 
    int n = 40; 
    _initialize(); 
    cout << "Fibonacci number is " << fib(n); 
    return 0; 
} 
 ``` 
```Cpp

/* C program for Memoized version for nth Fibonacci number */
#include<stdio.h>
#define NIL -1
#define MAX 100
  
int lookup[MAX];
  
/* Function to initialize NIL values in lookup table */
void _initialize()
{
  int i;
  for (i = 0; i < MAX; i++)
    lookup[i] = NIL;
}
  
/* function for nth Fibonacci number */
int fib(int n)
{
   if (lookup[n] == NIL)
   {
      if (n <= 1)
         lookup[n] = n;
      else
         lookup[n] = fib(n-1) + fib(n-2);
   }
  
   return lookup[n];
}
  
int main ()
{
  int n = 40;
  _initialize();
  printf("Fibonacci number is %d ", fib(n));
  return 0;
}
```

b) Tabulation (Bottom Up): The tabulated program for a given problem builds a table in bottom up fashion and returns the last entry from table. For example, for the same Fibonacci number, we first calculate fib(0) then fib(1) then fib(2) then fib(3) and so on. So literally, we are building the solutions of subproblems bottom-up.

Following is the tabulated version for nth Fibonacci Number.

```C++

/* C program for Tabulated version */
#include<stdio.h>
int fib(int n)
{
  int f[n+1];
  int i;
  f[0] = 0;   f[1] = 1; 
  for (i = 2; i <= n; i++)
      f[i] = f[i-1] + f[i-2];
  
  return f[n];
}
   
int main ()
{
  int n = 9;
  printf("Fibonacci number is %d ", fib(n));
  return 0;
}
```
```Java

/* Java program for Tabulated version */
public class Fibonacci
{
  int fib(int n)
  {
    int f[] = new int[n+1];
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++)
          f[i] = f[i-1] + f[i-2];
    return f[n];
  }
  
  public static void main(String[] args)
  {
    Fibonacci f = new Fibonacci();
    int n = 9;
    System.out.println("Fibonacci number is" + " " + f.fib(n));
  }
  
}
```

# Optimal Substructure Property in Dynamic Programming | DP-2
Difficulty Level : Easy
Last Updated : 07 Sep, 2018
As we discussed in Set 1, following are the two main properties of a problem that suggest that the given problem can be solved using Dynamic programming:
1) Overlapping Subproblems
2) Optimal Substructure

We have already discussed Overlapping Subproblem property in the Set 1. Let us discuss Optimal Substructure property here.

2) Optimal Substructure: A given problems has Optimal Substructure Property if optimal solution of the given problem can be obtained by using optimal solutions of its subproblems.

For example, the Shortest Path problem has following optimal substructure property:
If a node x lies in the shortest path from a source node u to destination node v then the shortest path from u to v is combination of shortest path from u to x and shortest path from x to v. The standard All Pair Shortest Path algorithms like Floyd–Warshall and Bellman–Ford are typical examples of Dynamic Programming.

On the other hand, the Longest Path problem doesn’t have the Optimal Substructure property. Here by Longest Path we mean longest simple path (path without cycle) between two nodes. Consider the following unweighted graph given in the CLRS book. There are two longest paths from q to t: q→r→t and q→s→t. Unlike shortest paths, these longest paths do not have the optimal substructure property. For example, the longest path q→r→t is not a combination of longest path from q to r and longest path from r to t, because the longest path from q to r is q→s→t→r and the longest path from r to t is r→q→s→t.

![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/LongestPath.gif)

We will be covering some example problems in future posts on Dynamic Programming.

# Longest Increasing Subsequence | DP-3
Difficulty Level : Medium
Last Updated : 28 May, 2021
We have already discussed Overlapping Subproblems and Optimal Substructure properties. 
Now, let us discuss the Longest Increasing Subsequence (LIS) problem as an example problem that can be solved using Dynamic Programming. 

The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order. For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}. 

longest-increasing-subsequence

Examples: 

Input: arr[] = {3, 10, 2, 1, 20}
Output: Length of LIS = 3
The longest increasing subsequence is 3, 10, 20

Input: arr[] = {3, 2}
Output: Length of LIS = 1
The longest increasing subsequences are {3} and {2}

Input: arr[] = {50, 3, 10, 7, 40, 80}
Output: Length of LIS = 4
The longest increasing subsequence is {3, 7, 40, 80}
 
![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Longest-Increasing-Subsequence.png)


 
Method 1: Recursion.
Optimal Substructure: Let arr[0..n-1] be the input array and L(i) be the length of the LIS ending at index i such that arr[i] is the last element of the LIS.

Then, L(i) can be recursively written as: 

L(i) = 1 + max( L(j) ) where 0 < j < i and arr[j] < arr[i]; or
L(i) = 1, if no such j exists.
To find the LIS for a given array, we need to return max(L(i)) where 0 < i < n.
Formally, the length of the longest increasing subsequence ending at index i, will be 1 greater than the maximum of lengths of all longest increasing subsequences ending at indices before i, where arr[j] < arr[i] (j < i).
Thus, we see the LIS problem satisfies the optimal substructure property as the main problem can be solved using solutions to subproblems.

The recursive tree given below will make the approach clearer:  

Input  : arr[] = {3, 10, 2, 11}
f(i): Denotes LIS of subarray ending at index 'i'

(LIS(1)=1)

        f(4)  {f(4) = 1 + max(f(1), f(2), f(3))}
    /    |    \
  f(1)  f(2)  f(3) {f(3) = 1, f(2) and f(1) are > f(3)}
        |      |  \
        f(1)  f(2)  f(1) {f(2) = 1 + max(f(1)}
                |
              f(1) {f(1) = 1}
Below is the implementation of the recursive approach: 

```cpp
/* A Naive C/C++ recursive implementation
of LIS problem */
#include <stdio.h>
#include <stdlib.h>
 
/* To make use of recursive calls, this
function must return two things:
1) Length of LIS ending with element arr[n-1].
    We use max_ending_here for this purpose
2) Overall maximum as the LIS may end with
    an element before arr[n-1] max_ref is
    used this purpose.
The value of LIS of full array of size n
is stored in *max_ref which is our final result
*/
int _lis(int arr[], int n, int* max_ref)
{
    /* Base case */
    if (n == 1)
        return 1;
 
    // 'max_ending_here' is length of LIS
    // ending with arr[n-1]
    int res, max_ending_here = 1;
 
    /* Recursively get all LIS ending with arr[0],
    arr[1] ... arr[n-2]. If arr[i-1] is smaller
    than arr[n-1], and max ending with arr[n-1]
    needs to be updated, then update it */
    for (int i = 1; i < n; i++) {
        res = _lis(arr, i, max_ref);
        if (arr[i - 1] < arr[n - 1]
            && res + 1 > max_ending_here)
            max_ending_here = res + 1;
    }
 
    // Compare max_ending_here with the overall
    // max. And update the overall max if needed
    if (*max_ref < max_ending_here)
        *max_ref = max_ending_here;
 
    // Return length of LIS ending with arr[n-1]
    return max_ending_here;
}
 
// The wrapper function for _lis()
int lis(int arr[], int n)
{
    // The max variable holds the result
    int max = 1;
 
    // The function _lis() stores its result in max
    _lis(arr, n, &max);
 
    // returns max
    return max;
}
 
/* Driver program to test above function */
int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Length of lis is %d", lis(arr, n));
    return 0;
}
```
  Output: 

  Length of lis is 5
Complexity Analysis: 

Time Complexity: The time complexity of this recursive approach is exponential as there is a case of overlapping subproblems as explained in the recursive tree diagram above.
Auxiliary Space: O(1). No external space used for storing values apart from the internal stack space.
Method 2: Dynamic Programming.
We can see that there are many subproblems in the above recursive solution which are solved again and again. So this problem has Overlapping Substructure property and recomputation of same subproblems can be avoided by either using Memoization or Tabulation.



The simulation of approach will make things clear:  

  Input  : arr[] = {3, 10, 2, 11}
  LIS[] = {1, 1, 1, 1} (initially)
  Iteration-wise simulation : 

  arr[2] > arr[1] {LIS[2] = max(LIS [2], LIS[1]+1)=2}
  arr[3] < arr[1] {No change}
  arr[3] < arr[2] {No change}
  arr[4] > arr[1] {LIS[4] = max(LIS [4], LIS[1]+1)=2}
  arr[4] > arr[2] {LIS[4] = max(LIS [4], LIS[2]+1)=3}
  arr[4] > arr[3] {LIS[4] = max(LIS [4], LIS[3]+1)=3}
We can avoid recomputation of subproblems by using tabulation as shown in the below code: 

Below is the implementation of the above approach:  

```cpp
/* Dynamic Programming C++ implementation
   of LIS problem */
#include <bits/stdc++.h>
using namespace std;
 
/* lis() returns the length of the longest
  increasing subsequence in arr[] of size n */
int lis(int arr[], int n)
{
    int lis[n];
 
    lis[0] = 1;
 
    /* Compute optimized LIS values in
       bottom up manner */
    for (int i = 1; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }
 
    // Return maximum value in lis[]
    return *max_element(lis, lis + n);
}
 
/* Driver program to test above function */
int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Length of lis is %d\n", lis(arr, n));
 
    return 0;
}
```
  Output
  Length of lis is 5
Complexity Analysis: 

Time Complexity: O(n2). 
As nested loop is used.
Auxiliary Space: O(n). 
Use of any array to store LIS values at each index.
Note: The time complexity of the above Dynamic Programming (DP) solution is O(n^2) and there is a O(N log N) solution for the LIS problem. We have not discussed the O(N log N) solution here as the purpose of this post is to explain Dynamic Programming with a simple example. See below post for O(N log N) solution. 
Longest Increasing Subsequence Size (N log N)

Method 3: Dynamic Programming

If we closely observe the problem then we can convert this problem to longest Common Subsequence Problem. Firstly we will create another array of unique elements of original array and sort it. Now the longest increasing subsequence of our array must be present as a subsequence in our sorted array. That’s why our problem is now reduced to finding the common subsequence between the two arrays.

Eg. arr =[50,3,10,7,40,80]
    // Sorted array
    arr1 = [3,7,10,40,50,80]
    // LIS is longest common subsequence between the two arrays
    ans = 4
    The longest increasing subsequence is {3, 7, 40, 80}
    

# Dynamic Programming Approach of Finding LIS by reducing the problem to longest common Subsequence
 ```py3
def lis(a):
    n=len(a)
    # Creating the sorted list
    b=sorted(list(set(a)))
    m=len(b)
     
     
    # Creating dp table for storing the answers of sub problems
    dp=[[-1 for i in range(m+1)] for j in range(n+1)]
     
    # Finding Longest common Subsequence of the two arrays
    for i in range(n+1):
             
        for j in range(m+1):
            if i==0 or j==0:
                dp[i][j]=0
            elif a[i-1]==b[j-1]:
                dp[i][j]=1+dp[i-1][j-1]
            else:
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])
    return dp[-1][-1]
     
# Driver program to test above function
arr = [10, 22, 9, 33, 21, 50, 41, 60]
print("Length of lis is ", lis(arr))

```   
  Output

  Length of lis is  5
Complexity Analysis : O(n*n)

As nested loop is used

Space Complexity : O(n*n)

As a matrix is used for storing the values.