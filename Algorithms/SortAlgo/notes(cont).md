# TimSort
TimSort is a sorting algorithm based on Insertion Sort and Merge Sort.

A stable sorting algorithm works in O(n Log n) time
Used in Java’s Arrays.sort() as well as Python’s sorted() and sort().
First sort small pieces using Insertion Sort, then merges the pieces using merge of merge sort.
We divide the Array into blocks known as Run. We sort those runs using insertion sort one by one and then merge those runs using the combine function used in merge sort. If the size of the Array is less than run, then Array gets sorted just by using Insertion Sort. The size of the run may vary from 32 to 64 depending upon the size of the array. Note that the merge function performs well when size subarrays are powers of 2. The idea is based on the fact that insertion sort performs well for small arrays.

We consider size of run as 32.
We one by one sort pieces of size equal to run
After sorting individual pieces, we merge them one by one. We double the size of merged subarrays after every iteration.

```cpp
#include<bits/stdc++.h>
using namespace std;
const int RUN = 32;
 
// This function sorts array from left index to
// to right index which is of size atmost RUN
void insertionSort(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}
 
// Merge function merges the sorted runs
void merge(int arr[], int l, int m, int r)
{
     
    // Original array is broken in two parts
    // left and right array
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];
 
    int i = 0;
    int j = 0;
    int k = l;
 
    // After comparing, we
    // merge those two array
    // in larger sub array
    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
 
    // Copy remaining elements of left, if any
    while (i < len1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }
 
    // Copy remaining element of right, if any
    while (j < len2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}
 
// Iterative Timsort function to sort the
// array[0...n-1] (similar to merge sort)
void timSort(int arr[], int n)
{
     
    // Sort individual subarrays of size RUN
    for (int i = 0; i < n; i+=RUN)
        insertionSort(arr, i, min((i+RUN-1),
                                    (n-1)));
 
    // Start merging from size RUN (or 32).
    // It will merge
    // to form size 64, then 128, 256
    // and so on ....
    for (int size = RUN; size < n;
                             size = 2*size)
    {
         
        // pick starting point of
        // left sub array. We
        // are going to merge
        // arr[left..left+size-1]
        // and arr[left+size, left+2*size-1]
        // After every merge, we
        // increase left by 2*size
        for (int left = 0; left < n;
                             left += 2*size)
        {
             
            // find ending point of
            // left sub array
            // mid+1 is starting point
            // of right sub array
            int mid = left + size - 1;
            int right = min((left + 2*size - 1),
                                            (n-1));
 
            // merge sub array arr[left.....mid] &
            // arr[mid+1....right]
              if(mid < right)
                merge(arr, left, mid, right);
        }
    }
}
 
// Utility function to print the Array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);
    printf("\n");
}
 
// Driver program to test above function
int main()
{
    int arr[] = {-2, 7, 15, -14, 0, 15, 0, 7, -7,
                       -4, -13, 5, 8, -14, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Given Array is\n");
    printArray(arr, n);
 
    // Function Call
    timSort(arr, n);
 
    printf("After Sorting Array is\n");
    printArray(arr, n);
    return 0;
}
```
    Output:

    Given Array is
    -2, 7, 15, -14, 0, 15, 0, 7, -7, -4, -13, 5, 8, -14, 12
    After Sorting Array is
    -14  -14  -13  -7  -4  -2  0  0  5  7  7  8  12  15  15

# Comb Sort

Comb Sort is mainly an improvement over Bubble Sort. Bubble sort always compares adjacent values. So all inversions are removed one by one. Comb Sort improves on Bubble Sort by using gap of size more than 1. The gap starts with a large value and shrinks by a factor of 1.3 in every iteration until it reaches the value 1. Thus Comb Sort removes more than one inversion counts with one swap and performs better than Bubble Sort.
The shrink factor has been empirically found to be 1.3 (by testing Combsort on over 200,000 random lists) [Source: Wiki]
Although, it works better than Bubble Sort on average, worst case remains O(n2).
Below is the implementation.

```cpp
// C++ implementation of Comb Sort
#include<bits/stdc++.h>
using namespace std;
 
// To find gap between elements
int getNextGap(int gap)
{
    // Shrink gap by Shrink factor
    gap = (gap*10)/13;
 
    if (gap < 1)
        return 1;
    return gap;
}
 
// Function to sort a[0..n-1] using Comb Sort
void combSort(int a[], int n)
{
    // Initialize gap
    int gap = n;
 
    // Initialize swapped as true to make sure that
    // loop runs
    bool swapped = true;
 
    // Keep running while gap is more than 1 and last
    // iteration caused a swap
    while (gap != 1 || swapped == true)
    {
        // Find next gap
        gap = getNextGap(gap);
 
        // Initialize swapped as false so that we can
        // check if swap happened or not
        swapped = false;
 
        // Compare all elements with current gap
        for (int i=0; i<n-gap; i++)
        {
            if (a[i] > a[i+gap])
            {
                swap(a[i], a[i+gap]);
                swapped = true;
            }
        }
    }
}
 
// Driver program
int main()
{
    int a[] = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0};
    int n = sizeof(a)/sizeof(a[0]);
 
    combSort(a, n);
 
    printf("Sorted array: \n");
    for (int i=0; i<n; i++)
        printf("%d ", a[i]);
 
    return 0;
}
```
    Output : 

    Sorted array: 
    -44 -6 0 1 3 4 8 23 28 56 
    Illustration: 
    Let the array elements be 

    8, 4, 1, 56, 3, -44, 23, -6, 28, 0
    Initially gap value = 10 
    After shrinking gap value => 10/1.3 = 7; 

    8 4 1 56 3 -44 23 -6 28 0
    -6 4 1 56 3 -44 23  8 28 0
    -6 4 0 56 3 -44 23  8 28 1
    New gap value => 7/1.3 = 5;  



    -44 4 0 56 3 -6 23 8 28 1
    -44 4 0 28 3 -6 23 8 56 1
    -44 4 0 28 1 -6 23 8 56 3
    New gap value => 5/1.3 = 3; 

    -44 1  0 28 4 -6 23 8 56 3
    -44 1 -6 28 4  0 23 8 56 3
    -44 1 -6 23 4  0 28 8 56 3
    -44 1 -6 23 4  0  3 8 56 28
    New gap value => 3/1.3 = 2;  

    -44 1 -6 0 4 23 3 8 56 28
    -44 1 -6 0 3 23 4 8 56 28
    -44 1 -6 0 3 8 4 23 56 28
    New gap value => 2/1.3 = 1;  

    -44 -6 1 0 3 8 4 23 56 28
    -44 -6 0 1 3 8 4 23 56 28
    -44 -6 0 1 3 4 8 23 56 28
    -44 -6 0 1 3 4 8 23 28 56 

no more swaps required (Array sorted)
Time Complexity: Average case time complexity of the algorithm is Ω(N2/2p), where p is the number of increments. The worst-case complexity of this algorithm is O(n2) and the Best Case complexity is O(nlogn). 
Auxiliary Space : O(1). 

# Pigeonhole Sort
Pigeonhole sorting is a sorting algorithm that is suitable for sorting lists of elements where the number of elements and the number of possible key values are approximately the same. 
It requires O(n + Range) time where n is number of elements in input array and ‘Range’ is number of possible values in array. 
Working of Algorithm : 
 

Find minimum and maximum values in array. Let the minimum and maximum values be ‘min’ and ‘max’ respectively. Also find range as ‘max-min+1’. 
 
* Set up an array of initially empty “pigeonholes” the same size as of the range.
* Visit each element of the array and then put each element in its pigeonhole. An element arr[i] is put in hole at index arr[i] – min.
* Start the loop all over the pigeonhole array in order and put the elements from non- empty holes back into the original array.
Comparison with Counting Sort : 
It is similar to counting sort, but differs in that it “moves items twice: once to the bucket array and again to the final destination “. 
 

![ps](https://media.geeksforgeeks.org/wp-content/uploads/countingsort.png)

 
```cpp

/* C program to implement Pigeonhole Sort */
#include <bits/stdc++.h>
using namespace std;
 
/* Sorts the array using pigeonhole algorithm */
void pigeonholeSort(int arr[], int n)
{
    // Find minimum and maximum values in arr[]
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    int range = max - min + 1; // Find range
 
    // Create an array of vectors. Size of array
    // range. Each vector represents a hole that
    // is going to contain matching elements.
    vector<int> holes[range];
 
    // Traverse through input array and put every
    // element in its respective hole
    for (int i = 0; i < n; i++)
        holes[arr[i]-min].push_back(arr[i]);
 
    // Traverse through all holes one by one. For
    // every hole, take its elements and put in
    // array.
    int index = 0;  // index in sorted array
    for (int i = 0; i < range; i++)
    {
       vector<int>::iterator it;
       for (it = holes[i].begin(); it != holes[i].end(); ++it)
            arr[index++]  = *it;
    }
}
 
// Driver program to test the above function
int main()
{
    int arr[] = {8, 3, 2, 7, 4, 6, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    pigeonholeSort(arr, n);
 
    printf("Sorted order is : ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
 
    return 0;
}
```
    Output: 
    



    Sorted order is : 2 3 4 6 7 8 8 
    Pigeonhole sort has limited use as requirements are rarely met. For arrays where range is much larger than n, bucket sort is a generalization that is more efficient in space and time.

# Cycle Sort

Cycle sort is an in-place sorting Algorithm, unstable sorting algorithm, a comparison sort that is theoretically optimal in terms of the total number of writes to the original array. 
 

It is optimal in terms of number of memory writes. It minimizes the number of memory writes to sort (Each value is either written zero times, if it’s already in its correct position, or written one time to its correct position.)
It is based on the idea that array to be sorted can be divided into cycles. Cycles can be visualized as a graph. We have n nodes and an edge directed from node i to node j if the element at i-th index must be present at j-th index in the sorted array. 
Cycle in arr[] = {2, 4, 5, 1, 3} 
 
![cycle-sort](https://media.geeksforgeeks.org/wp-content/cdn-uploads/cycle-sort.png)

Cycle in arr[] = {4, 3, 2, 1} 
![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/cyclc-sort2.png)

 
We one by one consider all cycles. We first consider the cycle that includes first element. We find correct position of first element, place it at its correct position, say j. We consider old value of arr[j] and find its correct position, we keep doing this till all elements of current cycle are placed at correct position, i.e., we don’t come back to cycle starting point.
 
Explanation : 

    arr[] = {10, 5, 2, 3}
    index =  0   1   2   3
    cycle_start = 0 
    item = 10 = arr[0]

    Find position where we put the item  
    pos = cycle_start
    i=pos+1
    while(i<n)
    if (arr[i] < item)  
        pos++;

    We put 10 at arr[3] and change item to 
    old value of arr[3].
    arr[] = {10, 5, 2, 10} 
    item = 3 

    Again rotate rest cycle that start with index '0' 
    Find position where we put the item = 3 
    we swap item with element at arr[1] now 
    arr[] = {10, 3, 2, 10} 
    item = 5

    Again rotate rest cycle that start with index '0' and item = 5 
    we swap item with element at arr[2].
    arr[] = {10, 3, 5, 10 } 
    item = 2

    Again rotate rest cycle that start with index '0' and item = 2
    arr[] = {2, 3,  5, 10}  

    Above is one iteration for cycle_stat = 0.
    Repeat above steps for cycle_start = 1, 2, ..n-2

> cyclicsort.cpp

# Cocktail Sort

Cocktail Sort is a variation of Bubble sort. The Bubble sort algorithm always traverses elements from left and moves the largest element to its correct position in first iteration and second largest in second iteration and so on. Cocktail Sort traverses through a given array in both directions alternatively. 
Algorithm: 
Each iteration of the algorithm is broken up into 2 stages: 

The first stage loops through the array from left to right, just like the Bubble Sort. During the loop, adjacent items are compared and if value on the left is greater than the value on the right, then values are swapped. At the end of first iteration, largest number will reside at the end of the array.
The second stage loops through the array in opposite direction- starting from the item just before the most recently sorted item, and moving back to the start of the array. Here also, adjacent items are compared and are swapped if required.
Example : 

Let us consider an example array (5 1 4 2 8 0 2)

    First Forward Pass: 
    (5 1 4 2 8 0 2) ? (1 5 4 2 8 0 2), Swap since 5 > 1 
    (1 5 4 2 8 0 2) ? (1 4 5 2 8 0 2), Swap since 5 > 4 
    (1 4 5 2 8 0 2) ? (1 4 2 5 8 0 2), Swap since 5 > 2 
    (1 4 2 5 8 0 2) ? (1 4 2 5 8 0 2) 
    (1 4 2 5 8 0 2) ? (1 4 2 5 0 8 2), Swap since 8 > 0 
    (1 4 2 5 0 8 2) ? (1 4 2 5 0 2 8), Swap since 8 > 2
    After first forward pass, greatest element of the array will be present at the last index of array.
    First Backward Pass: 
    (1 4 2 5 0 2 8) ? (1 4 2 5 0 2 8) 
    (1 4 2 5 0 2 8) ? (1 4 2 0 5 2 8), Swap since 5 > 0 
    (1 4 2 0 5 2 8) ? (1 4 0 2 5 2 8), Swap since 2 > 0 
    (1 4 0 2 5 2 8) ? (1 0 4 2 5 2 8), Swap since 4 > 0 
    (1 0 4 2 5 2 8) ? (0 1 4 2 5 2 8), Swap since 1 > 0
    After first backward pass, smallest element of the array will be present at the first index of the array.
    Second Forward Pass: 
    (0 1 4 2 5 2 8) ? (0 1 4 2 5 2 8) 
    (0 1 4 2 5 2 8) ? (0 1 2 4 5 2 8), Swap since 4 > 2 
    (0 1 2 4 5 2 8) ? (0 1 2 4 5 2 8) 
    (0 1 2 4 5 2 8) ? (0 1 2 4 2 5 8), Swap since 5 > 2
    Second Backward Pass: 
    (0 1 2 4 2 5 8) ? (0 1 2 2 4 5 8), Swap since 4 > 2
    Now, the array is already sorted, but our algorithm doesn’t know if it is completed. The algorithm needs to complete this whole pass without any swap to know it is sorted. 
    (0 1 2 2 4 5 8) ? (0 1 2 2 4 5 8) 
    (0 1 2 2 4 5 8) ? (0 1 2 2 4 5 8)

Worst and Average Case Time Complexity: O(n*n). 
Best Case Time Complexity: O(n). Best case occurs when array is already sorted.
Auxiliary Space: O(1)
Sorting In Place: Yes
Stable: Yes

Comparison with Bubble Sort: 
Time complexities are same, but Cocktail performs better than Bubble Sort. Typically cocktail sort is less than two times faster than bubble sort. Consider the example (2, 3, 4, 5, 1). Bubble sort requires four traversals of array for this example, while Cocktail sort requires only two traversals.

# Strand Sort

Given a list of items, sort them in increasing order.

    Examples:

    Input : ip[] = {10, 5, 30, 40, 2, 4, 9}
    Output : op[] = {2, 4, 5, 9, 10, 30, 40}

    Input : ip[] = {1, 10, 7}
    Output : op[] = {1, 7, 10}
Strand Sort is a sorting algorithm that works in O(n) time if list is already sorted and works in O(n*n) in worst case.

Below are simple steps used in the algorithm.

Let ip[] be input list and op[] be output list.
Create an empty sublist and move first item of ip[] to it.
Traverse remaining items of ip. For every item x, check if x is greater than last inserted item to sublist. If yes, remove x from ip and add at the end of sublist. If no, ignore x (Keep it it in ip)
Merge sublist into op (output list)
Recur for remaining items in ip and current items in op.
Illustration :

    Let ip[] = {10, 5, 30, 40, 2, 4, 9}
    Initialize : op[] = {}
                sublist[] = {}

    Move first item of ip to sublist.
    sublist[] = {10}

    Traverse remaining items of ip and
    if current element is greater than
    last item of sublist, move this item
    from ip to sublist. Now
    sublist[] = {10, 30, 40}
    ip[] = {5, 2, 4, 9}
                    
    Merge sublist into op.
    op = {10, 30, 40}

    Next recursive call:
    Move first item of ip to sublist.
    sublist[] = {5}

    Traverse remaining items of ip and move
    elements greater than last inserted.
    ip[] = {2, 4}
    sublist[] = {5, 9}

    Merge sublist into op.
    op = {5, 9, 10, 30, 40}

    Last Recursive Call:
    {2, 4} are first moved to sublist and
    then merged into op.
    op = {2, 4, 5, 9, 10, 30, 40}

# Bitonic Sort

Background

Bitonic Sort is a classic parallel algorithm for sorting. 
 

* Bitonic sort does O(n Log 2n) comparisons.
* The number of comparisons done by Bitonic sort are more than popular sorting algorithms like Merge Sort [ does O(nLogn) comparisons], but Bitonice sort is better for parallel implementation because we always compare elements in predefined sequence and the sequence of comparison doesn’t depend on data. Therefore it is suitable for implementation in hardware and parallel processor array.
* Bitonic Sort must be done if number of elements to sort are 2^n. The procedure of bitonic sequence fails if the number of elements are not in aforementioned quantity precisely.
To understand Bitonic Sort, we must first understand what is Bitonic Sequence and how to make a given sequence Bitonic. 
 

Bitonic Sequence

A sequence is called Bitonic if it is first increasing, then decreasing. In other words, an array arr[0..n-i] is Bitonic if there exists an index i where 0<=i<=n-1 such that 
 
    x0 <= x1 …..<= xi  and  xi >= xi+1….. >= xn-1 

1. A sequence, sorted in increasing order is considered Bitonic with the decreasing part as empty. Similarly, decreasing order sequence is considered Bitonic with the increasing part as empty.
2. A rotation of Bitonic Sequence is also bitonic.

How to form a Bitonic Sequence from a random input? 
We start by forming 4-element bitonic sequences from consecutive 2-element sequence. Consider 4-element in sequence x0, x1, x2, x3. We sort x0 and x1 in ascending order and x2 and x3 in descending order. We then concatenate the two pairs to form a 4 element bitonic sequence. 
Next, we take two 4 element bitonic sequences, sorting one in ascending order, the other in descending order (using the Bitonic Sort which we will discuss below), and so on, until we obtain the bitonic sequence.
Example: 
Convert the following sequence to bitonic sequence: 3, 7, 4, 8, 6, 2, 1, 5 
 

Step 1: Consider each 2-consecutive elements as bitonic sequence and apply bitonic sort on each 2- pair elements. In next step, take two 4 element bitonic sequences and so on.

 

![bitonic sort](https://media.geeksforgeeks.org/wp-content/uploads/bit2.png)

 

![bitonic sort1](https://media.geeksforgeeks.org/wp-content/uploads/bitonic.png)

Note: x0 and x1 are sorted in ascending order and x2 and x3 in descending order and so on
Step 2: Two 4 element bitonic sequences : A(3,7,8,4) and B(2,6,5,1) with comparator length as 2


![bitonic sort 2](https://media.geeksforgeeks.org/wp-content/uploads/bitonic2.png)
After this step, we’ll get Bitonic sequence of length 8. 
 

 3, 4, 7, 8, 6, 5, 2, 1
 

Bitonic Sorting

It mainly involves two steps. 
 

1. Forming a bitonic sequence (discussed above in detail). After this step we reach the fourth stage in below diagram, i.e., the array becomes {3, 4, 7, 8, 6, 5, 2, 1}
2. Creating one sorted sequence from bitonic sequence: After first step, first half is sorted in increasing order and second half in decreasing order. 
We compare first element of first half with first element of second half, then second element of first half with second element of second and so on. We exchange elements if an element of first half is smaller. 
After above compare and exchange steps, we get two bitonic sequences in array. See fifth stage in below diagram. In the fifth stage, we have {3, 4, 2, 1, 6, 5, 7, 8}. If we take a closer look at the elements, we can notice that there are two bitonic sequences of length n/2 such that all elements in first bitnic sequence {3, 4, 2, 1} are smaller than all elements of second bitonic sequence {6, 5, 7, 8}. 
We repeat the same process within two bitonic sequences and we get four bitonic sequences of length n/4 such that all elements of leftmost bitonic sequence are smaller and all elements of rightmost. See sixth stage in below diagram, arrays is {2, 1, 3, 4, 6, 5, 7, 8}. 
If we repeat this process one more time we get 8 bitonic sequences of size n/8 which is 1. Since all these bitonic sequence are sorted and every bitonic sequence has one element, we get the sorted array.
 

![Bitonic- Sort](https://media.geeksforgeeks.org/wp-content/uploads/bitonic3.png)

```cpp
#include<bits/stdc++.h>
using namespace std;
 
/*The parameter dir indicates the sorting direction, ASCENDING
   or DESCENDING; if (a[i] > a[j]) agrees with the direction,
   then a[i] and a[j] are interchanged.*/
void compAndSwap(int a[], int i, int j, int dir)
{
    if (dir==(a[i]>a[j]))
        swap(a[i],a[j]);
}
 
/*It recursively sorts a bitonic sequence in ascending order,
  if dir = 1, and in descending order otherwise (means dir=0).
  The sequence to be sorted starts at index position low,
  the parameter cnt is the number of elements to be sorted.*/
void bitonicMerge(int a[], int low, int cnt, int dir)
{
    if (cnt>1)
    {
        int k = cnt/2;
        for (int i=low; i<low+k; i++)
            compAndSwap(a, i, i+k, dir);
        bitonicMerge(a, low, k, dir);
        bitonicMerge(a, low+k, k, dir);
    }
}
 
/* This function first produces a bitonic sequence by recursively
    sorting its two halves in opposite sorting orders, and then
    calls bitonicMerge to make them in the same order */
void bitonicSort(int a[],int low, int cnt, int dir)
{
    if (cnt>1)
    {
        int k = cnt/2;

        // sort in ascending order since dir here is 1
        bitonicSort(a, low, k, 1);

        // sort in descending order since dir here is 0
        bitonicSort(a, low+k, k, 0);

        // Will merge wole sequence in ascending order
        // since dir=1.
        bitonicMerge(a,low, cnt, dir);
    }
}

/* Caller of bitonicSort for sorting the entire array of
   length N in ASCENDING order */
void sort(int a[], int N, int up)
{
    bitonicSort(a,0, N, up);
}
 
// Driver code
int main()
{
    int a[]= {3, 7, 4, 8, 6, 2, 1, 5};
    int N = sizeof(a)/sizeof(a[0]);
 
    int up = 1;   // means sort in ascending order
    sort(a, N, up);
 
    printf("Sorted array: \n");
    for (int i=0; i<N; i++)
        printf("%d ", a[i]);
    return 0;
}
```
    Output:  

    Sorted array: 
    1 2 3 4 5 6 7 8
    

    Analysis of Bitonic Sort

    To form a sorted sequence of length n from two sorted sequences of length n/2, log(n) comparisons are required (for example: log(8) = 3 when sequence size. Therefore, The number of comparisons T(n) of the entire sorting is given by:
    T(n) = log(n) + T(n/2)
    The solution of this recurrence equation is
    T(n) = log(n) + log(n)-1 + log(n)-2 + … + 1 = log(n) · (log(n)+1) / 2
    As, each stage of the sorting network consists of n/2 comparators. Therefore total ?(n log2n) comparators.

# Pancake sorting

Given an unsorted array, sort the given array. You are allowed to do only following operation on array. 

flip(arr, i): Reverse array from 0 to i 
Unlike a traditional sorting algorithm, which attempts to sort with the fewest comparisons possible, the goal is to sort the sequence in as few reversals as possible. 
The idea is to do something similar to Selection Sort. We one by one place maximum element at the end and reduce the size of current array by one. 
Following are the detailed steps. Let given array be arr[] and size of array be n. 

Start from current size equal to n and reduce current size by one while it’s greater than 1. Let the current size be curr_size. Do following for every curr_size
Find index of the maximum element in arr[0..curr_szie-1]. Let the index be ‘mi’
    Call flip(arr, mi)
    Call flip(arr, curr_size-1)

# Binary Insertion Sort

We can use binary search to reduce the number of comparisons in normal insertion sort. Binary Insertion Sort uses binary search to find the proper location to insert the selected item at each iteration. 
In normal insertion sort, it takes O(n) comparisons (at nth iteration) in the worst case. We can reduce it to O(log n) by using binary search.

```C++
// C program for implementation of
// binary insertion sort
#include <stdio.h>
 
// A binary search based function
// to find the position
// where item should be inserted
// in a[low..high]
int binarySearch(int a[], int item,
                 int low, int high)
{
    if (high <= low)
        return (item > a[low]) ?
                (low + 1) : low;
 
    int mid = (low + high) / 2;
 
    if (item == a[mid])
        return mid + 1;
 
    if (item > a[mid])
        return binarySearch(a, item,
                            mid + 1, high);
    return binarySearch(a, item, low,
                        mid - 1);
}
 
// Function to sort an array a[] of size 'n'
void insertionSort(int a[], int n)
{
    int i, loc, j, k, selected;
 
    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = a[i];
 
        // find location where selected sould be inseretd
        loc = binarySearch(a, selected, 0, j);
 
        // Move all elements after location to create space
        while (j >= loc)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = selected;
    }
}
 
// Driver Code
int main()
{
    int a[]
        = { 37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54 };
    int n = sizeof(a) / sizeof(a[0]), i;
 
    insertionSort(a, n);
 
    printf("Sorted array: \n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
 
    return 0;
}
```
    Output
    Sorted array: 
    0 12 17 23 31 37 46 54 72 88 100
    Time Complexity: The algorithm as a whole still has a running worst-case running time of O(n2) because of the series of swaps required for each insertion. 

# BogoSort or Permutation Sort
BogoSort also known as permutation sort, stupid sort, slow sort, shotgun sort or monkey sort is a particularly ineffective algorithm based on generate and test paradigm. The algorithm successively generates permutations of its input until it finds one that is sorted.(Wiki) 
For example, if bogosort is used to sort a deck of cards, it would consist of checking if the deck were in order, and if it were not, one would throw the deck into the air, pick the cards up at random, and repeat the process until the deck is sorted. 

    PseudoCode: 
    

    while not Sorted(list) do
        shuffle (list)
    done
    Example:
    Let us consider an example array ( 3 2 5 1 0 4 ) 
    4 5 0 3 2 1 (1st shuffling) 
    4 1 3 2 5 0 (2ndshuffling) 
    1 0 3 2 5 4 (3rd shuffling) 
    3 1 0 2 4 5 (4th shuffling) 
    1 4 5 0 3 2 (5th shuffling) 
    . 
    . 
    . 
    0 1 2 3 4 5 (nth shuffling)—— Sorted Array
    Here, n is unknown because algorithm doesn’t known in which step the resultant permutation will come out to be sorted. 
 

```C++
// C++ implementation of Bogo Sort
#include<bits/stdc++.h>
using namespace std;
 
// To check if array is sorted or not
bool isSorted(int a[], int n)
{
    while ( --n > 1 )
        if (a[n] < a[n-1])
            return false;
    return true;
}
 
// To generate permutation of the array
void shuffle(int a[], int n)
{
    for (int i=0; i < n; i++)
        swap(a[i], a[rand()%n]);
}
 
// Sorts array a[0..n-1] using Bogo sort
void bogosort(int a[], int n)
{
    // if array is not sorted then shuffle
    // the array again
    while ( !isSorted(a, n) )
        shuffle(a, n);
}
 
// prints the array
void printArray(int a[], int n)
{
    for (int i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
 
// Driver code
int main()
{
    int a[] = {3, 2, 5, 1, 0, 4};
    int n = sizeof a/sizeof a[0];
    bogosort(a, n);
    printf("Sorted array :\n");
    printArray(a,n);
    return 0;
}
```
    Output: 
    Sorted array :
    0 1 2 3 4 5 
    Time Complexity: 
    
    Worst Case : O(∞) (since this algorithm has no upper bound)
    Average Case: O(n*n!)
    Best Case : O(n)(when array given is already sorted)
    Auxiliary Space : O(1)

# Gnome Sort

Gnome Sort also called Stupid sort is based on the concept of a Garden Gnome sorting his flower pots. A garden gnome sorts the flower pots by the following method- 
 

* He looks at the flower pot next to him and the previous one; if they are in the right order he steps one pot forward, otherwise he swaps them and steps one pot backwards.
* If there is no previous pot (he is at the starting of the pot line), he steps forwards; if there is no pot next to him (he is at the end of the pot line), he is done.
    Input – 
    Array- arr[]  
    Total elements - n
Algorithm Steps 

If you are at the start of the array then go to the right element (from arr[0] to arr[1]).
If the current array element is larger or equal to the previous array element then go one step right
 

    if (arr[i] >= arr[i-1])
        i++;
 



If the current array element is smaller than the previous array element then swap these two elements and go one step backwards
 

        if (arr[i] < arr[i-1])
        {
            swap(arr[i], arr[i-1]);
            i--;
        }
 

Repeat steps 2) and 3) till ‘i’ reaches the end of the array (i.e- ‘n-1’)
If the end of the array is reached then stop and the array is sorted.
Example- 
 

   34 2 10 -9
 

Underlined elements are the pair under consideration.
“Red” colored are the pair which needs to be swapped.
Result of the swapping is colored as “blue”
![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gnomesort.png)

```C++
#include <iostream>
using namespace std;
 
// A function to sort the algorithm using gnome sort
void gnomeSort(int arr[], int n)
{
    int index = 0;
 
    while (index < n) {
        if (index == 0)
            index++;
        if (arr[index] >= arr[index - 1])
            index++;
        else {
            swap(arr[index], arr[index - 1]);
            index--;
        }
    }
    return;
}
 
// A utility function ot print an array of size n
void printArray(int arr[], int n)
{
    cout << "Sorted sequence after Gnome sort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
 
// Driver program to test above functions.
int main()
{
    int arr[] = { 34, 2, 10, -9 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    gnomeSort(arr, n);
    printArray(arr, n);
 
    return (0);
}
```
    Output: 

    Sorted sequence after applying Gnome sort: -9 2 10 34
    Time Complexity – As there are no nested loop (only one while) it may seem that this is a linear O(N) time algorithm. But the time complexity is O(N^2). This is because the variable – ‘index’ in our program doesn’t always gets incremented, it gets decremented too. 
    However this sorting algorithm is adaptive and performs better if the array is already/partially sorted.
    Auxiliary Space –  This is an in-place algorithm. So O(1) auxiliary space is needed.

# Sleep Sort – The King of Laziness / Sorting while Sleeping

In this algorithm we create different threads for each of the elements in the input array and then each thread sleeps for an amount of time which is proportional to the value of corresponding array element.

Hence, the thread having the least amount of sleeping time wakes up first and the number gets printed and then the second least element and so on. The largest element wakes up after a long time and then the element gets printed at the last. Thus the output is a sorted one.

All this multithreading process happens in background and at the core of the OS. We do not get to know anything about what’s happening in the background, hence this is a “mysterious” sorting algorithm.

Example : Let’s assume (for convenience) we have a computer that’s so slow it takes 3 seconds to work through each element:

INPUT: 8 2 9 

3s: sleep 8
6s: sleep 2
8s: "2" (2 wakes up so print it)
9s: sleep 9
11s: "8" (8 wakes up so print it)
18s: "9" (9 wakes up so print it)

OUTPUT: 2 8 9
Implementation
To implement sleep sort, we need multithreading functions, such as _beginthread() and WaitForMultipleObjects(). Hence we need to include windows.h to use these functions. This won’t compile on Online IDE. We must run it in your PC (Note this code is for WINDOWS and not for LINUX).



To perform a sleep sort we need to create threads for each of the value in the input array. We do this using the function _beginthread().

In each of the threads we assign two instructions:

1) Sleep : Sleep this thread till arr[i] milliseconds (where arr[i] is the array element which this thread is associated to). We do this using Sleep() function. The Sleep(n) function suspends the activity associated with this thread till ‘n’ milliseconds. Hence if we write Sleep(1000), then it means that the thread will sleep for 1 second (1000 milliseconds = 1 second)

2) Print : When the thread ‘wakes’ up after the sleep then print the array element – arr[i] which this thread is associated to.

After creating the threads, we process these threads. We do this using WaitForMultipleObjects().

```c
// C implementation of Sleep Sort
#include <stdio.h>
#include <windows.h>
#include <process.h>
  
// This is the instruction set of a thread
// So in these threads, we "sleep" for a particular
// amount of time and then when it wakes up
// the number is printed out
void routine(void *a)
{
    int n = *(int *) a; // typecasting from void to int
  
    // Sleeping time is proportional to the number
    // More precisely this thread sleep for 'n' milliseconds
    Sleep(n);
  
    // After the sleep, print the number
    printf("%d ", n);
}
  
/* A function that performs sleep sort
_beginthread() is a C run-time library call that creates a new
'thread' for all the integers in the array and returns that
thread.
  
Each of the 'thread' sleeps for a time proportional to that
integer and print it after waking.
  
We pass three parameters to _beginthread :-
1) start_address --> start address of the routine/function
                     which creates a new thread
2) stack_size --> Stack Size of the new thread (which is 0)
3) arglist --> Address of the argument to be passed
  
The return value of _beginthread() function is a handle to the
thread which is created. So we must accept is using the datatype-
'HANDLE' which is included in windows.h header
'HANDLE' datatype is used to represent an event/thread/process etc
So 'HANDLE' datatype is used to define a thread
We store the threads in an array - threads[] which is declared
using 'HANDLE' datatype.
  
WaitForMultipleObjects() is a function that processes the threads
and has four arguments-
1) no_of_threads --> Number of threads to be processed
2) array_of_threads --> This is the array of threads which should be
                        processed. This array must be of the type
                        'HANDLE'
3) TRUE or FALSE --> We pass TRUE if we want all the threads in the
                     array to be processed
4) time_limit --> The threads will be processed until this time limit
                  is crossed. So if we pass a 0 then no threads will
                  be processed, otherwise if we pass an INFINITE, then
                  the program will stop only when all the threads
                  are processed. We can put a cap on the execution
                  time of the program by passing the desired time
                  limit */
void sleepSort(int arr[], int n)
{
    // An array of threads, one for each of the elements
    // in the input array
    HANDLE threads[n];
  
    // Create the threads for each of the input array elements
    for (int i = 0; i < n; i++)
        threads[i] = (HANDLE)_beginthread(&routine, 0,  &arr[i]);
  
    // Process these threads
    WaitForMultipleObjects(n, threads, TRUE, INFINITE);
    return;
}
  
// Driver program to test above functions
int main()
{
    // Doesn't work for negative numbers
    int arr[] = {34, 23, 122, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
  
    sleepSort (arr, n);
  
    return(0);
}
```
SleepSort

Limitations
1) This algorithm won’t work for negative numbers as a thread cannot sleep for a negative amount of time.

2) Since this algorithm depends on the input elements, so a huge number in the input array causes this algorithm to slow down drastically (as the thread associated with that number has to sleep for a long time). So even if the input array element contains only 2 elements, like- {1, 100000000}, then also we have to wait for a much longer duration to sort.



3) This algorithm doesn’t produce a correct sorted output every time. This generally happens when there is a very small number to the left of a very large number in the input array.
For example – {34, 23, 1, 12253, 9}.
The output after sleep sorting is {9, 1, 23, 34, 1223}

A wrong output also occurs when the input array is reverse sorted initially, like- {10, 9, 8, 7, 6, 5}.

The reason for such an unexpected output is because some time is taken between scanning through each element as well as some other OS operations (like inserting each threads in a priority queue for scheduling). We cannot simply ignore the time taken by all these things.

We describe this using the below example-

Let's assume (for convenience) we have a computer that's
so slow it takes 3 seconds to work through each element: 
INPUT: 10 9 8 7 6 5

3s: sleep 10
6s: sleep 9
9s: sleep 8
12s: sleep 7
13s: "10" (10 wakes up so print it)
15s: sleep 6
15s: "9" (9 wakes up so print it)
17s: "8" (8 wakes up so print it)
18s: sleep 5
19s: "7" (7 wakes up so print it)
21s: "6" (6 wakes up so print it)
23s: "5" (5 wakes up so print it)

OUTPUT: 10 9 8 7 6 5 
The above output is just an example.
Obviously, modern-day computers computer are not so slow (to take 3 seconds to scan through each element).
In reality running sleep sort on a modern computer on the above array gives the output – {9, 5, 7, 10, 8, 6}

How to fix this ?
1) We can fix this by repeatedly sleep sorting on the new output until the output becomes sorted. Every time it will sort the elements more accurately.

2) The wrong output as discussed earlier happens due to the time taken by other OS works and scanning through each element.

In our program we have used the function Sleep(arr[i]), which means that each thread associated with the array elements sleep for ‘arr[i]’ milliseconds. Since milliseconds is a very small quantity and other OS tasks can take more time than ‘arr[i]’ milliseconds which ultimately can cause an error in sleep sorting. Increasing the sleeping time by even 10 times can give a sorted output as the OS tasks will finish all its task in between this much sleep, hence not producing any errors.

Had we used Sleep(10*arr[i]) instead of just Sleep(arr[i]) then we will certainly get a more precise output than the latter one. For example the input array – {10, 9, 8, 7, 6, 5} will give the correct sorted output – {5, 6, 7, 8, 9, 10} if we use Sleep(10*arr[i]) instead of just Sleep(arr[i]) .

However it is still possible that Sleep(10*arr[i]) will give wrong results for some test cases. To make it more precise increase the sleep time more , say something like – Sleep(20*arr[i]).



Hence the bottom line is that more the sleep time, more accurate the results are. (Sounds interesting, eh?) . But again that would increase the runtime of this algorithm.

Exercise to the readers-
1) The above algorithm tries to sort it in ascending order. Can you sort an input array in descending order using sleep sort. Think upon it.

2) Is it a comparison based sorting algorithm ? How many comparisons this algorithm makes ?
[ Answer : No, it makes zero comparisons ]

3) Can we do sleeping sort without using windows.h header and without using Sleep() function?
[One idea can be to create a priority queue where the elements are arranged according to the time left before waking up and getting printed. The element at the front of the priority queue will be the first one to get waked up. However the implementation doesn’t looks easy. Think on it.]

Time Complexity
Although there are many conflicting opinions about the time complexity of sleep sort, but we can approximate the time complexity using the below reasoning-

Since Sleep() function and creating multiple threads is done internally by the OS using a priority queue (used for scheduling purposes). Hence inserting all the array elements in the priority queue takes O(Nlog N) time. Also the output is obtained only when all the threads are processed, i.e- when all the elements ‘wakes’ up. Since it takes O(arr[i]) time to wake the ith array element’s thread. So it will take a maximum of O(max(input)) for the largest element of the array to wake up. Thus the overall time complexity can be assumed as O(NlogN + max(input)),
where, N = number of elements in the input array, and input = input array elements

Auxiliary Space
All the things are done by the internal priority queue of the OS. Hence auxiliary space can be ignored.

Conclusion
Sleep Sort is related to Operating System more than any other sorting algorithm. This sorting algorithm is a perfect demonstration of multi-threading and scheduling done by OS.

The phrase “Sorting while Sleeping” itself sounds very unique. Overall it is a fun, lazy, weird algorithm. But as rightly said by someone- “If it works then it is not lazy”.
### sleepsort.c
[using_TDM_GCC_COMPILER✅]

# Selection Sort

The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.
1) The subarray which is already sorted. 
2) Remaining subarray which is unsorted.
In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray. 
Following example explains the above steps: 

arr[] = 64 25 12 22 11

// Find the minimum element in arr[0...4]
// and place it at beginning
11 25 12 22 64

// Find the minimum element in arr[1...4]
// and place it at beginning of arr[1...4]
11 12 25 22 64

// Find the minimum element in arr[2...4]
// and place it at beginning of arr[2...4]
11 12 22 25 64

// Find the minimum element in arr[3...4]
// and place it at beginning of arr[3...4]
11 12 22 25 64 
Flowchart of the Selection Sort: 
 
```cpp
// C program for implementation of selection sort
#include <stdio.h>
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
```
    Output: 
    Sorted array: 
    11 12 22 25 64
 

Time Complexity: O(n2) as there are two nested loops.
Auxiliary Space: O(1) 
The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation. 

# Stooge Sort

The Stooge sort is a recursive sorting algorithm. It is defined as below (for ascending order sorting).  

Step 1 : If value at index 0 is greater than
         value at last index, swap them.
Step 2:  Recursively, 
       a) Stooge sort the initial 2/3rd of the array.
       b) Stooge sort the last 2/3rd of the array.
       c) Stooge sort the initial 2/3rd again to confirm.
NOTE: Always take the ceil of ((2/3)*N) for selecting elements.  

Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Illustration:  

Input :   2 4 5 3 1
Output : 1 2 3 4 5
Explanation:
Initially, swap 2 and 1 following above step 1.
          1 4 5 3 2
          Now, recursively sort initial 2/3rd of the elements.
          1 4 5 3 2
          1 3 4 5 2 
          Then, recursively sort last 2/3rd of the elements.
          1 3 4 5 2
          1 2 3 4 5
          Again, sort the initial 2/3rd of the elements to confirm final data is sorted.
          1 2 3 4 5
![stooge_sort](https://media.geeksforgeeks.org/wp-content/uploads/stoogeSort.png)

# Tag Sort (To get both sorted and original)
Difficulty Level : Easy
Last Updated : 28 Jun, 2021
Geek-O-Lympics
This is not a new sorting algorithm, but an idea when we need to avoid swapping of large objects or need to access elements of a large array in both original and sorted orders.
A common sorting task is to sort elements of an array using a sorting algorithm like Quick Sort, Bubble Sort.. etc, but there may be times when we need to keep the actual array in tact and use a “tagged” array to store the correct positioning of the array when it is sorted. When we want to access elements in sorted way, we can use this “tagged” array.

Why to use Tag Sort?

When we are operating on large array of objects, it might be too costly to swap these large object. After all its about the disk swaps and we want to minimize it!

Tag Sort allows sorting an integer array after tagging it with original object.
In turn, we only swap the tag array integers instead of large array of objects.
The actual elements are not being changed during the sort process. The positions in the tag array are being changed so they will hold the correct ordering of the elements when they are sorted.
In this example, the original elements in arr[] are not changed, but the original elements in tag[] are manipulated. The tag[] array will now hold the correct subscript ordering of the elements in arr[] so the array can be sorted into descending order when the tag[] array is called upon.
Tag Sort

Another Example, Suppose we have following Person object which inherently takes large chunk of memory( in GB or hundreds of MB).



class Person 
{
    private int id;
    private float salary;
    private Object someBigObject = new Object(); 
    public Person(int id, float salary) 
    { }
    public float getSalary() 
    { }
    public String toString() 
    { }
}
Hence, it might not be practical to move around these objects as disk seeks for swaps can eat up a lot of time. To avoid this, we start by creating a tag array.

Every Person object is tagged to one element in the tag array and Instead of swapping the person object for sorting based on salary , we swap the tag[] integers.
While printing the sorted array we take a cue from the tag array to print the sorted Persons array.
Eventually, we’ll escape swapping large Persons object.
Below is the implementation of above idea.

```java
// Java Program to illustrate Tag Sort. This code
// uses Bubble Sort to modify tag array according
// to salaries. We can use other optimized sorting
// techniques also.
class Person
{
    private int id;
    private float salary;
    private Object someBigObject = new Object();
  
    public Person(int id, float salary)
    {
        this.id = id;
        this.salary = salary;
    }
  
    public float getSalary()
    {
        return salary;
    }
  
    @Override
    public String toString()
    {
        return "Person{" +
               "id=" + id +
               ", salary=" + salary +
               ", someBigObject=" + someBigObject +
               '}';
    }
}
  
public class Main
{
    public static void main(String[] args)
    {
        // Creating objects and their original
        // order (in tag array)
        int n = 5;
        Person persons[] = new Person[n];
        persons[0] = new Person(0, 233.5f);
        persons[1] = new Person(1, 23f);
        persons[2] = new Person(2, 13.98f);
        persons[3] = new Person(3, 143.2f);
        persons[4] = new Person(4, 3f);
        int tag[] = new int[n];
        for (int i = 0; i < n; i++)
            tag[i] = i;
  
        // Every Person object is tagged to
        // an element in the tag array.
        System.out.println("Given Person and Tag ");
        for (int i = 0; i < n; i++)
            System.out.println(persons[i] + " : Tag: " + tag[i]);
  
        // Modifying tag array so that we can access
        // persons in sorted order.
        tagSort(persons, tag);
  
        System.out.println("New Tag Array after "+ "getting sorted as per Person[] ");
        for (int i=0; i<n; i++)
            System.out.println(tag[i]);
  
        // Accessing persons in sorted (by salary)
        // way using modified tag array.
        for (int i = 0; i < n; i++)
            System.out.println(persons[tag[i]]);
    }
  
    // Modifying tag array so that we can access
    // persons in sorted order of salary.
    public static void tagSort(Person persons[],
                               int tag[])
    {
        int n = persons.length;
        for (int i=0; i<n; i++)
        {
            for (int j=i+1; j<n; j++)
            {
                if (persons[tag[i]].getSalary() >
                        persons[tag[j]].getSalary())
                {
                    // Note we are not sorting the
                    // actual Persons array, but only
                    // the tag array
                    int temp = tag[i];
                    tag[i] = tag[j];
                    tag[j] = temp;
                }
            }
        }
    }
}
```
    Output:

    Given Person and Tag 
    Person{id=0, salary=233.5, someBigObject=java.lang.Object@15db9742} : Tag: 0
    Person{id=1, salary=23.0, someBigObject=java.lang.Object@6d06d69c} : Tag: 1
    Person{id=2, salary=13.98, someBigObject=java.lang.Object@7852e922} : Tag: 2
    Person{id=3, salary=143.2, someBigObject=java.lang.Object@4e25154f} : Tag: 3
    Person{id=4, salary=3.0, someBigObject=java.lang.Object@70dea4e} : Tag: 4
    New Tag Array after getting sorted as per Person[] 
    4
    2
    1
    3
    0
    Person{id=4, salary=3.0, someBigObject=java.lang.Object@70dea4e}
    Person{id=2, salary=13.98, someBigObject=java.lang.Object@7852e922}
    Person{id=1, salary=23.0, someBigObject=java.lang.Object@6d06d69c}
    Person{id=3, salary=143.2, someBigObject=java.lang.Object@4e25154f}
    Person{id=0, salary=233.5, someBigObject=java.lang.Object@15db9742}

# Tree Sort

Tree sort is a sorting algorithm that is based on Binary Search Tree data structure. It first creates a binary search tree from the elements of the input list or array and then performs an in-order traversal on the created binary search tree to get the elements in sorted order. 
Algorithm: 
 

    Step 1: Take the elements input in an array.
    Step 2: Create a Binary search tree by inserting data items from the array into the
            binary search tree.
    Step 3: Perform in-order traversal on the tree to get the elements in sorted order.

```cpp
// C++ program to implement Tree Sort
#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int key;
	struct Node *left, *right;
};

// A utility function to create a new BST Node
struct Node *newNode(int item)
{
	struct Node *temp = new Node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// Stores inorder traversal of the BST
// in arr[]
void storeSorted(Node *root, int arr[], int &i)
{
	if (root != NULL)
	{
		storeSorted(root->left, arr, i);
		arr[i++] = root->key;
		storeSorted(root->right, arr, i);
	}
}

/* A utility function to insert a new
Node with given key in BST */
Node* insert(Node* node, int key)
{
	/* If the tree is empty, return a new Node */
	if (node == NULL) return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	/* return the (unchanged) Node pointer */
	return node;
}

// This function sorts arr[0..n-1] using Tree Sort
void treeSort(int arr[], int n)
{
	struct Node *root = NULL;

	// Construct the BST
	root = insert(root, arr[0]);
	for (int i=1; i<n; i++)
		root = insert(root, arr[i]);

	// Store inorder traversal of the BST
	// in arr[]
	int i = 0;
	storeSorted(root, arr, i);
}

// Driver Program to test above functions
int main()
{
	//create input array
	int arr[] = {5, 4, 7, 2, 11};
	int n = sizeof(arr)/sizeof(arr[0]);

	treeSort(arr, n);

		for (int i=0; i<n; i++)
	cout << arr[i] << " ";

	return 0;
}
```

# Cartesian Tree Sorting
Difficulty Level : Expert
Last Updated : 19 May, 2016
Geek-O-Lympics
Prerequisites : Cartesian Tree

Cartesian Sort is an Adaptive Sorting as it sorts the data faster if data is partially sorted. In fact, there are very few sorting algorithms that make use of this fact.

For example consider the array {5, 10, 40, 30, 28}. The input data is partially sorted too as only one swap between “40” and “28” results in a completely sorted order. See how Cartesian Tree Sort will take advantage of this fact below.

Below are steps used for sorting.

Step 1 : Build a (min-heap) Cartesian Tree from the given input sequence.
![ctree1](https://www.geeksforgeeks.org/wp-content/uploads/ctree1-1024x420.png)



Step 2 : Starting from the root of the built Cartesian Tree, we push the nodes in a priority queue.
Then we pop the node at the top of the priority queue and push the children of the popped node in the priority queue in a pre-order manner.

Pop the node at the top of the priority queue and add it to a list.
Push left child of the popped node first (if present).
Push right child of the popped node next (if present).
![ctree1](https://www.geeksforgeeks.org/wp-content/uploads/ctree11-1024x420.png)
![ctree1](https://www.geeksforgeeks.org/wp-content/uploads/ctree21-1024x420.png)


How to build (min-heap) Cartesian Tree?
Building min-heap is similar to building a (max-heap) Cartesian Tree (discussed in previous post), except the fact that now we scan upward from the node’s parent up to the root of the tree until a node is found whose value is smaller (and not larger as in the case of a max-heap Cartesian Tree) than the current one and then accordingly reconfigure links to build the min-heap Cartesian tree.

Why not to use only priority queue?
One might wonder that using priority queue would anyway result in a sorted data if we simply insert the numbers of the input array one by one in the priority queue (i.e- without constructing the Cartesian tree).

But the time taken differs a lot.

Suppose we take the input array – {5, 10, 40, 30, 28}

If we simply insert the input array numbers one by one (without using a Cartesian tree), then we may have to waste a lot of operations in adjusting the queue order everytime we insert the numbers (just like a typical heap performs those operations when a new number is inserted, as priority queue is nothing but a heap).



Whereas, here we can see that using a Cartesian tree took only 5 operations (see the above two figures in which we are continuously pushing and popping the nodes of Cartesian tree), which is linear as there are 5 numbers in the input array also. So we see that the best case of Cartesian Tree sort is O(n), a thing where heap-sort will take much more number of operations, because it doesn’t make advantage of the fact that the input data is partially sorted.

Why pre-order traversal?
The answer to this is that since Cartesian Tree is basically a heap- data structure and hence follows all the properties of a heap. Thus the root node is always smaller than both of its children. Hence, we use a pre-order fashion popping-and-pushing as in this, the root node is always pushed earlier than its children inside the priority queue and since the root node is always less than both its child, so we don’t have to do extra operations inside the priority queue.

Refer to the below figure for better understanding-
![ctree3](https://www.geeksforgeeks.org/wp-content/uploads/ctree3-1024x420.png)

### cartesiansort.cpp

Time Complexity : O(n) best-case behaviour (when the input data is partially sorted), O(n log n) worst-case behavior (when the input data is not partially sorted)

Auxiliary Space : We use a priority queue and a Cartesian tree data structure. Now, at any moment of time the size of the priority queue doesn’t exceeds the size of the input array, as we are constantly pushing and popping the nodes. Hence we are using O(n) auxiliary space.

# Odd-Even Sort / Brick Sort

This is basically a variation of bubble-sort. This algorithm is divided into two phases- Odd and Even Phase. The algorithm runs until the array elements are sorted and in each iteration two phases occurs- Odd and Even Phases.
In the odd phase, we perform a bubble sort on odd indexed elements and in the even phase, we perform a bubble sort on even indexed elements.
 

```C++

// A C++ Program to implement Odd-Even / Brick Sort
#include<bits/stdc++.h>
using namespace std;
 
// A function to sort the algorithm using Odd Even sort
void oddEvenSort(int arr[], int n)
{
    bool isSorted = false; // Initially array is unsorted
 
    while (!isSorted)
    {
        isSorted = true;
 
        // Perform Bubble sort on odd indexed element
        for (int i=1; i<=n-2; i=i+2)
        {
            if (arr[i] > arr[i+1])
             {
                swap(arr[i], arr[i+1]);
                isSorted = false;
              }
        }
 
        // Perform Bubble sort on even indexed element
        for (int i=0; i<=n-2; i=i+2)
        {
            if (arr[i] > arr[i+1])
            {
                swap(arr[i], arr[i+1]);
                isSorted = false;
            }
        }
    }
 
    return;
}
 
// A utility function ot print an array of size n
void printArray(int arr[], int n)
{
   for (int i=0; i < n; i++)
       cout << arr[i] << " ";
   cout << "\n";
}
 
// Driver program to test above functions.
int main()
{
    int arr[] = {34, 2, 10, -9};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    oddEvenSort(arr, n);
    printArray(arr, n);
 
    return (0);
}
```
    Output : 

    -9 2 10 34 
    We demonstrate the above algorithm using the below illustration on the array = {3, 2, 3, 8, 5, 6, 4, 1}
    

![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/odd-even-sort.png)

    Please refer wiki for proof of correctness.
    Time Complexity : O(N2) where, N = Number of elements in the input array.
    Auxiliary Space : O(1). Just like bubble sort this is also an in-place algorithm.

# QuickSort on Singly Linked List
QuickSort on Doubly Linked List is discussed here. QuickSort on Singly linked list was given as an exercise. Following is C++ implementation for same. The important things about implementation are, it changes pointers rather swapping data and time complexity is same as the implementation for Doubly Linked List. 
 

In partition(), we consider last element as pivot. We traverse through the current list and if a node has value greater than pivot, we move it after tail. If the node has smaller value, we keep it at its current position. 

In QuickSortRecur(), we first call partition() which places pivot at correct position and returns pivot. After pivot is placed at correct position, we find tail node of left side (list before pivot) and recur for left list. Finally, we recur for right list.
 
```cpp
// C++ program for Quick Sort on Singly Linled List
#include <cstdio>
#include <iostream>
using namespace std;
 
/* a node of the singly linked list */
struct Node {
    int data;
    struct Node* next;
};
 
/* A utility function to insert a node at the beginning of
 * linked list */
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node = new Node;
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
/* A utility function to print linked list */
void printList(struct Node* node)
{
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
 
// Returns the last node of the list
struct Node* getTail(struct Node* cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}
 
// Partitions the list taking the last element as the pivot
struct Node* partition(struct Node* head, struct Node* end,
                       struct Node** newHead,
                       struct Node** newEnd)
{
    struct Node* pivot = end;
    struct Node *prev = NULL, *cur = head, *tail = pivot;
 
    // During partition, both the head and end of the list
    // might change which is updated in the newHead and
    // newEnd variables
    while (cur != pivot) {
        if (cur->data < pivot->data) {
            // First node that has a value less than the
            // pivot - becomes the new head
            if ((*newHead) == NULL)
                *newHead = cur;
 
            prev = cur;
            cur = cur->next;
        }
        else // If cur node is greater than pivot
        {
            // Move cur node to next of tail, and change
            // tail
            if (prev)
                prev->next = cur->next;
            struct Node* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
 
    // If the pivot data is the smallest element in the
    // current list, pivot becomes the head
    if ((*newHead) == NULL)
        (*newHead) = pivot;
 
    // Update newEnd to the current last node
    (*newEnd) = tail;
 
    // Return the pivot node
    return pivot;
}
 
// here the sorting happens exclusive of the end node
struct Node* quickSortRecur(struct Node* head, struct Node* end)
{
    // base condition
    if (!head || head == end)
        return head;
 
    Node *newHead = NULL, *newEnd = NULL;
 
    // Partition the list, newHead and newEnd will be
    // updated by the partition function
    struct Node* pivot = partition(head, end, &newHead, &newEnd);
 
    // If pivot is the smallest element - no need to recur
    // for the left part.
    if (newHead != pivot) {
        // Set the node before the pivot node as NULL
        struct Node* tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
 
        // Recur for the list before pivot
        newHead = quickSortRecur(newHead, tmp);
 
        // Change next of last node of the left half to
        // pivot
        tmp = getTail(newHead);
        tmp->next = pivot;
    }
 
    // Recur for the list after the pivot element
    pivot->next = quickSortRecur(pivot->next, newEnd);
 
    return newHead;
}
 
// The main function for quick sort. This is a wrapper over
// recursive function quickSortRecur()
void quickSort(struct Node** headRef)
{
    (*headRef)= quickSortRecur(*headRef, getTail(*headRef));
    return;
}
 
// Driver code
int main()
{
    struct Node* a = NULL;
    push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);
 
    cout << "Linked List before sorting \n";
    printList(a);
 
    quickSort(&a);
 
    cout << "Linked List after sorting \n";
    printList(a);
 
    return 0;
}
```
    Output
    Linked List before sorting 
    30 3 4 20 5 
    Linked List after sorting 
    3 4 5 20 30 

# QuickSort on Doubly Linked List

Following is a typical recursive implementation of QuickSort for arrays. The implementation uses last element as pivot. 

```cpp
/* A typical recursive implementation of Quicksort for array*/
 
/* This function takes last element as pivot, places the pivot element at its
   correct position in sorted array, and places all smaller (smaller than
   pivot) to left of pivot and all greater elements to right of pivot */
int partition (int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1); 

    for (int j = l; j <= h- 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap (&arr[i], &arr[j]);
        }
    }
    swap (&arr[i + 1], &arr[h]);
    return (i + 1);
}
 
/* A[] --> Array to be sorted, l  --> Starting index, h  --> Ending index */
void quickSort(int A[], int l, int h)
{
    if (l < h)
    {       
        int p = partition(A, l, h); /* Partitioning index */
        quickSort(A, l, p - 1); 
        quickSort(A, p + 1, h);
    }
}
```
Can we use the same algorithm for Linked List? 
Following is C++ implementation for the doubly linked list. The idea is simple, we first find out pointer to the last node. Once we have a pointer to the last node, we can recursively sort the linked list using pointers to first and last nodes of a linked list, similar to the above recursive function where we pass indexes of first and last array elements. The partition function for a linked list is also similar to partition for arrays. Instead of returning index of the pivot element, it returns a pointer to the pivot element. In the following implementation, quickSort() is just a wrapper function, the main recursive function is _quickSort() which is similar to quickSort() for array implementation.
```cpp

// A C++ program to sort a linked list using Quicksort
#include <bits/stdc++.h>
using namespace std;
 
/* a node of the doubly linked list */
class Node
{
    public:
    int data;
    Node *next;
    Node *prev;
};
 
/* A utility function to swap two elements */
void swap ( int* a, int* b )
{ std::swap( *a, *b); }
 
// A utility function to find
// last node of linked list
Node *lastNode(Node *root)
{
    while (root && root->next)
        root = root->next;
    return root;
}
 
/* Considers last element as pivot,
places the pivot element at its
correct position in sorted array,
and places all smaller (smaller than
pivot) to left of pivot and all greater
elements to right of pivot */
Node* partition(Node *l, Node *h)
{
    // set pivot as h element
    int x = h->data;
 
    // similar to i = l-1 for array implementation
    Node *i = l->prev;
 
    // Similar to "for (int j = l; j <= h- 1; j++)"
    for (Node *j = l; j != h; j = j->next)
    {
        if (j->data <= x)
        {
            // Similar to i++ for array
            i = (i == NULL)? l : i->next;
 
            swap(&(i->data), &(j->data));
        }
    }
    i = (i == NULL)? l : i->next; // Similar to i++
    swap(&(i->data), &(h->data));
    return i;
}
 
/* A recursive implementation
of quicksort for linked list */
void _quickSort(Node* l, Node *h)
{
    if (h != NULL && l != h && l != h->next)
    {
        Node *p = partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}
 
// The main function to sort a linked list.
// It mainly calls _quickSort()
void quickSort(Node *head)
{
    // Find last node
    Node *h = lastNode(head);
 
    // Call the recursive QuickSort
    _quickSort(head, h);
}
 
// A utility function to print contents of arr
void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
 
/* Function to insert a node at the
beginging of the Doubly Linked List */
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node; /* allocate node */
    new_node->data = new_data;
 
    /* since we are adding at the
    beginning, prev is always NULL */
    new_node->prev = NULL;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* change prev of head node to new node */
    if ((*head_ref) != NULL) (*head_ref)->prev = new_node ;
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
/* Driver code */
int main()
{
    Node *a = NULL;
    push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);
 
    cout << "Linked List before sorting \n";
    printList(a);
 
    quickSort(a);
 
    cout << "Linked List after sorting \n";
    printList(a);
 
    return 0;
}
```
    Output :



    Linked List before sorting
    30  3  4  20  5
    Linked List after sorting
    3  4  5  20  30
Time Complexity: Time complexity of the above implementation is same as time complexity of QuickSort() for arrays. It takes O(n^2) time in the worst case and O(nLogn) in average and best cases. The worst case occurs when the linked list is already sorted.
Can we implement random quicksort for a linked list? 
Quicksort can be implemented for Linked List only when we can pick a fixed point as the pivot (like the last element in the above implementation). Random QuickSort cannot be efficiently implemented for Linked Lists by picking random pivot.

# 3-Way QuickSort (Dutch National Flag)
In simple QuickSort algorithm, we select an element as pivot, partition the array around a pivot and recur for subarrays on the left and right of the pivot. 
Consider an array which has many redundant elements. For example, {1, 4, 2, 4, 2, 4, 1, 2, 4, 1, 2, 2, 2, 2, 4, 1, 4, 4, 4}. If 4 is picked as a pivot in Simple Quick Sort, we fix only one 4 and recursively process remaining occurrences.
The idea of 3 way Quick Sort is to process all occurrences of the pivot and is based on Dutch National Flag algorithm. 

In 3 Way QuickSort, an array arr[l..r] is divided in 3 parts:
a. arr[l..i] elements less than pivot.
b. arr[i+1..j-1] elements equal to pivot.
c. arr[j..r] elements greater than pivot.
Below is the implementation of the above algorithm.

```cpp
// C++ program for 3-way quick sort
#include <bits/stdc++.h>
using namespace std;
 
/* This function partitions a[] in three parts
   a) a[l..i] contains all elements smaller than pivot
   b) a[i+1..j-1] contains all occurrences of pivot
   c) a[j..r] contains all elements greater than pivot */
void partition(int a[], int l, int r, int& i, int& j)
{
    i = l - 1, j = r;
    int p = l - 1, q = r;
    int v = a[r];
 
    while (true) {
        // From left, find the first element greater than
        // or equal to v. This loop will definitely
        // terminate as v is last element
        while (a[++i] < v)
            ;
 
        // From right, find the first element smaller than
        // or equal to v
        while (v < a[--j])
            if (j == l)
                break;
 
        // If i and j cross, then we are done
        if (i >= j)
            break;
 
        // Swap, so that smaller goes on left greater goes
        // on right
        swap(a[i], a[j]);
 
        // Move all same left occurrence of pivot to
        // beginning of array and keep count using p
        if (a[i] == v) {
            p++;
            swap(a[p], a[i]);
        }
 
        // Move all same right occurrence of pivot to end of
        // array and keep count using q
        if (a[j] == v) {
            q--;
            swap(a[j], a[q]);
        }
    }
 
    // Move pivot element to its correct index
    swap(a[i], a[r]);
 
    // Move all left same occurrences from beginning
    // to adjacent to arr[i]
    j = i - 1;
    for (int k = l; k < p; k++, j--)
        swap(a[k], a[j]);
 
    // Move all right same occurrences from end
    // to adjacent to arr[i]
    i = i + 1;
    for (int k = r - 1; k > q; k--, i++)
        swap(a[i], a[k]);
}
 
// 3-way partition based quick sort
void quicksort(int a[], int l, int r)
{
    if (r <= l)
        return;
 
    int i, j;
 
    // Note that i and j are passed as reference
    partition(a, l, r, i, j);
 
    // Recur
    quicksort(a, l, j);
    quicksort(a, i, r);
}
 
// A utility function to print an array
void printarr(int a[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d  ", a[i]);
    printf("\n");
}
 
// Driver code
int main()
{
    int a[] = { 4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4 };
    int size = sizeof(a) / sizeof(int);
   
      // Function Call
    printarr(a, size);
    quicksort(a, 0, size - 1);
    printarr(a, size);
    return 0;
}
```
    Output
    4  9  4  4  1  9  4  4  9  4  4  1  4  
    1  1  4  4  4  4  4  4  4  4  9  9  9  


Another Implementation using Dutch National Flag Algorithm



```cpp
// C++ program for 3-way quick sort
#include <bits/stdc++.h>
using namespace std;
 
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
// A utility function to print an array
void printarr(int a[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}
 
/* This function partitions a[] in three parts
a) a[l..i] contains all elements smaller than pivot
b) a[i+1..j-1] contains all occurrences of pivot
c) a[j..r] contains all elements greater than pivot */
 
// It uses Dutch National Flag Algorithm
void partition(int a[], int low, int high, int& i, int& j)
{
    // To handle 2 elements
    if (high - low <= 1) {
        if (a[high] < a[low])
            swap(&a[high], &a[low]);
        i = low;
        j = high;
        return;
    }
 
    int mid = low;
    int pivot = a[high];
    while (mid <= high) {
        if (a[mid] < pivot)
            swap(&a[low++], &a[mid++]);
        else if (a[mid] == pivot)
            mid++;
        else if (a[mid] > pivot)
            swap(&a[mid], &a[high--]);
    }
 
    // update i and j
    i = low - 1;
    j = mid; // or high+1
}
 
// 3-way partition based quick sort
void quicksort(int a[], int low, int high)
{
    if (low >= high) // 1 or 0 elements
        return;
 
    int i, j;
 
    // Note that i and j are passed as reference
    partition(a, low, high, i, j);
 
    // Recur two halves
    quicksort(a, low, i);
    quicksort(a, j, high);
}
 
// Driver Code
int main()
{
    int a[] = { 4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4 };
    // int a[] = {4, 39, 54, 14, 31, 89, 44, 34, 59, 64, 64,
    // 11, 41}; int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int a[] = {91, 82, 73, 64, 55, 46, 37, 28, 19, 10};
    // int a[] = {4, 9, 4, 4, 9, 1, 1, 1};
    int size = sizeof(a) / sizeof(int);
 
    // Function Call
    printarr(a, size);
    quicksort(a, 0, size - 1);
    printarr(a, size);
    return 0;
}
```
    Output
    4 9 4 4 1 9 4 4 9 4 4 1 4 
    1 1 4 4 4 4 4 4 4 4 9 9 9 

# Merge Sort for Linked Lists
 
Merge sort is often preferred for sorting a linked list. The slow random-access performance of a linked list makes some other algorithms (such as quicksort) perform poorly, and others (such as heapsort) completely impossible. 

sorting image

Let the head by the first node of the linked list be sorted and headRef be the pointer to head. Note that we need a reference to head in MergeSort() as the below implementation changes next links to sort the linked lists (not data at the nodes), so the head node has to be changed if the data at the original head is not the smallest value in the linked list. 

MergeSort(headRef)
1) If the head is NULL or there is only one element in the Linked List 
    then return.
2) Else divide the linked list into two halves.  
      FrontBackSplit(head, &a, &b); /* a and b are two halves */
3) Sort the two halves a and b.
      MergeSort(a);
      MergeSort(b);
4) Merge the sorted a and b (using SortedMerge() discussed here) 
   and update the head pointer using headRef.
     *headRef = SortedMerge(a, b);
Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.
 
```cpp
// C++ code for linked list merged sort
#include <bits/stdc++.h>
using namespace std;
 
/* Link list node */
class Node {
public:
    int data;
    Node* next;
};
 
/* function prototypes */
Node* SortedMerge(Node* a, Node* b);
void FrontBackSplit(Node* source,
                    Node** frontRef, Node** backRef);
 
/* sorts the linked list by changing next pointers (not data) */
void MergeSort(Node** headRef)
{
    Node* head = *headRef;
    Node* a;
    Node* b;
 
    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
 
    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b);
 
    /* Recursively sort the sublists */
    MergeSort(&a);
    MergeSort(&b);
 
    /* answer = merge the two sorted lists together */
    *headRef = SortedMerge(a, b);
}
 
/* See https:// www.geeksforgeeks.org/?p=3622 for details of this
function */
Node* SortedMerge(Node* a, Node* b)
{
    Node* result = NULL;
 
    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 
    /* Pick either a or b, and recur */
    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}
 
/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,
    and return the two lists using the reference parameters.
    If the length is odd, the extra node should go in the front list.
    Uses the fast/slow pointer strategy. */
void FrontBackSplit(Node* source,
                    Node** frontRef, Node** backRef)
{
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;
 
    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
 
    /* 'slow' is before the midpoint in the list, so split it in two
    at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}
 
/* Function to print nodes in a given linked list */
void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}
 
/* Function to insert a node at the beginging of the linked list */
void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = new Node();
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
/* Driver program to test above functions*/
int main()
{
    /* Start with the empty list */
    Node* res = NULL;
    Node* a = NULL;
 
    /* Let us create a unsorted linked lists to test the functions
Created lists shall be a: 2->3->20->5->10->15 */
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&a, 20);
    push(&a, 3);
    push(&a, 2);
 
    /* Sort the above created Linked List */
    MergeSort(&a);
 
    cout << "Sorted Linked List is: \n";
    printList(a);
 
    return 0;
}
```
    Output: 
    Sorted Linked List is: 
    2 3 5 10 15 20
 

Time Complexity: O(n*log n)



Space Complexity: O(n*log n)

Approach 2: This approach is simpler and uses log n space.

mergeSort():

If the size of the linked list is 1 then return the head
Find mid using The Tortoise and The Hare Approach
Store the next of mid in head2 i.e. the right sub-linked list.
Now Make the next midpoint null.
Recursively call mergeSort() on both left and right sub-linked list and store the new head of the left and right linked list.
Call merge() given the arguments new heads of left and right sub-linked lists and store the final head returned after merging.
Return the final head of the merged linkedlist.
merge(head1, head2):

Take a pointer say merged to store the merged list in it and store a dummy node in it.
Take a pointer temp and assign merge to it.
If the data of head1 is less than the data of head2, then, store head1 in next of temp & move head1 to the next of head1.
Else store head2 in next of temp & move head2 to the next of head2.
Move temp to the next of temp.
Repeat steps 3, 4 & 5 until head1 is not equal to null and head2 is not equal to null.
Now add any remaining nodes of the first or the second linked list to the merged linked list.
Return the next of merged(that will ignore the dummy and return the head of the final merged linked list)
```java
// Java program for the above approach
import java.io.*;
import java.lang.*;
import java.util.*;
 
// Node Class
class Node {
    int data;
    Node next;
    Node(int key)
    {
        this.data = key;
        next = null;
    }
}
 
class GFG {
   
    // Function to merge sort
    static Node mergeSort(Node head)
    {
        if (head.next == null)
            return head;
 
        Node mid = findMid(head);
        Node head2 = mid.next;
        mid.next = null;
        Node newHead1 = mergeSort(head);
        Node newHead2 = mergeSort(head2);
        Node finalHead = merge(newHead1, newHead2);
 
        return finalHead;
    }
 
    // Function to merge two linked lists
    static Node merge(Node head1, Node head2)
    {
        Node merged = new Node(-1);
        Node temp = merged;
       
        // While head1 is not null and head2
        // is not null
        while (head1 != null && head2 != null) {
            if (head1.data < head2.data) {
                temp.next = head1;
                head1 = head1.next;
            }
            else {
                temp.next = head2;
                head2 = head2.next;
            }
            temp = temp.next;
        }
       
        // While head1 is not null
        while (head1 != null) {
            temp.next = head1;
            head1 = head1.next;
            temp = temp.next;
        }
       
        // While head2 is not null
        while (head2 != null) {
            temp.next = head2;
            head2 = head2.next;
            temp = temp.next;
        }
        return merged.next;
    }
 
    // Find mid using The Tortoise and The Hare approach
    static Node findMid(Node head)
    {
        Node slow = head, fast = head.next;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
 
    // Function to print list
    static void printList(Node head)
    {
        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
    }
 
    // Driver Code
    public static void main(String[] args)
    {
        Node head = new Node(7);
        Node temp = head;
        temp.next = new Node(10);
        temp = temp.next;
        temp.next = new Node(5);
        temp = temp.next;
        temp.next = new Node(20);
        temp = temp.next;
        temp.next = new Node(3);
        temp = temp.next;
        temp.next = new Node(2);
        temp = temp.next;
 
        // Apply merge Sort
        head = mergeSort(head);
        System.out.print("\nSorted Linked List is: \n");
        printList(head);
    }
}
```
    Output:

    Sorted Linked List is: 
    2 3 5 7 10 20 
Time Complexity: O(n*log n)

Space Complexity: O(log n)

# Merge Sort for Doubly Linked List
Given a doubly linked list, write a function to sort the doubly linked list in increasing order using merge sort.
For example, the following doubly linked list should be changed to 24810
 
Merge sort for singly linked list is already discussed. The important change here is to modify the previous pointers also when merging two lists.
Below is the implementation of merge sort for doubly linked list. 
 

```cpp
// C++ program for merge sort on doubly linked list
#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *next, *prev;
};
 
Node *split(Node *head);
 
// Function to merge two linked lists
Node *merge(Node *first, Node *second)
{
    // If first linked list is empty
    if (!first)
        return second;
 
    // If second linked list is empty
    if (!second)
        return first;
 
    // Pick the smaller value
    if (first->data < second->data)
    {
        first->next = merge(first->next,second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = merge(first,second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}
 
// Function to do merge sort
Node *mergeSort(Node *head)
{
    if (!head || !head->next)
        return head;
    Node *second = split(head);
 
    // Recur for left and right halves
    head = mergeSort(head);
    second = mergeSort(second);
 
    // Merge the two sorted halves
    return merge(head,second);
}
 
// A utility function to insert a new node at the
// beginning of doubly linked list
void insert(Node **head, int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = temp->prev = NULL;
    if (!(*head))
        (*head) = temp;
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}
 
// A utility function to print a doubly linked list in
// both forward and backward directions
void print(Node *head)
{
    Node *temp = head;
    cout<<"Forward Traversal using next poitner\n";
    while (head)
    {
        cout << head->data << " ";
        temp = head;
        head = head->next;
    }
    cout  << "\nBackward Traversal using prev pointer\n";
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
}
 
// Utility function to swap two integers
void swap(int *A, int *B)
{
    int temp = *A;
    *A = *B;
    *B = temp;
}
 
// Split a doubly linked list (DLL) into 2 DLLs of
// half sizes
Node *split(Node *head)
{
    Node *fast = head,*slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *temp = slow->next;
    slow->next = NULL;
    return temp;
}
 
// Driver program
int main(void)
{
    Node *head = NULL;
    insert(&head, 5);
    insert(&head, 20);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 30);
    insert(&head, 10);
    head = mergeSort(head);
    cout << "Linked List after sorting\n";
    print(head);
    return 0;
}
```
    Output: 
    Linked List after sorting
    Forward Traversal using next pointer
    3 4 5 10 20 30
    Backward Traversal using prev pointer
    30 20 10 5 4 3

# 3-way Merge Sort
Difficulty Level : Medium
Last Updated : 28 Jun, 2021
Geek-O-Lympics
Prerequisite – Merge Sort

Merge sort involves recursively splitting the array into 2 parts, sorting and finally merging them. A variant of merge sort is called 3-way merge sort where instead of splitting the array into 2 parts we split it into 3 parts.
Merge sort recursively breaks down the arrays to subarrays of size half. Similarly, 3-way Merge sort breaks down the arrays to subarrays of size one third.

Examples:

Input  : 45, -2, -45, 78, 30, -42, 10, 19 , 73, 93 
Output : -45 -42 -2 10 19 30 45 73 78 93 

Input  : 23, -19
Output : -19  23
```cpp
// C++ Program to perform 3 way Merge Sort
#include <bits/stdc++.h>
using namespace std;
  
/* Merge the sorted ranges [low, mid1), [mid1,mid2) 
and [mid2, high) mid1 is first midpoint 
index in overall range to merge mid2 is second 
midpoint index in overall range to merge*/
void merge(int gArray[], int low, int mid1, 
           int mid2, int high, int destArray[]) 
{ 
    int i = low, j = mid1, k = mid2, l = low; 
  
    // choose smaller of the smallest in the three ranges 
    while ((i < mid1) && (j < mid2) && (k < high)) 
    { 
        if(gArray[i] < gArray[j])
        {
            if(gArray[i] < gArray[k])
            {
                destArray[l++] = gArray[i++];
            }
            else
            {
                destArray[l++] = gArray[k++];
            }
        }
        else
        {
            if(gArray[j] < gArray[k])
            {
                destArray[l++] = gArray[j++];
            }
            else
            {
                destArray[l++] = gArray[k++];
            }
        }
    } 
  
    // case where first and second ranges
    // have remaining values 
    while ((i < mid1) && (j < mid2)) 
    { 
        if(gArray[i] < gArray[j])
        {
            destArray[l++] = gArray[i++];
        }
        else
        {
            destArray[l++] = gArray[j++];
        }
    } 
  
    // case where second and third ranges
    // have remaining values 
    while ((j < mid2) && (k < high)) 
    { 
        if(gArray[j] < gArray[k])
        {
            destArray[l++] = gArray[j++];
        }
        else
        {
            destArray[l++] = gArray[k++];
        } 
    } 
  
    // case where first and third ranges have 
    // remaining values 
    while ((i < mid1) && (k < high)) 
    { 
        if(gArray[i] < gArray[k])
        {
            destArray[l++] = gArray[i++];
        }
        else
        {
            destArray[l++] = gArray[k++];
        } 
    } 
  
    // copy remaining values from the first range 
    while (i < mid1) 
        destArray[l++] = gArray[i++]; 
  
    // copy remaining values from the second range 
    while (j < mid2) 
        destArray[l++] = gArray[j++]; 
  
    // copy remaining values from the third range 
    while (k < high) 
        destArray[l++] = gArray[k++]; 
} 
  
  
/* Performing the merge sort algorithm on the 
given array of values in the rangeof indices 
[low, high). low is minimum index, high is 
maximum index (exclusive) */
void mergeSort3WayRec(int gArray[], int low,
                      int high, int destArray[]) 
{ 
    // If array size is 1 then do nothing 
    if (high - low < 2) 
        return; 
  
    // Splitting array into 3 parts 
    int mid1 = low + ((high - low) / 3); 
    int mid2 = low + 2 * ((high - low) / 3) + 1; 
  
    // Sorting 3 arrays recursively 
    mergeSort3WayRec(destArray, low, mid1, gArray); 
    mergeSort3WayRec(destArray, mid1, mid2, gArray); 
    mergeSort3WayRec(destArray, mid2, high, gArray); 
  
    // Merging the sorted arrays 
    merge(destArray, low, mid1, mid2, high, gArray); 
}
  
void mergeSort3Way(int gArray[], int n) 
{ 
    // if array size is zero return null 
    if (n == 0) 
        return; 
  
    // creating duplicate of given array 
    int fArray[n]; 
  
    // copying alements of given array into 
    // duplicate array 
    for (int i = 0; i < n; i++) 
        fArray[i] = gArray[i]; 
  
    // sort function 
    mergeSort3WayRec(fArray, 0, n, gArray); 
  
    // copy back elements of duplicate array 
    // to given array 
    for (int i = 0; i < n; i++) 
        gArray[i] = fArray[i]; 
} 
  
// Driver Code
int main()
{
    int data[] = {45, -2, -45, 78, 30, 
                 -42, 10, 19, 73, 93};
    mergeSort3Way(data,10);
    cout << "After 3 way merge sort: ";
    for (int i = 0; i < 10; i++)
    {
        cout << data[i] << " ";
    }
    return 0;
}
```  
    Output:
    After 3 way merge sort: 
    -45 -42 -2 10 19 30 45 73 78 93 
Here, we first copy the contents of data array to another array called fArray. Then, sort the array by finding midpoints that divide the array into 3 parts and called sort function on each array respectively. The base case of recursion is when size of array is 1 and it returns from the function. Then merging of arrays starts and finally the sorted array will be in fArray which is copied back to gArray.



Time Complexity: In case of 2-way Merge sort we get the equation: T(n) = 2T(n/2) + O(n)
Similarly, in case of 3-way Merge sort we get the equation: T(n) = 3T(n/3) + O(n)