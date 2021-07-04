/*Lowest Common Ancestor in a Binary Tree | Set 1
Given a binary tree (not a binary search tree) and two values say n1 and n2, write a program to find the least common ancestor.

Following is definition of LCA from Wikipedia: 
Let T be a rooted tree. 
The lowest common ancestor between two nodes n1 and n2 is defined as 
the lowest node in T that has both n1 and n2 as descendants 
(where we allow a node to be a descendant of itself).
The LCA of n1 and n2 in T is the shared ancestor of n1 and n2 
that is located farthest from the root. 
Computation of lowest common ancestors may be useful, for instance, 
as part of a procedure for determining the distance between pairs of nodes in a tree: 

the distance from n1 to n2 can be computed as the 
distance from the root to n1, plus 
the distance from the root to n2, minus 
twice the distance from the root to their lowest common ancestor

         1
       /  \
      2    3
     / \  / \
    4  5 6  7 

eg
LCA(4,5) = 2
LCA(4,6) = 1
LCA(3,4) = 1
LCA(2,4) = 2
*/
#include <iostream>
#include <vector>

using namespace std;
struct btree{
    int data;
    btree *left, *right;
};

btree *root=NULL;

struct btree *newNode(int val){
    btree *t=new btree;
    t->data=val;
    t->left=t->right=NULL;
    return t;
}

bool findpath(struct btree *t, vector<int>& arr, int key){
    if(!t) return false;
    arr.push_back(t->data);
    if(t->data==key)    return true;
    if((t->left && findpath(t->left,arr,key)) || (t->right && findpath(t->right,arr, key)))
        return true;
    
    // not found
    arr.pop_back();
    return false;
}

int findLCA(struct btree *root, int n1, int n2){
    if(!root)   return -1;
    vector<int>arr1;
    vector<int>arr2;
    int i=0;
    if(!findpath(root,arr1,n1) || !findpath(root,arr2,n2)){
        return -1;
    }
    for (i = 0; i < arr1.size() && i < arr2.size(); i++)
    {
        if (arr1[i] != arr2[i])
            break;
    }
    return arr1[i-1];
}

int main(){
    root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    cout<<"The Least Common Ancessor(4,5)= "<<findLCA(root,4,5)<<endl;
    cout<<"The Least Common Ancessor(4,6)= "<<findLCA(root,4,6)<<endl;
    cout<<"The Least Common Ancessor(3,4)= "<<findLCA(root,3,4)<<endl;
    cout<<"The Least Common Ancessor(2,4)= "<<findLCA(root,2,4)<<endl;
    return 0;
}