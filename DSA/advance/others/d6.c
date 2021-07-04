/*Ternary Search Tree
Difficulty Level : Hard
Last Updated : 11 Jun, 2021
A ternary search tree is a special trie data structure where the child nodes of a standard trie are ordered as a binary search tree. 
Representation of ternary search trees: 
Unlike trie(standard) data structure where each node contains 26 pointers for its children, each node in a ternary search tree contains only 3 pointers: 
1. The left pointer points to the node whose value is less than the value in the current node. 
2. The equal pointer points to the node whose value is equal to the value in the current node. 
3. The right pointer points to the node whose value is greater than the value in the current node.
Apart from above three pointers, each node has a field to indicate data(character in case of dictionary) and another field to mark end of a string. 
So, more or less it is similar to BST which stores data based on some order. However, data in a ternary search tree is distributed over the nodes. e.g. It needs 4 nodes to store the word “Geek”. 
Below figure shows how exactly the words in a ternary search tree are stored? 
 



One of the advantage of using ternary search trees over tries is that ternary search trees are a more space efficient (involve only three pointers per node as compared to 26 in standard tries). Further, ternary search trees can be used any time a hashtable would be used to store strings.
Tries are suitable when there is a proper distribution of words over the alphabets so that spaces are utilized most efficiently. Otherwise ternary search trees are better. Ternary search trees are efficient to use(in terms of space) when the strings to be stored share a common prefix.
Applications of ternary search trees: 
1. Ternary search trees are efficient for queries like “Given a word, find the next word in dictionary(near-neighbor lookups)” or “Find all telephone numbers starting with 9342 or “typing few starting characters in a web browser displays all website names with this prefix”(Auto complete feature)”.
2. Used in spell checks: Ternary search trees can be used as a dictionary to store all the words. Once the word is typed in an editor, the word can be parallely searched in the ternary search tree to check for correct spelling.*/
// C program to demonstrate Ternary Search Tree (TST) insert, traverse
// and search operations
#include <stdio.h>
#include <stdlib.h>
#define MAX 50

// A node of ternary search tree
struct Node
{
	char data;

	// True if this character is last character of one of the words
	unsigned isEndOfString: 1;

	struct Node *left, *eq, *right;
};

// A utility function to create a new ternary search tree node
struct Node* newNode(char data)
{
	struct Node* temp = (struct Node*) malloc(sizeof( struct Node ));
	temp->data = data;
	temp->isEndOfString = 0;
	temp->left = temp->eq = temp->right = NULL;
	return temp;
}

// Function to insert a new word in a Ternary Search Tree
void insert(struct Node** root, char *word)
{
	// Base Case: Tree is empty
	if (!(*root))
		*root = newNode(*word);

	// If current character of word is smaller than root's character,
	// then insert this word in left subtree of root
	if ((*word) < (*root)->data)
		insert(&( (*root)->left ), word);

	// If current character of word is greate than root's character,
	// then insert this word in right subtree of root
	else if ((*word) > (*root)->data)
		insert(&( (*root)->right ), word);

	// If current character of word is same as root's character,
	else
	{
		if (*(word+1))
			insert(&( (*root)->eq ), word+1);

		// the last character of the word
		else
			(*root)->isEndOfString = 1;
	}
}

// A recursive function to traverse Ternary Search Tree
void traverseTSTUtil(struct Node* root, char* buffer, int depth)
{
	if (root)
	{
		// First traverse the left subtree
		traverseTSTUtil(root->left, buffer, depth);

		// Store the character of this node
		buffer[depth] = root->data;
		if (root->isEndOfString)
		{
			buffer[depth+1] = '\0';
			printf( "%s\n", buffer);
		}

		// Traverse the subtree using equal pointer (middle subtree)
		traverseTSTUtil(root->eq, buffer, depth + 1);

		// Finally Traverse the right subtree
		traverseTSTUtil(root->right, buffer, depth);
	}
}

// The main function to traverse a Ternary Search Tree.
// It mainly uses traverseTSTUtil()
void traverseTST(struct Node* root)
{
	char buffer[MAX];
	traverseTSTUtil(root, buffer, 0);
}

// Function to search a given word in TST
int searchTST(struct Node *root, char *word)
{
	if (!root)
		return 0;

	if (*word < (root)->data)
		return searchTST(root->left, word);

	else if (*word > (root)->data)
		return searchTST(root->right, word);

	else
	{
		if (*(word+1) == '\0')
			return root->isEndOfString;

		return searchTST(root->eq, word+1);
	}
}

// Driver program to test above functions
int main()
{
	struct Node *root = NULL;

	insert(&root, "cat");
	insert(&root, "cats");
	insert(&root, "up");
	insert(&root, "bug");

	printf("Following is traversal of ternary search tree\n");
	traverseTST(root);

	printf("\nFollowing are search results for cats, bu and cat respectively\n");
	searchTST(root, "cats")? printf("Found\n"): printf("Not Found\n");
	searchTST(root, "bu")? printf("Found\n"): printf("Not Found\n");
	searchTST(root, "cat")? printf("Found\n"): printf("Not Found\n");

	return 0;
}
