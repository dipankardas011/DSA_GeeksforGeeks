/*Print Postorder traversal from given Inorder and Preorder traversals
Given Inorder and Preorder traversals of a binary tree, 
print Postorder traversal.

Example:

Input:
Inorder traversal in[] = {4, 2, 5, 1, 3, 6}
Preorder traversal pre[] = {1, 2, 4, 5, 3, 6}
                hash_pre[]={3, 1, 0, 2, 4, 5} // made

Output:
Postorder traversal is {4, 5, 2, 6, 3, 1}
Traversals in the above example represents following tree 

         1
      /    \    
     2       3
   /   \      \
  4     5      6

*/

#include <iostream>
#include <map>
using namespace std;
int preIndex = 0;
void printPost(int in[], int pre[], int start, int end, map<int, int> hm)
{
    if (start > end)
        return;
    int in_index = hm[pre[preIndex++]];
    printPost(in, pre, start, in_index - 1, hm);
    printPost(in, pre, in_index + 1, end, hm);
    cout << in[in_index] << " ";
}

void printpostmain(int in[], int pre[], int n)
{
    map<int, int> hm;
    for (int i = 0; i < n; i++)
        hm[in[i]] = i;

    printPost(in, pre, 0, n - 1, hm);
}

int main()
{
    int in[] = {4, 2, 5, 1, 3, 6};
    int pre[] = {1, 2, 4, 5, 3, 6};
    printpostmain(in, pre, sizeof(pre) / sizeof(pre[0]));
    return 0;
}