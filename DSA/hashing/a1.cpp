// Print a Binary Tree in Vertical Order | Set 2 (Map based Method)
// Given a binary tree, print it vertically. The following example illustrates the vertical order traversal.
//             1
//          /    \ 
//         2      3
//       / \   /   \
//       4   5  6   7
//                 /  \ 
//                8   9

// The output of print this tree vertically will be:
// 4
// 2
// 1 5 6
// 3 8
// 7
// 9

#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct a1
{
    int key;
    a1 *left, *right;
};

a1 *create(int key)
{
    a1 *t = new a1;
    t->key = key;
    t->left = t->right = 0;
    return t;
}
// Utility function to store vertical order in map 'm'
// 'hd' is horigontal distance of current node from root.
// 'hd' is initially passed as 0
void getverticalorder(a1 *root, int hd, map<int, vector<int>> &m)
{
    if (!root)
        return;
    // preorder root, left, right
    m[hd].push_back(root->key);
    getverticalorder(root->left, hd - 1, m);
    getverticalorder(root->right, hd + 1, m);
}

void printvertical(a1 *root)
{
    map<int, vector<int>> m;
    int hd = 0;
    getverticalorder(root, hd, m);

    map<int, vector<int>>::iterator it;
    for(it = m.begin(); it!=m.end(); it++)
    {
        for(int i=0;i<it->second.size();++i)
            cout<<it->second[i]<<" ";
        cout<<endl;
    }
}

int main() {
    a1 *root=create(1);
    root->left=create(2);
    root->right=create(3);
    root->left->left=create(4);
    root->left->right=create(5);
    root->right->left=create(6);
    root->right->right=create(7);
    root->right->left->right=create(8);
    root->right->right->right=create(9);
    printvertical(root);
    return 0;
}