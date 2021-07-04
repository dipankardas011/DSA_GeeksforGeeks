/*Count smaller elements on right side
Write a function to count number of smaller elements on right of each element in an array. Given an unsorted array arr[] of distinct integers, construct another array countSmaller[] such that countSmaller[i] contains count of smaller elements on right side of each element arr[i] in array.

Examples: 

Input:   arr[] =  {12, 1, 2, 3, 0, 11, 4}
Output:  countSmaller[]  =  {6, 1, 1, 1, 0, 1, 0} 

(Corner Cases)
Input:   arr[] =  {5, 4, 3, 2, 1}
Output:  countSmaller[]  =  {4, 3, 2, 1, 0} 

Input:   arr[] =  {1, 2, 3, 4, 5}
Output:  countSmaller[]  =  {0, 0, 0, 0, 0}

Method 1 (Simple) 
Use two loops. The outer loop picks all elements from left to right. The inner loop iterates through all the elements on right side of the picked element and updates countSmaller[].

Time Complexity: O(n^2) 
Auxiliary Space: O(1)

Method 2 (Use Self Balancing BST) 
A Self Balancing Binary Search Tree (AVL, Red Black,.. etc) can be used to get the solution in O(nLogn) time complexity. We can augment these trees so that every node N contains size the subtree rooted with N. We have used AVL tree in the following implementation.
We traverse the array from right to left and insert all elements one by one in an AVL tree. While inserting a new key in an AVL tree, we first compare the key with root. If key is greater than root, then it is greater than all the nodes in left subtree of root. So we add the size of left subtree to the count of smaller element for the key being inserted. We recursively follow the same approach for all nodes down the root.

Time Complexity: O(nLogn) 
Auxiliary Space: O(n)

Method 3 (Using BST with 2 extra fields) 
Another approach to solve the above problem would be to use a simple Binary Search Tree with 2 extra fields: 
1) to hold the elements on the left side of a node 
2) to store the frequency of element. 

In this approach, we traverse the input array from the ending to the begging and add the elements into the BST. 
While inserting the elements to the BST, we can compute the number of elements which are lesser elements simply by computing the sum of frequency of the element and the number of elements to the left side of current node, if we are moving to right side of the current node. 

Once we place an element in it’s correct position, we can return it’s this sum value
Time Complexity: O(nLogn) 
Auxiliary Space: O(n) */
#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
    int val;
    int count;
    node* left;
    node* right;
    node(int num1, int num2){
        this->val=num1;
        this->count=num2;
        this->left=this->right=NULL;
    }
};

//function to addnode and find the smaller element on the right side
int addNode(node*& root, int val, int countSmaller)
{
    if(root==NULL){
        root=new node(val,0);
        return countSmaller;
    }

    if(root->val < val){
        return root->count+addNode(root->right,val,countSmaller+1);
    }

    else{
        root->count++;
        return addNode(root->left,val,countSmaller);
    }
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int data[]={10,6,15,20,30,5,7};
    int size=sizeof(data)/sizeof(data[0]);
    int ans[size]={0};

    node* root=NULL;
    for(int i=size-1;i>=0;i--){
        ans[i]=addNode(root, data[i],0);
    }
    for(int i=0;i<size;i++)
        cout<<ans[i]<<"\t";
    cout<<endl;
    return 0;
}