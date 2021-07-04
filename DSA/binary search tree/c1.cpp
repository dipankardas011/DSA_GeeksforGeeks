/*Threaded Binary Tree
Inorder traversal of a Binary tree can either be done using recursion or with the use of a auxiliary stack. The idea of threaded binary trees is to make inorder traversal faster and do it without stack and without recursion. A binary tree is made threaded by making all right child pointers that would normally be NULL point to the inorder successor of the node (if it exists).
There are two types of threaded binary trees. 
Single Threaded: Where a NULL right pointers is made to point to the inorder successor (if successor exists)
Double Threaded: Where both left and right NULL pointers are made to point to inorder predecessor and inorder successor respectively. The predecessor threads are useful for reverse inorder traversal and postorder traversal.
The threads are also useful for fast accessing ancestors of a node.
Following diagram shows an example Single Threaded Binary Tree. The dotted lines represent threads. 

tree
{
	int data;
	tree *left, *right;
	bool rightThread;
}

Since right pointer is used for two purposes, the boolean variable rightThread is used to indicate whether right pointer points to right child or inorder successor. 
Similarly, we can add leftThread for a double threaded binary tree.


// Utility function to find leftmost node in a tree rooted
// with n
Node leftMost(Node n)
{
	if (n == null)
		return null;

	while (n.left != null)
		n = n.left;

	return n;
}

// C code to do inorder traversal in a threaded binary tree
static void inOrder(Node root)
{
	Node cur = leftMost(root);
	while (cur != null) {
		System.out.printf("%d ", cur.data);

		// If this node is a thread node, then go to
		// inorder successor
		if (cur.rightThread)
			cur = cur.right;
		else // Else go to the leftmost child in right
			// subtree
			cur = leftmost(cur.right);
	}
}

*/
// Like standard BST insert, we search for the key value in the tree. If key is already present, then we return otherwise the 
// new key is inserted at the point where search terminates. 
// In BST, search terminates either when we find the key or when we reach a NULL left or right pointer. 
// Here all left and right NULL pointers are replaced by threads except left pointer of first node and right pointer of last node. 
// So here search will be unsuccessful when we reach a NULL pointer or a thread.

#include <bits/stdc++.h>

using namespace std;

struct tree {
	int data;
	tree *left, *right;

	bool lthread;// True if left pointer points to predecessor
    // in Inorder Traversal
	bool rthread;// True if right pointer points to successor
    // in Inorder Traversal
};

tree *insert (tree *root, int key) 
{
	tree *ptr=root;
	tree *parent=NULL;

	while (ptr) 
	{
		if(key == root->data) 
		{
			cout<<"duplicate key\n";
			return root;
		}
		parent = ptr;

		if (key < ptr->data)
		{
			if (ptr->lthread == false)
				ptr = ptr->left;
			else
				break;
		}

		else 
		{
			if (ptr->rthread == false) {
				ptr = ptr->right;
			}
			else	
				break;
		}
	}

	tree *temp = new tree;

	temp->data = key;
	temp->lthread = true;
	temp->rthread = true;

	if(parent == NULL) 
	{
		root = temp;
		temp->left = temp->right = NULL;
	}
	else if (key < parent->data) 
	{
		// left child
		temp->left = parent->left;
		temp->right = parent;
		parent->lthread = false;
		parent->left = temp;
	}
	else 
	{
		// right child
		temp->left = parent;
		temp->right = parent->right;
		parent->rthread = false;
		parent->right = temp;
	}
	return root;
}

tree *inorderSuccessor (tree *ptr)
{
	if(ptr->rthread == true)	return ptr->right;

	ptr = ptr->right;// left most child in right subtree
	while (ptr->lthread == false)
		ptr = ptr->left;
	return ptr;
}

void inorder(tree *root)
{
	if(!root)
		cout<<"tree is empty\n";
	
	tree *ptr=root;
	while (ptr->lthread == false)
		ptr = ptr->left;

	while (ptr != NULL) {
		cout<<ptr->data<<" ";
		ptr=inorderSuccessor(ptr);
	}
}

tree *inorderPredessor(tree *ptr) {

	if (ptr->lthread == true)	return ptr->left;

	ptr = ptr->left;
	while (ptr->rthread == false)
		ptr=ptr->right;
	return ptr;
}

// Here 'par' is pointer to parent Node and 'ptr' is
// pointer to current Node.
tree* caseA(tree* root, tree* par,
                   tree* ptr)
{
    // If Node to be deleted is root
    if (par == NULL)
        root = NULL;
 
    // If Node to be deleted is left
    // of its parent
    else if (ptr == par->left) {
        par->lthread = true;
        par->left = ptr->left;
    }
    else {
        par->rthread = true;
        par->right = ptr->right;
    }
 
    // Free memory and return new root
    free(ptr);
    return root;
}
 
// Here 'par' is pointer to parent Node and 'ptr' is
// pointer to current Node.
tree* caseB(tree* root, tree* par,
                   tree* ptr)
{
    tree* child;
 
    // Initialize child Node to be deleted has
    // left child.
    if (ptr->lthread == false)
        child = ptr->left;
 
    // Node to be deleted has right child.
    else
        child = ptr->right;
 
    // Node to be deleted is root Node.
    if (par == NULL)
        root = child;
 
    // Node is left child of its parent.
    else if (ptr == par->left)
        par->left = child;
    else
        par->right = child;
 
    // Find successor and predecessor
    tree* s = inorderSuccessor(ptr);
    tree* p = inorderPredessor(ptr);
 
    // If ptr has left subtree.
    if (ptr->lthread == false)
        p->right = s;
 
    // If ptr has right subtree.
    else {
        if (ptr->rthread == false)
            s->left = p;
    }
 
    free(ptr);
    return root;
}
 
// Here 'par' is pointer to parent Node and 'ptr' is
// pointer to current Node.
tree* caseC(tree* root, tree* par,
                   tree* ptr)
{
    // Find inorder successor and its parent.
    tree* parsucc = ptr;
    tree* succ = ptr->right;
 
    // Find leftmost child of successor
    while (succ->lthread==false) {
        parsucc = succ;
        succ = succ->left;
    }
 
    ptr->data = succ->data;
 
    if (succ->lthread == true && succ->rthread == true)
        root = caseA(root, parsucc, succ);
    else
        root = caseB(root, parsucc, succ);
 
    return root;
}
 
// Deletes a key from threaded BST with given root and
// returns new root of BST.
tree* delThreadedBST(tree* root, int dkey)
{
    // Initialize parent as NULL and ptrent
    // Node as root.
    tree *par = NULL, *ptr = root;
 
    // Set true if key is found
    int found = 0;
 
    // Search key in BST : find Node and its
    // parent.
    while (ptr != NULL) {
        if (dkey == ptr->data) {
            found = 1;
            break;
        }
        par = ptr;
        if (dkey < ptr->data) {
            if (ptr->lthread == false)
                ptr = ptr->left;
            else
                break;
        }
        else {
            if (ptr->rthread == false)
                ptr = ptr->right;
            else
                break;
        }
    }
 
    if (found == 0)
        printf("dkey not present in tree\n");
 
    // Two Children
    else if (ptr->lthread == false && ptr->rthread == false)
        root = caseC(root, par, ptr);
 
    // Only Left Child
    else if (ptr->lthread == false)
        root = caseB(root, par, ptr);
 
    // Only Right Child
    else if (ptr->rthread == false)
        root = caseB(root, par, ptr);
 
    // No child
    else
        root = caseA(root, par, ptr);
 
    return root;
}

int main()
{
    tree *root = NULL;
 
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 16);
    root = insert(root, 14);
    root = insert(root, 17);
    root = insert(root, 13);
 
    inorder(root);
	root = delThreadedBST(root, 20);
	cout<<"\nnew inorder\n";
    inorder(root);
	cout<<"\n";
    return 0;
}