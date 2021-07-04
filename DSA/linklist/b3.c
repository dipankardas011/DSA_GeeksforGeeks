/*Count nodes in Circular linked list
Given a circular linked list, count number of nodes in it. 
For example, the output is 5 for below list.
*/

/* only the count func()*/
typedef struct circular{
    int data;
    struct circular *next;
}node;
node *head = 0;

int count_circularll(){
    node *t=head;
    int count=0;
    do{
        count++;
        t=t->next;
    }while(head != t);
    return count;
}