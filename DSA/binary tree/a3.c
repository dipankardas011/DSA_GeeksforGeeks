/*Evaluation of Expression Tree
Difficulty Level : Medium
 Last Updated : 02 Nov, 2020
Given a simple expression tree, consisting of basic binary 
operators i.e., + , – ,* and / and some integers, evaluate the expression tree.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct link
{
    char data[5];
    struct link *left, *right;
} btree;

#define N 30
int stack[N];
static char exp[N]={'\0'};


int top = -1;

void push(int v)
{
    if (top == N - 1)
        return;
    stack[++top] = v;
}
int pop()
{
    if (top == -1)
    {
        return -999;
    }
    return stack[top--];
}

int peek(){
    return stack[top];
}


btree *root = NULL;

btree *create(char val[])
{
    btree *t = (btree *)malloc(sizeof(btree));
    strcpy(t->data, val);
    t->left = t->right = 0;
    return t;
}

void make_tree(char val[])
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

char *x = exp;

void inorder(btree *t)
{
    if (t != 0)
    {
        inorder(t->left);
        printf("%s ",t->data);
        inorder(t->right);

        if(t->data[0]=='*'||t->data[0]=='/'||t->data[0]=='+'||t->data[0]=='-'){
            int a=pop();
            int b=pop();
            // printf("popped element are %d %d\n",a,b);
            switch(t->data[0]){
                case '*':push(b*a);break;
                case '/':push(b/a);break;
                case '-':push(b-a);break;
                case '+':push(b+a);break;
            }
            // printf("top element= %d\n",peek());
        }
        else{
            // printf("%d\n",atoi(t->data));
            push(atoi(t->data));
        }
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
    make_tree("+");
    make_tree("*");
    make_tree("-");
    make_tree("5");
    make_tree("4");
    make_tree("100");
    make_tree("20");
    printf("THE EXPRESSION= ");
    inorder(root);
    printf("\nThe res = %d\n",pop());
    delete_tree(root);
    return 0;
}