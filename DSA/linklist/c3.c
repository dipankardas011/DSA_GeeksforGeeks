/*Sort the biotonic doubly linked list
Sort the given biotonic doubly linked list. 
A biotonic doubly linked list is a doubly linked 
list which is first increasing and then decreasing. 
A strictly increasing or a strictly decreasing list 
is also a biotonic doubly linked list.
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

void Sort(){
    node *i,*j;
    i=head;
    while(i!=0){
        j=i->next;
        while(j!=0){
            if(j->data < i->data){
                int t=j->data;
                j->data=i->data;
                i->data=t;
            }
            j=j->next;
        }
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
    int m;
    do{
        printf("enter element\n");
        scanf("%d",&m);
        insert(m);
        printf("~~~~enter 1 to continue~~~~\n");
        scanf("%d",&m);
    }while(m==1);
    display();
    /* assuming it is sorted */
    Sort();
    display();
    delete();
}