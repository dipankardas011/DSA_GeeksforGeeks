# Interpolation search vs Binary search

Interpolation search works better than Binary Search for a Sorted and Uniformly Distributed array. 

Binary Search goes to the middle element to check irrespective of search-key. On the other hand, Interpolation Search may go to different locations according to search-key. If the value of the search-key is close to the last element, Interpolation Search is likely to start search toward the end side.

On average the interpolation search makes about log(log(n)) comparisons (if the elements are uniformly distributed), where n is the number of elements to be searched. In the worst case (for instance where the numerical values of the keys increase exponentially) it can make up to O(n) comparisons. 

# Why is Binary Search preferred over Ternary Search?
Difficulty Level : Medium
Last Updated : 01 Oct, 2019
The following is a simple recursive Binary Search function in C++ taken from here.
```cpp
// A recursive binary search function. It returns location of x in
// given array arr[l..r] is present, otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
   
        // If the element is present at the middle itself
        if (arr[mid] == x)  return mid;
   
        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);
   
        // Else the element can only be present in right subarray
        return binarySearch(arr, mid+1, r, x);
   }
   
   // We reach here when element is not present in array
   return -1;
} 
```
The following is a simple recursive Ternary Search function :

```Cpp
// A recursive ternary search function. It returns location of x in
// given array arr[l..r] is present, otherwise -1
int ternarySearch(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid1 = l + (r - l)/3;
        int mid2 = mid1 + (r - l)/3;
  
        // If x is present at the mid1
        if (arr[mid1] == x)  return mid1;
  
        // If x is present at the mid2
        if (arr[mid2] == x)  return mid2;
  
        // If x is present in left one-third
        if (arr[mid1] > x) return ternarySearch(arr, l, mid1-1, x);
  
        // If x is present in right one-third
        if (arr[mid2] < x) return ternarySearch(arr, mid2+1, r, x);
  
        // If x is present in middle one-third
        return ternarySearch(arr, mid1+1, mid2-1, x);
   }
   // We reach here when element is not present in array
   return -1;
}
```

```Java
import java.io.*;
  
class GFG
{
public static void main (String[] args) 
{
      
// A recursive ternary search function. 
// It returns location of x in given array
// arr[l..r] is present, otherwise -1
static int ternarySearch(int arr[], int l, 
                         int r, int x)
{
   if (r >= l)
   {
        int mid1 = l + (r - l) / 3;
        int mid2 = mid1 + (r - l) / 3;
    
        // If x is present at the mid1
        if (arr[mid1] == x)  return mid1;
    
        // If x is present at the mid2
        if (arr[mid2] == x)  return mid2;
    
        // If x is present in left one-third
        if (arr[mid1] > x) 
            return ternarySearch(arr, l, mid1 - 1, x);
    
        // If x is present in right one-third
        if (arr[mid2] < x) 
            return ternarySearch(arr, mid2 + 1, r, x);
    
        // If x is present in middle one-third
        return ternarySearch(arr, mid1 + 1, 
                                  mid2 - 1, x);
    }
     
    // We reach here when element is
    // not present in array
    return -1;
    }
}
```
```Python 3
# A recursive ternary search function. It returns location of x in
# given array arr[l..r] is present, otherwise -1
def ternarySearch(arr, l, r, x):
    if (r >= l):
        mid1 = l + (r - l)//3
        mid2 = mid1 + (r - l)//3
   
        # If x is present at the mid1
        if arr[mid1] == x:
            return mid1
   
        # If x is present at the mid2
        if arr[mid2] == x:
            return mid2
   
        # If x is present in left one-third
        if arr[mid1] > x:
            return ternarySearch(arr, l, mid1-1, x)
   
        # If x is present in right one-third
        if arr[mid2] < x:
            return ternarySearch(arr, mid2+1, r, x)
   
        # If x is present in middle one-third
        return ternarySearch(arr, mid1+1, mid2-1, x)
     
    # We reach here when element is not present in array
    return -1
     
```
Which of the above two does less comparisons in worst case?
From the first look, it seems the ternary search does less number of comparisons as it makes Log3n recursive calls, but binary search makes Log2n recursive calls. Let us take a closer look.
The following is recursive formula for counting comparisons in worst case of Binary Search.

    T(n) = T(n/2) + 2,  T(1) = 1
The following is recursive formula for counting comparisons in worst case of Ternary Search.


    T(n) = T(n/3) + 4, T(1) = 1
In binary search, there are 2Log2n + 1 comparisons in worst case. In ternary search, there are 4Log3n + 1 comparisons in worst case.

    Time Complexity for Binary search = 2clog2n + O(1)
    Time Complexity for Ternary search = 4clog3n + O(1)
Therefore, the comparison of Ternary and Binary Searches boils down the comparison of expressions 2Log3n and Log2n . The value of 2Log3n can be written as (2 / Log23) * Log2n . Since the value of (2 / Log23) is more than one, Ternary Search does more comparisons than Binary Search in worst case.

# Binary Search functions in C++ STL (binary_search, lower_bound and upper_bound)
Difficulty Level : Easy
Last Updated : 31 May, 2021
Binary search is an important component in competitive programming or any algorithmic competition, having knowledge of shorthand functions reduces the time to code them. This searching only works when container is sorted. Related functions are discussed below.
1.binary_search(start_ptr, end_ptr, num) : This function returns boolean true if the element is present in the container, else returns false.
 

```CPP

// C++ code to demonstrate the working of binary_search()
 
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    // initializing vector of integers
    vector<int> arr = {10, 15, 20, 25, 30, 35};
     
    // using binary_search to check if 15 exists
    if (binary_search(arr.begin(), arr.end(), 15))
       cout << "15 exists in vector";
    else
       cout << "15 does not exist";
      
    cout << endl;
     
    // using binary_search to check if 23 exists
    if (binary_search(arr.begin(), arr.end(), 23))
         cout << "23 exists in vector";
    else
         cout << "23 does not exist";
      
    cout << endl;   
}
```
    Output: 
    
    15 exists in vector
    23 does not exist
2. lower_bound(start_ptr, end_ptr, num) : Returns pointer to “position of num” if container contains 1 occurrence of num. Returns pointer to “first position of num” if container contains multiple occurrence of num. Returns pointer to “position of next higher number than num” if container does not contain occurrence of num. Subtracting the pointer to 1st position i.e “vect.begin()” returns the actual index.

```CPP

// C++ code to demonstrate the working of lower_bound()
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    // initializing vector of integers
    // for single occurrence
    vector<int> arr1 = {10, 15, 20, 25, 30, 35};
     
    // initializing vector of integers
    // for multiple occurrences
    vector<int> arr2 = {10, 15, 20, 20, 25, 30, 35};
     
    // initializing vector of integers
    // for no occurrence
    vector<int> arr3 = {10, 15, 25, 30, 35};   
     
    // using lower_bound() to check if 20 exists
    // single occurrence
    // prints 2
    cout << "The position of 20 using lower_bound "
            " (in single occurrence case) : ";
    cout << lower_bound(arr1.begin(), arr1.end(), 20)
            - arr1.begin();
      
    cout << endl;
     
    // using lower_bound() to check if 20 exists
    // multiple occurrence
    // prints 2
    cout << "The position of 20 using lower_bound "
             "(in multiple occurrence case) : ";
    cout << lower_bound(arr2.begin(), arr2.end(), 20)
            - arr2.begin();
      
    cout << endl;
      
    // using lower_bound() to check if 20 exists
    // no occurrence
    // prints 2 ( index of next higher)
    cout << "The position of 20 using lower_bound "
             "(in no occurrence case) : ";
    cout << lower_bound(arr3.begin(), arr3.end(), 20)
            - arr3.begin();
      
    cout << endl;   
}
```
    Output: 

    The position of 20 using lower_bound (in single occurrence case) : 2
    The position of 20 using lower_bound (in multiple occurrence case) : 2
    The position of 20 using lower_bound (in no occurrence case) : 2
3. upper_bound(start_ptr, end_ptr, num) : Returns pointer to “position of next higher number than num” if container contains 1 occurrence of num. Returns pointer to “first position of next higher number than last occurrence of num” if container contains multiple occurrence of num. Returns pointer to “position of next higher number than num” if container does not contain occurrence of num. Subtracting the pointer to 1st position i.e “vect.begin()” returns the actual index.



Binary search is the most efficient search algorithm.
 

```CPP

// C++ code to demonstrate the working of upper_bound()
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    // initializing vector of integers
    // for single occurrence
    vector<int> arr1 = {10, 15, 20, 25, 30, 35};
     
    // initializing vector of integers
    // for multiple occurrences
    vector<int> arr2 = {10, 15, 20, 20, 25, 30, 35};
     
    // initializing vector of integers
    // for no occurrence
    vector<int> arr3 = {10, 15, 25, 30, 35};
     
     
    // using upper_bound() to check if 20 exists
    // single occurrence
    // prints 3
    cout << "The position of 20 using upper_bound"
           " (in single occurrence case) : ";
    cout << upper_bound(arr1.begin(), arr1.end(), 20)
            - arr1.begin();
      
    cout << endl;
     
    // using upper_bound() to check if 20 exists
    // multiple occurrence
    // prints 4
    cout << "The position of 20 using upper_bound "
             "(in multiple occurrence case) : ";
    cout << upper_bound(arr2.begin(), arr2.end(), 20)
            - arr2.begin();
      
    cout << endl;
      
    // using upper_bound() to check if 20 exists
    // no occurrence
    // prints 2 ( index of next higher)
    cout << "The position of 20 using upper_bound"
            " (in no occurrence case) : ";
    cout << upper_bound(arr3.begin(), arr3.end(), 20)
           - arr3.begin();
      
    cout << endl;   
}
```
    Output: 
    

    The position of 20 using upper_bound (in single occurrence case) : 3
    The position of 20 using upper_bound (in multiple occurrence case) : 4
    The position of 20 using upper_bound (in no occurrence case) : 2
    Time Complexity :O(logN) -where N is number of elements in array.

# Arrays.binarySearch() in Java with examples | Set 1

Arrays.binarySearch() is the simplest and most efficient method to find an element in a sorted array in Java

Declaration:

public static int binarySearch(data_type arr, data_type key )
where data_type can be any of the primitive data types: byte, char, double, int, float, short, long and Object as well.

Description:
Searches the specified array of the given data type for the specified value using the binary search algorithm. The array must be sorted (as by the Arrays.sort() method) prior to making this call. If it is not sorted, the results are undefined. If the array contains multiple elements with the specified value, there is no guarantee which one will be found.

Parameters:
arr – the array to be searched
key – the value to be searched for



Returns:
index of the search key, if it is contained in the array; otherwise, (-(insertion point) – 1). The insertion point is defined as the point at which the key would be inserted into the array: the index of the first element greater than the key, or a.length if all elements in the array are less than the specified key. Note that this guarantees that the return value will be >= 0 if and only if the key is found.

    Examples:

    Searching for 35 in byteArr[] = {10,20,15,22,35}
    will give result as 4 as it is the index of 35

    Searching for g in charArr[] = {'g','p','q','c','i'}
    will give result as 0 as it is the index of 'g'

    Searching for 22 in intArr[] = {10,20,15,22,35};
    will give result as 3 as it is the index of 22

    Searching for 1.5 in doubleArr[] = {10.2,15.1,2.2,3.5}
    will give result as -1 as it is the insertion point of 1.5

    Searching for 35.0 in floatArr[] = {10.2f,15.1f,2.2f,3.5f}
    will give result as -5 as it is the insertion point of 35.0

    Searching for 5 in shortArr[] = {10,20,15,22,35}
    will give result as -1 as it is the insertion point of 5
```java

// Java program to demonstrate working of Arrays.
// binarySearch() in a sorted array.
import java.util.Arrays;
  
public class GFG
{
    public static void main(String[] args)
    {
        byte byteArr[] = {10,20,15,22,35};
        char charArr[] = {'g','p','q','c','i'};
        int intArr[] = {10,20,15,22,35};
        double doubleArr[] = {10.2,15.1,2.2,3.5};
        float floatArr[] = {10.2f,15.1f,2.2f,3.5f};
        short shortArr[] = {10,20,15,22,35};
  
        Arrays.sort(byteArr);
        Arrays.sort(charArr);
        Arrays.sort(intArr);
        Arrays.sort(doubleArr);
        Arrays.sort(floatArr);
        Arrays.sort(shortArr);
  
        byte byteKey = 35;
        char charKey = 'g';
        int intKey = 22;
        double doubleKey = 1.5;
        float floatKey = 35;
        short shortKey = 5;
  
        System.out.println(byteKey + " found at index = "
                           +Arrays.binarySearch(byteArr,byteKey));
        System.out.println(charKey + " found at index = "
                           +Arrays.binarySearch(charArr,charKey));
        System.out.println(intKey + " found at index = "
                           +Arrays.binarySearch(intArr,intKey));
        System.out.println(doubleKey + " found at index = "
                           +Arrays.binarySearch(doubleArr,doubleKey));
        System.out.println(floatKey + " found at index = "
                           +Arrays.binarySearch(floatArr,floatKey));
        System.out.println(shortKey + " found at index = "
                           +Arrays.binarySearch(shortArr,shortKey));
    }
}
```
    Output:

    35 found at index = 4
    g found at index = 1
    22 found at index = 3
    1.5 found at index = -1
    35.0 found at index = -5
    5 found at index = -1
Important Points:

If input list is not sorted, the results are undefined.
If there are duplicates, there is no guarantee which one will be found.
Arrays.binarysearch() vs Collections.binarysearch()
Arrays.binarysearch() works for arrays which can be of primitive data type also. Collections.binarysearch() works for objects Collections like ArrayList and LinkedList.

There are variants of this method in which we can also specify the range of array to search in. We will be discussing that as well as searching in an Object array in further posts.

# Arrays.binarySearch() in Java with examples | Set 2 (Search in subarray)

Arrays.binarySearch()| Set 1 Covers how to find an element in a sorted array in Java. This set will cover “How to Search a key in an array within a given range including only start index”.

    Syntax :  

    public static int binarySearch(data_type[] arr, int fromIndex, int toIndex, data_type key)

    Parameters :

    arr – the array to be searched



    fromIndex – the index of the first element (inclusive) to be searched

    toIndex – the index of the last element (exclusive) to be searched

    key  – the value to be searched for 

It is a static inbuilt method defined in Arrays (java.util.Arrays) class in java and returns the index of the specified key is found within the specified range.
Here, data_type can be any of the primitive data_type: byte, char, double, int, float, short, long and Object as well.
The above function Searches a range of the specified array of the given data type for the specified key using a binary search algorithm.
The range within which the specified key to be searched must be sorted (as by the Arrays.sort() method) prior to making this call. Otherwise, the result would be undefined. If the specified array contains multiple values same as the specified key, there is no guarantee which one will be found.
Returns : 
Index of the specified key is found within the specified range in the specified array, Otherwise (-(insertion point) – 1). 

The insertion point is defined as a point at which the specified key would be inserted: the index of the first element in the range greater than the key, or toIndex if all elements in the range are less than the specified key. 
Note: This guarantees that the return value will be >= 0 if and only if the key is found.

    Examples:  

    byteArr[] = {10,20,15,22,35}

    key = 22 to be searched between the range 2 to 4 in specified array.



    Output: 3

    charArr[] = {‘g’,’p’,’q’,’c’,’i’}

    key = p to be searched between the range 1 to 4 in specified array.

    Output: 3

    intArr[] = {1,2,3,4,5,6}

    key = 3 to be searched between the range 1 to 4 in specified array.

    Output: 2

    doubleArr[] = {10.2,1.51,2.2,3.5}

    key = 1.5 to be searched between the range 1 to 4 in specified array.

    Output: -2 as it is the insertion point of 1.5

    floatArr[] = {10.2f,15.1f,2.2f,3.5f}

    key = 35.0 to be searched between the range 1 to 4 in specified array.

    Output: -5

    shortArr[] = {10,20,15,22,35}

    key = 5 to be searched between the range 0 to 4 in specified array.

    Output: -1

Implementation :
 

```java
// Java program to demonstrate working of  binarySearch()
// method for specified range in a sorted array.
import java.util.Arrays;
 
public class GFG {
    public static void main(String[] args)
    {
        byte byteArr[] = { 10, 20, 15, 22, 35 };
        char charArr[] = { 'g', 'p', 'q', 'c', 'i' };
        int intArr[] = { 1, 2, 3, 4, 5, 6 };
        double doubleArr[] = { 10.2, 15.1, 2.2, 3.5 };
        float floatArr[] = { 10.2f, 15.1f, 2.2f, 3.5f };
        short shortArr[] = { 10, 20, 15, 22, 35 };
 
        Arrays.sort(byteArr);
        Arrays.sort(charArr);
        Arrays.sort(intArr);
        Arrays.sort(doubleArr);
        Arrays.sort(floatArr);
        Arrays.sort(shortArr);
 
        byte byteKey = 22;
        char charKey = 'p';
        int intKey = 3;
        double doubleKey = 1.5;
        float floatKey = 35;
        short shortKey = 5;
 
        System.out.println(
            byteKey + " found at index = "
            + Arrays.binarySearch(byteArr, 2, 4, byteKey));
        System.out.println(
            charKey + " found at index = "
            + Arrays.binarySearch(charArr, 1, 4, charKey));
        System.out.println(
            intKey + " found at index = "
            + Arrays.binarySearch(intArr, 1, 4, intKey));
        System.out.println(doubleKey + " found at index = "
                           + Arrays.binarySearch(
                               doubleArr, 1, 4, doubleKey));
        System.out.println(floatKey + " found at index = "
                           + Arrays.binarySearch(
                               floatArr, 1, 4, floatKey));
        System.out.println(shortKey + " found at index = "
                           + Arrays.binarySearch(
                               shortArr, 0, 4, shortKey));
    }
}
```
    Output
    22 found at index = 3
    p found at index = 3
    3 found at index = 2
    1.5 found at index = -2
    35.0 found at index = -5
    5 found at index = -1
Exceptions :  

IllegalArgumentException : throws when starting index(fromIndex) is greater than the end index(toIndex) of specified range.(means: fromIndex > toIndex)
ArrayIndexOutOfBoundsException : throws if one or both index are not valid means fromIndex<0 or toIndex > arr.length.

# Collections.binarySearch() in Java with Examples
Difficulty Level : Easy
Last Updated : 28 Jun, 2021
java.util.Collections.binarySearch() method is a java.util.Collections class method that returns position of an object in a sorted list.
 

    // Returns index of key in sorted list sorted in
    // ascending order
    public static int binarySearch(List slist, T key)

    // Returns index of key in sorted list sorted in
    // order defined by Comparator c.
    public static int binarySearch(List slist, T key, Comparator c)

If key is not present, the it returns "(-(insertion point) - 1)". 
The insertion point is defined as the point at which the key 
would be inserted into the list.
The method throws ClassCastException if elements of list are not comparable using the specified comparator, or the search key is not comparable with the elements.
Searching an int key in a list sorted in ascending order: 
 
```java
// Java program to demonstrate working of Collections.
// binarySearch()
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class GFG {
    public static void main(String[] args)
    {
        List<Integer> al = new ArrayList<Integer>();
        al.add(1);
        al.add(2);
        al.add(3);
        al.add(10);
        al.add(20);

        // 10 is present at index 3.
        int index = Collections.binarySearch(al, 10);
        System.out.println(index);

        // 13 is not present. 13 would have been inserted
        // at position 4. So the function returns (-4-1)
        // which is -5.
        index = Collections.binarySearch(al, 13);
        System.out.println(index);
    }
}
```
    Output : 

    3
    -5
Searching an int key in a list sorted in descending order. 
 
```java
// Java program to demonstrate working of Collections.
// binarySearch() in an array sorted in descending order.
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class GFG {
    public static void main(String[] args)
    {
        List<Integer> al = new ArrayList<Integer>();
        al.add(100);
        al.add(50);
        al.add(30);
        al.add(10);
        al.add(2);

        // The last parameter specifies the comparator
        // method used for sorting.
        int index = Collections.binarySearch(
            al, 50, Collections.reverseOrder());

        System.out.println("Found at index " + index);
    }
}
```
    Output : 
    Found at index 1
Searching in a list of user-defined class objects: 
 
```java
// Java program to demonstrate working of Collections.
// binarySearch() in a list of user defined objects
import java.util.*;

class Binarysearch {
    public static void main(String[] args)
    {
        // Create a list
        List<Domain> l = new ArrayList<Domain>();
        l.add(new Domain(10, "quiz.geeksforgeeks.org"));
        l.add(new Domain(20, "practice.geeksforgeeks.org"));
        l.add(new Domain(30, "code.geeksforgeeks.org"));
        l.add(new Domain(40, "www.geeksforgeeks.org"));

        Comparator<Domain> c = new Comparator<Domain>() {
            public int compare(Domain u1, Domain u2)
            {
                return u1.getId().compareTo(u2.getId());
            }
        };

        // Searching a domain with key value 10. To search
        // we create an object of domain with key 10.
        int index = Collections.binarySearch(l, new Domain(10, null), c);
        System.out.println("Found at index  " + index);

        // Searching an item with key 5
        index = Collections.binarySearch(l, new Domain(5, null), c);
        System.out.println(index);
    }
}

// A user-defined class to store domains with id and url
class Domain {
    private int id;
    private String url;

    // Constructor
    public Domain(int id, String url)
    {
        this.id = id;
        this.url = url;
    }

    public Integer getId() { return Integer.valueOf(id); }
}
```
    Output : 

    0
    -1
Arrays.binarysearch() vs Collections.binarySearch() 
Arrays.binarysearch() works for arrays which can be of primitive data type also. Collections.binarysearch() works for objects Collections like ArrayList and LinkedList. 
Important Points: 
 

If input list is not sorted, the results are undefined.
If there are duplicates, there is no guarantee which one will be found.
This method runs in log(n) time for a “random access” list like ArrayList. If the specified list does not implement the RandomAccess interface and is large, this method will do an iterator-based binary search that performs O(n) link traversals and O(log n) element comparisons.

