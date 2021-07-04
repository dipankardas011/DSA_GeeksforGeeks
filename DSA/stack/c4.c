/*
    there must be some error


Check if a queue can be sorted into another queue using a stack
Given a Queue consisting of first n natural numbers (in random order). The task is to check whether the given Queue elements can be arranged in increasing order in another Queue using a stack. The operation allowed are:
1. Push and pop elements from the stack
2. Pop (Or enqueue) from the given Queue.
3. Push (Or Dequeue) in the another Queue.
Examples :

Input : Queue[] = { 5, 1, 2, 3, 4 }
Output : Yes
Pop the first element of the given Queue i.e 5.
Push 5 into the stack.
Now, pop all the elements of the given Queue and push them to
second Queue.
Now, pop element 5 in the stack and push it to the second Queue.
 
Input : Queue[] = { 5, 1, 2, 6, 3, 4 }
Output : No
Push 5 to stack.
Pop 1, 2 from given Queue and push it to another Queue.
Pop 6 from given Queue and push to stack.
Pop 3, 4 from given Queue and push to second Queue.
Now, from using any of above operation, we cannot push 5
into the second Queue because it is below the 6 in the stack.
*/
#include <stdio.h>
#include <stdlib.h>
#define n 50

int f1=-1,
    f2=-1,
    r1=-1,
    r2=-1,
    top=-1;

int que1[n];
int que2[n];
int stack[n];

void push1(int v){
    if(f1==-1){
        f1=r1=0;
    }
    else{
        r1++;
    }
    que1[r1]=v;
}
int pop1(){
    if(f1 > r1)
        return -999;
    else
        return que1[f1++];
}

void push2(int v){
    if(f2==-1)
        f2=r2=0;
    else
        r2++;
    que2[r2]=v;
}
int pop2(){
    if(f2 > r2)
        return -999;
    else
        return que2[f2++];
}


void pushstack(int m){
    if(top==n-1)
        exit(0);
    stack[++top] = m;
}
int popstack(){
    if(top == -1)
        return INT_MAX;
    
    return stack[top--];
}
int peek(){return stack[top];}
int peekque(){return que1[f1];}

void empty(void);

int size_of_que(){
    int count=0;
    for(int i=f1;i<=r1;i++)
        count++;
    return count;
}

void IfReversePossible(){
    while(size_of_que()){
        if(top == -1)
            pushstack(pop1());
        else{
            if(peek() < peekque()){
                printf("NO\n");
                return ;
            }
            else{
                push2(pop1());
            }
        }
    }
    while(top!=-1){
        push2(popstack());
    }
    printf("yes\n");
} 

int main(void){
    push1(5);
    push1(1);
    push1(2);
    push1(3);
    push1(4);
    IfReversePossible();
    empty();
    //
    push1(5);
    push1(1);
    push1(2);
    push1(6);
    push1(3);
    push1(4);
    IfReversePossible();
    empty();
    //
    int ch;
    do{
        printf("enter the element: ");
        scanf("%d",&ch);
        push1(ch);
        printf("~~  PRESS 1 TO CONTINUE . . . . . \n");
        scanf("%d",&ch);
    }while(ch==1);
    IfReversePossible();
    empty();
}

void empty(void){
    f1=r1=r2=f2=top = -1;
}