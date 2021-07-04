/*Swap nodes in a linked list without swapping data
Given a linked list and two keys in it, swap nodes for two given keys. 
Nodes should be swapped by changing links. 
Swapping data of nodes may be expensive in many situations 
when data contains many fields. 
It may be assumed that all keys in the linked list are distinct.
Examples: 

Input:  10->15->12->13->20->14,  x = 12, y = 20
Output: 10->15->20->13->12->14

Input:  10->15->12->13->20->14,  x = 10, y = 20
Output: 20->15->12->13->10->14

Input:  10->15->12->13->20->14,  x = 12, y = 13
Output: 10->15->13->12->20->14
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct singlell{
    int data;
    struct singlell *next;
}node;

node *head=NULL;

node *create_memory(){
    node *t;
    t=(node *)malloc(sizeof(node));
    t->next=NULL;
    return t;
}

void delete_memory(){
    node *temp;
    if(head == 0)
        return ;
    temp=head;
    node *t;
    while(temp->next!=0){
        t=temp;
        t=t->next;
        free(temp);
        temp=t;
    }
    free(t);
}

void display(){
    node *t=head;
    while(t!=0){
        printf("add: %u\t",t);
        printf("|%d|%u|\n",t->data,t->next);
        t=t->next;
    }
    //printf("NULL\n");
}

void input(){
    node *t;
    int ch;
    do{
        node *newnode=create_memory();
        printf("enter the element\n");
        scanf("%d",&newnode->data);
        if(head==0){
            head=newnode;
        }
        else{
            t=head;
            while(t->next!=0)
                t=t->next;
            t->next=newnode;
        }
        printf("\nenter 1 to continue\n");
        scanf("%d",&ch);
    }while(ch==1);
}

void swapnode(int x, int y){
    if(x==y)
    return ;
    
    node *currx,*prevx;
    currx=head;
    prevx=NULL;
    while(currx && currx->data!=x){
        prevx=currx;
        currx=currx->next;
    }

    node *curry,*prevy;
    curry=head;
    prevy=NULL;
    while(curry && curry->data!=y){
        prevy=curry;
        curry=curry->next;
    }

    if(currx==NULL || curry==NULL)
        return ;//no elements found

    if(prevx!=NULL)
    prevx->next=curry;
    else
    head=curry;

    if(prevy!=NULL)
    prevy->next=currx;
    else
    head=currx;

    node *t;
    t=currx->next;
    currx->next=curry->next;
    curry->next=t;
}

int main(){
    int k;
    int a,b;
    printf("\nwelcome\n");
    input();
    display();
    printf("enter the value of x: ");
    scanf("%d",&a);
    printf("enter the value of y: ");
    scanf("%d",&b);
    swapnode(a,b);
    display();
    delete_memory();
}