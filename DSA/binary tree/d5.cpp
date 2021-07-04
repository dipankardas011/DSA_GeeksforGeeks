/*Print root to leaf paths without using recursion
Difficulty Level : Medium
 Last Updated : 18 Feb, 2019
Given a binary tree, print all its root to leaf paths without using recursion. For example, consider the following Binary Tree.

        6
     /    \
    3      5
  /   \     \
 2     5     4
     /   \
    7     4

There are 4 leaves, hence 4 root to leaf paths -
  6->3->2              
  6->3->5->7
  6->3->5->4
  6->5>4
*/
// C++ program to Print root to leaf path WITHOUT 
// using recursion 
#include <bits/stdc++.h> 
using namespace std; 

/* A binary tree */
struct Node 
{ 
	int data; 
	struct Node *left, *right; 
}; 

/* Helper function that allocates a new node 
with the given data and NULL left and right 
pointers.*/
Node* newNode(int data) 
{ 
	Node* node = new Node; 
	node->data = data; 
	node->left = node->right = NULL; 
	return node; 
} 

/* Function to print root to leaf path for a leaf 
using parent nodes stored in map */
void printTopToBottomPath(Node* curr, 
						map<Node*, Node*> parent) 
{ 
	stack<Node*> stk; 

	// start from leaf node and keep on pushing 
	// nodes into stack till root node is reached 
	while (curr) 
	{ 
		stk.push(curr); 
		curr = parent[curr]; 
	} 

	// Start popping nodes from stack and print them 
	while (!stk.empty()) 
	{ 
		curr = stk.top(); 
		stk.pop(); 
		cout << curr->data << " "; 
	} 
	cout << endl; 
} 

/* An iterative function to do preorder traversal 
of binary tree and print root to leaf path 
without using recursion */
void printRootToLeaf(Node* root) 
{ 
	// Corner Case 
	if (root == NULL) 
		return; 

	// Create an empty stack and push root to it 
	stack<Node*> nodeStack; 
	nodeStack.push(root); 

	// Create a map to store parent pointers of binary 
	// tree nodes 
	map<Node*, Node*> parent; 

	// parent of root is NULL 
	parent[root] = NULL; 

	/* Pop all items one by one. Do following for 
	every popped item 
		a) push its right child and set its parent 
		pointer 
		b) push its left child and set its parent 
		pointer 
	Note that right child is pushed first so that 
	left is processed first */
	while (!nodeStack.empty()) 
	{ 
		// Pop the top item from stack 
		Node* current = nodeStack.top(); 
		nodeStack.pop(); 

		// If leaf node encountered, print Top To 
		// Bottom path 
		if (!(current->left) && !(current->right)) 
			printTopToBottomPath(current, parent); 

		// Push right & left children of the popped node 
		// to stack. Also set their parent pointer in 
		// the map 
		if (current->right) 
		{ 
			parent[current->right] = current; 
			nodeStack.push(current->right); 
		} 
		if (current->left) 
		{ 
			parent[current->left] = current; 
			nodeStack.push(current->left); 
		} 
	} 
} 

// Driver program to test above functions 
int main() 
{ 
	/* Constructed binary tree is 
		10 
		/ \ 
	8 2 
	/ \ / 
	3	 5 2	 */
	Node* root = newNode(10); 
	root->left = newNode(8); 
	root->right = newNode(2); 
	root->left->left = newNode(3); 
	root->left->right = newNode(5); 
	root->right->left = newNode(2); 

	printRootToLeaf(root); 

	return 0; 
}