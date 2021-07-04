/*Design a stack with operations on middle element
How to implement a stack which will support following operations in O(1) 
time complexity?
1) push() which adds an element to the top of stack.
2) pop() which removes an element from top of stack.
3) findMiddle() which will return middle element of the stack.
4) deleteMiddle() which will delete the middle element.
Push and pop are standard stack operations.
The important question is, whether to use a linked list or array 
for implementation of stack?
Please note that, we need to find and delete middle element. 
Deleting an element from middle is not O(1) for array. 
Also, we may need to move the middle pointer up 
when we push an element and move down when we pop(). 
In singly linked list, moving middle pointer in both directions is not 
possible.
The idea is to use Doubly Linked List (DLL).
We can delete middle element in O(1) time by maintaining mid pointer.
We can move mid pointer in both directions using previous and next pointers.
Following is implementation of push(), pop() and findMiddle() operations. 
Implementation of deleteMiddle() is left as an exercise. 
If there are even elements in stack, findMiddle() returns the second middle 
element. 
For example, if stack contains {1, 2, 3, 4}, then findMiddle() would return 3.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct doublell{
    int data;
    struct doublell *next, *prev;
}stack;

static stack *top;
static stack *mid;
static int count;

stack *create_memory(int val){
    stack *t=(stack *)malloc(sizeof(stack));
    t->data=val;
    t->next = t->prev =0;

    return t;
}
/* finsert from top and delte from top */
void input(int x){
    stack *new=create_memory(x);
    if(top==0){
        top=new;
        count++;
        return ;
    }
    
    new->next=top;
    top->prev=new;
    top=new;
    if(count==1)
        mid=new;
    else if((count+1)%2!=0)
        mid=mid->prev;
    count++;
    return;
}

void pop(){
    if(top==0)
        printf("empty\n");
    else{
        stack *t;
        t=top;
        count--;
        mid=mid->next;
        top=top->next;
        free(t);
    }
}

void FindMid(){
    printf("middle element: %d\n",mid->data);
}

void display(){
    stack *t=top;
    do{
        printf("%d\n",t->data);
        t=t->next;
    }while(t!=0);
}

void delete(){
    stack *t;
    do{
        t=top;
        free(t);
        top=top->next;
    }while(top!=0);
}
int main(){
    printf("welcome to find & delete the middle element of a stack in O(1) complexity\n");
    input(1);
    input(2);
    input(3);
    input(4);
    input(5);
    input(6);
    input(7);
    pop();
    pop();
    //pop();
    FindMid();
    display();

    delete();
}