/*Find shortest unique prefix for every word in a given list | Set 1 (Using Trie)
Difficulty Level : Hard
Last Updated : 06 Mar, 2019
Given an array of words, find all shortest unique prefixes to represent each word in the given array. Assume that no word is prefix of another.

Examples:

Input: arr[] = {"zebra", "dog", "duck", "dove"}
Output: dog, dov, du, z
Explanation: dog => dog
             dove = dov 
             duck = du
             z   => zebra 

Input: arr[] =  {"geeksgeeks", "geeksquiz", "geeksforgeeks"};
Output: geeksf, geeksg, geeksq}

An Efficient Solution is to use Trie. The idea is to maintain a count in every node. Below are steps.

1) Construct a Trie of all words. Also maintain frequency of every node (Here frequency is number of times node is visited during insertion). Time complexity of this step is O(N) where N is total number of characters in all words.

2) Now, for every word, we find the character nearest to the root with frequency as 1. The prefix of the word is path from root to this character. To do this, we can traverse Trie starting from root. For every node being traversed, we check its frequency. If frequency is one, we print all characters from root to this node and don’t traverse down this node.

Time complexity if this step also is O(N) where N is total number of characters in all words.

                root
                / \
         (d, 3)/   \(z, 1)
              /     \
          Node1     Node2
           / \          \
     (o,2)/   \(u,1)     \(e,1)
         /     \          \
   Node1.1    Node1.2     Node2.1
      /  \         \            \
(g,1)/    \ (t,1)   \(c,1)       \(b,1)
    /      \         \            \ 
   Leaf   Leaf       Node1.2.1     Node2.1.1
   (dog)  (dot)        \               \
                         \(k, 1)          \(r, 1)
                          \                \   
                          Leaf           Node2.1.1.1
                          (duck)              \
                                                \(a,1)
                                                 \
                                                 Leaf
                                                 (zebra)
*/
// C++ program to print all prefixes that
// uniquely reprsent words.
#include<bits/stdc++.h>
using namespace std;

#define MAX 256

// Maximum length of an input word
#define MAX_WORD_LEN 500

// Trie Node.
struct trieNode
{
	struct trieNode *child[MAX];
	int freq; // To store frequency
};

// Function to create a new trie node.
struct trieNode *newTrieNode(void)
{
	struct trieNode *newNode = new trieNode;
	newNode->freq = 1;
	for (int i = 0; i<MAX; i++)
		newNode->child[i] = NULL;
	return newNode;
}

// Method to insert a new string into Trie
void insert(struct trieNode *root, string str)
{
	// Length of the URL
	int len = str.length();
	struct trieNode *pCrawl = root;

	// Traversing over the length of given str.
	for (int level = 0; level<len; level++)
	{
		// Get index of child node from current character
		// in str.
		int index = str[level];

		// Create a new child if not exist already
		if (!pCrawl->child[index])
			pCrawl->child[index] = newTrieNode();
		else
		(pCrawl->child[index]->freq)++;

		// Move to the child
		pCrawl = pCrawl->child[index];
	}
}

// This function prints unique prefix for every word stored
// in Trie. Prefixes one by one are stored in prefix[].
// 'ind' is current index of prefix[]
void findPrefixesUtil(struct trieNode *root, char prefix[],
					int ind)
{
    // Corner case
    if (root == NULL)
        return;

    // Base case
    if (root->freq == 1)
    {
        prefix[ind] = '\0';
        cout << prefix << " ";
        return;
    }

    for (int i = 0; i < MAX; i++)
    {
        if (root->child[i] != NULL)
        {
            prefix[ind] = i;
            findPrefixesUtil(root->child[i], prefix, ind + 1);
        }
    }
}

// Function to print all prefixes that uniquely
// represent all words in arr[0..n-1]
void findPrefixes(string arr[], int n)
{
	// Construct a Trie of all words
	struct trieNode *root = newTrieNode();
	root->freq = 0;
	for (int i = 0; i<n; i++)
		insert(root, arr[i]);

	// Create an array to store all prefixes
	char prefix[MAX_WORD_LEN];

	// Print all prefixes using Trie Traversal
	findPrefixesUtil(root, prefix, 0);
}

// Driver function.
int main()
{
	string arr[] = {"zebra", "dog", "duck", "dove"};
	int n = sizeof(arr)/sizeof(arr[0]);
	findPrefixes(arr, n);

	return 0;
}