/*Binary Indexed Tree or Fenwick Tree

Let us consider the following problem to understand Binary Indexed Tree.

We have an array arr[0 . . . n-1]. We would like to
1 Compute the sum of the first i elements.
2 Modify the value of a specified element of the array arr[i] = x where 0 <= i <= n-1.

A simple solution is to run a loop from 0 to i-1 and calculate the sum of the elements. To update a value, simply do arr[i] = x. The first operation takes O(n) time and the second operation takes O(1) time. Another simple solution is to create an extra array and store the sum of the first i-th elements at the i-th index in this new array. The sum of a given range can now be calculated in O(1) time, but the update operation takes O(n) time now. This works well if there are a large number of query operations but a very few number of update operations.

Could we perform both the query and update operations in O(log n) time?
One efficient solution is to use Segment Tree that performs both operations in O(Logn) time.

An alternative solution is Binary Indexed Tree, which also achieves O(Logn) time complexity for both operations. Compared with Segment Tree, Binary Indexed Tree requires less space and is easier to implement..

Representation
Binary Indexed Tree is represented as an array. Let the array be BITree[]. Each node of the Binary Indexed Tree stores the sum of some elements of the input array. The size of the Binary Indexed Tree is equal to the size of the input array, denoted as n. In the code below, we use a size of n+1 for ease of implementation.

Construction
We initialize all the values in BITree[] as 0. Then we call update() for all the indexes, the update() operation is discussed below.

Operations

getSum(x): Returns the sum of the sub-array arr[0,…,x]
// Returns the sum of the sub-array arr[0,…,x] using BITree[0..n], which is constructed from arr[0..n-1]
1) Initialize the output sum as 0, the current index as x+1.
2) Do following while the current index is greater than 0.
…a) Add BITree[index] to sum
…b) Go to the parent of BITree[index]. The parent can be obtained by removing
the last set bit from the current index, i.e., index = index – (index & (-index))
3) Return sum.

The diagram above provides an example of how getSum() is working. Here are some important observations.

BITree[0] is a dummy node.

BITree[y] is the parent of BITree[x], if and only if y can be obtained by removing the last set bit from the binary representation of x, that is y = x – (x & (-x)).


"The child node BITree[x] of the node BITree[y] stores the sum of the elements between y(inclusive) and x(exclusive): arr[y,…,x)."


update(x, val): Updates the Binary Indexed Tree (BIT) by performing arr[index] += val
// Note that the update(x, val) operation will not change arr[]. It only makes changes to BITree[]
1) Initialize the current index as x+1.
2) Do the following while the current index is smaller than or equal to n.
…a) Add the val to BITree[index]
…b) Go to parent of BITree[index]. The parent can be obtained by incrementing the last set bit of the current index, i.e., index = index + (index & (-index))

The update function needs to make sure that all the BITree nodes which contain arr[i] within their ranges being updated. We loop over such nodes in the BITree by repeatedly adding the decimal number corresponding to the last set bit of the current index.



How does Binary Indexed Tree work?
The idea is based on the fact that all positive integers can be represented as the sum of powers of 2. For example 19 can be represented as 16 + 2 + 1. Every node of the BITree stores the sum of n elements where n is a power of 2. For example, in the first diagram above (the diagram for getSum()), the sum of the first 12 elements can be obtained by the sum of the last 4 elements (from 9 to 12) plus the sum of 8 elements (from 1 to 8). The number of set bits in the binary representation of a number n is O(Logn). Therefore, we traverse at-most O(Logn) nodes in both getSum() and update() operations. The time complexity of the construction is O(nLogn) as it calls update() for all n elements.*/
#include <iostream>
using namespace std;

/*
n --> No. of elements present in input array. 
    BITree[0..n] --> Array that represents Binary Indexed Tree.
    arr[0..n-1] --> Input array for which prefix sum is evaluated. */
  
// Returns sum of arr[0..index]. This function assumes
// that the array is preprocessed and partial sums of
// array elements are stored in BITree[].
int getsum(int bitree[], int index)
{
    int sum=0;// initialize result
    index +=1;
    while(index>0){
        sum+=bitree[index];
        index -= index & (-index);
    }
    return sum;
}
// Updates a node in Binary Index Tree (BITree) at given index
// in BITree. The given value 'val' is added to BITree[i] and 
// all of its ancestors in tree.
void updateBIT(int bitree[], int n, int index, int val)
{
    index +=1;
    while(index<=n)
    {
        bitree[index]+=val;
        index += index & (-index);
    }
}

int *constructBIT(int arr[], int n)
{
    int *bitree=new int[n+1];
    for(int i=1;i<=n;i++)
        bitree[i]=0;

    for(int i=0;i<n;i++)
        updateBIT(bitree,n,i,arr[i]);
    // Uncomment below lines to see contents of BITree[]
    for (int i=1; i<=n; i++)
        cout << bitree[i] << " ";
    return bitree;
}

int main(){
    // Can we extend the Binary Indexed Tree to computing the sum of a range in O(Logn) time?
    //rangeSum(l, r) = getSum(r) – getSum(l-1).
    int freq[]={2,1,1,3,2,3,4,5,6,7,8,9};
    int n=sizeof(freq)/sizeof(freq[0]);
    int *bitree=constructBIT(freq,n);
    cout<<"sum of elements in arr[0..5] is "<<getsum(bitree,5);

    //let use test the update operation
    freq[3]+=6;
    updateBIT(bitree,n,3,6);
    cout<<"\nsum of elements in arr[0..5] after update is "<<getsum(bitree,5);
    return 0;
}