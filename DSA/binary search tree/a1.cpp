/*
BST to a Tree with sum of all smaller keys
Given a Binary Search Tree(BST), convert it to a Binary Tree such that every key of the original BST is changed to key plus sum of all smaller keys in BST.

Given a BST with N Nodes we have to convert into Binary Tree
*/
#include <iostream>

class btree
{
    public:
    int data;
    btree *left;
    btree *right;
};

btree *create(int val)
{
    btree *t=new btree;
    t->data=val;
    t->left=t->right=NULL;
    return t;
}

void addsmaller(btree *root, int &sum)
{
    if (root)
    {
        addsmaller(root->left, sum);
        // the root val
        sum += root->data;
        root->data = sum;
        addsmaller(root->right, sum);
    }
}

void inorder(btree *r)
{
    if(r)
    {
        inorder(r->left);
        std::cout<<r->data<<" ";
        inorder(r->right);
    }
}

int main()
{
    // given BST
    btree *root=NULL;
    root=create(9);
    root->left=create(6);
    root->right=create(15);
    root->left->left=create(3);
    root->right->right=create(21);
    inorder(root);
    int sum=0;
    addsmaller(root, sum);
    std::cout<<""<<std::endl;
    inorder(root);
    return 0;
}