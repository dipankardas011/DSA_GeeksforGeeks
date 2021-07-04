/*Queue using Stacks
The problem is opposite of this post. 
We are given a stack data structure with push and pop operations, 
the task is to implement a queue using instances of stack data 
structure and operations on them.
A queue can be implemented using two stacks. 
Let queue to be implemented be q and stacks used to implement q 
be stack1 and stack2. q can be implemented in two ways:
*/
#include <stdio.h>
#include <stdlib.h>
#define N 5

static int stack1[N], stack2[N];

int top1=-1, top2=-1;

static int count;

void push1(int x){
    if(top1==N-1)
        printf("full\n");
    else
        stack1[++top1]=x;
}

void push2(int x){
    if(top2==N-1)
        printf("full\n");
    else
        stack2[++top2]=x;
}

int pop1(){
    return (stack1[top1--]);
}

int pop2(){
    return (stack2[top2--]);
}


void display(){
    if(top1==-1){
        printf("empty\n");
        return ;
    }
    printf("*****\n");
    for(int i=0;i<=top1;i++){
        printf("%d\n",stack1[i]);
    }
    printf("*****\n");
}

void enqueue(int m){
    push1(m);
    count++;
}

void dequeue(){
    int i;
    for(i=0;i<count;i++)
        push2(pop1());
    printf("popped element is: %d\n",pop2());
    count--;

    for(i=0;i<count;i++)
        push1(pop2());
    return ;
}

int main(void){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    dequeue();
    display();

    dequeue();
    enqueue(7);

    dequeue();
    dequeue();
    display();
}