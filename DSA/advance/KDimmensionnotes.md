# K-dimensional tree 
it is a binary search tree where the data in each node is a K dimensional point in space in short it is a space partitioning data structure for organizing points in a K dimensional space . 

* a non leave not in K dimensional three divides the space into two parts called as half spaces

* Point to the left of this space are represented to as `left subtree` of that node and points to the right of the space are represented by the `right subtree`

example
K=2
(3,6), (17,15),(13,15),(6,12),(9,1),(2,7),(10,19)

![the youtubelink](https://www.youtube.com/watch?v=2Gul_-cbWM0&t=68s)

if we have to insert the (13,15)
in 
X-- (3,6)
        \
        (17,15) --Y
first we compare 13 with the x of first 3
13 > 3:
    right side
    then compare with the Y of second
    15>=15:
     so right side
     so after all this

X-- (3,6)                               (X level)
    /    \
(2,7)    (17,15) --Y                     (Y level)
         /    \
      (6,12)  (13,15) --X               (X level)
        \          /
   Y--  (9,1)   (10,19)                    (Y level)
                            ......
alternating comparing
```C++
    const int k=2;
    struct node{
        int point[k];
        node* left, *right;
    };
```
```C++
struct node* newNode(int arr[]){
    struct node* temp=new node;
    for(int i=0;i<k;i++)
        temp->point[i]=arr[i];
    temp->left=temp->right=NULL;
    return temp;
}

```
finding the current dimension of comparison by
curr_dim = depth%k

let 0 denote X and 1 denote Y

(3,6) depth 0 curr_dim =0
(17,5) depth 1 curr_dim =1
(6,12) depth 2 curr_dim =0
(9,1) depth 3 curr_dim =1


# K Dimensional Tree | Set 3 (Delete)

We strongly recommend to refer below posts as a prerequisite of this.

K Dimensional Tree | Set 1 (Search and Insert)
K Dimensional Tree | Set 2 (Find Minimum)

In this post delete is discussed. The operation is to delete a given point from K D Tree.

Like Binary Search Tree Delete, we recursively traverse down and search for the point to be deleted. Below are steps are followed for every node visited.

1) If current node contains the point to be deleted



If node to be deleted is a leaf node, simply delete it (Same as BST Delete)
If node to be deleted has right child as not NULL (Different from BST)
Find minimum of current node’s dimension in right subtree.
Replace the node with above found minimum and recursively delete minimum in right subtree.
Else If node to be deleted has left child as not NULL (Different from BST)
Find minimum of current node’s dimension in left subtree.
Replace the node with above found minimum and recursively delete minimum in left subtree.
Make new left subtree as right child of current node.
2) If current doesn’t contain the point to be deleted

If node to be deleted is smaller than current node on current dimension, recur for left subtree.
Else recur for right subtree.
Why 1.b and 1.c are different from BST?
In BST delete, if a node’s left child is empty and right is not empty, we replace the node with right child. In K D Tree, doing this would violate the KD tree property as dimension of right child of node is different from node’s dimension. For example, if node divides point by x axis values. then its children divide by y axis, so we can’t simply replace node with right child. Same is true for the case when right child is not empty and left child is empty.

Why 1.c doesn’t find max in left subtree and recur for max like 1.b?
Doing this violates the property that all equal values are in right subtree. For example, if we delete (!0, 10) in below subtree and replace if with

Wrong Way (Equal key in left subtree after deletion)
            (5, 6)                             (4, 10)
             /              Delete(5, 6)         /  
        (4, 10)            ------------>     (4, 20)
             \
           (4, 20) 

Right way (Equal key in right subtree after deletion)
             (5, 6)                          (4, 10)
             /              Delete(5, 6)           \
         (4, 10)            ------------>         (4, 20)
              \
             (4, 20) 


Example of Delete:
Delete (30, 40): Since right child is not NULL and dimension of node is x, we find the node with minimum x value in right child. The node is (35, 45), we replace (30, 40) with (35, 45) and delete (30, 40).

![kdtreedelete2](https://media.geeksforgeeks.org/wp-content/uploads/K-Dimensional-Tree.png)

Delete (70, 70): Dimension of node is y. Since right child is NULL, we find the node with minimum y value in left child. The node is (50, 30), we replace (70, 70) with (50, 30) and recursively delete (50, 30) in left subtree. Finally we make the modified left subtree as right subtree of (50, 30).
![kdtreedelete](https://media.geeksforgeeks.org/wp-content/uploads/K-Dimensional-Tree-1.png)

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX