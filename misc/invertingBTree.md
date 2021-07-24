# Recursive method

```cpp
// Function to invert given binary Tree using preorder traversal
void invertBinaryTree(TreeNode root)
{
    // base case: if tree is empty
    if (root == Null)
        return
    // swap left subtree with right subtree
    swap(root.left, root.right)
    // invert left subtree
    invertBinaryTree(root.left)
    // invert right subtree
    invertBinaryTree(root.right)
}
```
> time Complexity: O(n)
> space Complexity: O(h)

# Iterative method

```cpp
// Iterative Function to invert given binary Tree using stack
void invertBinaryTree(TreeNode root) 
{
    // base case: if tree is empty
    if (root is null) 
        return
    // create an empty stack and push root node
    stack S
    S.push(root)
    // iterate until the stack is not empty
    while (S is not empty)
    {
        // pop top node from stack
        TreeNode curr = S.top()
        S.pop()
        // swap left child with right child
        swap(curr.left, curr.right)
        // push right child of popped node to the stack
        if (curr.right)
            S.push(curr.right)
        // push left child of popped node to the stack
        if (curr.left)
            S.push(curr.left)
    }
}
```

> time Complexity: O(n)
> space Complexity: O(h)

#  Using Level order traversal
We can solve this problem using Level Order Traversal. Here we the traverse the tree using a FIFO Queue.

```cpp
// Iterative Function to invert given binary Tree using queue
void invertBinaryTree(TreeNode root) 
{
    // base case: if tree is empty
    if (root is NULL) 
        return
    // maintain a queue and push push root node
    queue Q
    Q.enqueue(root)
    // iterate untill queue is not empty
    while (Q is not empty) 
    {
        // pop top node from queue
        TreeNode curr = Q.dequeue()
        // swap left child with right child
        swap(curr.left, curr.right)
        // push left child of popped node to the queue
        if (curr.left)
            Q.enqueue(curr.left)
        // push right child of popped node to the queue
        if (curr.right)
            Q.enqueue(curr.right)
    }
}
```

> time Complexity: O(n)
> space Complexity: O(h)