/*Find the maximum subarray XOR in a given array

Given an array of integers. find the maximum XOR subarray value in given array. Expected time complexity O(n).

Examples: 

Input: arr[] = {1, 2, 3, 4}
Output: 7
The subarray {3, 4} has maximum XOR value

Input: arr[] = {8, 1, 2, 12, 7, 6}
Output: 15
The subarray {1, 2, 12} has maximum XOR value

Input: arr[] = {4, 6}
Output: 6
The subarray {6} has maximum XOR value

An Efficient Solution can solve the above problem in O(n) time under the assumption that integers take fixed number of bits to store. The idea is to use Trie Data Structure. Below is algorithm.  

1) Create an empty Trie.  Every node of Trie is going to 
   contain two children, for 0 and 1 value of bit.
2) Initialize pre_xor = 0 and insert into the Trie.
3) Initialize result = minus infinite
4) Traverse the given array and do following for every 
   array element arr[i].
       a) pre_xor  = pre_xor  ^ arr[i]
          pre_xor now contains xor of elements from 
          arr[0] to arr[i].
       b) Query the maximum xor value ending with arr[i] 
          from Trie.
       c) Update result if the value obtained in step 
          4.b is more than current value of result.
How does 4.b work? 
We can observe from above algorithm that we build a Trie that contains XOR of all prefixes of given array. To find the maximum XOR subarray ending with arr[i], there may be two cases. 
i) The prefix itself has the maximum XOR value ending with arr[i]. For example if i=2 in {8, 2, 1, 12}, then the maximum subarray xor ending with arr[2] is the whole prefix. 
ii) We need to remove some prefix (ending at index from 0 to i-1). For example if i=3 in {8, 2, 1, 12}, then the maximum subarray xor ending with arr[3] starts with arr[1] and we need to remove arr[0].
To find the prefix to be removed, we find the entry in Trie that has maximum XOR value with current prefix. If we do XOR of such previous prefix with current prefix, we get the maximum XOR value ending with arr[i]. 
If there is no prefix to be removed (case i), then we return 0 (that’s why we inserted 0 in Trie). */
// C++ program for a Trie based O(n) solution to find max
// subarray XOR
#include<bits/stdc++.h>
using namespace std;

// Assumed int size
#define INT_SIZE 32

// A Trie Node
struct TrieNode
{
	int value; // Only used in leaf nodes
	TrieNode *arr[2];
};

// Utility function to create a Trie node
TrieNode *newNode()
{
	TrieNode *temp = new TrieNode;
	temp->value = 0;
	temp->arr[0] = temp->arr[1] = NULL;
	return temp;
}

// Inserts pre_xor to trie with given root
void insert(TrieNode *root, int pre_xor)
{
	TrieNode *temp = root;

	// Start from the msb, insert all bits of
	// pre_xor into Trie
	for (int i=INT_SIZE-1; i>=0; i--)
	{
		// Find current bit in given prefix
		bool val = pre_xor & (1<<i);

		// Create a new node if needed
		if (temp->arr[val] == NULL)
			temp->arr[val] = newNode();

		temp = temp->arr[val];
	}

	// Store value at leaf node
	temp->value = pre_xor;
}

// Finds the maximum XOR ending with last number in
// prefix XOR 'pre_xor' and returns the XOR of this maximum
// with pre_xor which is maximum XOR ending with last element
// of pre_xor.
int query(TrieNode *root, int pre_xor)
{
	TrieNode *temp = root;
	for (int i=INT_SIZE-1; i>=0; i--)
	{
		// Find current bit in given prefix
		bool val = pre_xor & (1<<i);

		// Traverse Trie, first look for a
		// prefix that has opposite bit
		if (temp->arr[1-val]!=NULL)
			temp = temp->arr[1-val];

		// If there is no prefix with opposite
		// bit, then look for same bit.
		else if (temp->arr[val] != NULL)
			temp = temp->arr[val];
	}
	return pre_xor^(temp->value);
}

// Returns maximum XOR value of a subarray in arr[0..n-1]
int maxSubarrayXOR(int arr[], int n)
{
	// Create a Trie and insert 0 into it
	TrieNode *root = newNode();
	insert(root, 0);

	// Initialize answer and xor of current prefix
	int result = INT_MIN, pre_xor =0;

	// Traverse all input array element
	for (int i=0; i<n; i++)
	{
		// update current prefix xor and insert it into Trie
		pre_xor = pre_xor^arr[i];
		insert(root, pre_xor);

		// Query for current prefix xor in Trie and update
		// result if required
		result = max(result, query(root, pre_xor));
	}
	return result;
}

// Driver program to test above functions
int main()
{
	int arr[] = {8, 1, 2, 12};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Max subarray XOR is " << maxSubarrayXOR(arr, n);
	return 0;
}
