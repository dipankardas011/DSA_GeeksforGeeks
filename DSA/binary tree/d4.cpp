/*Check for Symmetric Binary Tree (Iterative Approach)

Given a binary tree, check whether it is a mirror of itself without recursion.

Examples:

Input :   
    
     1
   /   \
  2     2
 / \   / \
3   4 4   3

Output : Symmetric

Input :    
   
    1
   / \
  2   2
   \   \
   3    3

Output : Not Symmetric*/

/*
level- the elements are which is not palindromic.
In other words,
1. The left child of left subtree = right child of right subtree.
2. The right child of left subtree = left child of right subtree.
If we insert the left child of left subtree first followed by right
child of the right subtree in the queue, we only need to ensure that these are equal.
Similarly, If we insert the right child of left subtree followed by left child of the 
right subtree in the queue, we again need to ensure that these are equal.*/

#include <iostream>
#include <queue>

struct tree{
    int data;
    struct tree *left;
    struct tree *right;
};

struct tree *create(int val){
    struct tree *n=new struct tree;
    n->data=val;
    n->left=n->right=0;
    return n;
}
struct tree *root=0;
bool execute(struct tree *root){
    if(root==0) return true;
    if(root->left==0 && root->right==0) return true;

    std::queue<struct tree*>q;

    q.push(root);
    q.push(root);

    tree *lchild, *rchild;
    while(!q.empty()){
        lchild=q.front();
        q.pop();
        rchild=q.front();
        q.pop();

        if(lchild->data!=rchild->data)  return false;// root data does not match

        // when there is child then only will work
        if(lchild->left && rchild->right){
            q.push(lchild->left);
            q.push(rchild->right);
        }
        if(lchild->left || rchild->right)   return false;

        // when there is child then only will work
        if(lchild->right && rchild->left){
            q.push(lchild->right);
            q.push(rchild->left);
        }
        if(lchild->right || rchild->left)   return false;
        // because it is not symmatic
    }
    return true;
}
int main(){
    root = create(1); 
    root->left = create(2); 
    root->right = create(2); 
    root->left->left = create(3); 
    root->left->right = create(4); 
    root->right->left = create(4); 
    // root->right->right = create(3); 
  
    if(execute(root)) 
        std::cout << "The given tree is Symmetric"; 
    else
        std::cout << "The given tree is not Symmetric"; 
    return 0;
}