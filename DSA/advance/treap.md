# Treap | Set 2 (Implementation of Search, Insert and Delete)

We strongly recommend to refer set 1 as a prerequisite of this post.

Treap (A Randomized Binary Search Tree)

In this post, implementations of search, insert and delete are discussed.

Search:
Same as standard BST search. Priority is not considered for search.

```cpp
// C function to search a given key in a given BST
TreapNode* search(TreapNode* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
       return root;
      
    // Key is greater than root's key
    if (root->key < key)
       return search(root->right, key);
   
    // Key is smaller than root's key
    return search(root->left, key);
}
```

`Insert`
1) Create new node with key equals to x and value equals to a random value.



2) Perform standard BST insert.

3) A newly inserted node gets a random priority, so Max-Heap property may be violated.. Use rotations to make sure that inserted node’s priority follows max heap property.

During insertion, we recursively traverse all ancestors of the inserted node.
a) If new node is inserted in left subtree and root of left subtree has higher priority, perform right rotation.

b) If new node is inserted in right subtree and root of right subtree has higher priority, perform left rotation.

```Cpp
/* Recursive implementation of insertion in Treap */
TreapNode* insert(TreapNode* root, int key)
{
    // If root is NULL, create a new node and return it
    if (!root)
        return newNode(key);
  
    // If key is smaller than root
    if (key <= root->key)
    {
        // Insert in left subtree
        root->left = insert(root->left, key);
  
        // Fix Heap property if it is violated
        if (root->left->priority > root->priority)
            root = rightRotate(root);
    }
    else  // If key is greater
    {
        // Insert in right subtree
        root->right = insert(root->right, key);
  
        // Fix Heap property if it is violated
        if (root->right->priority > root->priority)
            root = leftRotate(root);
    }
    return root;
}
```
`Delete:`
The delete implementation here is slightly different from the steps discussed in previous post.
1) If node is a leaf, delete it.
2) If node has one child NULL and other as non-NULL, replace node with the non-empty child.
3) If node has both children as non-NULL, find max of left and right children.
    a) If priority of right child is greater, perform left rotation at node
    b) If priority of left child is greater, perform right rotation at node.

The idea of step 3 is to move the node to down so that we end up with either case 1 or case 2.

```Cpp
/* Recursive implementation of Delete() */
TreapNode* deleteNode(TreapNode* root, int key)
{
    // Base case
    if (root == NULL) return root;
  
    // IF KEYS IS NOT AT ROOT
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
  
    // IF KEY IS AT ROOT
  
    // If left is NULL
    else if (root->left == NULL)
    {
        TreapNode *temp = root->right;
        delete(root);
        root = temp;  // Make right child as root
    }
  
    // If Right is NULL
    else if (root->right == NULL)
    {
        TreapNode *temp = root->left;
        delete(root);
        root = temp;  // Make left child as root
    }
  
    // If ksy is at root and both left and right are not NULL
    else if (root->left->priority < root->right->priority)
    {
        root = leftRotate(root);
        root->left = deleteNode(root->left, key);
    }
    else
    {
        root = rightRotate(root);
        root->right = deleteNode(root->right, key);
    }
  
    return root;
}
```