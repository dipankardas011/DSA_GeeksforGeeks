/*Sorting using trivial hash function
Sorting using trivial hash function.

Examples:

Input :  9 4 3 5 8 
Output : 3 4 5 8 9
We have read about various sorting algorithms such as heap sort, bubble sort, merge sort and others.
Here we will see how can we sort N elements using a hash array. But this algorithm has a limitation. We can sort only those N elements, where the value of elements is not large (typically not above 10^6).

Explanation of sorting using hash:

Step 1: Create a hash array of size(max_element), since that is the maximum we will need
Step 2: Traverse through all the elements and keep a count of number of occurrence of a particular element.
Step 3: After keeping a count of occurrence of all elements in the hash table, simply iterate from 0 to max_element in the hash array
Step 4: While iterating in the hash array, if we find the value stored at any hash position is more than 0, which indicated that the element is present at least once in the original list of elements.
Step 5: Hash[i] has the count of the number of times an element is present in the list, so when its >0, we print those number of times the element.



If you want to store the elements, use another array to store them in a sorted way.
If we want to sort it in descending order, we simply traverse from max to 0 and repeat the same procedure.

Below is the implementation of the above approach:*/
#include <bits/stdc++.h>
using namespace std;
// How to handle negative numbers?
// In case the array has negative numbers and positive numbers, we keep two hash arrays to keep a track of positive and negative elements.

// Explanation of sorting using hashing if the array has negative and positive numbers:
// Step 1: Create two hash arrays, one for positive and the other for negative
// Step 2: the positive hash array will have a size of max and the negative array will have a size of min
// Step 3: traverse from min to 0 in the negative hash array, and print the elements in the same way we did for positives.
// Step 4: Traverse from 0 to max for positive elements and print them in the same manner as explained above.

// Below is the implementation of the above approach:
void sortbyHash(int a[], int n)
{
    int max=*std::max_element(a,a+n);
    int min=abs(*std::min_element(a,a+n));
    
    int hashpos[max+1]={0};
    int hashneg[min+1]={0};

    for(int i=0;i<n;i++)
    {
        if(a[i] >= 0)
            hashpos[a[i]]+=1;
        else
            hashneg[abs(a[i])]+=1;
    }


    for(int i=min;i>0;i--)
    {
        if(hashneg[i])
        {
            for(int j=0;j<hashneg[i];j++)
                cout<<(-1)*i<<" ";
        }
    }

    for(int i=0;i<=max;i++)
    {
        if(hashpos[i])
        {
            for(int j=0;j<hashpos[i];j++)
                cout<<i<<" ";
        }
    }
}
int main()
{
    int a[]={ -1, -2, -3, -4, -5, -6, 8, 7,
                        5, 4, 3, 2, 1, 0};
    int n=sizeof(a)/sizeof(a[0]);
    sortbyHash(a,n);
    return 0;
}