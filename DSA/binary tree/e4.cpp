/*Replace each node in binary tree with the sum of its inorder predecessor and successor
Given a binary tree containing n nodes. The problem is to replace each node in the binary tree with the sum of its inorder predecessor and inorder successor.

Examples:

Input :          1
               /   \
              2     3
            /  \  /  \
           4   5  6   7

Output :        11
              /    \
             9      13
            / \    /  \
           2   3   4   3
                  
For 1:
Inorder predecessor = 5
Inorder successor  = 6
Sum = 11

For 4:
Inorder predecessor = 0
(as inorder predecessor is not present)
Inorder successor  = 2
Sum = 2

For 7:
Inorder predecessor = 3
Inorder successor  = 0
(as inorder successor is not present)
Sum = 3

Approach: Create an array arr. Store 0 at index 0. 
Now, store the inorder traversal of tree in the array arr. Then, store 0 at last index. 
0’s are stored as inorder predecessor of leftmost leaf and 
inorder successor of rightmost leaf is not present. Now, perform inorder traversal and 
while traversing node replace node’s value with arr[i-1] + arr[i+1] and then increment i. 
In the beginning initialize i = 1. For an element arr[i], the values arr[i-1] and arr[i+1] are 
its inorder predecessor and inorder successor respectively.
*/
#include <iostream>
#include <vector>
using namespace std;

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

// function to store the inorder traversal 
// of the binary tree in 'arr' 
void storeinordertraversal(btree *root, vector<int>& arr){
    if(!root)   return;
    // first recur on left child 
    storeinordertraversal(root->left,arr);
    // then store the root's data in 'arr'
    arr.push_back(root->data);
    // now recur on right child
    storeinordertraversal(root->right, arr);
}

// function to replace each node with the sum of its 
// inorder predecessor and successor 
void replaceNodeWithSum(struct btree* root, vector<int> arr, int* i){
    if(!root)   return ;
    replaceNodeWithSum(root->left, arr, i);
    // replace node's data with the sum of its
    // inorder predessor and successor
    root->data = arr[*i-1]+arr[*i+1];
    // move i to next arr[] element
    ++*i;
    replaceNodeWithSum(root->right, arr, i);
}

void replacenodebysum(btree *root){
    if(!root)   return ;
    vector<int>arr;
    // store the value of inorder predessor
    // for the leftmost leaf
    arr.push_back(0);
    storeinordertraversal(root,arr);
    // store the value of inorder successor 
    // for the rightmost leaf 
    arr.push_back(0);
    int i=1;
    replaceNodeWithSum(root,arr,&i);
}

void preorder(btree *t){
    if(t){
        // root-left-right
        cout<<t->data<<" ";
        preorder(t->left);
        preorder(t->right);
    }
}

int main(){
          root = newNode(1);        /*         1        */
    root->left = newNode(2);        /*       /   \      */
    root->right = newNode(3);       /*     2      3     */
    root->left->left = newNode(4);  /*    /  \  /   \   */
    root->left->right = newNode(5); /*   4   5  6   7   */
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    cout << "Preorder Traversal before tree modification: "; 
    preorder(root); 
  
    replacenodebysum(root); 
  
    cout << "\nPreorder Traversal after tree modification: "; 
    preorder(root); 
}