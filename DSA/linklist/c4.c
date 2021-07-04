/*Priority Queue using Doubly Linked List
Given Nodes with their priority, implement a priority queue 
using doubly linked list. 

Prerequisite : Priority Queue

push(): This function is used to insert a new data into the queue.
pop(): This function removes the element with the lowest priority 
value form the queue.
peek() / top(): This function is used to get the lowest priority 
element in the queue without removing it from the queue
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct priorityque{
    int data;
    int priority;
    struct priorityque *next,*prev;
}node;

node *front=0, *rear=0;

node *create_memory(int val ,int p){
    node *t=(node *)malloc(sizeof(node));
    t->data = val;
    t->priority = p;
    t->next = t->prev = NULL;

    return t;
}

void input(int data, int prior){
    node *new;
    new = create_memory(data, prior);
    if(front==0){
        front = rear = new;
        return ;
    }
    if(front->priority >= prior){ // insert in begining
        new->next=front;
        front->prev = new;
        front=new;
    }
    else if(rear->priority<prior){  // insert at last
        rear->next=new;
        new->prev=rear;
        rear=new;
    }
    else{
        node *curr=front->next;
        while(curr->priority>prior)
            curr=curr->next;
        curr->prev->next = new;
        new->prev=curr->prev;
        new->next=curr;
        curr->prev=new;
    }
}

void display(){
    node *t=front;
    do{
        printf("|%d|%d|",t->data,t->priority);
        t=t->next;
    }while(t!=0 && printf(" <-> "));
    printf("\n");
}

void delete(){
    node *temp;
    while(front!=0){
        temp=front;
        temp=temp->next;
        free(front);
        front=temp;
    }
    free(temp);
}

void pop(){
    if(front==0){
        printf("^~~~EMPTY\n");
        return ;
    }
    node *t;
    t=front;
    printf("popped element: |%d|%d|\n",t->data,t->priority);
    front=front->next;
    free(t);
}

int main(){
    input(12,4);
    input(21,3);
    input(90,9);
    input(9,54);
    input(67,3);
    
    display();
    pop();
    pop();
    display();

    delete();
}