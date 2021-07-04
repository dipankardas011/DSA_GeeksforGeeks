/*Find pair of rows in a binary matrix that has maximum bit difference
Difficulty Level : Hard
Last Updated : 02 Feb, 2017
Given a Binary Matrix. The task is to find the pair of row in the Binary matrix that has maximum bit difference

Examples:

Input: mat[][] = {{1, 1, 1, 1},
                 {1, 1, 0, 1},
                 {0, 0, 0, 0}};
Output : (1, 3)
Bit difference between row numbers 1 and 3
is maximum with value 4. Bit difference 
between 1 and 2 is 1 and between 2 and 3
is 3.

Input: mat[][] = {{1 ,1 ,1 ,1 }
                  {1 ,0, 1 ,1 }
                  {0 ,1 ,0 ,0 }
                  {0, 0 ,0 ,0 }} 
Output : (2, 3)
Bit difference between rows 2 and 3 is 
maximum which is 4.

Input: mat[][] = {{1 ,0 ,1 ,1 }
                  {1 ,1 ,1 ,1 }
                  {0 ,1 ,0 ,1 }
                  {1, 0 ,0 ,0 }} 
Output : (1, 3) or (2  ,4 ) or (3 ,4 ) 
They all are having  maximum bit difference
that is 3

An Efficient solution using Trie Data Structure. Below is algorithm.
1). Create an empty Trie. Every node of Trie contains
    two children for 0 and 1 bits.
2). Insert First Row of Binary matrix into Trie 

3).Traverse rest of the rows of given Binary Matrix 
   a). For Each Row First we search maximum bit difference
       with rows that we insert before that in Trie and 
       count bit difference 
   b). For every search we update maximum bit_diff count
       if needed else not store pair of index that have
       maximum bit difference 
   c). At Last Print Pair*/
// C++ program to Find Pair of row in Binary matrix
// that has maximum Bit difference
#include<bits/stdc++.h>
using namespace std;

// Maximum size of matrix
const int MAX = 100;

struct TrieNode
{
	int leaf; //store index of visited row
	struct TrieNode *Child[2];
};

// Utility function to create a new Trie node
TrieNode * getNode()
{
	TrieNode * newNode = new TrieNode;
	newNode->leaf = 0;
	newNode->Child[0] = newNode->Child[1] = NULL;
	return newNode;
}

// utility function insert new row in trie
void insert(TrieNode *root, int Mat[][MAX], int n, int row_index)
{
	TrieNode * temp = root;

	for (int i=0; i<n; i++)
	{
		// Add a new Node into trie
		if(temp->Child[ Mat[row_index][i] ] == NULL)
			temp->Child[ Mat[row_index][i] ] = getNode();

		// move current node to point next node in trie
		temp = temp->Child[ Mat[row_index][i] ];
	}

	// store index of currently inserted row
	temp->leaf = row_index +1 ;
}

// utility function calculate maximum bit difference of
// current row with previous visited row of binary matrix
pair<int, int> maxBitDiffCount(TrieNode * root, int Mat[][MAX], int n, int row_index)
{
	TrieNode * temp = root;
	int count = 0;

	// Find previous visited row of binary matrix
	// that has starting bit same as current row
	for (int i= 0 ; i < n ; i++)
	{
		// First look for same bit in trie
		if (temp->Child[ Mat[row_index][i] ] != NULL)
			temp = temp->Child[ Mat[row_index][i] ];

		// Else looking for opposite bit
		else if (temp->Child[1 - Mat[row_index][i]] != NULL)
		{
			temp = temp->Child[1- Mat[row_index][i]];
			count++;
		}
	}

	int leaf_index = temp->leaf;
	int count1 = 0 ;
	temp = root;

	// Find previous visited row of binary matrix
	// that has starting bit opposite to current row
	for (int i= 0 ; i < n ; i++)
	{
		// First looking for opposite bit
		if (temp->Child[ 1 - Mat[row_index][i] ] !=NULL)
		{
			temp = temp->Child[ 1- Mat[row_index][i] ];
			count1++;
		}

		// Else look for same bit in trie
		else if (temp->Child[ Mat[row_index][i] ] != NULL)
			temp = temp->Child[ Mat[row_index][i] ];
	}

	pair <int ,int> P = count1 > count ?
						make_pair(count1, temp->leaf):
						make_pair(count, leaf_index);

	// return pair that contain both bit difference
	// count and index of row with we get bit
	// difference
	return P;
}

// Returns maximum bit difference pair of row
void maxDiff( int mat[][MAX], int n, int m)
{
	TrieNode * root = getNode();

	// Insert first matrix row in trie
	insert(root, mat, m, 0);

	int max_bit_diff = INT_MIN;
	pair <int ,int> P, temp ;

	// Traverse all rest row of binary matrix
	for (int i = 1 ; i < n; i++)
	{
		// compute bit difference with previous visited
		// rows of matrix
		temp = maxBitDiffCount(root, mat, m ,i);

		// update maximum bit difference
		if (max_bit_diff < temp.first )
		{
			max_bit_diff = temp.first;
			P = make_pair( temp.second, i+1);
		}

		// insert current row value into Trie
		insert(root, mat, m, i );
	}

	// print maximum bit difference pair in row
	cout << "(" << P.first <<", "<< P.second << ")";
}

// Driver program
int main()
{
	int mat[][MAX] = {{0 ,1 ,0 ,1, 0 },
		{1, 0, 1 ,1 ,0 },
		{0 ,0 ,1 ,0, 1 }
	};
	maxDiff(mat, 3, 5) ;
	return 0;
}
