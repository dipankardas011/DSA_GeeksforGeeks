/*Density of Binary Tree in One Traversal

Given a Binary Tree, find density of it by doing one traversal of it.

Density of Binary Tree = Size / Height 
Examples:

Input: Root of following tree
        10
       /   \
      20   30

Output: 1.5
Height of given tree = 2
Size of given tree = 3

Input: Root of following tree
         10
      /   
     20   
    /
    30
Output: 1
Height of given tree = 3
Size of given tree = 3 
Density of a Binary Tree indicates, how balanced Binary Tree is.
For example density of a skewed tree is minimum and that of a 
perfect tree is maximum.*/
#include <stdio.h>
#include <stdlib.h>

struct tree {
    int data;
    struct tree* left, * right;
};

struct tree* root = 0;
int count=0;

struct tree* create(int val) {
    struct tree* t = (struct tree*)malloc(sizeof(struct tree));
    t->data = val;
    t->left = t->right = 0;
    return t;
}

void count_nodes(struct tree* t) {
    if (t != 0) {
        count++;
        
        count_nodes(t->left);
        count_nodes(t->right);
    }
}


int height(struct tree* t) {
    if (t == 0)
        return 0;
    int left = height(t->left);
    int right = height(t->right);
    return (left > right) ? left + 1 : right + 1;
}

void delete_tree(struct tree* t) {
    if (t == 0)
        return;

    delete_tree(t->left);
    delete_tree(t->right);

    free(t);
}


int main() {
    root = create(10);
    root->left = create(20);
    root->right = create(30);


    count_nodes(root);
    printf("height: %d\n",height(root));
    printf("count: %d\n",count);
    printf("The density of binary tree: %lf\n", (float)count/height(root));
    delete_tree(root);


    count=0;
    root = create(10);
    root->left = create(20);
    root->left->left = create(30);


    count_nodes(root);
    printf("height: %d\n",height(root));
    printf("count: %d\n",count);
    printf("The density of binary tree: %lf\n", (float)count / height(root));
    delete_tree(root);
    return 0;
}