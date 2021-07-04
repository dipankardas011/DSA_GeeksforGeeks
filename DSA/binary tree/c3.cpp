/*Linked complete binary tree & its creation
A complete binary tree is a binary tree where each level ‘l’ except the last has 2^l nodes and the nodes at the last level are all left-aligned. Complete binary trees are mainly used in heap-based data structures. 
The nodes in the complete binary tree are inserted from left to right in one level at a time. If a level is full, the node is inserted in a new level.
Below are some complete binary trees. 
 

       1
      / \
     2   3

        1
       / \
      2   3
     / \  / 
    4  5 6

Below binary trees are not complete:  
 

     1
    / \
   2   3
  /    /
  4   5

       1
      / \
     2   3
    / \  /
   4  5 6
  /
 7
Given parent index i, its left child is given by 2 * i + 1, and its right child is given by 2 * i + 2.
*/
//       same as c2.cpp