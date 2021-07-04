/*Write a function to get Nth node in a Linked List
Write a GetNth() function that takes a linked list and 
an integer index and returns the data value stored in 
the node at that index position. 

Example: 

Input:  1->10->30->14,  index = 2
Output: 30  
The node at index 2 is 30
*/

/* writing the function only as it will be okay */

typedef struct singlell{
    int data;
    struct singlell *next;
}node;

int getNth(node *head /* here we used single pointer as 
we don't intend to modify the head */, int index){
    int i=0;
    node *t=head;
    while(t!=0){
        if(i==index)
            return t->data;
        i++;
        t=t->next;
    }
}