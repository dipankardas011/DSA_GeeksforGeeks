/*evaluation of a postfix expression
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int top=-1;
int stack[20];
int length;
void push(int val){
    if(top==19)
        printf("stack limit reached\n");
    stack[++top]=val;
}
int pop(){
    if(top!=-1)
        return stack[top--];
    return -9999;
}


int evaluate_postfix(char *exp){
    int i;
    for(i=0;exp[i];i++){
        if(isdigit(exp[i]))
            push(exp[i] - '0');
        else{
            // operand
            int op1 = pop();
            int op2 = pop();
            switch(exp[i]){
                case '*': push(op2 * op1); break;
                case '/': push(op2 / op1); break;
                case '+': push(op2 + op1); break;
                case '-': push(op2 - op1);break;
                case '%': push(op2 % op1);break;
                case '^': push((int)pow(op2, op1));break;
            }
        }
    }
    return pop();
}

int main(){
    char exp[50];
    printf("enter the postfix expression to be calculated\n");
    scanf("%s",exp);
    length = strlen(exp);
    printf("\nthe value is: %d\n\n",evaluate_postfix(exp));
}