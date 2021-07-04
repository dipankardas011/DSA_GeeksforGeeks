/* reverse the string using the stack */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodes{
    char ch;
    struct nodes *next;
}stack;

stack *top=0;

stack *creatememory(char a){
    stack *t=(stack *)malloc(sizeof(stack));
    t->ch = a;
    t->next=0;
    return t;
}

void input(char a){
    stack *new=creatememory(a);
    if(top==0)
        top = new;
    else{
        new->next = top;
        top = new;
    }
}

char pop(){
    stack *temp;
    if(top==NULL){
        return '#';
    }
    temp = top;
    char re = temp->ch;
    top = top->next;
    free(temp);
    return re;
}


int main(){
    char str[10]="abcdefg";
    for(int i=0;i<strlen(str);i++)
        input(str[i]);
    char m;
    do{
        m = pop();
    }while(m!='#' && printf("%c",m));
}