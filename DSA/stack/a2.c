/*Implement two stacks in an array
Create a data structure twoStacks that represents two stacks. 
Implementation of twoStacks should use only one array, i.e., 
both stacks should use the same array for storing elements. 
Following functions must be supported by twoStacks.
push1(int x) –> pushes x to first stack
push2(int x) –> pushes x to second stack

pop1() –> pops an element from first stack and return the popped element
pop2() –> pops an element from second stack and return the popped element

Implementation of twoStack should be space efficient.
*/
#include <stdio.h>
#include <stdlib.h>

#define n 5
struct stack2{
    int arr[n];
    int top1;
    int top2;
};
struct stack2 s;

void enque1(int val){
    if(s.top1<s.top2-1){
        s.arr[++s.top1]=val;
    }
    else{
        printf("overflow element: %d\n",val);
    }
}
void enque2(int val){
    if(s.top2>s.top1+1){
        s.arr[--s.top2]=val;
    }
    else{
        printf("overflow element: %d\n",val);
    }
}
void pop1(){
    if(s.top1==-1)
        printf("empty\n");
    else{
        printf("popped elemnt from stack1: %d\n",s.arr[s.top1--]);
    }
}
void pop2(){
    if(s.top1>n-1)
        printf("empty\n");
    else{
        printf("popped elemnt from stack2: %d\n",s.arr[s.top2++]);
    }
}

void dis1(){
    printf("\n");
    for(int i=0;i<=s.top1;i++)
        printf("%d->",s.arr[i]);
    printf("\b\b  \n");
}
void dis2(){
    printf("\n");
    for(int i=s.top2;i<n;i++)
        printf("%d->",s.arr[i]);
    printf("\b\b  \n");
}

int main(){
    s.top1=-1;
    s.top2=n;
    enque1(7);
    enque1(5);
    enque2(4);
    enque2(9);
    enque1(1771);
    enque2(999);
    dis1();
    dis2();
    pop1();
    pop2();
    dis1();
    dis2();
}