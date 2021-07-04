/*Efficiently design Insert, Delete and Median queries on a set
Difficulty Level : Medium
Last Updated : 05 May, 2021
Given an empty set initially and a number of queries on it, each possibly of the following types:  

Insert – Insert a new element ‘x’.
Delete – Delete an existing element ‘x’.
Median – Print the median element of the numbers currently in the set
Example: 

Input :  Insert 1 
         Insert 4
         Insert 7
         Median 
Output : The first three queries
         should insert 1, 4 and 7
         into an empty set. The
         fourth query should return
         4 (median of 1, 4, 7).
For expository purpose, we assume the following, but these assumptions are not the limitations of the method discussed here: 
1. At any instance, all elements are distinct, that is, none of them occurs more than once. 
2. The ‘Median’ query is made only when there are odd number of elements in the set.( We will need to make two queries on our segment tree, in case of even numbers ) 
3. The elements in the set range from 1 to +10^6.*/
#include <bits/stdc++.h>
/*
Method 2(Using Segment Tree) 
We make a segment tree to store sum of intervals, where an interval [a, b] represents the number of elements present in the set, currently, in the range [a, b]. For example, if we consider the above example, query( 3, 7) returns 2, query(4, 4) returns 1, query(5, 5) returns 0.

Insert and delete queries are simple and both can be implemented using function update(int x, int diff) (adds ‘diff’ at index ‘x’)

Algorithm  

// adds ‘diff’ at index ‘x’
update(node, a, b, x, diff)

  // If leaf node
  If a == b and a == x
     segmentTree[node] += diff

  // If non-leaf node and x lies in its range
  If x is in [a, b]

     // Update children recursively    
     update(2*node, a, (a + b)/2, x, diff)
     update(2*node + 1, (a + b)/2 + 1, b, x, diff)

      // Update node
      segmentTree[node] = segmentTree[2 * node] + 
                          segmentTree[2 * node + 1]
The above recursive function runs in O( log( max_elem ) ) ( in this case max_elem is 10^6) and used for both insertion and deletion with the following calls: 

Insert ‘x’ is done using update(1, 0, 10^6, x, 1). Note that root of tree is passed, start index is passed as 0 and end index as 10^6 so that all ranges that have x are updated.
Delete ‘x’ is done using update(1, 0, 10^6, x, -1). Note that root of tree is passed, start index is passed as 0 and end index as 10^6 so that all ranges that have x are updated.
Now, the function to find the index with kth ‘1’, where ‘k’ in this case will always be (n + 1) / 2, this is going to work a lot like binary search, you can think of it as a recursive binary search function on a segment tree.

Let’s take an example to understand, our set currently has elements { 1, 4, 7, 8, 9 }, and hence is represented by the following segment tree.

If we are at a non-leaf node, we are sure that it has both children, we see if the left child has more or equal number of one’s as ‘k’, if yes, we are sure our index lies in the left subtree, otherwise, if left subtree has less number of 1’s than k, then we are sure that our index lies in the right subtree. We do this recursively to reach our index and from there, we return it.

Algorithm  

1.findKth(node, a, b, k)
2.  If a != b 
3.     If segmentTree[ 2 * node ] >= k
4.       return findKth(2*node, a, (a + b)/2, k)
5.     else
6.       return findKth(2*node + 1, (a + b)/2 + 1, 
                       b, k - segmentTree[ 2 * node ])
7.     else
8.       return a
The above recursive function runs in O( log(max_elem) ).
*/
// A C++ program to implement insert, delete and
// median queries using segment tree

#define maxn 3000005
#define max_elem 1000000
using namespace std;

// A global array to store segment tree.
// Note: Since it is global, all elements are 0.
int segmentTree[maxn];

// Update 'node' and its children in segment tree.
// Here 'node' is index in segmentTree[], 'a' and
// 'b' are starting and ending indexes of range stored
// in current node.
// 'diff' is the value to be added to value 'x'.
void update(int node, int a, int b, int x, int diff)
{
	// If current node is a leaf node
	if (a == b && a == x )
	{
		// add 'diff' and return
		segmentTree[node] += diff;
		return ;
	}

	// If current node is non-leaf and 'x' is in its
	// range
	if (x >= a && x <= b)
	{
		// update both sub-trees, left and right
		update(node*2, a, (a + b)/2, x, diff);
		update(node*2 + 1, (a + b)/2 + 1, b, x, diff);

		// Finally update current node
		segmentTree[node] = segmentTree[node*2] +
							segmentTree[node*2 + 1];
	}
}

// Returns k'th node in segment tree
int findKth(int node, int a, int b, int k)
{
	// non-leaf node, will definitely have both
	// children; left and right
	if (a != b)
	{
		// If kth element lies in the left subtree
		if (segmentTree[node*2] >= k)
			return findKth(node*2, a, (a + b)/2, k);

		// If kth one lies in the right subtree
		return findKth(node*2 + 1, (a + b)/2 + 1,
					b, k - segmentTree[node*2]);
	}

	// if at a leaf node, return the index it stores
	// information about
	return (segmentTree[node])? a : -1;
}

// insert x in the set
void insert(int x)
{
	update(1, 0, max_elem, x, 1);
}

// delete x from the set
void delet(int x)
{
	update(1, 0, max_elem, x, -1);
}

// returns median element of the set with odd
// cardinality only
int median()
{
	int k = (segmentTree[1] + 1) / 2;
	return findKth(1, 0, max_elem, k);
}

// Driver code
int main()
{
	insert(1);
	insert(4);
	insert(7);
	cout << "Median for the set {1,4,7} = "
		<< median() << endl;
	insert(8);
	insert(9);
	cout << "Median for the set {1,4,7,8,9} = "
		<< median() << endl;
	delet(1);
	delet(8);
	cout << "Median for the set {4,7,9} = "
		<< median() << endl;
	return 0;
}