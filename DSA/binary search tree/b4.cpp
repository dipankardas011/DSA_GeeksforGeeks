/*Remove BST keys outside the given range
Given a Binary Search Tree (BST) and a range [min, max], remove all keys which are outside the given range. The modified tree should also be BST. For example, consider the following BST and range [-10, 13]. 
The given tree should be changed to the following. Note that all keys outside the range [-10, 13] are removed and the modified tree is BST. 
There are two possible cases for every node. 
1) Node’s key is outside the given range. This case has two sub-cases. 
…….a) Node’s key is smaller than the min value. 
…….b) Node’s key is greater than the max value. 
2) Node’s key is in range.
We don’t need to do anything for case 2. In case 1, we need to remove the node and change the root of the subtree rooted with this node. 
*/
#include <bits/stdc++.h>

using std::cout;
using std::cin;

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

// create BST
node *BuildTree(node *root, int key)
{
    if(!root)   return CreateNode(key);

    if(key < root->data)
        root->left= BuildTree(root->left, key);
    else /*if(key > root->data)*/
        root->right= BuildTree(root->right, key);
    return root;
}

void find_inorder(node *n){
    if(n){
        find_inorder(n->left);
        cout<<n->data<<" ";
        find_inorder(n->right);
    }
}

node *removeOUTOFRANGE(node *root, int m, int n)
{
    if(!root)   return NULL;

    root->left=removeOUTOFRANGE(root->left, m,n);
    root->right=removeOUTOFRANGE(root->right,m,n);

    if(root->data < m){
        node *right=root->right;
        delete root;
        return right;
    }
    if(root->data > n){
        node *left=root->left;
        delete root;
        return left;
    }
    return root;
}

int main()
{
    node *root=0;
    root = BuildTree(root, 6);
    root = BuildTree(root, -13);
    root = BuildTree(root, 14);
    root = BuildTree(root, -8);
    root = BuildTree(root, 15);
    root = BuildTree(root, 13);
    root = BuildTree(root, 7);
    find_inorder(root);
    cout<<"\n";
    int m,n;
    cout<<"enter the range[m,n]: ";
    cin>>m>>n;
    root=removeOUTOFRANGE(root,m,n);    
/*-13 -8 6 7 13 14 15   
enter the range[m,n]: -10,13
-8 6 7 13*/
    find_inorder(root);
    cout<<"\n";
    return 0;
}