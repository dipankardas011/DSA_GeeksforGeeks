/*Convert Ternary Expression to a Binary Tree
Given a string that contains ternary expressions. The expressions may be nested, task is convert the given ternary expression to a binary Tree.

Examples:

Input :  string expression =   a?b:c 
Output :        a
              /  \
             b    c

Input : expression =  a?b?c:d:e
Output :     a
           /  \
          b    e
        /  \
       c    d
Asked In : Facebook Interview
*/
// C++ program to convert a ternary expression to
// a tree.
#include <bits/stdc++.h>
using namespace std;

// tree structure
struct Node
{
    char data;
    Node *left, *right;
};

// function create a new node
Node *newNode(char Data)
{
    Node *new_node = new Node;
    new_node->data = Data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

// Function to convert Ternary Expression to a Binary
// Tree. It return the root of tree
//Notice that we pass index i by reference because we want to skip the characters in the subtree
Node *convertExpression(string str, int &i)
{
    // store current character of expression_string
    // [ 'a' to 'z']
    Node *root = newNode(str[i]);

    //If it was last character return
    //Base Case
    if (i == str.length() - 1)
        return root;

    // Move ahead in str
    i++;
    //If the next character is '?'.Then there will be subtree for the current node
    if (str[i] == '?')
    {
        //skip the '?'
        i++;

        //construct the left subtree
        //Notice after the below recursive call i will point to ':' just before the right child of current node since we pass i by reference
        root->left = convertExpression(str, i);

        //skip the ':' character
        i++;

        //construct the right subtree
        root->right = convertExpression(str, i);
        return root;
    }
    //If the next character is not '?' no subtree just return it
    else
        return root;
}

// function print tree
void printTree(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

// Driver program to test above function
int main()
{
    string expression = "a?b?c:d:e";
    int i = 0;
    Node *root = convertExpression(expression, i);
    printTree(root);
    return 0;
}