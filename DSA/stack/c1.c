/*Sort a stack using a temporary stack
Given a stack of integers, sort it in descending order using another temporary stack.

Examples:

Input : [34, 3, 31, 98, 92, 23]
Output : [3, 23, 31, 34, 92, 98]

Input : [3, 5, 1, 4, 2, 8]
Output : [1, 2, 3, 4, 5, 8]
*/
#include <stdio.h>
#include <stdlib.h>
#define N 30
int top1=-1;
int top2=-1;
int stack[N];
int tempstack[N];


void pushINPUT(int val){
    stack[++top1]=val;
}
int popINPUT(){
    if(top1 == -1)
        return INT_MAX;
    return stack[top1--];
}
int peekINPUT(){
    return stack[top1];
}



void pushTEMP(int val){
    tempstack[++top2]=val;
}
int popTEMP(){
    if(top2 == -1)
        return INT_MAX;
    return tempstack[top2--];
}
int peekTEMP(){
    return tempstack[top2];
}

void displaytempstack(){
    if(top2==-1)
        printf("empty\n");
    else{
        for(int i = top2; i>=0; i--)
            printf("|%d|\n",tempstack[i]);
    }
}

void sortstack(){
    if(top2==-1){
        pushTEMP(popINPUT());
    }
    while(top1!=-1){
        if(peekINPUT() >= peekTEMP()){
            pushTEMP(popINPUT());
        }
        else{
            // if input is less than the temp
            int t = popINPUT();
            while(t < peekTEMP() && top2!=-1){
                pushINPUT(popTEMP());
            }
            // temp arr[] is smaller
            pushTEMP(t);
        }
    }

    displaytempstack();
}

void empty(){
    top1=-1;
    top2=-1;
}


int main(){
    pushINPUT(3);
    pushINPUT(5);
    pushINPUT(1);
    pushINPUT(4);
    pushINPUT(2);
    pushINPUT(8);

    sortstack();
    empty();
    printf("\n");
    //[34, 3, 31, 98, 92, 23]
    pushINPUT(34);
    pushINPUT(3);
    pushINPUT(31);
    pushINPUT(98);
    pushINPUT(92);
    pushINPUT(23);

    sortstack();
}