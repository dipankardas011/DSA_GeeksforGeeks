/*Sum of heights of all individual nodes in a binary tree
Given a binary tree, find sum of heights all individual Nodes in the tree. 

Example: 

Binary Tree
        1
       / \
      2   3
     / \
    4  5

For this tree:
1). Height of Node 1 - 3
2). Height of Node 2 - 2
3). Height of Node 3 - 1
4). Height of Node 4 - 1
5). Height of Node 5 - 1

Adding all of them = 8
*/
#include <iostream>

struct btree{
    int data;
    struct btree *left, *right;
};

btree *create(int val){
    btree *t=new btree;
    t->data=val;
    t->left=t->right=0;

    return t;
}

int height(btree *node){
    if(node==0) return 0;

    int ls=height(node->left);
    int rs=height(node->right);

    return (ls>rs)? ls+1 : rs+1;
}
int sum=0;

void postorder(btree *t){
    if(t){
        postorder(t->left);
        postorder(t->right);
        sum+=height(t);
    }
}

int main(){
    btree *root=0;
    root=create(1);
    root->left=create(2);
    root->right=create(3);
    root->left->left=create(4);
    root->left->right=create(5);
    postorder(root);
    std::cout<<"The sum of heights of all the individual node= "<<sum<<std::endl;
    return 0;
}