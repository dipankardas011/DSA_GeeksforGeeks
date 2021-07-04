# Why performance analysis? There are many important things that should be taken care of, like user friendliness, modularity, security, maintainability, etc. Why to worry about performance?
The answer to this is simple, we can have all the above things only if we have performance. So performance is like currency through which we can buy all the above things. Another reason for studying performance is - speed is fun!
To summarize, performance == scale. Imagine a text editor that can load 1000 pages, but can spell check 1 page per minute OR an image editor that takes 1 hour to rotate your image 90 degrees left OR ... you get it. If a software feature can not cope with the scale of tasks users need to perform - it is as good as dead.

Given two algorithms for a task, how do we find out which one is better? One naive way of doing this is - implement both the algorithms and run the two programs on your computer for different inputs and see which one takes less time. There are many problems with this approach for analysis of algorithms.
1. It might be possible that for some inputs, first algorithm performs better than the second. And for some inputs second performs better.
2. It might also be possible that for some inputs, first algorithm perform better on one machine and the second works better on other machine for some other inputs.

Asymptotic Analysis is the big idea that handles above issues in analyzing algorithms. In Asymptotic Analysis, we evaluate the performance of an algorithm in terms of input size (we don't measure the actual running time). We calculate, how the time (or space) taken by an algorithm increases with the input size.
For example, let us consider the search problem (searching a given item) in a sorted array. One way to search is Linear Search (order of growth is linear) and the other way is Binary Search (order of growth is logarithmic). To understand how Asymptotic Analysis solves the above mentioned problems in analyzing algorithms, let us say we run the Linear Search on a fast computer A and Binary Search on a slow computer B and we pick the constant values for the two computers so that it tells us exactly how long it takes for the given machine to perform the search in seconds. Let's say the constant for A is 0.2 and the constant for B is 1000 which means that A is 5000 times more powerful than B. For small values of input array size n, the fast computer may take less time. But, after a certain value of input array size, the Binary Search will definitely start taking less time compared to the Linear Search even though the Binary Search is being run on a slow machine. The reason is the order of growth of Binary Search with respect to input size is logarithmic while the order of growth of Linear Search is linear. So the machine dependent constants can always be ignored after a certain value of input size.
Here are some running times for this example:
Linear Search running time in seconds on A: 0.2 * n
Binary Search running time in seconds on B: 1000*log(n)
|n      | Running time on A | Running time on B |
------------|---------------|--------------------
|10     | 2 sec             | ~ 1 h             |
|100    | 20 sec            | ~ 1.8 h           |
|10^6   | ~ 55.5 h          | ~ 5.5 h           |
|10^9   | ~ 6.3 years       | ~ 8.3 h           |

Does Asymptotic Analysis always work? Asymptotic Analysis is not perfect, but that's the best way available for analyzing algorithms. For example, say there are two sorting algorithms that take 1000nLogn and 2nLogn time respectively on a machine. Both of these algorithms are asymptotically same (order of growth is nLogn). So, With Asymptotic Analysis, we can't judge which one is better as we ignore constants in Asymptotic Analysis.
Also, in Asymptotic analysis, we always talk about input sizes larger than a constant value. It might be possible that those large inputs are never given to your software and an algorithm which is asymptotically slower, always performs better for your particular situation. So, you may end up choosing an algorithm that is Asymptotically slower but faster for your software.
https://youtu.be/QJMtPlYPQTA
  Analysis of Algorithms | Set 2 (Worst, Average and Best Cases) 
In the previous post, we discussed how Asymptotic analysis overcomes the problems of naive way of analyzing algorithms. In this post, we will take an example of Linear Search and analyze it using Asymptotic analysis.
We can have three cases to analyze an algorithm: 
1) The Worst Case 
2) Average Case 
3) Best Case
Let us consider the following implementation of Linear Search. 
 
```cpp
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
    Output: 


    30 is present at index 2



## Worst Case Analysis (Usually Done) 
In the worst case analysis, we calculate upper bound on running time of an algorithm. We must know the case that causes maximum number of operations to be executed. For Linear Search, the worst case happens when the element to be searched (x in the above code) is not present in the array. When x is not present, the search() functions compares it with all the elements of arr[] one by one. Therefore, the worst case time complexity of linear search would be Θ(n).





## Average Case Analysis (Sometimes done) 
In average case analysis, we take all possible inputs and calculate computing time for all of the inputs. Sum all the calculated values and divide the sum by total number of inputs. We must know (or predict) distribution of cases. For the linear search problem, let us assume that all cases are uniformly distributed (including the case of x not being present in array). So we sum all the cases and divide the sum by (n+1). Following is the value of average case time complexity. 
 


Average Case Time =  

![analysis1](https://media.geeksforgeeks.org/wp-content/cdn-uploads/analysis1.png)

= ![analysis2](https://media.geeksforgeeks.org/wp-content/cdn-uploads/analysis2.png)

= Θ(n) 



## Best Case Analysis (Bogus) 
In the best case analysis, we calculate lower bound on running time of an algorithm. We must know the case that causes minimum number of operations to be executed. In the linear search problem, the best case occurs when x is present at the first location. The number of operations in the best case is constant (not dependent on n). So time complexity in the best case would be Θ(1) 
Most of the times, we do worst case analysis to analyze algorithms. In the worst analysis, we guarantee an upper bound on the running time of an algorithm which is good information. 
The average case analysis is not easy to do in most of the practical cases and it is rarely done. In the average case analysis, we must know (or predict) the mathematical distribution of all possible inputs. 
The Best Case analysis is bogus. Guaranteeing a lower bound on an algorithm doesn't provide any information as in the worst case, an algorithm may take years to run.
For some algorithms, all the cases are asymptotically same, i.e., there are no worst and best cases. For example, Merge Sort. Merge Sort does Θ(nLogn) operations in all cases. Most of the other sorting algorithms have worst and best cases. For example, in the typical implementation of Quick Sort (where pivot is chosen as a corner element), the worst occurs when the input array is already sorted and the best occur when the pivot elements always divide array in two halves. For insertion sort, the worst case occurs when the array is reverse sorted and the best case occurs when the array is sorted in the same order as output.


https://youtu.be/rlZpZ8es_6k






# Analysis of Algorithms | Set 3 (Asymptotic Notations) 


We have discussed Asymptotic Analysis, and Worst, Average, and Best Cases of Algorithms. The main idea of asymptotic analysis is to have a measure of the efficiency of algorithms that don't depend on machine-specific constants and doesn't require algorithms to be implemented and time taken by programs to be compared. Asymptotic notations are mathematical tools to represent the time complexity of algorithms for asymptotic analysis. The following 3 asymptotic notations are mostly used to represent the time complexity of algorithms. 

 


![thetanotation](https://media.geeksforgeeks.org/wp-content/uploads/AlgoAnalysis-1.png)

1, Θ Notation: The theta notation bounds a function from above and below, so it defines exact asymptotic behavior. 
A simple way to get Theta notation of an expression is to drop low order terms and ignore leading constants. For example, consider the following expression. 
3n3 + 6n2 + 6000 = Θ(n3) 
Dropping lower order terms is always fine because there will always be a number(n) after which Θ(n3) has higher values than Θ(n2) irrespective of the constants involved. 
For a given function g(n), we denote Θ(g(n)) is following set of functions. 
 
    Θ(g(n)) = {f(n): there exist positive constants c1, c2 and n0 such 
    that 0 <= c1*g(n) <= f(n) <= c2*g(n) for all n >= n0}


The above definition means, if f(n) is theta of g(n), then the value f(n) is always between c1*g(n) and c2*g(n) for large values of n (n >= n0). The definition of theta also requires that f(n) must be non-negative for values of n greater than n0. 

 


![BigO](https://media.geeksforgeeks.org/wp-content/uploads/AlgoAnalysis-2.png)

2. Big O Notation: The Big O notation defines an upper bound of an algorithm, it bounds a function only from above. For example, consider the case of Insertion Sort. It takes linear time in best case and quadratic time in worst case. We can safely say that the time complexity of Insertion sort is O(n^2). Note that O(n^2) also covers linear time. 
If we use Θ notation to represent time complexity of Insertion sort, we have to use two statements for best and worst cases: 
1. The worst case time complexity of Insertion Sort is Θ(n^2). 
2. The best case time complexity of Insertion Sort is Θ(n). 

The Big O notation is useful when we only have upper bound on time complexity of an algorithm. Many times we easily find an upper bound by simply looking at the algorithm.  


    O(g(n)) = { f(n): there exist positive constants c and 

                  n0 such that 0 <= f(n) <= c*g(n) for 

                  all n >= n0}


![BigOmega](https://media.geeksforgeeks.org/wp-content/uploads/AlgoAnalysis-3.png)

3. Ω Notation: Just as Big O notation provides an asymptotic upper bound on a function, Ω notation provides an asymptotic lower bound. 
Ω Notation can be useful when we have lower bound on time complexity of an algorithm. As discussed in the previous post, the best case performance of an algorithm is generally not useful, the Omega notation is the least used notation among all three. 


For a given function g(n), we denote by Ω(g(n)) the set of functions.  


    Ω (g(n)) = {f(n): there exist positive constants c and

                  n0 such that 0 <= c*g(n) <= f(n) for

                  all n >= n0}.

Let us consider the same Insertion sort example here. The time complexity of Insertion Sort can be written as Ω(n), but it is not a very useful information about insertion sort, as we are generally interested in worst case and sometimes in average case. 

Properties of Asymptotic Notations : 
As we have gone through the definition of this three notations let's now discuss some important properties of those notations. 




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

    1. If f(n) = O(g(n)) and f(n) = Ω(g(n)) then f(n) = Θ(g(n))

    2. If f(n) = O(g(n)) and d(n)=O(e(n)) 
          then f(n) + d(n) = O( max( g(n), e(n) )) 
          Example: f(n) = n i.e O(n) 
                         d(n) = n² i.e O(n²) 
                         then f(n) + d(n) = n + n² i.e O(n²)




    3. If f(n)=O(g(n)) and d(n)=O(e(n)) 
           then f(n) * d(n) = O( g(n) * e(n) ) 
           Example: f(n) = n i.e O(n) 
           d(n) = n² i.e O(n²) 
                      then f(n) * d(n) = n * n² = n³ i.e O(n³)




_______________________________________________________________________________

Exercise: 
Which of the following statements is/are valid? 
1. Time Complexity of QuickSort is Θ(n^2) 
2. Time Complexity of QuickSort is O(n^2) 
3. For any two functions f(n) and g(n), we have f(n) = Θ(g(n)) if and only if f(n) = O(g(n)) and f(n) = Ω(g(n)). 
4. Time complexity of all computer algorithms can be written as Ω(1) 
