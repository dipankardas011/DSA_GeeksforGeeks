/*Remove duplicates from a sorted doubly linked list
Given a sorted doubly linked list containing n nodes. 
The problem is to remove duplicate nodes from the given list.
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct doublell{
    int data;
    struct doublell *next, *prev;
}node;

node *head=NULL,*tail=NULL;

node *create_memory(int val){
    node *t=(node *)malloc(sizeof(node));
    t->data=val;
    t->prev = t->next = NULL;
    return t;
}

void insert(int x){
    node *t;
    t=create_memory(x);
    if(head == 0){
        head=tail=t;
        return ;
    }
    tail->next = t;
    t->prev = tail;
    tail=t;
    return ;
}

void display(){
    node *t=head;
    do{
        printf("%d",t->data);
        t=t->next;
    }while(t!=0 && printf(" <-> "));
    printf("\n");
}

void RemoveDuplicate(){
    node *i;
    node *temp;
    i=head;
    while(i->next!=0){
        if(i->next->next==0){   // the last element to be deleted
            temp=i->next;
            i->next=0;
            free(temp);
        }
        else if(i->data == i->next->data){
            //consecutive same
            temp = i->next;
            i->next = temp->next;
            temp->next->prev = i;
            free(temp);
        }
        else
            i=i->next;
    }
}

void delete(){
    node *temp;
    while(head!=0){
        temp=head;
        temp=temp->next;
        free(head);
        head=temp;
    }
    free(temp);
}

int main(){
    insert(4);
    insert(4);
    insert(4);
    insert(4);
    insert(6);
    insert(8);
    insert(8);
    insert(10);
    insert(12);
    insert(12);
    display();
    /* assuming it is sorted */
    RemoveDuplicate();
    display();
    delete();
}