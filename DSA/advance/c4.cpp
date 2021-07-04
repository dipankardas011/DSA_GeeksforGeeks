/*K Dimensional Tree | Set 1 (Search and Insert)
Difficulty Level : Medium
Last Updated : 03 Nov, 2020
A K-D Tree(also called as K-Dimensional Tree) is a binary search tree where data in each node is a K-Dimensional point in space. In short, it is a space partitioning(details below) data structure for organizing points in a K-Dimensional space.

A non-leaf node in K-D tree divides the space into two parts, called as half-spaces.

Points to the left of this space are represented by the left subtree of that node and points to the right of the space are represented by the right subtree. We will soon be explaining the concept on how the space is divided and tree is formed.

For the sake of simplicity, let us understand a 2-D Tree with an example.

The root would have an x-aligned plane, the root’s children would both have y-aligned planes, the root’s grandchildren would all have x-aligned planes, and the root’s great-grandchildren would all have y-aligned planes and so on.



Generalization:
Let us number the planes as 0, 1, 2, …(K – 1). From the above example, it is quite clear that a point (node) at depth D will have A aligned plane where A is calculated as:

A = D mod K

How to determine if a point will lie in the left subtree or in right subtree?

If the root node is aligned in planeA, then the left subtree will contain all points whose coordinates in that plane are smaller than that of root node. Similarly, the right subtree will contain all points whose coordinates in that plane are greater-equal to that of root node.

Creation of a 2-D Tree:
Consider following points in a 2-D plane:
(3, 6), (17, 15), (13, 15), (6, 12), (9, 1), (2, 7), (10, 19)

Insert (3, 6): Since tree is empty, make it the root node.
Insert (17, 15): Compare it with root node point. Since root node is X-aligned, the X-coordinate value will be compared to determine if it lies in the rightsubtree or in the right subtree. This point will be Y-aligned.
Insert (13, 15): X-value of this point is greater than X-value of point in root node. So, this will lie in the right subtree of (3, 6). Again Compare Y-value of this point with the Y-value of point (17, 15) (Why?). Since, they are equal, this point will lie in the right subtree of (17, 15). This point will be X-aligned.
Insert (6, 12): X-value of this point is greater than X-value of point in root node. So, this will lie in the right subtree of (3, 6). Again Compare Y-value of this point with the Y-value of point (17, 15) (Why?). Since, 12 < 15, this point will lie in the left subtree of (17, 15). This point will be X-aligned.
Insert (9, 1):Similarly, this point will lie in the right of (6, 12).
Insert (2, 7):Similarly, this point will lie in the left of (3, 6).
Insert (10, 19): Similarly, this point will lie in the left of (13, 15).
ktree_1

How is space partitioned?
All 7 points will be plotted in the X-Y plane as follows:

Point (3, 6) will divide the space into two parts: Draw line X = 3.

Point (2, 7) will divide the space to the left of line X = 3 into two parts horizontally.
Draw line Y = 7 to the left of line X = 3.

Point (17, 15) will divide the space to the right of line X = 3 into two parts horizontally.
Draw line Y = 15 to the right of line X = 3.

 



Point (6, 12) will divide the space below line Y = 15 and to the right of line X = 3 into two parts.
Draw line X = 6 to the right of line X = 3 and below line Y = 15.

 

Point (13, 15) will divide the space below line Y = 15 and to the right of line X = 6 into two parts.
Draw line X = 13 to the right of line X = 6 and below line Y = 15.

Point (9, 1) will divide the space between lines X = 3, X = 6 and Y = 15 into two parts.
Draw line Y = 1 between lines X = 3 and X = 6.

Point (10, 19) will divide the space to the right of line X = 3 and above line Y = 15 into two parts.
Draw line Y = 19 to the right of line X = 3 and above line Y = 15.

*/
#include<bits/stdc++.h>
using namespace std;

#define K 2

struct node{
    int point[K];
    node *left, *right;
};

node *newNode(int arr[]){
    node *temp=new node;
    for(int i=0;i<K;i++)
        temp->point[i]=arr[i];
    temp->left=temp->right=0;
    return temp;
}

// insertion
node *insertRec(node *root, int point[], unsigned depth)
{
    if(!root)   return newNode(point);

    // calculate the dimension
    unsigned cd=depth%K;

    if(point[cd] < (root->point[cd]))
        root->left=insertRec(root->left,point,depth+1);
    else
        root->right=insertRec(root->right,point, depth+1);
    return root;
}

node *insert(node *root, int point[]) { return insertRec(root,point,0); }

bool arePointsSame(int point1[], int point2[]){
    for(int i=0;i<K;i++)
    if(point1[i]!=point2[i])
        return false;
    return true;
}

bool searchRec(node* root, int point[],unsigned depth)
{
    if(!root)   return false;
    if(arePointsSame(root->point,point))    return true;

    unsigned cd = depth%K;

    if(point[cd] < root->point[cd])
        return searchRec(root->left,point,depth+1);
    else
        return searchRec(root->right,point,depth+1);
}

bool search(node *root, int point[])
{ return searchRec(root,point, 0); }

int main(){
    node *root=NULL;
    int point[][K]={{3, 6}, {17, 15}, {13, 15}, {6, 12},
                       {9, 1}, {2, 7}, {10, 19}};
    int n=sizeof(point)/sizeof(point[0]);

    for(int i=0;i<n;i++)
        root=insert(root,point[i]);
    int point1[]={10,19};
    (search(root, point1))? cout << "Found\n": cout << "Not Found\n";
  
    int point2[] = {12, 19};
    (search(root, point2))? cout << "Found\n": cout << "Not Found\n";
    return 0;
}