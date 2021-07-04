/*Sum of all leaf nodes of binary tree
Given a binary tree, find the sum of all the leaf nodes.

Examples:

Input : 
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
          \
           8
Output :
Sum = 4 + 5 + 8 + 7 = 24
*/
#include <iostream>

struct btree{
    int data;
    struct btree *left, *right;
};
btree *root=0;

btree *newNode(int val){
    btree *t=new btree;
    t->data=val;
    t->left=t->right=0;

    return t;
}

void SumLeafNodes(btree *t, int &sum){
    if(t==0)    return;

    if(t->left==0 && t->right==0)
        //leaf node
        sum+=t->data;
    SumLeafNodes(t->left,sum);
    SumLeafNodes(t->right,sum);
}

int main(){
    root = newNode(1); 
    root->left = newNode(2); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right = newNode(3); 
    root->right->right = newNode(7); 
    root->right->left = newNode(6); 
    root->right->left->right = newNode(8);
    int SUM=0;
    SumLeafNodes(root, SUM);
    std::cout<<"the sum of all the leaf nodes= "<<SUM<<std::endl;
    return 0;
}