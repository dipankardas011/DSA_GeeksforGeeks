/*Check if a given Binary Tree is SumTree
Write a function that returns true if the given Binary Tree is SumTree else false. A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree. An empty tree is SumTree and sum of an empty tree can be considered as 0. A leaf node is also considered as SumTree.

Following is an example of SumTree. 

          26
        /   \
      10     3
    /    \     \
  4      6      3
*/

#include <iostream>

typedef struct binarytree{
    int data;
    struct binarytree *left, *right;
}btree;

btree *root=NULL;

btree *create(int v){
    btree *m=new btree;
    m->data=v;
    m->left=m->right=NULL;
    return m;
}

int sum(btree* k){
    if(k==0)
        return 0;
    return sum(k->left)+sum(k->right)+k->data;
}

bool isSUMTREE(btree *r){
    int ls,rs;
    if(r==0 || (r->left==0 && r->right==0))
        return true;
    ls=sum(r->left);
    rs=sum(r->right);

    if((r->data==ls+rs) && isSUMTREE(r->left) && isSUMTREE(r->right))
        return true;
    return false;
}

int main(){
    {
        // the example 1
        root=create(26);
        root->left=create(10);
        root->left->left=create(4);
        root->left->right=create(6);
        root->right=create(3);
        root->right->right=create(3);
        if(isSUMTREE(root)==true)
            std::cout<<"it's a SUM TREE\n";
        else
            std::cout<<"not a SUM TREE\n";
        
    }
    
}