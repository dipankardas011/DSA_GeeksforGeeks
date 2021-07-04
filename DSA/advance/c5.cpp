/*K Dimensional Tree | Set 2 (Find Minimum)

We strongly recommend to refer below post as a prerequisite of this.

K Dimensional Tree | Set 1 (Search and Insert)

In this post find minimum is discussed. The operation is to find minimum in the given dimension. This is especially needed in delete operation.

For example, consider below KD Tree, if given dimension is x, then output should be 5 and if given dimensions is y, then output should be 12.
*/
#include <bits/stdc++.h>
using namespace std;

#define K 2

struct node
{
    int point[K];
    node *left, *right;
};

node *newNode(int arr[])
{
    node *temp = new node;
    for (int i = 0; i < K; i++)
        temp->point[i] = arr[i];
    temp->left = temp->right = 0;
    return temp;
}

// insertion
node *insertRec(node *root, int point[], unsigned depth)
{
    if (!root)
        return newNode(point);

    // calculate the dimension
    unsigned cd = depth % K;

    if (point[cd] < (root->point[cd]))
        root->left = insertRec(root->left, point, depth + 1);
    else
        root->right = insertRec(root->right, point, depth + 1);
    return root;
}

node *insert(node *root, int point[]) { return insertRec(root, point, 0); }

bool arePointsSame(int point1[], int point2[])
{
    for (int i = 0; i < K; i++)
        if (point1[i] != point2[i])
            return false;
    return true;
}

bool searchRec(node *root, int point[], unsigned depth)
{
    if (!root)
        return false;
    if (arePointsSame(root->point, point))
        return true;

    unsigned cd = depth % K;

    if (point[cd] < root->point[cd])
        return searchRec(root->left, point, depth + 1);
    else
        return searchRec(root->right, point, depth + 1);
}

bool search(node *root, int point[])
{
    return searchRec(root, point, 0);
}

int min(int x, int y, int z)
{
    return min(x, min(y, z));
}

// Recursively finds minimum of d'th dimension in KD tree
// The parameter depth is used to determine current axis.
int findMinRec(node *root, int d, unsigned depth)
{
    // Base cases
    if (root == NULL)
        return INT_MAX;

    // Current dimension is computed using current depth and total
    // dimensions (k)
    unsigned cd = depth % K;

    // Compare point with root with respect to cd (Current dimension)
    if (cd == d)
    {
        if (root->left == NULL)
            return root->point[d];
        return min(root->point[d], findMinRec(root->left, d, depth + 1));
    }

    // If current dimension is different then minimum can be anywhere
    // in this subtree
    return min(root->point[d],
               findMinRec(root->left, d, depth + 1),
               findMinRec(root->right, d, depth + 1));
}

// A wrapper over findMinRec(). Returns minimum of d'th dimension
int findMin(node *root, int d)
{
    // Pass current level or depth as 0
    return findMinRec(root, d, 0);
}

int main()
{
    node *root = NULL;
    int points[][K] = {{30, 40}, {5, 25}, {70, 70}, {10, 12}, {50, 30}, {35, 45}};

    int n = sizeof(points) / sizeof(points[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, points[i]);

    cout << "Minimum of 0'th dimension is " << findMin(root, 0) << endl;
    cout << "Minimum of 1'th dimension is " << findMin(root, 1) << endl;

    return 0;
}