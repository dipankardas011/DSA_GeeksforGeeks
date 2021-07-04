/*Print the path common to the two paths from the root to the two given nodes
Given a binary tree with distinct nodes(no two nodes have the same have data values). The problem is to print the path common to the two paths from the root to the two given nodes n1 and n2. If either of the nodes are not present then print “No Common Path”.

Examples:

Input :          1
               /   \
              2     3
             / \   /  \
            4   5  6   7
               /    \   
              8      9

          n1 = 4, n2 = 8

Output : 1->2
Path form root to n1:
1->2->4

Path form root to n2:
1->2->5->8

Common Path:
1->2
*/
#include <iostream>
#include <vector>

struct btree
{
    int data;
    btree *left, *right;
};

struct btree *newnode(int val)
{
    btree *t = new btree;
    t->data = val;
    t->left = t->right = NULL;
    return t;
}
// finds the path from *node to the val(distination)
bool PathFinder(struct btree *node, std::vector<int> &arr, int val)
{
    if (!node)
        return false;
    arr.push_back(node->data);
    if (node->data == val)
        return true;

    if ((node->left && PathFinder(node->left, arr, val)) ||
        (node->right && PathFinder(node->right, arr, val)))
        return true;

    // not found in both the child
    arr.pop_back();
    return false;
}

void CommonPathFinder(struct btree *root, int n1, int n2)
{
    if (!root)
    {
        std::cout << "empty tree\n";
        return;
    }
    std::vector<int> arr1;
    std::vector<int> arr2;
    if (!PathFinder(root, arr1, n1) || !PathFinder(root, arr2, n2))
    {
        std::cout << "one of the node is not present\n";
        return;
    }
    int i;
    std::cout<<"the common path: ";
    for (i = 0; i < arr1.size() && i < arr2.size(); i++)
    {
        if (arr1[i] != arr2[i])
        {
            std::cout << "\b\b   ";
            break;
        }
        std::cout << arr1[i] << "->";
    }
}

int main()
{
    struct btree *root = 0;
    root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);
    root->left->right->left = newnode(8);
    root->right->left->right = newnode(9);
    CommonPathFinder(root, 4, 8);
    return 0;
}