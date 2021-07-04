/*Sorted Linked List to Balanced BST
Given a Singly Linked List which has data members sorted in ascending order. 
Construct a Balanced Binary Search Tree which has same data members as the given Linked List.
Examples:

Input:  Linked List 1->2->3
Output: A Balanced BST 
     2   
   /  \  
  1    3 


Input: Linked List 1->2->3->4->5->6->7
Output: A Balanced BST
        4
      /   \
     2     6
   /  \   / \
  1   3  5   7

Input: Linked List 1->2->3->4
Output: A Balanced BST
      3   
    /  \  
   2    4 
 / 
1

Input:  Linked List 1->2->3->4->5->6
Output: A Balanced BST
      4   
    /   \  
   2     6 
 /  \   / 
1   3  5 
ded*/
#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node *left, *right;
};

class linkl
{
    public:
    int data;
    linkl *next;
};

node *createtree(int val)
{
    node *t=new node;
    t->data=val;
    t->left=t->right=0;
    return t;
}
linkl *createlist(int val)
{
    linkl *t=new linkl;
    t->data=val;
    t->next=NULL;
    return t;
}

node *root=NULL;
linkl *head=NULL;

void given_link_list()
{
    head=createlist(1);
    head->next=createlist(2);
    head->next->next=createlist(3);
    head->next->next->next=createlist(4);
    head->next->next->next->next=createlist(5);
    head->next->next->next->next->next=createlist(6);
    head->next->next->next->next->next->next=createlist(7);
}

void get_data(vector<int>& arr, linkl *base)
{
    linkl *iter=base;
    while(iter)
    {
        arr.push_back(iter->data);
        iter=iter->next;
    }
}

node *build_tree(vector<int>& arr, int start, int end)
{
    if(start > end) return NULL;

    int mid = (start+end)/2;
    node *newnode=createtree(arr[mid]);

    newnode->left = build_tree(arr, start, mid-1);
    newnode->right = build_tree(arr, mid+1, end);

    return newnode;
}

void preorder(node *n)
{
    if(n)
    {
        std::cout<<n->data<<" ";
        preorder(n->left);
        preorder(n->right);
    }
}

void exec()
{
    vector<int> vec;
    get_data(vec, head);
    
    root = build_tree(vec, 0, vec.size()-1);
    preorder(root);
}

//driver
int main()
{
    given_link_list();// created the linklist
    // get the data from the linklist and store it in vect
    // then make the tree
    exec();
    return 0;
}