/*Find pairs with given sum in doubly linked list
Given a sorted doubly linked list of positive distinct elements, 
the task is to find pairs in doubly linked list whose sum is equal 
to given value x, without using any extra space ? 

Example:  

Input : head : 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
        x = 7
Output: (6, 1), (5,2)
Expected time complexity is O(n) and auxiliary space is O(1).
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

void FindPair(int sum){
    node *left,*right;
    left = head;
    right = tail;
    int ff;
    while(left != right){
        ff=left->data+right->data;
        if(ff>sum)
            right = right->prev;
        else if (ff<sum)
            left = left->next;
        else{
            printf("the pair(%d, %d)\n",left->data, right->data);
            left=left->next;
            right = right->prev;
        }
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
    insert(1);
    insert(2);
    insert(4);
    insert(5);
    insert(6);
    insert(8);
    insert(9);
    display();
    /* assuming it is sorted */
    FindPair(7);
    delete();
}