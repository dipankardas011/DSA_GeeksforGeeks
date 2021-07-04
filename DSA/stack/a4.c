/*Design a stack that supports getMin() in O(1) time and O(1) extra 
space
Question: Design a Data Structure SpecialStack that supports 
all the stack operations like push(), pop(), isEmpty(), isFull() 
and an additional operation getMin() which should return minimum 
element from the SpecialStack. All these operations of SpecialStack 
must be O(1). To implement SpecialStack, you should only use standard 
Stack data structure and no other data structure like arrays, list, ..
 etc.

Example:

Consider the following SpecialStack
16  --> TOP
15
29
19
18

When getMin() is called it should return 15, 
which is the minimum element in the current stack. 

If we do pop two times on stack, the stack becomes
29  --> TOP
19
18

When getMin() is called, it should return 18 
which is the minimum in the current stack.
*/



//          HARD HARD  using O(1)
#include <stdio.h>
#include <stdlib.h>

#define n 5

int stack[n];
int top=-1;
int min[n]={INT_MAX};
int minindex=0;

int isempty(){
    if(top==-1)
        return 1;
    return 0;
}

int isfull(){
    if(top==n-1)
        return 1;
    return 0;
}

void push(int v){
    if(isfull()==1)
        printf("full\n");
    else if(isempty()==1){
        stack[++top]=v;
        min[minindex]=v;
    }
    else{
        if(min[minindex]>v){
            min[++minindex]=v;
        }
        stack[++top]=v;
    }
}
void pop(){
    if(isempty()==1)
        printf("empty\n");
    else{
        if(min[minindex]==stack[top])
            minindex--;
        printf("the popped element: %d\n",stack[top--]);
    }
}

void dis(){
    int  i;
    if(isempty()==1){
        printf("empty\n");
        return ;
    }
    for(i=top;i>=0;i--)
        printf("%d\n",stack[i]);
    printf("minimum element: %d\n",min[minindex]);
}

int main(){
    push(18);
    push(19);
    push(29);
    push(15);
    push(16);

    dis();
    pop();
    pop();
    dis();
}