/*Insertion in a Binary Tree in level order
Given a binary tree and a key, insert the key into 
the binary tree at the first position available in level order.*/
#include <stdio.h>
#include <stdlib.h>
#define N 30

typedef struct link
{
    int data;
    struct link *left, *right;
} btree;

btree *queue[N];
int front = -1, rear = -1;
void push(btree *x)
{
    if (front == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = x;
}
btree *pop()
{
    if (front > rear)
        return NULL;
    return queue[front++];
}
int isempty()
{
    if (front == -1 && rear == -1)
        return 1;
    return 0;
}
btree *peek(){return queue[front];}



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


/* the height of the root node is 1 */
int count(btree *t)
{
    if (t == 0)
        return -1;
    int m = count(t->left);
    int n = count(t->right);
    return ((m > n) ? m+1 : n+1);
}

void display_height()
{
    int len = count(root);
    printf("height: %d\n", len);
}

btree *insert_by_level(btree *t, int val)
{
    if (t == NULL)
    {
        t = create(val);
        return t;
    }

    push(t);
    while (!isempty())
    {
        btree *temp = peek();
        pop();
        if (temp->left != NULL)
            push(temp->left);
        else
        {
            temp->left = create(val);
            return temp;
        }
        if (temp->right != NULL)
            push(temp->right);
        else
        {
            temp->right = create(val);
            return temp;
        }
    }
}

void inorder(btree *t)
{
    if (t != 0)
    {
        inorder(t->left);
        printf("%d ", t->data);
        inorder(t->right);
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
    display_height();
    inorder(root);
    printf("\n");

    root = insert_by_level(root, 111111);
    inorder(root);
    printf("\n");
    display_height();
    delete_tree(root);
    return 0;
}