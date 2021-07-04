/*Convert a Binary Tree to a Circular Doubly Link List
Given a Binary Tree, convert it to a Circular Doubly Linked List (In-Place).

The left and right pointers in nodes are to be used as 
previous and next pointers respectively in converted Circular Linked List.
The order of nodes in List must be same as Inorder of the given Binary Tree.
The first node of Inorder traversal must be head node of the Circular List.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct binary_tree{
    int data;
    struct binary_tree *lchild, *rchild;
}btree;

typedef struct doublell{
    int data;
    struct doublell *prev, *next;
}node;

btree *root=NULL;

node *tail=NULL;

node *create_memory_node(){
    node *ptr=(node *)malloc(sizeof(node));
    ptr->next = ptr->prev = NULL;

    return ptr;
}

btree *create_memory_tree(){
    btree *tree=(btree *)malloc(sizeof(btree));
    tree->lchild = tree->rchild = NULL;

    return tree;
}

void input_tree(){
    int ch;
    
    if(root==0){
        root=create_memory_tree();
        printf("enter the elments: ");
        scanf("%d",&root->data);
    }btree *t=root;
    do{
        btree *new=create_memory_tree();
        printf("enter the elments: ");
        scanf("%d",&new->data);
        int m=0;
        int x;
        t=root;
        while(m==0){
            printf("~~~~enter 0 to goto left and 1 for right~~~~\n");
            scanf("%d",&x);
            if(x==0){
                if(t->lchild == NULL){
                    t->lchild = new;
                    m=1;
                }
                else{
                    t=t->lchild;
                }
            }
            else if(x==1){
                if(t->rchild == NULL){
                    t->rchild = new;
                    m=1;
                }
                else{
                    t=t->rchild;
                }
            }
            else{
                printf("^~~~~wrong choice pressed\n");
            }
        }
        printf("\tenter 1 to CONTINUE: ");
        scanf("%d",&ch);
    }while(ch==1);
}

void input(int x){
    node *new;
    new=create_memory_node();
    new->data=x;
    if(tail==0){
        tail=new;
        tail->next = tail->prev = tail;
        return ;
    }
    new->prev = tail;
    new->next = tail->next;
    tail->next->prev = new;
    tail->next=new;
    tail = new;
    return ;
}

void inorder_tree(btree *p){
    // left root right
    if(p!=NULL){
        inorder_tree(p->lchild);
        printf("%d\t",p->data);
        input(p->data);
        inorder_tree(p->rchild);
    }
}


void delete_tree(btree *p){
    btree *templ,*tempr;
    if(p!=NULL){
        templ=p->lchild;
        tempr=p->rchild;
        free(p);
        delete_tree(templ);
        //printf("DELETE");
        delete_tree(tempr);
    }
}

void display_ll(){
    node *t=tail->next;
    printf("\nDOUBLE CIRCULAR LINK LIST\n");
    printf("| ADRE. PREV | DATA | ADDRE. NEXT |\n");
    while(t->next != tail->next){
        printf("|%u|%d|%u|->\n",t->prev,t->data,t->next);
        t=t->next;
    }
    printf("|%u|%d|%u|->X\n",t->prev,t->data,t->next);
}

void delete_ll(){
    node *t=tail->next,*fr;
    while(t->next != tail->next){
        fr=t;
        fr=fr->next;
        free(t);
        t=fr;
    }
    free(fr);
}

int main(){
    printf("\nwelcome to binary tree conversion to doubly link list\n");
    input_tree();
    inorder_tree(root);

    display_ll();
    delete_tree(root);
    delete_ll();
}