/*Find distance between two nodes of a Binary Tree
Find the distance between two keys in a binary tree, no parent pointers are given. 
The distance between two nodes is the minimum number of edges to be traversed 
to reach one node from another.
*/
// Dist(n1, n2) = Dist(root, n1) + Dist(root, n2) - 2*Dist(root, lca)
// 'n1' and 'n2' are the two given keys
// 'root' is root of given Binary Tree.
// 'lca' is lowest common ancestor of n1 and n2
// Dist(n1, n2) is the distance between n1 and n2.
#include <iostream>
#include <vector>
using namespace std;
struct btree
{
    int data;
    struct btree *left, *right;
};

btree *newnode(int val)
{
    btree *t = new btree;
    t->data = val;
    t->left = t->right = NULL;
    return t;
}

int distance(btree *t, int key)
{
    if (!t)
        return -1;
    int dis = -1;
    if ((t->data == key) ||
        ((dis = distance(t->left, key)) >= 0 ||
         (dis = distance(t->right, key)) >= 0))
        return dis + 1;
    return dis;
}

bool findpath(struct btree *t, vector<int> &arr, int key)
{
    if (!t)
        return false;
    arr.push_back(t->data);
    if (t->data == key)
        return true;
    if ((t->left && findpath(t->left, arr, key)) || (t->right && findpath(t->right, arr, key)))
        return true;

    // not found
    arr.pop_back();
    return false;
}

int findLCA(struct btree *root, int n1, int n2)
{
    if (!root)
        return -1;
    vector<int> arr1;
    vector<int> arr2;
    int i = 0;
    if (!findpath(root, arr1, n1) || !findpath(root, arr2, n2))
    {
        // if anyone key is not present then we cannot find
        return -1;
    }
    for (i = 0; i < arr1.size() && i < arr2.size(); i++)
    {
        if (arr1[i] != arr2[i])
            break;
    }
    return arr1[i - 1];
}

void CalculateDisof_2_Nodes(btree *root, int n1, int n2)
{
    int lca = findLCA(root, n1, n2);
    int dis = distance(root, n1) +
              distance(root, n2) -
              2 * distance(root, lca);

    cout << "the distance b/w (" << n1 << ", " << n2 << ") = " << dis << endl;
}

int main()
{
    /*
             1
           /  \
          2    3
         / \  / \
        4  5 6  7
              \
              8
    */
    btree *root = NULL;
    root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);
    root->right->left->right = newnode(8);
    CalculateDisof_2_Nodes(root, 4, 5);
    CalculateDisof_2_Nodes(root, 4, 6);
    CalculateDisof_2_Nodes(root, 3, 4);
    CalculateDisof_2_Nodes(root, 2, 4);
    CalculateDisof_2_Nodes(root, 8, 5);
    return 0;
}