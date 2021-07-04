/*Check if removing an edge can divide a Binary Tree in two halves
Given a Binary Tree, find if there exist edge whose removal creates two trees of equal size.

Examples:  

Input : root of following tree
           5
         /   \
       1      6    
      /      /  \
     3      7    4
Output : true
Removing edge 5-6 creates two trees of equal size

Input : root of following tree
           5
         /   \
       1      6    
            /  \
           7    4
         /  \    \
        3    2    8
Output : false
There is no edge whose removal creates two trees
of equal size.
*/
#include <iostream>

typedef struct binaryt{
    int data;
    struct binaryt *left, *right;
}btree;



btree *create(int val){
    btree*t=new btree;
    t->data=val;
    t->right=t->left=0;
    return t;
}

void deletetree(btree *t){
    if(t!=NULL){
        deletetree(t->left);
        deletetree(t->right);
        delete t;
    }
}

// to calculate the size=number of nodes
int count(btree *n){
    if(n==NULL)    return 0;
    
    return count(n->left)+count(n->right)+1;
}

bool checkcount(btree *t, int n){
    if(t==NULL)    return false;
    
    if(count(t)==n-count(t))  return true;

    // rest of nodes
    return checkcount(t->left,n)||checkcount(t->right,n);
}

int main(){
    btree *root=0;
    {
        // eg 1
        root=create(5);
        root->left=create(1);
        root->left->left=create(3);
        root->right=create(6);
        root->right->left=create(7);
        root->right->right=create(4);
        int n=count(root);
        if(checkcount(root,n)==true)  std::cout<<"it can be divided\n";
        else    std::cout<<"it cannot be divided\n";
    }
    deletetree(root);
    return 0;
}