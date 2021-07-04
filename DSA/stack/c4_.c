#include <stdio.h>
#include <stdlib.h>
#define N 20
typedef struct nodes{
    int q[N];
    int front;
    int rear;
}queue;
// queue is the new datatype


void push(queue *f, int data){
    if(f->front == -1 && f->rear == -1){
        f->front = f->rear = 0;
    }
    else if(f->rear == N-1){
        printf("the queue is full\n");
        return ;
    }
    else{
        f->rear++;
    }
    f->q[f->rear] = data;
}

int pop(queue *f){
    if(f->front > f->rear){
        return INT_MAX;
    }//empty

    return f->q[f->front++];
}

int peek(queue *f){
    return f->q[f->front];
}

typedef struct meme{
    int arr[N];
    int top;
}stack;

void pushst(stack *m, int data){
    if(m->top == N-1)
        return ;
    m->arr[++m->top] = data;
}

int popst(stack *m){
    if(m->top == -1)
        return -9999;
    return m->arr[m->top--];
}
queue xxx;
void tostack(queue *Q, stack *S){
    
    while(1){
        int x = pop(Q);
        if(x == INT_MAX){
            break;
        }
        pushst(S, x);
    }
    xxx.front = xxx.rear =-1;
    while(1){
        int m = popst(S);
        if(m == -9999)
            return ;
        push(&xxx, m);
    }
}

void display(queue *f){
    if(f->front == -1 && f->rear == -1)
        return;
    for(int i=f->front; i<=f->rear; i++){
        printf("%d->",f->q[i]);
    }
    printf("NULL\n");
}


int main(){
    int ch;
    queue que1;
    stack st;
    st.top = -1;
    que1.front = que1.rear = -1;
    do{
        printf("enter the elements\n");
        scanf("%d",&ch);
        push(&que1, ch);
        printf("-> ENTER 1 TO CONTINUE.....\n");
        scanf("%d",&ch);
    }while(ch==1);
    display(&que1);
    tostack(&que1, &st);
    display(&xxx);
}