/* reverse the queue */
#include <stdio.h>
#define N 20
int queue[N];
int front = -1;
int rear = -1;

// int pop(){
//     if(front > rear)
//         return -999;
//     return queue[front++];
// }
void push(int v)
{
    if (front == -1 && rear == -1)
        front = rear = 0;
    else
        rear++;
    queue[rear] = v;
}
void display()
{
    if (front == -1 && rear == -1)
        return;
    for (int i = front; i <= rear; i++)
        printf("%d->", queue[i]);
    printf("NULL\n");
}

void operation()
{
    int left = front;
    int right = rear;
    while (left < right)
    {
        int t = queue[left];
        queue[left] = queue[right];
        queue[right] = t;
        left++;
        right--;
    }
}

int main()
{
    push(3);
    push(5);
    push(6);
    push(9);
    push(12);

    display();
    operation();
    display();
}