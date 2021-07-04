/*Write a function that counts the number of 
times a given int occurs in a Linked List
Given a singly linked list and a key, 
count number of occurrences of given key in linked list. 
For example, if given linked list is 1->2->1->2->1->3->1 
and given key is 1, then output should be 4.
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
        printf("%d->",t->data);
        t=t->next;
    }
    printf("NULL\n");
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

int count(int key){
    int i=0;
    node *t=head;
    while(t!=0){
        if(key==t->data)
            i++;
        t=t->next;
    }
    return i;
}

int main(){
    int k;
    printf("\nwelcome\n");
    input();
    display();
    printf("enter the key for counting\n");
    scanf("%d",&k);
    printf("frequency of %d key: %d\n",k,count(k));
    
    delete_memory();
}