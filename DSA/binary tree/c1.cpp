/*Construct a complete binary tree from given array in level order fashion
Given an array of elements, our task is to construct a complete binary tree from this array in level order fashion. That is, elements from left in the array will be filled in the tree level wise starting from level 0.

Examples:

Input  :  arr[] = {1, 2, 3, 4, 5, 6}
Output : Root of the following tree
                  1
                 / \
                2   3
               / \ /
              4  5 6


Input: arr[] = {1, 2, 3, 4, 5, 6, 6, 6, 6, 6}
Output: Root of the following tree
                   1
                  / \
                 2   3
                / \ / \
               4  5 6  6
              / \ /
             6  6 6
*/
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct tree{
    int data;
    tree* left,*right;
};

tree* create(int val){
    tree* t=(tree*)malloc(sizeof(tree));
    t->data=val;
    t->left=t->right=0;
    return t;
}
int N;
tree* root=NULL;
void inorder(tree *t){
    if(t){
        inorder(t->left);
        cout<<t->data<<"\t";
        inorder(t->right);
    }
}


void insert(int v){
    cout<<"helllo\n";
}

tree* insert(int index, int arr[], tree* t){
    if(index<N){
        // the element is present
        tree* temp=create(arr[index]);
        t=temp;
        t->left=insert(2*index+1,arr,t->left);
        t->right=insert(2*index+2, arr, t->right);
    }
    return t;
}

int main(){
    int arr[]={1,2,3,4,5,6};
    N=sizeof(arr)/sizeof(arr[0]);
    root=insert(0,arr,root);
    inorder(root);
    return 0;
}