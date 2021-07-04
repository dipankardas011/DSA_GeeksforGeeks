/*Linked List | Set 3 (Deleting a node)
We have discussed Linked List Introduction 
and Linked List Insertion in previous posts on a singly linked list.
Let us formulate the problem statement to 
understand the deletion process. 
Given a ‘key’, delete the first occurrence of this key in the linked list. 
To delete a node from the linked list, we need to do the following steps. 
1) Find the previous node of the node to be deleted. 
2) Change the next of the previous node. 
3) Free memory for the node to be deleted.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct singlell{
    char data;
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
        printf("%c->",t->data);
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
        scanf(" %c",&newnode->data);
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

void deleteatpos(){
    if(head==0){
        printf("^~~~empty link list\n");
        return ;
    }
    int pos;
    printf("enter the position for deleting\n");
    scanf("%d",&pos);
    if(pos==1){
        node *t;
        t=head;
        head=head->next;
        free(t);
        return ;
    }
    node *prev, *current;
    current=head;
    int i=1;
    while(i++ < pos){
        prev=current;
        current=current->next;
    }
    prev->next=current->next;
    free(current);
}

int main(){
    printf("\nwelcome\n");
    input();
    display();
    deleteatpos();
    display();
    delete_memory();
}