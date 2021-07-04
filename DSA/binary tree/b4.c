/*Level Order Binary Tree Traversal
Difficulty Level : Easy
 Last Updated : 13 Nov, 2020
Level order traversal of a tree is breadth first traversal for the tree.
        1
       / \
      2   3
    /   \
    4   5
    
12345
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct link
{
    int data;
    struct link *left, *right;
} btree;

btree *root = NULL;
btree *create(int val)
{
    btree *t = (btree *)malloc(sizeof(btree));
    t->data = val;
    t->left = t->right = 0;

    return t;
}

void make_tree(int val)
{
    btree *new = create(val);
    if (root == 0)
    {
        root = new;
        printf("\t###  DONE!  ###\n");
        return;
    }

    int ch = 0;
    // value of m represent whether it is found
    int m = 0;
    btree *temp = root;
    while (m == 0)
    {
        printf("~~~\nenter 1 for left and 0 for right\n");
        printf("help us to traverse the tree where you want to insert: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            if (temp->left == NULL)
            {
                m = 1;
                temp->left = new;
            }
            else
            {
                temp = temp->left;
            }
            break;

        case 0:
            if (temp->right == NULL)
            {
                m = 1;
                temp->right = new;
            }
            else
            {
                temp = temp->right;
            }
            break;
        default:
            printf("WARNING! wrong key pressed\n");
        }
    }
    printf("\t###  DONE!  ###\n");
}

// /* inorder traversal using iterative method */
// void inorder_traversal(){
//     btree* curr = root;
//     push(curr);
//     curr=curr->left;
//     while(top!=-1 || curr!=NULL){
//         while(curr!=NULL){
//             push(curr);
//             curr=curr->left;
//         }
//         curr = pop();
//         printf("%d ",curr->data);
//         curr=curr->right;
//     }
// }

int queue[30];
int f = -1;
int r = -1;

int height(btree *t)
{
    if (t == 0)
        return 0;
    int m = height(t->left);
    int n = height(t->right);
    return ((m > n) ? m + 1 : n + 1);
}

void print_level(btree *t, int i)
{
    if (t == 0)
    {
        return;
    }
    if (i == 1)
    {
        printf("%d ", t->data);
    }
    else if (i > 1)
    {
        print_level(t->left, i - 1);
        print_level(t->right, i - 1);
    }
}

void display()
{
    int level = height(root);
    btree *curr = root;
    for (int i = 1; i <= level; i++)
    {
        print_level(curr, i);
        printf("\n");
    }
}

void delete_tree(btree *t)
{
    if (t == 0)
        return;

    delete_tree(t->left);
    delete_tree(t->right);

    free(t);
}

int main()
{
    make_tree(4);
    make_tree(5);
    make_tree(3);
    make_tree(7);
    make_tree(8);
    //inorder_traversal();
    display();
    delete_tree(root);
}