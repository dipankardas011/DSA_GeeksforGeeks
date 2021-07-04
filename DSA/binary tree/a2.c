/*AVL with duplicate keys

Please refer below post before reading about AVL tree handling of duplicates.

How to handle duplicates in Binary Search Tree?
This is to augment AVL tree node to store count together with regular fields 
like key, left and right pointers.
Insertion of keys 12, 10, 20, 9, 11, 10, 12, 12 in an empty Binary Search Tree 
would create following.

          12(3)
       /        \
     10(2)      20(1)
    /    \       
 9(1)   11(1)   
Count of a key is shown in bracket

Below is implementation of normal AVL Tree with count with every key. 
This code basically is taken from code for insert and delete in AVL tree. 
The changes made for handling duplicates are highlighted, rest of the code is same.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct link{
    int data;
    struct link *left, *right;
    int counter;
}avlbtree;

avlbtree *root=NULL;

avlbtree *create(int val){
    avlbtree *t=(avlbtree *)malloc(sizeof(avlbtree));
    t->data=val;
    t->counter=0;
    t->left=t->right=0;

    return t;
}

void input(int val){
    avlbtree *new=create(val);
    if(root==0){
        root=new;
        new->counter = new->counter+1;
        printf("\tDONE!\n");
        return ;
    }

    // comparing the number with the size
    avlbtree *temp = root;
    avlbtree *parent;
    int pos;
    while(temp!=0){
        if(temp->data==val){
            temp->counter +=1;
            printf("\tDONE!\n");
            return ;
        }
        else if(val < temp->data){
            // left
            parent=temp;
            temp=temp->left;
            pos = 1;
        }
        else{
            //right
            parent=temp;
            temp=temp->right;
            pos=0;
        }
    }
    if(pos==1){
        //left
        parent->left= new;
        new->counter+=1;
    }
    else if(pos==0){
        //right
        parent->right=new;
        new->counter+=1;
    }
    printf("\tDONE!\n");

}

avlbtree *inorder(avlbtree *t){
    if(t!=0){
        inorder(t->left);
        printf("|%d|%d| ",t->data,t->counter);
        inorder(t->right);
    }
}

void delete_tree(avlbtree *t)
{
    if (t == 0)
        return;

    delete_tree(t->left);
    delete_tree(t->right);

    free(t);
}

int main(){
    // 12, 10, 20, 9, 11, 10, 12, 12
    input(12);
    input(10);
    input(20);
    input(9);
    input(11);
    input(10);
    input(12);
    input(12);
    printf("\n");
    inorder(root);
    delete_tree(root);
    return 0;
}