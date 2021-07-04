# Analysis of Algorithms | Set 2 (Worst, Average and Best Cases)
In the previous post, we discussed how Asymptotic analysis overcomes the problems of naive way of analyzing algorithms. In this post, we will take an example of Linear Search and analyze it using Asymptotic analysis.
We can have three cases to analyze an algorithm: 
1. The Worst Case 
2. Average Case 
3. Best Case
Let us consider the following implementation of Linear Search. 
 

```C++

// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;
  
// Linearly search x in arr[].
// If x is present then return the index,
// otherwise return -1
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}
  
// Driver Code
int main()
{
    int arr[] = { 1, 10, 30, 15 };
    int x = 30;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << x << " is present at index "
         << search(arr, n, x);
  
    getchar();
    return 0;
}
  
```
```C

// C implementation of the approach
#include <stdio.h>
  
// Linearly search x in arr[].
// If x is present then return the index,
// otherwise return -1
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}
  
/* Driver program to test above functions*/
int main()
{
    int arr[] = { 1, 10, 30, 15 };
    int x = 30;
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d is present at index %d", x,
           search(arr, n, x));
  
    getchar();
    return 0;
}
```
```Java

// Java implementation of the approach
  
public class GFG {
  
    // Linearly search x in arr[].  If x is present then
    // return the index, otherwise return -1
    static int search(int arr[], int n, int x)
    {
        int i;
        for (i = 0; i < n; i++) {
            if (arr[i] == x) {
                return i;
            }
        }
        return -1;
    }
  
    /* Driver program to test above functions*/
    public static void main(String[] args)
    {
        int arr[] = { 1, 10, 30, 15 };
        int x = 30;
        int n = arr.length;
        System.out.printf("%d is present at index %d", x,
                          search(arr, n, x));
    }
}
```

```Python 3

# Python 3 implementation of the approach
  
# Linearly search x in arr[]. If x is present
# then return the index, otherwise return -1
  
  
def search(arr, x):
    for index, value in enumerate(arr):
        if value == x:
            return index
    return -1
  
  
# Driver Code
arr = [1, 10, 30, 15]
x = 30
print(x, "is present at index",
      search(arr, x))
```  

```C#

// C# implementation of the approach
using System;
public class GFG {
  
    // Linearly search x in arr[].  If x is present then
    // return the index, otherwise return -1
    static int search(int[] arr, int n, int x)
    {
        int i;
        for (i = 0; i < n; i++) {
            if (arr[i] == x) {
                return i;
            }
        }
        return -1;
    }
  
    /* Driver program to test above functions*/
    public static void Main()
    {
        int[] arr = { 1, 10, 30, 15 };
        int x = 30;
        int n = arr.Length;
        Console.WriteLine(x + " is present at index "
                          + search(arr, n, x));
    }
}
```

`Worst Case Analysis (Usually Done) `
In the worst case analysis, we calculate upper bound on running time of an algorithm. We must know the case that causes maximum number of operations to be executed. For Linear Search, the worst case happens when the element to be searched (x in the above code) is not present in the array. When x is not present, the search() functions compares it with all the elements of arr[] one by one. Therefore, the worst case time complexity of linear search would be Θ(n).

`Average Case Analysis (Sometimes done) `
In average case analysis, we take all possible inputs and calculate computing time for all of the inputs. Sum all the calculated values and divide the sum by total number of inputs. We must know (or predict) distribution of cases. For the linear search problem, let us assume that all cases are uniformly distributed (including the case of x not being present in array). So we sum all the cases and divide the sum by (n+1). Following is the value of average case time complexity. 
 

Average Case Time =  
![analysis1](https://media.geeksforgeeks.org/wp-content/cdn-uploads/analysis1.png)
= ![analysis2](https://media.geeksforgeeks.org/wp-content/cdn-uploads/analysis2.png)
= Θ(n) 
Best Case Analysis (Bogus) 
In the best case analysis, we calculate lower bound on running time of an algorithm. We must know the case that causes minimum number of operations to be executed. In the linear search problem, the best case occurs when x is present at the first location. The number of operations in the best case is constant (not dependent on n). So time complexity in the best case would be Θ(1) 
Most of the times, we do worst case analysis to analyze algorithms. In the worst analysis, we guarantee an upper bound on the running time of an algorithm which is good information. 
The average case analysis is not easy to do in most of the practical cases and it is rarely done. In the average case analysis, we must know (or predict) the mathematical distribution of all possible inputs. 
The Best Case analysis is bogus. Guaranteeing a lower bound on an algorithm doesn’t provide any information as in the worst case, an algorithm may take years to run.
For some algorithms, all the cases are asymptotically same, i.e., there are no worst and best cases. For example, Merge Sort. Merge Sort does Θ(nLogn) operations in all cases. Most of the other sorting algorithms have worst and best cases. For example, in the typical implementation of Quick Sort (where pivot is chosen as a corner element), the worst occurs when the input array is already sorted and the best occur when the pivot elements always divide array in two halves. For insertion sort, the worst case occurs when the array is reverse sorted and the best case occurs when the array is sorted in the same order as output.

# Analysis of Algorithms | Set 3 (Asymptotic Notations)
Difficulty Level : Easy
Last Updated : 04 Feb, 2021
We have discussed Asymptotic Analysis, and Worst, Average, and Best Cases of Algorithms. The main idea of asymptotic analysis is to have a measure of the efficiency of algorithms that don’t depend on machine-specific constants and doesn’t require algorithms to be implemented and time taken by programs to be compared. Asymptotic notations are mathematical tools to represent the time complexity of algorithms for asymptotic analysis. The following 3 asymptotic notations are mostly used to represent the time complexity of algorithms. 

 

![thetanotation](https://media.geeksforgeeks.org/wp-content/uploads/AlgoAnalysis-1.png)

1) Θ Notation: The theta notation bounds a function from above and below, so it defines exact asymptotic behavior. 
A simple way to get Theta notation of an expression is to drop low order terms and ignore leading constants. For example, consider the following expression. 
3n3 + 6n2 + 6000 = Θ(n3) 
Dropping lower order terms is always fine because there will always be a number(n) after which Θ(n3) has higher values than Θ(n2) irrespective of the constants involved. 
For a given function g(n), we denote Θ(g(n)) is following set of functions. 
 

    Θ(g(n)) = {f(n): there exist positive constants c1, c2 and n0 such 
                    that 0 <= c1*g(n) <= f(n) <= c2*g(n) for all n >= n0}
The above definition means, if f(n) is theta of g(n), then the value f(n) is always between c1*g(n) and c2*g(n) for large values of n (n >= n0). The definition of theta also requires that f(n) must be non-negative for values of n greater than n0. 



 

![BigO](https://media.geeksforgeeks.org/wp-content/uploads/AlgoAnalysis-2.png)

2) Big O Notation: The Big O notation defines an upper bound of an algorithm, it bounds a function only from above. For example, consider the case of Insertion Sort. It takes linear time in best case and quadratic time in worst case. We can safely say that the time complexity of Insertion sort is O(n^2). Note that O(n^2) also covers linear time. 
If we use Θ notation to represent time complexity of Insertion sort, we have to use two statements for best and worst cases: 
1. The worst case time complexity of Insertion Sort is Θ(n^2). 
2. The best case time complexity of Insertion Sort is Θ(n). 

The Big O notation is useful when we only have upper bound on time complexity of an algorithm. Many times we easily find an upper bound by simply looking at the algorithm.  

    O(g(n)) = { f(n): there exist positive constants c and 
                    n0 such that 0 <= f(n) <= c*g(n) for 
                    all n >= n0}
 

![BigOmega](https://media.geeksforgeeks.org/wp-content/uploads/AlgoAnalysis-3.png)

3) Ω Notation: Just as Big O notation provides an asymptotic upper bound on a function, Ω notation provides an asymptotic lower bound. 
Ω Notation can be useful when we have lower bound on time complexity of an algorithm. As discussed in the previous post, the best case performance of an algorithm is generally not useful, the Omega notation is the least used notation among all three. 

For a given function g(n), we denote by Ω(g(n)) the set of functions.  



    Ω (g(n)) = {f(n): there exist positive constants c and
                    n0 such that 0 <= c*g(n) <= f(n) for
                    all n >= n0}.
Let us consider the same Insertion sort example here. The time complexity of Insertion Sort can be written as Ω(n), but it is not a very useful information about insertion sort, as we are generally interested in worst case and sometimes in average case. 

Properties of Asymptotic Notations : 
As we have gone through the definition of this three notations let’s now discuss some important properties of those notations. 

1. General Properties : 

     If f(n) is O(g(n)) then a*f(n) is also O(g(n)) ; where a is a constant. 

     Example: f(n) = 2n²+5 is O(n²) 
     then 7*f(n) = 7(2n²+5) = 14n²+35 is also O(n²) .

     Similarly this property satisfies for both Θ and Ω notation. 
 

     We can say 
     If f(n) is Θ(g(n)) then a*f(n) is also Θ(g(n)) ; where a is a constant. 
     If f(n) is Ω (g(n)) then a*f(n) is also Ω (g(n)) ; where a is a constant.

2. Transitive Properties : 

    If f(n) is O(g(n)) and g(n) is O(h(n)) then f(n) = O(h(n)) .

    Example: if f(n) = n, g(n) = n² and h(n)=n³
    n is O(n²) and n² is O(n³)
    then n is O(n³)



   Similarly this property satisfies for both Θ and Ω notation.

   We can say
   If f(n) is Θ(g(n)) and g(n) is Θ(h(n)) then f(n) = Θ(h(n)) .
   If f(n) is Ω (g(n)) and g(n) is Ω (h(n)) then f(n) = Ω (h(n))

3. Reflexive Properties : 

      Reflexive properties are always easy to understand after transitive.

      If f(n) is given then f(n) is O(f(n)). Since MAXIMUM VALUE OF f(n) will be f(n) ITSELF !

      Hence x = f(n) and y = O(f(n) tie themselves in reflexive relation always.

      Example: f(n) = n² ; O(n²) i.e O(f(n))

      Similarly this property satisfies for both Θ and Ω notation.

      We can say that:

      If f(n) is given then f(n) is Θ(f(n)).

      If f(n) is given then f(n) is Ω (f(n)).

4. Symmetric Properties : 
 

      If f(n) is Θ(g(n)) then g(n) is Θ(f(n)) . 
 

      Example: f(n) = n² and g(n) = n² 
      then f(n) = Θ(n²) and g(n) = Θ(n²) 
 

      This property only satisfies for Θ notation.

5. Transpose Symmetric Properties : 
 

      If f(n) is O(g(n)) then g(n) is Ω (f(n)). 
 

      Example: f(n) = n , g(n) = n² 
      then n is O(n²) and n² is Ω (n) 

This property only satisfies for O and Ω notations.

6. Some More Properties : 

     1.) If f(n) = O(g(n)) and f(n) = Ω(g(n)) then f(n) = Θ(g(n))

     2.) If f(n) = O(g(n)) and d(n)=O(e(n)) 
          then f(n) + d(n) = O( max( g(n), e(n) )) 
          Example: f(n) = n i.e O(n) 
                         d(n) = n² i.e O(n²) 
                         then f(n) + d(n) = n + n² i.e O(n²)



      3.) If f(n)=O(g(n)) and d(n)=O(e(n)) 
           then f(n) * d(n) = O( g(n) * e(n) ) 
           Example: f(n) = n i.e O(n) 
           d(n) = n² i.e O(n²) 
                      then f(n) * d(n) = n * n² = n³ i.e O(n³)

# Analysis of algorithms | little o and little omega notations
Difficulty Level : Easy
Last Updated : 19 Apr, 2020
The main idea of asymptotic analysis is to have a measure of efficiency of algorithms that doesn’t depend on machine specific constants, mainly because this analysis doesn’t require algorithms to be implemented and time taken by programs to be compared. We have already discussed Three main asymptotic notations. The following 2 more asymptotic notations are used to represent time complexity of algorithms.

Little ο asymptotic notation

Big-Ο is used as a tight upper-bound on the growth of an algorithm’s effort (this effort is described by the function f(n)), even though, as written, it can also be a loose upper-bound. “Little-ο” (ο()) notation is used to describe an upper-bound that cannot be tight.

Definition : Let f(n) and g(n) be functions that map positive integers to positive real numbers. We say that f(n) is ο(g(n)) (or f(n) Ε ο(g(n))) if for any real constant c > 0, there exists an integer constant n0 ≥ 1 such that 0 ≤ f(n) < c*g(n).

Thus, little o() means loose upper-bound of f(n). Little o is a rough estimate of the maximum order of growth whereas Big-Ο may be the actual order of growth.

![](https://media.geeksforgeeks.org/wp-content/uploads/Analysis-of-Algorithms-little-o-omega.png)

In mathematical relation,
f(n) = o(g(n)) means
lim  f(n)/g(n) = 0
n→∞


Examples:

Is 7n + 8 ∈ o(n2)?
In order for that to be true, for any c, we have to be able to find an n0 that makes
f(n) < c * g(n) asymptotically true.
lets took some example,
If c = 100,we check the inequality is clearly true. If c = 1/100 , we’ll have to use
a little more imagination, but we’ll be able to find an n0. (Try n0 = 1000.) From
these examples, the conjecture appears to be correct.
then check limits,
lim  f(n)/g(n) = lim  (7n + 8)/(n2) = lim  7/2n = 0 (l’hospital)
n→∞ n→∞ n→∞



hence 7n + 8 ∈ o(n2)

Little ω asymptotic notation

Definition : Let f(n) and g(n) be functions that map positive integers to positive real numbers. We say that f(n) is ω(g(n)) (or f(n) ∈ ω(g(n))) if for any real constant c > 0, there exists an integer constant n0 ≥ 1 such that f(n) > c * g(n) ≥ 0 for every integer n ≥ n0.

f(n) has a higher growth rate than g(n) so main difference between Big Omega (Ω) and little omega (ω) lies in their definitions.In the case of Big Omega f(n)=Ω(g(n)) and the bound is 0<=cg(n)<=f(n), but in case of little omega, it is true for 0<=c*g(n)<f(n).

The relationship between Big Omega (Ω) and Little Omega (ω) is similar to that of Big-Ο and Little o except that now we are looking at the lower bounds. Little Omega (ω) is a rough estimate of the order of the growth whereas Big Omega (Ω) may represent exact order of growth. We use ω notation to denote a lower bound that is not asymptotically tight.
And, f(n) ∈ ω(g(n)) if and only if g(n) ∈ ο((f(n)).

In mathematical relation,
if f(n) ∈ ω(g(n)) then,

lim  f(n)/g(n) = ∞
n→∞

Example:
Prove that 4n + 6 ∈ ω(1);
the little omega(ο) running time can be proven by applying limit formula given below.
if lim  f(n)/g(n) = ∞ then functions f(n) is ω(g(n))
n→∞
here,we have functions f(n)=4n+6 and g(n)=1
lim   (4n+6)/(1) = ∞
n→∞
and,also for any c we can get n0 for this inequality 0 <= c*g(n) < f(n), 0 <= c*1 < 4n+6
Hence proved.

# Lower and Upper Bound Theory

The Lower and Upper Bound Theory provides a way to find the lowest complexity algorithm to solve a problem. Before understanding the theory, first lets have a brief look on what actually Lower and Upper bounds are. 

Lower Bound – 
Let L(n) be the running time of an algorithm A(say), then g(n) is the Lower Bound of A if there exist two constants C and N such that L(n) >= C*g(n) for n > N. Lower bound of an algorithm is shown by the asymptotic notation called Big Omega (or just Omega). 
 
Upper Bound – 
Let U(n) be the running time of an algorithm A(say), then g(n) is the Upper Bound of A if there exist two constants C and N such that U(n) <= C*g(n) for n > N. Upper bound of an algorithm is shown by the asymptotic notation called Big Oh(O) (or just Oh). 
1. Lower Bound Theory: 
According to the lower bound theory, for a lower bound L(n) of an algorithm, it is not possible to have any other algorithm (for a common problem) whose time complexity is less than L(n) for random input. Also every algorithm must take at least L(n) time in worst case. Note that L(n) here is the minimum of all the possible algorithm, of maximum complexity. 
The Lower Bound is a very important for any algorithm. Once we calculated it, then we can compare it with the actual complexity of the algorithm and if their order are same then we can declare our algorithm as optimal. So in this section we will be discussing about techniques for finding the lower bound of an algorithm. 

Note that our main motive is to get an optimal algorithm, which is the one having its Upper Bound Same as its Lower Bound (U(n)=L(n)). Merge Sort is a common example of an optimal algorithm.

Trivial Lower Bound – 
It is the easiest method to find the lower bound. The Lower bounds which can be easily observed on the basis of the number of input taken and the number of output produces are called Trivial Lower Bound. 

Example: Multiplication of n x n matrix, where, 



Input: For 2 matrix we will have 2n2 inputs
Output: 1 matrix of order n x n, i.e.,  n2 outputs 
In the above example its easily predictable that the lower bound is O(n2). 

Computational Model – 
The method is for all those algorithms that are comparison based. For example in sorting we have to compare the elements of the list among themselves and then sort them accordingly. Similar is the case with searching and thus we can implement the same in this case. Now we will look at some examples to understand its usage.

Ordered Searching – 
It is a type of searching in which the list is already sorted.
Example-1: Linear search 
Explanation – 
In linear search we compare the key with first element if it does not match we compare with second element and so on till we check against the nth element. Else we will end up with a failure. 

Example-2: Binary search 
Explanation – 
In binary search, we check the middle element against the key, if it is greater we search the first half else we check the second half and repeat the same process. 
The diagram below there is an illustration of binary search in an array consisting of 4 elements 
 
![](https://media.geeksforgeeks.org/wp-content/uploads/123123.png)


Calculating the lower bound: The max no of comparisons are n. Let there be k levels in the tree. 

No. of nodes will be 2k-1
The upper bound of no of nodes in any comparison based search of an element in list of size n will be n as there are maximum of n comparisons in worst case scenario 2k-1
Each level will take 1 comparison thus no. of comparisons k≥|log2n|
Thus the lower bound of any comparison based search from a list of n elements cannot be less than log(n). Therefore we can say that Binary Search is optimal as its complexity is Θ(log n).

Sorting – 
The diagram below is an example of tree formed in sorting combinations with 3 elements.



![](https://media.geeksforgeeks.org/wp-content/uploads/321321.png)

Example – For n elements, finding lower bound using computation model. 

Explanation – 
For n elements we have a total on n! combinations (leaf nodes). (Refer the diagram the total combinations are 3! or 6) also it is clear that the tree formed is a binary tree. Each level in the diagram indicates a comparison. Let there be k levels => 2k is the total number of leaf nodes in a full binary tree thus in this case we have n!≤2k.

As the k in the above example is the no of comparisons thus by computational model lower bond = k.  

    Now we can say that,
    n!≤2T(n)
    Thus, 
    T(n)>|log n!| 
    => n!<=nn
    Thus,
    log n!<=log nn
    Taking ceiling function on both sides, we get
    |-log nn-|>=|-log n!-|
    Thus complexity becomes Θ(lognn) or Θ(nlogn) 
Using Lower bond theory to solve the algebraic problem:

Straight Line Program – 
The type of programs build without any loops or control structures is called Straight Line Program. For example,
```C
//summing to nos
Sum(a, b)
{
    //no loops and no control structures
    c:= a+b;
    return c;
}
```
Algebraic Problem – 
Problems related to algebra like solving equations inequalities etc., comes under algebraic problems. For example, solving equation ax2+bx+c with simple programming.
```C
Algo_Sol(a, b, c, x)
{
    //1 assignment
    v:=a*x;
 
    //1 assignment
    v:=v+b;
 
    //1 assignment
    v:=v*x;
 
    //1 assignment
    ans:=v+c;
    return ans;
}
```
Complexity for solving here is 4 (excluding the returning). 
The above example shows us a simple way to solve an equation for 2 degree polynomial i.e., 4 thus for nth degree polynomial we will have complexity of O(n2). 

Let us demonstrate via an algorithm. 

Example: anxn+an-1xn-1+an-2xn-2+…+a1x+a0 is a polynomial of degree n.



```C
pow(x, n)
  {
    p := 1;
   
    //loop from 1 to n
    for i:=1 to n
        p := p*x;
 
    return p;
  }
 
polynomial(A, x, n)
  {
     int p, v:=0;
     for i := 0 to n
   
         //loop within a loop from 0 to n
         v := v + A[i]*pow(x, i);
     return v;
  }
```
Loop within a loop => complexity = O(n2);
Now to find an optimal algorithm we need to find the lower bound here (as per lower bound theory). As per Lower Bound Theory, The optimal algorithm to solve the above problem is the one having complexity O(n). Lets prove this theorem using lower bounds.

Theorem: To prove that optimal algo of solving a n degree polynomial is O(n) 
Proof: The best solution for reducing the algo is to make this problem less complex by dividing the polynomial into several straight line problems.

    => anxn+an-1xn-1+an-2xn-2+...+a1x+a0 
    can be written as, 
    ((..(anx+an-1)x+..+a2)x+a1)x+a0
    Now, algorithm will be as,
    v=0
    v=v+an
    v=v*x
    v=v+an-1
    v=v*x
    ...
    v=v+a1
    v=v*x
    v=v+a0 
```C
polynomial(A, x, n)
     {
      int p, v=0;
 
      // loop executed n times
      for i = n to 0
             v = (v + A[i])*x;
 
         return v;
      }
```
Clearly, the complexity of this code is O(n). This way of solving such equations is called Horner’s method. Here is where lower bound theory works and give the optimum algorithm’s complexity as O(n). 

2. Upper Bound Theory: 
According to the upper bound theory, for an upper bound U(n) of an algorithm, we can always solve the problem in at most U(n) time.Time taken by a known algorithm to solve a problem with worse case input gives us the upper bound.

# Analysis of Algorithms | Set 4 (Analysis of Loops)
Difficulty Level : Easy
Last Updated : 08 May, 2019
We have discussed Asymptotic Analysis,  Worst, Average and Best Cases  and Asymptotic Notations in previous posts. In this post, analysis of iterative programs with simple examples is discussed.

1. O(1): Time complexity of a function (or set of statements) is considered as O(1) if it doesn’t contain loop, recursion and call to any other non-constant time function.

// set of non-recursive and non-loop statements
For example swap() function has O(1) time complexity.
A loop or recursion that runs a constant number of times is also considered as O(1). For example the following loop is O(1).

    // Here c is a constant   
    for (int i = 1; i <= c; i++) {  
            // some O(1) expressions
    }
2. O(n): Time Complexity of a loop is considered as O(n) if the loop variables is incremented / decremented by a constant amount. For example following functions have O(n) time complexity.

        // Here c is a positive integer constant   
        for (int i = 1; i <= n; i += c) {  
                // some O(1) expressions
        }

        for (int i = n; i > 0; i -= c) {
                // some O(1) expressions
        }
3. O(nc): Time complexity of nested loops is equal to the number of times the innermost statement is executed. For example the following sample loops have O(n2) time complexity



  
        for (int i = 1; i <=n; i += c) {
            for (int j = 1; j <=n; j += c) {
                // some O(1) expressions
            }
        }

        for (int i = n; i > 0; i -= c) {
            for (int j = i+1; j <=n; j += c) {
                // some O(1) expressions
        }
For example Selection sort and Insertion Sort have O(n2) time complexity.
4. O(Logn) Time Complexity of a loop is considered as O(Logn) if the loop variables is divided / multiplied by a constant amount.

        for (int i = 1; i <=n; i *= c) {
            // some O(1) expressions
        }
        for (int i = n; i > 0; i /= c) {
            // some O(1) expressions
        }
For example Binary Search(refer iterative implementation) has O(Logn) time complexity. Let us see mathematically how it is O(Log n). The series that we get in first loop is 1, c, c2, c3, … ck. If we put k equals to Logcn, we get cLogcn which is n.
5. O(LogLogn) Time Complexity of a loop is considered as O(LogLogn) if the loop variables is reduced / increased exponentially by a constant amount.

    // Here c is a constant greater than 1   
    for (int i = 2; i <=n; i = pow(i, c)) { 
        // some O(1) expressions
    }
    //Here fun is sqrt or cuberoot or any other constant root
    for (int i = n; i > 1; i = fun(i)) { 
        // some O(1) expressions
    }
See this for mathematical details.
How to combine time complexities of consecutive loops?
When there are consecutive loops, we calculate time complexity as sum of time complexities of individual loops.

    for (int i = 1; i <=m; i += c) {  
            // some O(1) expressions
    }
    for (int i = 1; i <=n; i += c) {
            // some O(1) expressions
    }
   Time complexity of above code is O(m) + O(n) which is O(m+n)
   If m == n, the time complexity becomes O(2n) which is O(n).   
How to calculate time complexity when there are many if, else statements inside loops?
As discussed here, worst case time complexity is the most useful among best, average and worst. Therefore we need to consider worst case. We evaluate the situation when values in if-else conditions cause maximum number of statements to be executed.
For example consider the linear search function where we consider the case when element is present at the end or not present at all.
When the code is too complex to consider all if-else cases, we can get an upper bound by ignoring if else and other complex control statements.
How to calculate time complexity of recursive functions?
Time complexity of a recursive function can be written as a mathematical recurrence relation. To calculate time complexity, we must know how to solve recurrences. We will soon be discussing recurrence solving techniques as a separate post.

# Analysis of Algorithm | Set 4 (Solving Recurrences)
Difficulty Level : Medium
Last Updated : 14 Jun, 2021
 
In the previous post, we discussed analysis of loops. Many algorithms are recursive in nature. When we analyze them, we get a recurrence relation for time complexity. We get running time on an input of size n as a function of n and the running time on inputs of smaller sizes. For example in Merge Sort, to sort a given array, we divide it in two halves and recursively repeat the process for the two halves. Finally we merge the results. Time complexity of Merge Sort can be written as T(n) = 2T(n/2) + cn. There are many other algorithms like Binary Search, Tower of Hanoi, etc. 

There are mainly three ways for solving recurrences. 

1) Substitution Method: We make a guess for the solution and then we use mathematical induction to prove the guess is correct or incorrect. 

    For example consider the recurrence T(n) = 2T(n/2) + n

    We guess the solution as T(n) = O(nLogn). Now we use induction
    to prove our guess.

    We need to prove that T(n) <= cnLogn. We can assume that it is true
    for values smaller than n.

    T(n) = 2T(n/2) + n
        <= 2cn/2Log(n/2) + n
        =  cnLogn - cnLog2 + n
        =  cnLogn - cn + n
        <= cnLogn
2) Recurrence Tree Method: In this method, we draw a recurrence tree and calculate the time taken by every level of tree. Finally, we sum the work done at all levels. To draw the recurrence tree, we start from the given recurrence and keep drawing till we find a pattern among levels. The pattern is typically a arithmetic or geometric series. 
 

    For example consider the recurrence relation 
    T(n) = T(n/4) + T(n/2) + cn2

           cn2
         /      \
     T(n/4)     T(n/2)

    If we further break down the expression T(n/4) and T(n/2), 
    we get following recursion tree.

                    cn2
            /           \      
        c(n2)/16      c(n2)/4
        /      \          /     \
    T(n/16)     T(n/8)  T(n/8)    T(n/4) 
    Breaking down further gives us following
                    cn2
                /            \      
        c(n2)/16          c(n2)/4
        /      \            /      \
    c(n2)/256   c(n2)/64  c(n2)/64    c(n2)/16
    /    \      /    \    /    \       /    \  

    To know the value of T(n), we need to calculate sum of tree 
    nodes level by level. If we sum the above tree level by level, 
    we get the following series
    T(n)  = c(n^2 + 5(n^2)/16 + 25(n^2)/256) + ....
    The above series is geometrical progression with ratio 5/16.

    To get an upper bound, we can sum the infinite series. 
    We get the sum as (n2)/(1 - 5/16) which is O(n2)
3) Master Method: 
Master Method is a direct way to get the solution. The master method works only for following type of recurrences or for recurrences that can be transformed to following type. 
    
    T(n) = aT(n/b) + f(n) where a >= 1 and b > 1
There are following three cases: 
1. If f(n) = O(n^c) where c < Logba then T(n) = Θ(n^(Logba)) 

2. If f(n) = Θ(n^c) where c = Logba then T(n) = Θ(n^cLog n) 

3. If f(n) = Ω(n^c) where c > Logba then T(n) = Θ(f(n))

How does this work? 
Master method is mainly derived from recurrence tree method. If we draw recurrence tree of T(n) = aT(n/b) + f(n), we can see that the work done at root is f(n) and work done at all leaves is Θ(nc) where c is Logba. And the height of recurrence tree is Logbn 
 

Master Theorem

In recurrence tree method, we calculate total work done. If the work done at leaves is polynomially more, then leaves are the dominant part, and our result becomes the work done at leaves (Case 1). If work done at leaves and root is asymptotically same, then our result becomes height multiplied by work done at any level (Case 2). If work done at root is asymptotically more, then our result becomes work done at root (Case 3). 

Examples of some standard algorithms whose time complexity can be evaluated using Master Method 
Merge Sort: T(n) = 2T(n/2) + Θ(n). It falls in case 2 as c is 1 and Logba] is also 1. So the solution is Θ(n Logn) 

Binary Search: T(n) = T(n/2) + Θ(1). It also falls in case 2 as c is 0 and Logba is also 0. So the solution is Θ(Logn) 



Notes: 
1) It is not necessary that a recurrence of the form T(n) = aT(n/b) + f(n) can be solved using Master Theorem. The given three cases have some gaps between them. For example, the recurrence T(n) = 2T(n/2) + n/Logn cannot be solved using master method. 

2) Case 2 can be extended for f(n) = Θ(ncLogkn) 
If f(n) = Θ(ncLogkn) for some constant k >= 0 and c = Logba, then T(n) = Θ(ncLogk+1n) 

# Analysis of Algorithm | Set 5 (Amortized Analysis Introduction)
Difficulty Level : Medium
Last Updated : 27 Mar, 2021
Amortized Analysis is used for algorithms where an occasional operation is very slow, but most of the other operations are faster. In Amortized Analysis, we analyze a sequence of operations and guarantee a worst case average time which is lower than the worst case time of a particular expensive operation. 
The example data structures whose operations are analyzed using Amortized Analysis are Hash Tables, Disjoint Sets and Splay Trees. 

Let us consider an example of a simple hash table insertions. How do we decide table size? There is a trade-off between space and time, if we make hash-table size big, search time becomes slow, but space required becomes high. 

 

![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Dynamic-Table.png)

The solution to this trade-off problem is to use Dynamic Table (or Arrays). The idea is to increase size of table whenever it becomes full. Following are the steps to follow when table becomes full. 
1) Allocate memory for a larger table of size, typically twice the old table. 
2) Copy the contents of old table to new table. 
3) Free the old table. 



If the table has space available, we simply insert new item in available space. 

What is the time complexity of n insertions using the above scheme? 
If we use simple analysis, the worst case cost of an insertion is O(n). Therefore, worst case cost of n inserts is n * O(n) which is O(n2). This analysis gives an upper bound, but not a tight upper bound for n insertions as all insertions don’t take Θ(n) time. 

 

![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/AmortizedAnalysis.png)
So using Amortized Analysis, we could prove that the Dynamic Table scheme has O(1) insertion time which is a great result used in hashing. Also, the concept of dynamic table is used in vectors in C++, ArrayList in Java. 

Following are few important notes. 
1) Amortized cost of a sequence of operations can be seen as expenses of a salaried person. The average monthly expense of the person is less than or equal to the salary, but the person can spend more money in a particular month by buying a car or something. In other months, he or she saves money for the expensive month. 

2) The above Amortized Analysis done for Dynamic Array example is called Aggregate Method. There are two more powerful ways to do Amortized analysis called Accounting Method and Potential Method. We will be discussing the other two methods in separate posts. 

3) The amortized analysis doesn’t involve probability. There is also another different notion of average-case running time where algorithms use randomization to make them faster and expected running time is faster than the worst-case running time. These algorithms are analyzed using Randomized Analysis. Examples of these algorithms are Randomized Quick Sort, Quick Select and Hashing. We will soon be covering Randomized analysis in a different post. 



Amortized analysis of insertion in Red-Black Tree 

Let us discuss the Amortized Analysis of Red-Black Tree operations (Insertion) using Potential Method. 

To perform the amortized analysis of Red-Black Tree Insertion operation, we use Potential(or Physicist’s) method. For potential method, we define a potential function \phi  that maps a data structure to a non-negative real value. An operation can result in a change of this potential. 

Let us define the potential function \phi  in the following manner: 
![](https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-64964895702d879f26b758bad55a3483_l3.svg)
(1) \begin{equation*} g(n)=\begin{cases} 0, & \text{if n is red}.\\ 1, & \text{if n is black with no red children}. \\ 0, & \text{if n is black with one red child}.\\ 2, & \text{if n is black and has two red children }.\\ \end{cases} \end{equation*}  

where n is a node of Red-Black Tree 

Potential function \phi  = \sum_{} g(n)  ,over all nodes of the red black tree. 

Further, we define the amortized time of an operation as: 

Amortized time= c + \Delta\phi  (h) 

\Delta\phi  (h)= \phi  (h’) – \phi  (h) 
where h and h’ are the states of Red-Black Tree before and after the operation respectively 
c is the actual cost of the operation 



The change in potential should be positive for low-cost operations and negative for high-cost operations. 

A new node is inserted on a leaf of a red-black tree. We have the leaves of a red-black tree of any one of the following types: 
 

![](https://media.geeksforgeeks.org/wp-content/uploads/20191226164057/AmoInsertion1.png)

The insertions and their amortized analysis can be represented as: 
(1) 
![](https://media.geeksforgeeks.org/wp-content/uploads/20191226170158/Amoins2.png)


This insertion is performed by first recolouring the parent and the other sibling(red). Then the grandparent and uncle of that leaf node is considered for further recolouring which leads to the amortized cost to be -1(when grandparent of the leaf node is red), -2 (when uncle of the leaf is black and grandparent is black) or +1 (when uncle of the leaf is red and grandparent is black). The insertion can be shown as: 
 

![](https://media.geeksforgeeks.org/wp-content/uploads/20191226170437/AmoIns3.png)

(2) 
 
![](https://media.geeksforgeeks.org/wp-content/uploads/20191231194036/AmoIns4.png)


In this insertion, the node is inserted without any changes as the black depth of the leaves remain the same. This is the case when leaf may have a black sibling or do not have any sibling (since we consider the colour of the colour of null node to be black). 

![](https://media.geeksforgeeks.org/wp-content/uploads/20191226170955/AmoIns5.png)

So, the amortized cost of this insertion is 0. 

(3) 
 ![](https://media.geeksforgeeks.org/wp-content/uploads/20191231194000/AmoIns6-1.png)



In this insertion, we cannot recolour the leaf node, its parent and the sibling such that the black depth stays the same as before. So, we need to perform a Left- Left rotation. 

After rotation, there are no changes when the grandparent of g(the inserted node) is black. Also, for the case of Red Grandparent of g(the inserted node), we do not have any changes. So, the insertion is completed with amortized cost= +2. The insertion has been depicted below: 
 



After calculating these particular amortized costs at the leaf site of a red-black tree we can discuss the nature of total amortized cost of insertion in a red-black tree. Since this may happen that two red nodes may have a parent-child relationship till the root of the red-black tree. 

So in extreme(or corner) case, we reduce the number of black nodes with two red children by 1 and we at most increase the number of black nodes with no red children by 1, leaving a net loss of at most 1 to the potential function. Since one unit of potential pays for each operation therefore 

\Delta\phi  (h) \leq  n 
where n is total number of nodes 

Thus, the total amortized cost of insertion in Red-Black Tree is O(n). 

For any doubts regarding insertions in red black tree, you may refer Insertions in Red-Black Tree. 

# What does ‘Space Complexity’ mean?

Space Complexity: 
The term Space Complexity is misused for Auxiliary Space at many places. Following are the correct definitions of Auxiliary Space and Space Complexity. 

Auxiliary Space is the extra space or temporary space used by an algorithm. 

Space Complexity of an algorithm is total space taken by the algorithm with respect to the input size. Space complexity includes both Auxiliary space and space used by input. 

For example, if we want to compare standard sorting algorithms on the basis of space, then Auxiliary Space would be a better criteria than Space Complexity. Merge Sort uses O(n) auxiliary space, Insertion sort and Heap Sort use O(1) auxiliary space. Space complexity of all these sorting algorithms is O(n) though. 

Space complexity is a parallel concept to time complexity. If we need to create an array of size n, this will require O(n) space. If we create a two dimensional array of size n*n, this will require O(n2) space.



In recursive calls stack space also counts. 

Example : 

    int add (int n){
        if (n <= 0){
            return 0;
        }
        return n + add (n-1);
    }

Here each call add a level to the stack :

    1.  add(4)
    2.    -> add(3)
    3.      -> add(2)
    4.        -> add(1)
    5.          -> add(0)

Each of these calls is added to call stack and takes up actual memory.
So it take O(n) space.
However just because you have n calls total doesn’t mean it takes O(n) space.

Look at the below function :

    int addSequence (int n){
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum+ = pairSum(i, i+1);
        }
        return sum;
    }

    int paiSem(int x, int y){
        return x + y;
    }

There will be roughly O(n) calls to pairSum. However, those 
calls do not exist simultaneously on the call stack,
so you only need O(1) space.
Note: It’s necessary to mention that space complexity depends on a variety of things such as the programming language, the compiler, or even the machine running the algorithm.

# Pseudo-polynomial Algorithms

What is Pseudo-polynomial?
An algorithm whose worst case time complexity depends on numeric value of input (not number of inputs) is called Pseudo-polynomial algorithm.
For example, consider the problem of counting frequencies of all elements in an array of positive numbers. A pseudo-polynomial time solution for this is to first find the maximum value, then iterate from 1 to maximum value and for each value, find its frequency in array. This solution requires time according to maximum value in input array, therefore pseudo-polynomial. On the other hand, an algorithm whose time complexity is only based on number of elements in array (not value) is considered as polynomial time algorithm.

Pseudo-polynomial and NP-Completeness
Some NP-Complete problems have Pseudo Polynomial time solutions. For example, Dynamic Programming Solutions of 0-1 Knapsack, Subset-Sum and Partition problems are Pseudo-Polynomial. NP complete problems that can be solved using a pseudo-polynomial time algorithms are called weakly NP-complete.

# NP-Completeness | Set 1 (Introduction)
Difficulty Level : Hard
Last Updated : 07 Sep, 2018
We have been writing about efficient algorithms to solve complex problems, like shortest path, Euler graph, minimum spanning tree, etc. Those were all success stories of algorithm designers. In this post, failure stories of computer science are discussed.

Can all computational problems be solved by a computer? There are computational problems that can not be solved by algorithms even with unlimited time. For example Turing Halting problem (Given a program and an input, whether the program will eventually halt when run with that input, or will run forever). Alan Turing proved that general algorithm to solve the halting problem for all possible program-input pairs cannot exist. A key part of the proof is, Turing machine was used as a mathematical definition of a computer and program (Source Halting Problem).
Status of NP Complete problems is another failure story, NP complete problems are problems whose status is unknown. No polynomial time algorithm has yet been discovered for any NP complete problem, nor has anybody yet been able to prove that no polynomial-time algorithm exist for any of them. The interesting part is, if any one of the NP complete problems can be solved in polynomial time, then all of them can be solved.



What are `NP`, `P`, `NP-complete` and `NP-Hard` problems?
`P` is set of problems that can be solved by a deterministic Turing machine in Polynomial time.

`NP` is set of decision problems that can be solved by a Non-deterministic Turing Machine in Polynomial time. P is subset of NP (any problem that can be solved by deterministic machine in polynomial time can also be solved by non-deterministic machine in polynomial time).
Informally, NP is set of decision problems which can be solved by a polynomial time via a “Lucky Algorithm”, a magical algorithm that always makes a right guess among the given set of choices (Source Ref 1).

`NP-complete` problems are the hardest problems in NP set.  A decision problem L is NP-complete if:
1) L is in NP (Any given solution for NP-complete problems can be verified quickly, but there is no efficient known solution).
2) Every problem in NP is reducible to L in polynomial time (Reduction is defined below).

A problem is `NP-Hard` if it follows property 2 mentioned above, doesn’t need to follow property 1. Therefore, NP-Complete set is also a subset of NP-Hard set.

![](https://media.geeksforgeeks.org/wp-content/uploads/NP-Completeness-1.png)

Decision vs Optimization Problems
NP-completeness applies to the realm of decision problems.  It was set up this way because it’s easier to compare the difficulty of decision problems than that of optimization problems.   In reality, though, being able to solve a decision problem in polynomial time will often permit us to solve the corresponding optimization problem in polynomial time (using a polynomial number of calls to the decision problem). So, discussing the difficulty of decision problems is often really equivalent to discussing the difficulty of optimization problems. (Source Ref 2).
For example, consider the vertex cover problem (Given a graph, find out the minimum sized vertex set that covers all edges). It is an optimization problem. Corresponding decision problem is, given undirected graph G and k, is there a vertex cover of size k?

What is Reduction?
Let L1 and L2 be two decision problems. Suppose algorithm A2 solves L2. That is, if y is an input for L2 then algorithm A2 will answer Yes or No depending upon whether y belongs to L2 or not.
The idea is to find a transformation from L1 to L2 so that the algorithm A2 can be part of an algorithm A1 to solve L1.
![](https://media.geeksforgeeks.org/wp-content/uploads/NP-Completeness1.png)
Learning reduction in general is very important. For example, if we have library functions to solve certain problem and if we can reduce a new problem to one of the solved problems, we save a lot of time. Consider the example of a problem where we have to find minimum product path in a given directed graph where product of path is multiplication of weights of edges along the path. If we have code for Dijkstra’s algorithm to find shortest path, we can take log of all weights and use Dijkstra’s algorithm to find the minimum product path rather than writing a fresh code for this new problem.

How to prove that a given problem is NP complete?
From the definition of NP-complete, it appears impossible to prove that a problem L is NP-Complete.  By definition, it requires us to that show every problem in NP is polynomial time reducible to L.   Fortunately, there is an alternate way to prove it.   The idea is to take a known NP-Complete problem and reduce it to L.  If polynomial time reduction is possible, we can prove that L is NP-Complete by transitivity of reduction (If a NP-Complete problem is reducible to L in polynomial time, then all problems are reducible to L in polynomial time).

What was the first problem proved as NP-Complete?
There must be some first NP-Complete problem proved by definition of NP-Complete problems.  SAT (Boolean satisfiability problem) is the first NP-Complete problem proved by Cook (See CLRS book for proof).

It is always useful to know about NP-Completeness even for engineers. Suppose you are asked to write an efficient algorithm to solve an extremely important problem for your company. After a lot of thinking, you can only come up exponential time approach which is impractical. If you don’t know about NP-Completeness, you can only say that I could not come with an efficient algorithm. If you know about NP-Completeness and prove that the problem as NP-complete, you can proudly say that the polynomial time solution is unlikely to exist. If there is a polynomial time solution possible, then that solution solves a big problem of computer science many scientists have been trying for years.

We will soon be discussing more NP-Complete problems and their proof for NP-Completeness.

# Polynomial Time Approximation Scheme

It is a very well know fact that there is no known polynomial time solution for NP Complete problems and these problems occur a lot in real world (See this, this and this for example). So there must be a way to handle them. We have seen algorithms to these problems which are p approximate (For example 2 approximate for Travelling Salesman). Can we do better?

Polynomial Time Approximation Scheme (PTAS) is a type of approximate algorithms that provide user to control over accuracy which is a desirable feature. These algorithms take an additional parameter ε > 0 and provide a solution that is (1 + ε) approximate for minimization and (1 – ε) for maximization. For example consider a minimization problem, if ε is 0.5, then the solution provided by the PTAS algorithm is 1.5 approximate. The running time of PTAS must be polynomial in terms of n, however, it can be exponential in terms of ε.

In PTAS algorithms, the exponent of the polynomial can increase dramatically as ε reduces, for example if the runtime is O(n(1/ε)!) which is a problem. There is a stricter scheme, Fully Polynomial Time Approximation Scheme (FPTAS). In FPTAS, algorithm need to polynomial in both the problem size n and 1/ε.

Example (0-1 knapsack problem):
      We know that 0-1 knapsack is NP Complete. There is a DP based pseudo polynomial solution for this. But if input values are high, then the solution becomes infeasible and there is a need of approximate solution. One approximate solution is to use Greedy Approach (compute value per kg for all items and put the highest value per kg first if it is smaller than W), but Greedy approach is not PTAS, so we don’t have control over accuracy.

Below is a FPTAS solution for 0-1 Knapsack problem:
Input:
W (Capacity of Knapsack)
        val[0..n-1] (Values of Items)
        wt[0..n-1] (Weights of Items)



Find the maximum valued item, i.e., find maximum value in val[]. Let this maximum value be maxVal.
Compute adjustment factor k for all values
    >k  = (maxVal * ε) / n
Adjust all values, i.e., create a new array val'[] that values divided by k. Do following for every value val[i].
    >val'[i] = floor(val[i] / k)
Run DP based solution for reduced values, i,e, val'[0..n-1] and all other parameter same.
The above solution works in polynomial time in terms of both n and ε. The solution provided by this FPTAS is (1 – ε) approximate. The idea is to rounds off some of the least significant digits of values then they will be bounded by a polynomial and 1/ε.

Example:

    val[] = {12, 16, 4, 8}
    wt[]  = {3, 4, 5, 2}
    W = 10
    ε = 0.5
    
    maxVal = 16 [maximum value in val[]]
    Adjustment factor, k = (16 * 0.5)/4 = 2.0

    Now we apply DP based solution on below modified 
    instance of problem.

    val'[] = {6, 8, 2, 4}  [ val'[i] = floor(val[i]/k) ]
    wt[] = {3, 4, 5, 2}
    W = 10
How is the solution (1 – ε) * OPT?
Here OPT is the optimal value. Let S be the set produced by above FPTAS algorithm and total value of S be val(S). We need to show that

       val(S) >= (1 - ε)*OPT 
Let O be the set produced by optimal solution (the solution with total value OPT), i.e., val(O) = OPT.

       val(O) - k*val'(O) <= n*k 
       [Because val'[i] = floor(val[i]/k) ] 
After the dynamic programming step, we get a set that is optimal for the scaled instance
and therefore must be at least as good as choosing the set O with the smaller profits. From that, we can conclude,

      val'(S) >= k . val'(O)
              >= val(O) - nk
              >= OPT - ε * maxVal
              >= OPT - ε * OPT [OPT >= maxVal]
              >= (1 - ε) * OPT 

# A Time Complexity Question
Difficulty Level : Easy
Last Updated : 29 Oct, 2020
What is the time complexity of following function fun()? Assume that log(x) returns log value in base 2. 

```cpp
void fun()
{
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= log(i); j++)
            printf("GeeksforGeeks");
}
```
Time Complexity of the above function can be written as θ(log 1) + θ(log 2) + θ(log 3) + . . . . + θ(log n) which is θ(log n!)
Order of growth of ‘log n!’ and ‘n log n’ is same for large values of n, i.e., θ(log n!) = θ(n log n). So time complexity of fun() is θ(n log n).
The expression θ(log n!) = θ(n log n) can be easily derived from following Stirling’s approximation (or Stirling’s formula). 

    log n! = n*log n - n = O(n*log(n)) 
Please write comments if you find anything incorrect, or you want to share more information about the topic discussed above.

# Time Complexity of building a heap
Difficulty Level : Medium
Last Updated : 18 Sep, 2017
Consider the following algorithm for building a Heap of an input array A.

    BUILD-HEAP(A) 
        heapsize := size(A); 
        for i := floor(heapsize/2) downto 1 
            do HEAPIFY(A, i); 
        end for 
    END
A quick look over the above algorithm suggests that the running time is O(nlg(n)), since each call to Heapify costs O(lg(n)) and Build-Heap makes O(n) such calls.
This upper bound, though correct, is not asymptotically tight.

We can derive a tighter bound by observing that the running time of Heapify depends on the height of the tree ‘h’ (which is equal to lg(n), where n is number of nodes) and the heights of most sub-trees are small.
The height ’h’ increases as we move upwards along the tree. Line-3 of Build-Heap runs a loop from the index of the last internal node (heapsize/2) with height=1, to the index of root(1) with height = lg(n). Hence, Heapify takes different time for each node, which is O(h).

For finding the Time Complexity of building a heap, we must know the number of nodes having height h.
For this we use the fact that, A heap of size n has at most \left \lceil \frac{n}{2^{h+1}} \right \rceil  nodes with height h.

Now to derive the time complexity, we express the total cost of Build-Heap as-



(1)  ![](https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-c68cff1daa1d0880c2e65ab4062ef3d1_l3.svg) 

Step 2 uses the properties of the Big-Oh notation to ignore the ceiling function and the constant 2(2^{h+1} = 2.2^h). Similarly in Step three, the upper limit of the summation can be increased to infinity since we are using Big-Oh notation.

Sum of infinite G.P. (x < 1)

(2)  ![](https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-185c07cec4efa614ebfb52b4434fa6b5_l3.svg)

On differentiating both sides and multiplying by x, we get

(3)  ![](https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-f533b28af7646ab9d7894fe78e24e68a_l3.svg)

Putting the result obtained in (3) back in our derivation (1), we get

(4)  ![](https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-1f5a465fbfa61f71a5b89cc630df2817_l3.svg)

Hence Proved that the Time complexity for Building a Binary Heap is O(n).

# Time Complexity where loop variable is incremented by 1, 2, 3, 4 ..
Difficulty Level : Easy
Last Updated : 30 Oct, 2015
What is the time complexity of below code?

```cpp
void fun(int n)
{
   int j = 1, i = 0;
   while (i < n)
   {
       // Some O(1) task
       i = i + j;
       j++;
   }
}
```
The loop variable ‘i’ is incremented by 1, 2, 3, 4, … until i becomes greater than or equal to n.

The value of i is x(x+1)/2 after x iterations. So if loop runs x times, then x(x+1)/2 < n. Therefore time complexity can be written as Θ(√n).

# Time Complexity of Loop with Powers
Difficulty Level : Medium
Last Updated : 19 Oct, 2020
What is the time complexity of the below function?

```cpp
void fun(int n, int k)
{
    for (int i = 1; i <= n; i++)
    {
        int p = pow(i, k);
        for (int j = 1; j <= p; j++)
        {
            // Some O(1) work
        }
    }
}
```
Time complexity of above function can be written as 1k + 2k + 3k + … n1k.

Let us try few examples: 

    k=1
    Sum = 1 + 2 + 3 ... n 
        = n(n+1)/2 
        = n2/2 + n/2

    k=2
    Sum = 12 + 22 + 32 + ... n12.
        = n(n+1)(2n+1)/6
        = n3/3 + n2/2 + n/6

    k=3
    Sum = 13 + 23 + 33 + ... n13.
        = n2(n+1)2/4
        = n4/4 + n3/2 + n2/4     
    In general, asymptotic value can be written as (nk+1)/(k+1) + Θ(nk)
    If  n>=k then the time complexity will be considered in O((nk+1)/(k+1)) and if n<k, then the time complexity will be considered as  in the O(nk)

# Performance of loops (A caching question)
Difficulty Level : Easy
Last Updated : 20 May, 2017
Consider below two C language functions to compute sum of elements in a 2D array. Ignoring the compiler optimizations, which of the two is better implementation of sum?

```cpp
// Function 1
int fun1(int arr[R][C])
{
    int sum = 0;
    for (int i=0; i<R; i++)
      for (int j=0; j<C; j++)
          sum += arr[i][j];
}
  
// Function 2
int fun2(int arr[R][C])
{
    int sum = 0;
    for (int j=0; j<C; j++)
      for (int i=0; i<R; i++)
          sum += arr[i][j];
}
```
In C/C++, elements are stored in Row-Major order. So the first implementation has better spatial locality (nearby memory locations are referenced in successive iterations). Therefore, first implementation should always be preferred for iterating multidimensional arrays.