/* convert the PREFIX TO POSTFIX 
Algorithm for Prefix to Postfix: 

Read the Prefix expression in reverse order (from right to left)
If the symbol is an operand, then push it onto the Stack
If the symbol is an operator, then pop two operands from the Stack 
Create a string by concatenating the two operands and the operator after them. 
string = operand1 + operand2 + operator 
And push the resultant string back to Stack
Repeat the above steps until end of Prefix expression.

Examples: 

Input :  Prefix :  *+AB-CD
Output : Postfix : AB+CD-*
Explanation : Prefix to Infix :  (A+B) * (C-D)
              Infix to Postfix :  AB+CD-*

Input :  Prefix :  *-A/BC-/AKL
Output : Postfix : ABC/-AK/L-*
Explanation : Prefix to Infix :  (A-(B/C))*((A/K)-L)
              Infix to Postfix : ABC/-AK/L-*

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct nodes{
    char *pointer;
    struct nodes *next;
}stack;

stack *top=NULL;

stack *create_memory(){
    stack *t=(stack *)malloc(sizeof(stack));
    t->next=t->pointer=0;

    return t;
}

void push(char *p){
    stack *new=create_memory();
    new->pointer=p;
    if(!top){
        top=new;
        return ;
    }
    new->next=top;
    top=new;
    return ;
}
    /* very complicated in C easier in C++ and Java as String[] can be formed*/
char * pop(){
    if(!top){
        return NULL;
    }
    stack *t;
    t=top;
    top=top->next;
    return t->pointer;
}

char *peek(){
    return (top->pointer);
}

int IsOperator(char a){
    switch(a){
        case '+':
        case '^':
        case '%':
        case '-':
        case '/':
        case '*': return 1;

        default: return 0;
    }
}



int main(){
    char *prefx="*-A/BC-/AKL";
}