/*Shuffle a given array using Fisher–Yates shuffle Algorithm
Difficulty Level : Medium
Last Updated : 21 Apr, 2021
Given an array, write a program to generate a random permutation of array elements. This question is also asked as “shuffle a deck of cards” or “randomize a given array”. Here shuffle means that every permutation of array element should equally likely.
 

![shuffle-array](https://media.geeksforgeeks.org/wp-content/cdn-uploads/shuffle-array-300x92.jpg)

Let the given array be arr[]. A simple solution is to create an auxiliary array temp[] which is initially a copy of arr[]. Randomly select an element from temp[], copy the randomly selected element to arr[0] and remove the selected element from temp[]. Repeat the same process n times and keep copying elements to arr[1], arr[2], … . The time complexity of this solution will be O(n^2).
Fisher–Yates shuffle Algorithm works in O(n) time complexity. The assumption here is, we are given a function rand() that generates random number in O(1) time. 
The idea is to start from the last element, swap it with a randomly selected element from the whole array (including last). Now consider the array from 0 to n-2 (size reduced by 1), and repeat the process till we hit the first element. 
Following is the detailed algorithm 
 
```
To shuffle an array a of n elements (indices 0..n-1):
  for i from n - 1 downto 1 do
       j = random integer with 0 <= j <= i
       exchange a[j] and a[i]
```
*/
#include <iostream>
#include <time.h>

void printArray (int arr[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

void randomize(int arr[], int n)
{
    srand(time(NULL));
    for(int i=n-1; i>0; i--)
    {
        int j=rand()%(i+1);
        std::swap(arr[i], arr[j]);
    }
}

int main(int argc, char const *argv[])
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int n=sizeof(arr)/sizeof(int);
    randomize(arr,n);
    printArray(arr,n);
    remove(argv[0]);
    return 0;
}
/*Time Complexity: O(n), assuming that the function rand() takes O(1) time.
How does this work? 
The probability that ith element (including the last one) goes to last position is 1/n, because we randomly pick an element in first iteration.
The probability that ith element goes to second last position can be proved to be 1/n by dividing it in two cases. 
Case 1: i = n-1 (index of last element): 
The probability of last element going to second last position is = (probability that last element doesn’t stay at its original position) x (probability that the index picked in previous step is picked again so that the last element is swapped) 
So the probability = ((n-1)/n) x (1/(n-1)) = 1/n 
Case 2: 0 < i < n-1 (index of non-last): 
The probability of ith element going to second position = (probability that ith element is not picked in previous iteration) x (probability that ith element is picked in this iteration) 
So the probability = ((n-1)/n) x (1/(n-1)) = 1/n*/