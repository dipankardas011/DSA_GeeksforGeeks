/*Print path from root to a given node in a binary tree
Given a binary tree with distinct nodes(no two nodes have the same have data values). The problem is to print the path from root to a given node x. If node x is not present then print “No Path”.

Examples:

Input :          1
               /   \
              2     3
             / \   /  \
            4   5  6   7

               x = 5

Output : 1->2->5
*/
#include <iostream>
#include <vector>
using namespace std;

struct btree{
    int data;
    btree *left, *right;
};

btree *root=0;

btree *create(int val){
    btree *t=new btree;
    t->data=val;
    t->left=t->right=0;
    return t;
}

bool FindXnode(struct btree *t,vector<int>& arr, int x)
{
    if(t==0) return false;
    arr.push_back(t->data);
    if(t->data==x)  return true;

    // using preorder concept
    // check if the child if the curent node is ==x
    if(FindXnode(t->left, arr, x)|| FindXnode(t->right,arr,x))
        return true;

    // if nether the child is == x then remove the parent node
    arr.pop_back();
    return false;
}

int main(){
    root=create(1);
    root->left=create(2);
    root->right=create(3);
    root->left->left=create(4);
    root->left->right=create(5);
    root->right->left=create(6);
    root->right->right=create(7);

    int x;
    cout<<"enter the node whose path is to be found: ";
    cin>>x;
    vector <int>arr;
    if(FindXnode(root, arr, x)){
        for(int i=0;i<arr.size(); i++)
            cout<<arr[i]<<"->";
        cout<<"\b\b    \n";
    }
    else    cout<<"no path\n";
    return 0;
}