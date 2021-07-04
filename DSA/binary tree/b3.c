/*Inorder Tree Traversal without Recursion
 
Using Stack is the obvious way to traverse tree without recursion. 
Below is an algorithm for traversing binary tree using stack. 
See this for step wise step execution of the algorithm. 

1) Create an empty stack S.
2) Initialize current node as root
3) Push the current node to S and set current = current->left until current is NULL
4) If current is NULL and stack is not empty then 
     a) Pop the top item from stack.
     b) Print the popped item, set current = popped_item->right 
     c) Go to step 3.
5) If current is NULL and stack is empty then we are done.
*/
#include <stdio.h>
#include <stdlib.h>
#define N 30
typedef struct link
{
    int data;
    struct link *left, *right;
} btree;

btree *stack[N];
int top=-1;

void push(btree *t){
    if(top==N-1)
        exit(0);
    stack[++top]=t;
}

btree *pop(){
    if(top!=-1)
        return stack[top--];
    return NULL;
}

btree* peek(){
    return stack[top];
}

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

/* inorder traversal using iterative method */
void inorder_traversal(){
    btree* curr = root;
    push(curr);
    curr=curr->left;
    while(top!=-1 || curr!=NULL){
        while(curr!=NULL){
            push(curr);
            curr=curr->left;
        }
        curr = pop();
        printf("%d ",curr->data);
        curr=curr->right;
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

int main(){
    make_tree(4);
    make_tree(5);
    make_tree(3);
    make_tree(7);
    make_tree(8);
    inorder_traversal();
    delete_tree(root);
}