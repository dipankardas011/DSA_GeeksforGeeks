/*Sorting array using Stacks
Given an array of elements, task is to sort these elements using stack.

Prerequisites : Stacks

Examples :

Input :  8 5 7 1 9 12 10
Output : 1 5 7 8 9 10 12 
Explanation :
Output is sorted element set

Input :  7 4 10 20 2 5 9 1
Output : 1 2 4 5 7 9 10 20
*/
#include <stdio.h>

#include <stdlib.h>
#define N 50
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


/* DRIVER */
int main(){
    int n;
    printf("enter the size of arr[]\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements\n");
    for(int i=0;i<n;i++)
        scanf("%d",arr+i);
    for(int i=0;i<n;i++)
        pushINPUT(arr[i]);

    sortstack();
    for(int i=0;i<n;i++){
        arr[i] = popTEMP();
    }
    printf("\n");
    for(int i=n-1;i>=0;i--)
        printf("%d ",arr[i]);
}