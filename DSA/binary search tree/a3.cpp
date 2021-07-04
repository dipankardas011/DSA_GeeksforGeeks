/*reverse the path of a binary tree (BST)
        8
       / \
      3  10
     / \   \
    1  6   14
      / \  /
    4   7 13
    node = 13
    change it to 
        13
       /  \
      3   14
     / \   \
    1  6    10
      / \   /
     4  7  8
    here the path is changed from
    8->10->14->13 to
    13->14->10->8
    f*/
#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node *left, *right;
};

node *create(int val)
{
    node *t=new node;
    t->data=val;
    t->left=t->right=0;
    return t;
}

void ReversePath(queue<int>& que, node *root, int key)
{
    if(!root)   return ;

    if(key > root->data)
    {
        // right traversal
        que.push(root->data);
        ReversePath(que, root->right, key);
        root->data=que.front();
        que.pop();
    }
    else if(key < root->data)
    {
        /// left traversal
        que.push(root->data);
        ReversePath(que, root->left, key);
        // after traversal so we have t ochange
        root->data=que.front();
        que.pop();
    }
    else
    {
        // found
        // replacing
        que.push(root->data);
        root->data=que.front();
        que.pop();
    }
    return ;
}

void inorder(node *n)
{
    if(n)
    {
        inorder(n->left);
        cout<<n->data<<" ";
        inorder(n->right);
    }
}


int main()
{
    node *root=0;
    root=create(8);
    root->left=create(3);
    root->right=create(10);
    root->left->left=create(1);
    root->left->right=create(6);
    root->right->right=create(14);
    root->left->right->left=create(4);
    root->left->right->right=create(7);
    root->right->right->left=create(13);
    queue<int> arr;
    ReversePath(arr, root,13);
    inorder(root);
    cout<<"\nSUCESS!\n";
    return 0;
}