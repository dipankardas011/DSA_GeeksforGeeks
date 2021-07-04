/*Merge Two Balanced Binary Search Trees
Difficulty Level : Medium
Last Updated : 27 May, 2021
You are given two balanced binary search trees e.g., AVL or Red Black Tree. Write a function that merges the two given balanced BSTs into a balanced binary search tree. Let there be m elements in first tree and n elements in the other tree. Your merge function should take O(m+n) time.
In the following solutions, it is assumed that sizes of trees are also given as input. If the size is not given, then we can get the size by traversing the tree

Method 2 (Merge Inorder Traversals) 
1) Do inorder traversal of first tree and store the traversal in one temp array arr1[]. This step takes O(m) time. 
2) Do inorder traversal of second tree and store the traversal in another temp array arr2[]. This step takes O(n) time. 
3) The arrays created in step 1 and 2 are sorted arrays. Merge the two sorted arrays into one array of size m + n. This step takes O(m+n) time. 
4) Construct a balanced tree from the merged array using the technique discussed in this post. This step takes O(m+n) time.*/
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *newNode(int v)
{
    node *t = new node;
    t->data = v;
    t->left = t->right = NULL;
    return t;
}

void InorderToArr(node* xx, vector<int>& vec){

    if(xx){
        InorderToArr(xx->left,vec);
        vec.push_back(xx->data);
        InorderToArr(xx->right,vec);
    }
}

void Mergevec(vector<int> v1, vector<int> v2, vector<int>& mergedvec)
{
    int m=v1.size();
    int n=v2.size();
    int i=0,j=0;
    while(i<m && j<n )
    {
        if(v1.at(i)<v2.at(j))
            mergedvec.push_back(v1.at(i++));
        else
            mergedvec.push_back(v2.at(j++));
    }

    while(i < m)
        mergedvec.push_back(v1.at(i++));
    
    while(j<n)
        mergedvec.push_back(v2.at(j++));

}

node* sortedArrayToBST(vector<int> arr, int start, int end)
{
    /* Base Case */
    if (start > end)
    return NULL;
 
    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    node *root = newNode(arr[mid]);
 
    /* Recursively construct the left subtree and make it
    left child of root */
    root->left = sortedArrayToBST(arr, start, mid-1);
 
    /* Recursively construct the right subtree and make it
    right child of root */
    root->right = sortedArrayToBST(arr, mid+1, end);
 
    return root;
}

node* exec(node* r1, node* r2){

    vector<int> v1;
    InorderToArr(r1,v1);

    vector<int> v2;
    InorderToArr(r2,v2);

    // for(auto i:v1)
    //     cout<<i<<endl;
    // cout<<endl;
    // for(auto i:v2)
    //     cout<<i<<endl;

    // now we need to merge them
    vector<int> resVec;
    Mergevec(v1,v2,resVec);
    // cout<<endl;
    // for(auto i:resVec)
    //     cout<<i<<endl;
    // now to make the tree
    node* r = sortedArrayToBST(resVec, 0, (resVec.size()-1));

    return r;
}

void Inorder(node* root){

    if(root){
        Inorder(root->left);
        cout<<root->data<<"\t";
        Inorder(root->right);
    }
}

int main()
{
    /* Create following tree as first balanced BST
        100
        / \
        50 300
    / \
    20 70
    */
    node *root1 = newNode(100);
    root1->left = newNode(50);
    root1->right = newNode(300);
    root1->left->left = newNode(20);
    root1->left->right = newNode(70);

    /* Create following tree as second balanced BST
            80
        / \
        40 120
    */
    node *root2 = newNode(80);
    root2->left = newNode(40);
    root2->right = newNode(120);

    node* ROOT = exec(root1,root2);
    cout<<"\nThe merged tree: ";
    Inorder(ROOT);
    return 0;
}