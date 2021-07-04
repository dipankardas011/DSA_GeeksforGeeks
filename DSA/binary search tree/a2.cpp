/*
Convert a normal BST to Balanced BST
Given a BST (Binary Search Tree) that may be unbalanced, convert it into a balanced BST that has minimum possible height.
*/
#include <bits/stdc++.h>
using namespace std;

class btree
{
public:
    int data;
    btree *left, *right;
};

btree *create(int val)
{
    btree *t = new btree;
    t->data = val;
    t->left = t->right = NULL;
    return t;
}

void collect_node_elements(btree *r, vector<int> &arr)
{
    if (r)
    {
        collect_node_elements(r->left, arr);
        // data using inorder
        // it is in ascending order
        arr.push_back(r->data);
        collect_node_elements(r->right, arr);
    }
}

btree *buildTreeUtil(vector<int> &nodes, int start, int end)
{
    // base case
    if (start > end)
        return NULL;

    /* Get the middle element and make it root */
    int mid = (start + end) / 2;
    btree *root = create(nodes[mid]);

    /* Using index in Inorder traversal, construct
       left and right subtress */
    root->left = buildTreeUtil(nodes, start, mid - 1);
    root->right = buildTreeUtil(nodes, mid + 1, end);

    return root;
}

void inorder(btree *r)
{
    if (r)
    {
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }
}
btree *avlroot = 0;

void exec(btree *root, btree *avlroot)
{
    vector<int> vec;
    collect_node_elements(root, vec);
    avlroot = buildTreeUtil(vec, 0, (vec.size() - 1));
    inorder(avlroot);
    return;
}

int main()
{
    /*
            4
           /
          3
         /
        2
       /
      1
    d*/
    btree *root = 0;

    root = create(4);
    root->left = create(3);
    root->left->left = create(2);
    root->left->left->right = create(6);
    root->left->left->left = create(1);
    exec(root, avlroot);
    return 0;
}