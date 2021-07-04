/*GCDs of given index ranges in an array
Given an array a[0 . . . n-1]. We should be able to efficiently find the GCD from index qs (query start) to qe (query end) where 0 <= qs <= qe <= n-1.

Example :

Input : a[] = {2, 3, 60, 90, 50};
        Index Ranges : {1, 3}, {2, 4}, {0, 2}
Output: GCDs of given ranges are 3, 10, 1

Method 3 (Segment Tree)

Prerequisites : Segment Tree Set 1, Segment Tree Set 2
Segment tree can be used to do preprocessing and query in moderate time. With segment tree, preprocessing time is O(n) and time to for GCD query is O(Logn). The extra space required is O(n) to store the segment tree.

Representation of Segment trees

Leaf Nodes are the elements of the input array.
Each internal node represents GCD of all leaves under it.
Array representation of tree is used to represent Segment Trees i.e., for each node at index i,

Left child is at index 2*i+1
Right child at 2*i+2 and the parent is at floor((i-1)/2).
Construction of Segment Tree from given array

Begin with a segment arr[0 . . . n-1] and keep dividing into two halves. Every time we divide the current segment into two halves (if it has not yet become a segment of length 1), then call the same procedure on both halves, and for each such segment, we store the GCD value in a segment tree node.
All levels of the constructed segment tree will be completely filled except the last level. Also, the tree will be a Full Binary Tree (every node has 0 or two children) because we always divide segments in two halves at every level.
Since the constructed tree is always full binary tree with n leaves, there will be n-1 internal nodes. So total number of nodes will be 2*n – 1.
Height of the segment tree will be &lceillog2n&rceil. Since the tree is represented using array and relation between parent and child indexes must be maintained, size of memory allocated for segment tree will be 2*2⌈log2n⌉ – 1
Query for GCD of given range

/ qs --> query start index, qe --> query end index
int GCD(node, qs, qe)
{
   if range of node is within qs and qe
      return value in node
   else if range of node is completely 
      outside qs and qe
      return INFINITE
   else
      return GCD( GCD(node's left child, qs, qe), 
                  GCD(node's right child, qs, qe) )
}

*/
#include <bits/stdc++.h>
using namespace std;

// store segment tree
int *st;
/*  A recursive function to get gcd of given
    range of array indexes. The following are parameters for
    this function.
  
    st    --> Pointer to segment tree
    si --> Index of current node in the segment tree. Initially
               0 is passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment
                 represented by current node, i.e., st[index]
    qs & qe  --> Starting and ending indexes of query range */
int findGCD(int ss, int se, int qs, int qe, int si)
{
    if (ss > qe || se < qs)
        return 0;
    if (qs <= ss && qe >= se)
        return st[si];
    int mid = ss + (se - ss) / 2; // we could write (se+ss)/2
    return __gcd(findGCD(ss, mid, qs, qe, si * 2 + 1),
                 findGCD(mid + 1, se, qs, qe, si * 2 + 2));
}

int RangeGCD(int ss, int se, int arr[], int n)
{
    if (ss < 0 || se > n - 1 || ss > se)
    {
        cout << "Invalid Argument" << endl;
        return -1;
    }
    return findGCD(0, n - 1, ss, se, 0);
}

int constructST(int arr[], int ss, int se, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return st[si];
    }
    int mid = (se + ss) / 2;
    st[si] = __gcd(constructST(arr, ss, mid, si * 2 + 1),
                   constructST(arr, mid + 1, se, si * 2 + 2));
    return st[si];
}

int *exec(int arr[], int n)
{
    int height = (int)ceil(log2(n));
    int size = 2 * (int)pow(2, height) - 1;
    st = new int[size];
    constructST(arr, 0, n - 1, 0);
    return st;
}

int main()
{
    int a[] ={2,3,6,9,5};
    int n=sizeof(a)/sizeof(int);
    exec(a,n);

    // query
    cout<<"GCD of the given range: "<<
            RangeGCD(1,3,a,n)<<endl;
    return 0;
}