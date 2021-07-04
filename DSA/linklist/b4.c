/*Josephus Circle using circular linked list
There are n people standing in a circle waiting to be executed. 
The counting out begins at some point in the circle and proceeds 
around the circle in a fixed direction. In each step, a certain 
number of people are skipped and the next person is executed. 
The elimination proceeds around the circle 
(which is becoming smaller and smaller as the executed people are removed) 
, until only the last person remains, who is given freedom. 
Given the total number of persons n and a number m which indicates 
that m-1 persons are skipped and m-th person is killed in circle. 
The task is to choose the place in the initial circle so that 
you are the last one remaining and so survive.
Examples : 
 

Input : Length of circle : n = 4
        Count to choose next : m = 2
Output : 1

Input : n = 5
        m = 3
Output : 4
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct circularll{
    int data;
    struct circularll *next;
}node;


int N,M;

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
        printf("|%d|%u|\n",t->data,t->next);
        t=t->next;
    }while(t!=start);
}

int count_node(){
    node *t=parent_head;
    int i=0;
    do{
        i++;
        t=t->next;
    }while(t!=parent_head);
    return i;
}

void input(){
    int ch=0;
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
        ch++;
    }while(ch<N);
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

int getJosephuspos(){
    // N,M are global
    node *ptr1=parent_head, *ptr2=parent_head;
    while(ptr1->next != ptr1){
        int count=1;
        while(count!=M){
            ptr2=ptr1;
            ptr1=ptr1->next;
            count++;
        }
        ptr2->next = ptr1->next;
        free(ptr1);
        ptr1=ptr2->next;
    }
    return ptr1->data;
}

int main(){
    printf("welcome to circular link list\n");
    printf("enter the no. of person's: ");
    scanf("%d",&N);
    input();
    printf("no. of nodes= %d\n",count_node());
    display(parent_head);

    printf("enter the no. of person's killed in circle: ");
    scanf("%d",&M);
    printf("last person surviving: %d\n",getJosephuspos());
    delete_nodes(parent_head);
}