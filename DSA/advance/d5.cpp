// Node having maximum sum of immediate children and itself in n-ary tree
// Difficulty Level : Medium
// Last Updated : 31 May, 2019
// Given an N-Ary tree, find and return the node for which sum of data of all children and the node itself is maximum. In the sum, data of node itself and data of its immediate children is to be taken.

// For example in the given tree,

// maxSum Node = 4 with maximum sum of 28

// CPP program to find the node whose children
// and node sum is maximum.
#include <iostream>
#include <vector>
using namespace std;

// Structure of a node of an n-ary tree
struct Node
{
    int key;
    vector<Node *> child;
};

// Utility function to create a new tree node
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    return temp;
}

// Helper function to find the node
void maxSumUtil(Node *root, Node **resNode, int *maxsum)
{
    // Base Case
    if (root == NULL)
        return;

    // curr contains the sum of the root and
    // its children
    int currsum = root->key;

    // total no of children
    int count = root->child.size();

    // for every child call recursively
    for (int i = 0; i < count; i++)
    {
        currsum += root->child[i]->key;
        maxSumUtil(root->child[i], resNode, maxsum);
    }

    // if curr is greater than sum, update it
    if (currsum > *maxsum)
    {

        // resultant node
        *resNode = root;
        *maxsum = currsum;
    }
    return;
}

// Function to find the node having max sum of
// children and node
int maxSum(Node *root)
{
    // resultant node with max sum of children
    // and node
    Node *resNode;

    // sum of node and its children
    int maxsum = 0;

    maxSumUtil(root, &resNode, &maxsum);

    // return the key of resultant node
    return resNode->key;
}

// Driver program
int main()
{
    /* Let us create below tree
	*		  1
	*	   /  | \
	*	  2   3  4
	*	 / \ / |\ \
	*	 5 6 7 8 9 10
	*/

    Node *root = newNode(1);
    (root->child).push_back(newNode(2));
    (root->child).push_back(newNode(3));
    (root->child).push_back(newNode(4));
    (root->child[0]->child).push_back(newNode(5));
    (root->child[0]->child).push_back(newNode(6));
    (root->child[2]->child).push_back(newNode(5));
    (root->child[2]->child).push_back(newNode(6));
    (root->child[2]->child).push_back(newNode(6));

    cout << maxSum(root) << endl;

    return 0;
}
