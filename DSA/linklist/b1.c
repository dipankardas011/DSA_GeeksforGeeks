/*Split a Circular Linked List into two halves
If there are odd number of nodes, then first list should contain one extra.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct circularll{
    int data;
    struct circularll *next;
}node;

node *parent_head=0;
node *head1=0;
node *head2=0;

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

int count_node(){
    node *t=parent_head;
    int i=0;
    do{
        i++;
        t=t->next;
    }while(t!=parent_head);
    return i;
}

void split_nodes(){
    head1=parent_head;
    int l=count_node();
    int x=0;
    node *t=parent_head;
    if(l%2==0){
        do{
            x++;
            if(x==l/2)
                break;
            t=t->next;
        }while(t!=parent_head);
    }
    else{
        do{
            x++;
            if(x==(l+1)/2)
                break;
            t=t->next;
        }while(t!=parent_head);
    }
    head2=t->next;
    t->next=0;
    t->next=head1;
    t=head2;
    while(t->next != parent_head){
        t=t->next;
    }
    t->next=head2;
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

int main(){
    printf("welcome\n");
    input();
    display(parent_head);
    split_nodes();
    printf("head1\n");
    display(head1);
    printf("head2\n");
    display(head2);
    delete_nodes(head1);
    delete_nodes(head2);
}