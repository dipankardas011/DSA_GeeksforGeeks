/*Exchange first and last nodes in Circular Linked List
Given a Circular linked list exchange the first and the last node. 
The task should be done with only one extra node, you can not 
declare more than one extra node and also you are not allowed to 
declare any other temporary variable. 
Note: Extra node means need of a node to traverse a list. 

Input : 5 4 3 2 1
Output : 1 4 3 2 5

Input  : 6 1 2 3 4 5 6 7 8 9
Output : 9 1 2 3 4 5 6 7 8 6
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct circularll{
    int data;
    struct circularll *next;
}node;

node *parent_head=0;
node * create_memory(){
    node *t;
    t=(node *)malloc(sizeof(node));
    t->next=0;
    return t;
}

void display(node *start){
    if(start==0){
        printf("empty\n");
        return ;
    }
    node *t=start;
    do{
        printf("|add: %u|%d|%u|\n",t,t->data,t->next);
        t=t->next;
    }while(t!=start);
}

void input(){
    int ch;
    do{
        node *new_node=create_memory();
        printf("enter the element: ");
        scanf("%d",&new_node->data);
        
        if(parent_head==0){
            parent_head=new_node;
            parent_head->next=parent_head;
        }
        else{
            node *temp = parent_head;
            while(temp->next!=parent_head)
                temp=temp->next;
            
            temp->next = new_node;
            new_node->next=parent_head;
        }
        printf("\tenter 1 to continue: ");
        scanf("%d",&ch);
    }while(ch==1);
}
void delete_nodes(node *st){
    node *t=st;
    node *f;
    do{
        f=t;
        f=f->next;
        free(t);
        t=f;
    }while(t!=0);
    free(t);
}

void swapLastFirst(){
    node *t=parent_head;
    node *start=parent_head;
    node *ta;
    while(t->next!=parent_head){
        ta=t;
        t=t->next;
    }
    //came to last node
    ta->next = start;
    t->next=start->next;
    start->next=t;
    parent_head=t;
}

int main(){
    printf("welcome\n");
    input();
    display(parent_head);
    swapLastFirst();
    printf("after swapping\n");
    display(parent_head);
}