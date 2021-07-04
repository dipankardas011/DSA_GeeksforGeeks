/*Reverse a stack without using extra space in O(n)
Reverse a Stack without using recursion and extra space. 
Even the functional Stack is not allowed.

Examples:  

Input : 1->2->3->4
Output : 4->3->2->1

Input :  6->5->4
Output : 4->5->6
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int data;
    struct stack *next;
}stack;

stack *top = NULL;


stack *creatememory(int val){
    stack *t=(stack *)malloc(sizeof(stack));
    t->data = val;
    t->next = 0;
    return t;
}
void freememory(){
    stack *temp;
    while(!top){
        temp = top;
        temp = temp->next;
        free(top);
        top = temp;
    }
    free(temp);
}


void push(int m){
    stack *new = creatememory(m);
    if(top == NULL){
        top = new;
    }
    else{
        new->next = top;
        top = new;
    }
}

void reverseSTACK(){
    stack *prev, *curr, *nextnode;
    prev = NULL;
    curr = nextnode = top;
    while(nextnode != NULL){
        nextnode = nextnode->next;
        curr->next = prev;
        prev = curr;
        curr = nextnode;
    }
    top = prev;
}

void display(){
    printf("\n~~ STACK CONTAINS ~~\n");
    stack *t = top;
    while(t!=0){
        printf("|%d|\n",t->data);
        t =t->next;
    }
}


/* no pop required */

int main(){
    push(1);
    push(2);
    push(3);
    push(7);
    push(9);
    display();

    reverseSTACK();
    display();
    freememory();
}