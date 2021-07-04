/*infix to postfix*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10
int length;
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

int convertToPostfix(char infix_exp[], char *postfx){
    int i,j;
    
    j=0;
    for(i=0;i<length;i++){

        if(find_operator(infix_exp[i])){
            if(infix_exp[i]=='(')
                push(infix_exp[i]);
            else if(infix_exp[i]==')'){
                while(top!=-1 && peek()!='('){
                    postfx[j++]=pop();
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
                    postfx[j++]=pop();
                    continue;
                }
                // == use associativity
                while(precedence(infix_exp[i]) == precedence(peek())){
                    if(associativity(peek())==1)
                    {push(infix_exp[i]);break;}
                    else if(associativity(peek())==-1){
                        postfx[j++]=pop();
                    }
                }
                push(infix_exp[i]);
            }
        }
        else{
            postfx[j++]=infix_exp[i];
        }
    }

    char ch=' ';
    while(1){
        ch=pop();
        if(ch=='@'){
            postfx[j]='\0';
            break;
        }
        else
            postfx[j++]=ch;
    }
}

void convertToPrefix(char infix[], char *prefx){

    strrev(infix);
    /*
        reverse the infix expression reverse the brackets
        then make the postfix of this expression
        then reverse it to get the prefix
    */
    for (int i = 0; i < length; i++) {
 
        if (infix[i] == '(') {
            infix[i] = ')';
            i++;
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
            i++;
        }
    }
    convertToPostfix(infix, prefx);
    strrev(prefx);
}

int main(){
    char infix_exp[30];
    printf("enter the INFIX expression for POSTFIX & PREFIX conversion\n");
    scanf("%s",infix_exp);
    length=strlen(infix_exp);

    char postfx[length];
    convertToPostfix(infix_exp, postfx);
    printf("POSTFIX: %s\n",postfx);

    char prefx[length];
    convertToPrefix(infix_exp,prefx);
    printf("PREFIX: %s\n",prefx);
}