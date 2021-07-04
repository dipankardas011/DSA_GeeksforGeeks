/*Function to check if a singly linked list is palindrome
Given a singly linked list of characters, 
write a function that returns true 
if 
    the given list is a palindrome, 
else 
    false.
*/
#include <stdio.h>
#include <stdlib.h>
#define CAP 50

typedef struct singlell{
    char data;
    struct singlell *next;
}node;

char stack[CAP];
int top=-1;

void push(char x){
    if(top<CAP-1)
        stack[++top]=x;
    else{
        printf("ERROR\n");
    }
}
char pop(){
    if(top==-1)
        return '#';
    return stack[top--];
}

node *head=NULL;

node *create_memory(){
    node *t;
    t=(node *)malloc(sizeof(node));
    t->next=NULL;
    return t;
}

void delete_memory(){
    node *temp;
    if(head == 0)
        return ;
    temp=head;
    node *t;
    while(temp->next!=0){
        t=temp;
        t=t->next;
        free(temp);
        temp=t;
    }
    free(t);
}

void display(){
    node *t=head;
    while(t!=0){
        printf("%c->",t->data);
        t=t->next;
    }
    printf("NULL\n");
}

void input(){
    node *t;
    int ch;
    do{
        node *newnode=create_memory();
        printf("enter the element\n");
        scanf(" %c",&newnode->data);
        if(head==0){
            head=newnode;
        }
        else{
            t=head;
            while(t->next!=0)
                t=t->next;
            t->next=newnode;
        }
        printf("\nenter 1 to continue\n");
        scanf("%d",&ch);
    }while(ch==1);
}

int find_palindrome(){
    node *t;
    if(head==0)
        return -1; // empty
    t=head;
    while(t!=0){
        push(t->data);
        t=t->next;
    }
    printf("hhh\n");
    char ch;
    t=head;
    while(t!=0){
        printf("hhh\n");
        ch=pop();
        printf("%c\n",ch);
        if(ch!=t->data)
            return 0;
        t=t->next;
    }
    return 1;
}


int main(){
    printf("\nwelcome\n");
    input();
    display();
    int x=find_palindrome();
    if(x==1)    printf("palindrome\n");
    else if(x==0)   printf("not a palindrome\n");
    else    printf("error\n");
    display();
    delete_memory();
}