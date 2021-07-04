/*Find the closest element in Binary Search Tree
Given a binary search tree and a target node K. The task is to find the node with minimum absolute difference with given target value K.

        9
       / \
      4  17
     / \   \
    3  6    22
      /\    /
     5 7   20


// For above binary search tree
Input  :  k = 4
Output :  4

Input  :  k = 18
Output :  17

Input  :  k = 12
Output :  9
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

void ClosestElement(node *root, int diff, int& o_pkey, int find)
{
    if(!root)   return ;

    if(root->data == find){
        o_pkey = root->data;
        return ;
    }
    
    if(diff > abs(find - root->data))
    {
        o_pkey=root->data;
        diff=abs(find - root->data);
    }

    if(find<root->data)  ClosestElement(root->left,diff,o_pkey,find);
    else    ClosestElement(root->right,diff,o_pkey,find);
}

int main()
{
    node *root = CreateNode(9);
    root->left    = CreateNode(4);
    root->right   = CreateNode(17);
    root->left->left = CreateNode(3);
    root->left->right = CreateNode(6);
    root->left->right->left = CreateNode(5);
    root->left->right->right = CreateNode(7);
    root->right->right = CreateNode(22);
    root->right->right->left = CreateNode(20);
    int data=0;
    int finder=0;
    cout<<"enter the key for finding closest element..  ";
    cin>>finder;
    ClosestElement(root,INT_MAX,data,finder);
    cout<<"the key is= "<<data<<endl;
    return 0;
}