/*Count BST subtrees that lie in given range
Given a Binary Search Tree (BST) of integer values and a range [low, high], return count of nodes where all the nodes under that node (or subtree rooted with that node) lie in the given range.

Examples:

Input:
        10
      /    \
    5       50
   /       /  \
 1       40   100
Range: [5, 45]
Output:  1 
There is only 1 node whose subtree is in the given range.
The node is 40 


Input:
        10
      /    \
    5       50
   /       /  \
 1       40   100
Range: [1, 45]
Output:  3 
There are three nodes whose subtree is in the given range.
The nodes are 1, 5 and 40
*/
#include <bits/stdc++.h>

using std::cout;
using std::cin;
using std::endl;

class node
{
    public:
    int data;
    node *left, *right;
};


node *CreateNode(int key)
{
    node *t=new node;
    t->data=key;
    t->left=t->right=0;
    return t;
}

bool inRange(node* root, int low, int high)
{
    return root->data >= low && root->data <= high;
}

bool getCountUtil(node* root, int low, int high, int* count)
{
    // Base case
    if (root == NULL)
        return true;

    // Recur for left and right subtrees
    bool l = getCountUtil(root->left, low, high, count);
    bool r = getCountUtil(root->right, low, high, count);
  
    // If both left and right subtrees are in range and current node
    // is also in range, then increment count and return true
    if (l && r && inRange(root, low, high)) {
        ++*count;
        return true;
    }
  
    return false;
}

int main()
{
    node *root=0;
    root = CreateNode(10);
    root->left = CreateNode(5);
    root->right = CreateNode(50);
    root->left->left = CreateNode(1);
    root->right->left = CreateNode(40);
    root->right->right = CreateNode(100);
    int count=0;
    getCountUtil(root,5,45, &count);
    cout<<"number of node within range[1,45] = "<<count<<endl;
    return 0;
}