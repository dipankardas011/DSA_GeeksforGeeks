/*Inorder Non-threaded Binary Tree Traversal without Recursion or Stack
We have discussed Thread based Morris Traversal. Can we do inorder traversal without threads if we have parent pointers available to us?

Input: Root of Below Tree [Every node of 
       tree has parent pointer also]
        10
      /    \
     5     100
           /  \
          80  120 
Output: 5 10 80 100 120
The code should not extra space (No Recursion
and stack)
*/
#include <bits/stdc++.h>
using namespace std;

class tree {
    public:
    int data;
    tree *left, *right;
    tree *parent;
};

tree *CreateNode(int val)
{
    tree *t = new tree;
    t->data = val;
    t->left = t->right = 0;
    t->parent = 0;

    return t;
}

tree *insert(tree *root, int key)
{
    if(!root)   return CreateNode(key);

    if(root->data > key) {
        root->left = insert (root->left, key);
        root->left->parent=root;
    }
    else {
        root->right = insert(root->right, key);
        root->right->parent=root;
    }

    return root;
}
/*
1. Initialize current node as root
2. Initialize a flag: leftdone = false;
3. Do following while root is not NULL
     a) If leftdone is false, set current node as leftmost
        child of node. 
     b) Mark leftdone as true and print current node.
     c) If right child of current nodes exists, set current
        as right child and set leftdone as false.
     d) Else If parent exists, If current node is left child
        of its parent, set current node as parent. 
        If current node is right child, keep moving to ancestors
        using parent pointer while current node is right child
        of its parent.  
     e) Else break (We have reached back to root)
*/
void InorderTraversal(tree *node)
{
    bool leftmost=false;

    while(node)
    {
        if(leftmost == false) {
            while(node->left)   node = node->left;
        }
        std::cout<<node->data<<" ";
        leftmost=true;

        if(node->right)
        {
            leftmost=false;
            node=node->right;
        }
        // if no right child of leftmost then
        else if(node->parent) {

            while (node->parent && node == node->parent->right)
            {
                node=node->parent;
            }

            if(node->parent==0)
                break;
            node=node->parent;
        }
        else    break;
    }
}

void inorder(tree *node){
    if(node) {
        inorder(node->left);
        std::cout<<node->data<<","<<node->parent<<" ";
        inorder(node->right);
    }
}

int main()
{
    /*
        10
      /    \
     5     100
           /  \
          80  120
    c*/

    tree *root = 0;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 100);
    root = insert(root, 80);
    root = insert(root, 120);
    InorderTraversal(root);
    return 0;
}