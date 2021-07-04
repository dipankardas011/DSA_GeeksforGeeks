/*Modify a binary tree to get preorder traversal using right pointers only
Given a binary tree. Modify it in such a way that after modification you 
can have a preorder traversal of it using only the right pointers. 
During modification, you can use right as well as left pointers.

Examples:

Input :    10
          /   \
        8      2
      /  \    
    3     5  
Output :    10
              \
               8
                \ 
                 3
                  \
                   5
                    \
                     2
Explanation : The preorder traversal
of given binary tree is 10 8 3 5 2.
*/
#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree *left, *right;
};

struct tree *root = 0;

struct tree *create(int val)
{
    struct tree *t = (struct tree *)malloc(sizeof(struct tree));
    t->data = val;
    t->left = t->right = 0;
    return t;
}
int count = 0;
void count_nodes(struct tree *t)
{
    if (t != 0)
    {
        count++;
        count_nodes(t->left);
        count_nodes(t->right);
    }
}

struct tree *pre_root = 0;

void create_custom_preorder(struct tree *t)
{
    if (t != 0)
    {
        // creating the var
        struct tree *new = create(t->data);
        
        if (pre_root == 0)
        {
            pre_root = new;
        }
        else
        {
            struct tree *temp = pre_root;
            while (temp->right != 0)
                temp = temp->right;
            temp->right = new;
        }
        create_custom_preorder(t->left);
        create_custom_preorder(t->right);
    }
}

void preorder(struct tree *t)
{
    if (t != 0)
    {
        printf("%d ", t->data);
        preorder(t->left);
        preorder(t->right);
    }
}

void delete_tree(struct tree *t)
{
    if (t == 0)
        return;

    delete_tree(t->left);
    delete_tree(t->right);

    free(t);
}
void display(struct tree *t)
{
    while (t != 0)
    {
        printf("%d ", t->data);
        t = t->right;
    }
}

int main()
{
    root = create(10);
    root->left = create(8);
    root->left->left = create(3);
    root->left->right = create(5);
    root->right = create(2);
    preorder(root);
    count_nodes(root);
    printf("\n");

    create_custom_preorder(root);
    count = 0;
    count_nodes(pre_root);
    display(pre_root);
    delete_tree(root);
    return 0;
}