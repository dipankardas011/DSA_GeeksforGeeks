/*A program to check if a binary tree is BST or not
A binary search tree (BST) is a node based binary tree data structure which has the following properties. 
• The left subtree of a node contains only nodes with keys less than the node’s key. 
• The right subtree of a node contains only nodes with keys greater than the node’s key. 
• Both the left and right subtrees must also be binary search trees.
From the above properties it naturally follows that: 
• Each node (item in the tree) has a distinct key.
*/
#include <bits/stdc++.h>

using namespace std;

struct node
{
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

node *root=0;

bool isBST(node *root, int min, int max)
{
    if(!root)   return true;

    if(root->data < min || root->data > max)
        return false;

    return (isBST(root->left, min, root->data-1) && isBST(root->right, root->data+1, max));

}

int main()
{
    root=CreateNode(4);
    root->left=CreateNode(2);
    root->right=CreateNode(5);
    root->left->left=CreateNode(1);
    root->left->right=CreateNode(3);
    (isBST(root, INT_MIN, INT_MAX))? 
                            cout<<"it is BST\n" : 
                            cout<<"not a BST\n";
    return 0;
}