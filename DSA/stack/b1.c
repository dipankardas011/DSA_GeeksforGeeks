/*Stack | Set 2 (Infix to Postfix)
Prerequisite – Stack | Set 1 (Introduction) 
Infix expression:The expression of the form a op b. 
When an operator is in-between every pair of operands.
Postfix expression:The expression of the form a b op. 
When an operator is followed for every pair of operands.
Why postfix representation of the expression? 
The compiler scans the expression either from left to 
right or from right to left. 
Consider the below expression: a op1 b op2 c op3 d 
If op1 = +, op2 = *, op3 = +
The compiler first scans the expression to evaluate the 
expression b * c, then again scan the expression to add a to it. 
The result is then added to d after another scan.
The repeated scanning makes it very in-efficient. 
It is better to convert the expression to postfix(or prefix) 
form before evaluation.
The corresponding expression in postfix form is: abc*+d+.
The postfix expressions can be evaluated easily using a stack.
We will cover postfix expression evaluation in a separate post.
Algorithm 
1. Scan the infix expression from left to right. 
2. If the scanned character is an operand, output it. 
3. Else, 
      1 If the precedence of the scanned operator is greater than the 
      precedence of the operator in the stack(or the stack is empty           
      or the stack contains a ‘(‘ ), push it. 
      2 Else, Pop all the operators from the stack which are greater than 
      or equal to in precedence than that of the scanned operator. 
      After doing that Push the scanned operator to the stack. 
      (If you encounter parenthesis while popping then stop there 
      and push the scanned operator in the stack.) 
4. If the scanned character is an ‘(‘, push it to the stack. 
5. If the scanned character is an ‘)’, pop the stack and and 
output it until a ‘(‘ is encountered, and discard both the parenthesis. 
6. Repeat steps 2-6 until infix expression is scanned. 
7. Print the output 
8. Pop and output from the stack until it is not empty.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

int precedence(char a){
    switch(a){
        // case '(':
        // case ')': return 4;

        case '^': return 3;

        case '*':
        case '/':
        case '%': return 2;

        case '+':
        case '-': return 1;
        
        default: return -1;
        
    }
}

int associativity(char a){
    switch(a){
        // case '(':
        // case ')':
        case '*':
        case '/':
        case '%':
        case '+':
        case '-': return -1; // left to right

        case '^': return 1; // right to left

        default: return 0;
    }
}


int top=-1;
char stack[N];

void push(char val){
    if(top==N-1)
        printf("^~~~ERROR FULL STACK\n");
    else
        stack[++top]=val;
}

char peek(){
    return stack[top];
}

char pop(){
    if(top==-1)
        return '@';
    return stack[top--];
}

int find_operator(char a){
    if(a=='^'||a=='/'||a=='*'||a=='+'||a=='-'||a=='('||a==')'||a=='%')
        return 1;
    return 0;
}

int main(){
    char infix_exp[20];
    printf("enter the INFIX expression for POSTFIX conversion\n");
    scanf("%s",infix_exp);
    int length=strlen(infix_exp);
    int i;

    for(i=0;i<length;i++){
        if(find_operator(infix_exp[i])){
            if(infix_exp[i]=='(')
                push(infix_exp[i]);
            else if(infix_exp[i]==')'){
                while(top!=-1 && peek()!='('){
                    printf("%c ",pop());
                }
                if(top!=-1 && peek()!='(')
                    return -1;
                else
                pop();//removing '('
            }
            else{
                if(precedence(infix_exp[i])>precedence(peek()))
                {
                    push(infix_exp[i]);
                    continue;
                }
                // <=
                while(top!=-1 && (precedence(infix_exp[i])<precedence(peek()))){
                    printf("%c ",pop());
                    continue;
                }
                // == use associativity
                while(precedence(infix_exp[i]) == precedence(peek())){
                    if(associativity(peek())==1)
                    {push(infix_exp[i]);break;}
                    else if(associativity(peek())==-1){
                        printf("%c ",pop());
                    }
                }
                push(infix_exp[i]);
            }
        }
        else{
            printf("%c ",infix_exp[i]);
        }
    }

    char ch=' ';
    while(1){
        ch=pop();
        if(ch=='@')
            exit(0);
        else
            printf("%c ",ch);
    }
}