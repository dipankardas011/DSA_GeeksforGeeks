/*Creating a tree with Left-Child Right-Sibling Representation
Difficulty Level : Medium
Last Updated : 18 May, 2021
Left-Child Right-Sibling Representation is a different representation of an n-ary tree where instead of holding a reference to each and every child node, a node holds just two references, first a reference to its first child, and the other to its immediate next sibling. This new transformation not only removes the need for advanced knowledge of the number of children a node has but also limits the number of references to a maximum of two, thereby making it so much easier to code. 

At each node, link children of same parent from left to right.
Parent should be linked with only first child.
Examples: 

Left Child Right Sibling tree representation
      10
      |  
      2 -> 3 -> 4 -> 5
      |    |  
      6    7 -> 8 -> 9*/
#include <iostream>
#include <queue>
using namespace std;

struct node{
    int data;
    node *next, *child;
};

node *newNode(int d){
    node *n=new node;
    n->data=d;
    n->next=n->child=NULL;
    return n;
}

node *addSibling(node *n, int data)
{
    if(n==NULL) return NULL;

    while(n->next){
        n=n->next;
    }

    return (n->next=newNode(data));
}

node *addChild(node *n, int data)
{
    if(n==NULL) return NULL;

    if(n->child)
        return addSibling(n->child,data);
    else
        return (n->child=newNode(data));
}

void traverseTree(node *root){
    if(root==NULL)  return ;

    while(root){
        cout<<" "<<root->data;
        if(root->child)
            traverseTree(root->child);
        root=root->next;
    }
}
// Traverses tree in level order
void traverseTree1(node* root)
{
    // Corner cases
    if (root == NULL)
        return;
 
    cout << root->data << " ";
 
    if (root->child == NULL)
        return;
 
    // Create a queue and enque root
    queue<node*> q;
    node* curr = root->child;
    q.push(curr);

    while (!q.empty()) {
 
        // Take out an item from the queue
        curr = q.front();
        q.pop();
 
        // Print next level of taken out item and enque
        // next level's children
        while (curr != NULL) {
            cout << curr->data << " ";
            if (curr->child != NULL) {
                q.push(curr->child);
            }
            curr = curr->next;
        }
    }
}

int main(void){
    /*   Let us create below tree
    *         10
    *     / / \   \
    *    2 3  4    5
    *         |   /  | \
    *         6   7  8  9   */
 
    // Left child right sibling
    /*  10
    *    |
    *    2 -> 3 -> 4 -> 5
    *              |    |
    *              6    7 -> 8 -> 9  */
    node *root = newNode(10);
    node *n1  = addChild(root, 2);
    node *n2  = addChild(root, 3);
    node *n3  = addChild(root, 4);
    node *n4  = addChild(n3, 6);
    node *n5  = addChild(root, 5);
    node *n6  = addChild(n5, 7);
    node *n7  = addChild(n5, 8);
    node *n8  = addChild(n5, 9);
    traverseTree(root);
    cout<<"the level order traversal"<<endl;
    traverseTree1(root);
    return 0;
}