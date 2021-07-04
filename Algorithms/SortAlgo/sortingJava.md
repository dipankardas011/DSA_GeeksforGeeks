# Arrays.sort() in Java with examples
sort() method is a java.util.Arrays class method. 
    Syntax: 
    public static void sort(int[] arr, int from_Index, int to_Index)

    arr - the array to be sorted
    from_Index - the index of the first element, inclusive, to be sorted
    to_Index - the index of the last element, exclusive, to be sorted

This method doesn't return any value.
 
A Java program to sort an array of integers in ascending order.
 

```Java

// A sample Java program to sort an array of integers
// using Arrays.sort(). It by default sorts in
// ascending order
import java.util.Arrays;
 
public class SortExample
{
    public static void main(String[] args)
    {
        // Our arr contains 8 elements
        int[] arr = {13, 7, 6, 45, 21, 9, 101, 102};
 
        Arrays.sort(arr);
 
        System.out.printf("Modified arr[] : %s",
                          Arrays.toString(arr));
    }
}
```
    Output: 

    Modified arr[] : [6, 7, 9, 13, 21, 45, 101, 102]
We can also use sort() to sort a subarray of arr[] 
 
```Java

// A sample Java program to sort a subarray
// using Arrays.sort().
import java.util.Arrays;
 
public class SortExample
{
    public static void main(String[] args)
    {
        // Our arr contains 8 elements
        int[] arr = {13, 7, 6, 45, 21, 9, 2, 100};
 
        // Sort subarray from index 1 to 4, i.e.,
        // only sort subarray {7, 6, 45, 21} and
        // keep other elements as it is.
        Arrays.sort(arr, 1, 5);
 
        System.out.printf("Modified arr[] : %s",
                          Arrays.toString(arr));
    }
}
```
    Output: 

    Modified arr[] : [13, 6, 7, 21, 45, 9, 2, 100]

We can also sort in descending order. 
 

```Java

// A sample Java program to sort a subarray
// in descending order using Arrays.sort().
import java.util.Arrays;
import java.util.Collections;
 
public class SortExample
{
    public static void main(String[] args)
    {
        // Note that we have Integer here instead of
        // int[] as Collections.reverseOrder doesn't
        // work for primitive types.
        Integer[] arr = {13, 7, 6, 45, 21, 9, 2, 100};
 
        // Sorts arr[] in descending order
        Arrays.sort(arr, Collections.reverseOrder());
 
        System.out.printf("Modified arr[] : %s",
                          Arrays.toString(arr));
    }
}
```
    Output: 

    Modified arr[] : [100, 45, 21, 13, 9, 7, 6, 2]
We can also sort strings in alphabetical order. 
 

```Java

// A sample Java program to sort an array of strings
// in ascending and descending orders using Arrays.sort().
import java.util.Arrays;
import java.util.Collections;
 
public class SortExample
{
    public static void main(String[] args)
    {
        String arr[] = {"practice.geeksforgeeks.org",
                        "quiz.geeksforgeeks.org",
                        "code.geeksforgeeks.org"
                       };
 
        // Sorts arr[] in ascending order
        Arrays.sort(arr);
        System.out.printf("Modified arr[] : \n%s\n\n",
                          Arrays.toString(arr));
 
        // Sorts arr[] in descending order
        Arrays.sort(arr, Collections.reverseOrder());
 
        System.out.printf("Modified arr[] : \n%s\n\n",
                          Arrays.toString(arr));
    }
}
```
    Output: 

    Modified arr[] : 


    Modified arr[] : 
    [quiz.geeksforgeeks.org, practice.geeksforgeeks.org, code.geeksforgeeks.org]

We can also sort an array according to user defined criteria. 
We use Comparator interface for this purpose. Below is an example. 
 

```Java

// Java program to demonstrate working of Comparator
// interface
import java.util.*;
import java.lang.*;
import java.io.*;
 
// A class to represent a student.
class Student
{
    int rollno;
    String name, address;
 
    // Constructor
    public Student(int rollno, String name,
                               String address)
    {
        this.rollno = rollno;
        this.name = name;
        this.address = address;
    }
 
    // Used to print student details in main()
    public String toString()
    {
        return this.rollno + " " + this.name +
                           " " + this.address;
    }
}
 
class Sortbyroll implements Comparator<Student>
{
    // Used for sorting in ascending order of
    // roll number
    public int compare(Student a, Student b)
    {
        return a.rollno - b.rollno;
    }
}
 
// Driver class
class Main
{
    public static void main (String[] args)
    {
        Student [] arr = {new Student(111, "bbbb", "london"),
                          new Student(131, "aaaa", "nyc"),
                          new Student(121, "cccc", "jaipur")};
 
        System.out.println("Unsorted");
        for (int i=0; i<arr.length; i++)
            System.out.println(arr[i]);
 
        Arrays.sort(arr, new Sortbyroll());
 
        System.out.println("\nSorted by rollno");
        for (int i=0; i<arr.length; i++)
            System.out.println(arr[i]);
    }
}
```
    Output: 

    Unsorted
    111 bbbb london
    131 aaaa nyc
    121 cccc jaipur

    Sorted by rollno
    111 bbbb london
    121 cccc jaipur
    131 aaaa nyc

Arrays.sort() vs Collections.sort() 
Arrays.sort works for arrays which can be of primitive data type also. Collections.sort() works for objects Collections like ArrayList, LinkedList, etc. 