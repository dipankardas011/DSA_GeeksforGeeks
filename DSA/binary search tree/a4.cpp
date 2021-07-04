/*Construct BST from given preorder traversal | Set 1
Given preorder traversal of a binary search tree, construct the BST.

For example, if the given traversal is {10, 5, 1, 7, 40, 50}, then the output should be the root of the following tree.

     10
   /   \
  5     40
 /  \      \
1    7      50
*/
#include <bits/stdc++.h>


class node
{
    public:
    int data;
    node *left, *right;
};

node *create(int val)
{
    node *t=new node;
    t->data=val;
    t->left=t->right=0;
    return t;
}
/*The first element of preorder traversal is always root. 
We first construct the root.
Then we find the index of first element which is greater than root. 
Let the index be ‘i’.
The values between root and ‘i’ will be part of left subtree, and 
the values between ‘i+1’ and ‘n-1’ will be part of right subtree.
Divide given pre[] at index “i” and recur for left and right sub-trees.*/
node *insert(int arr[], int& index, int low, int high, int len)
{
    if(index>=len || low>high)  return NULL;

    node *k=create(arr[index]);
    index++;

    if(low==high)   return k;
    int i;
    for(i=low;i<=high;i++)  if(arr[i] > k->data)    break;

    k->left=insert(arr, index, index, i-1,len);
    k->right=insert(arr, index, i, high, len);
    return k;
}

node *build_tree(int pre[], int N)
{
    int index=0;

    return insert(pre, index, 0, N-1, N);
}

void inorder(node *n)
{
    if(n)
    {
        inorder(n->left);
        std::cout<<n->data<<" ";
        inorder(n->right);
    }
}

int main()
{
    int pre[]={10,5,1,7,40,50};
    int size=sizeof(pre)/sizeof(pre[0]);
    node *root=build_tree(pre, size);
    inorder(root);
    return 0;
}