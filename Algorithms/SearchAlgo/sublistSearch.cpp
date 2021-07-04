/*Sublist Search (Search a linked list in another list)
Difficulty Level : Easy
Last Updated : 24 May, 2021
Given two linked lists, the task is to check whether the first list is present in 2nd list or not. 
Examples:

Input  : list1 =  10->20
         list2  = 5->10->20
Output : LIST FOUND

Input  : list1 =  1->2->3->4
         list2  = 1->2->1->2->3->4
Output : LIST FOUND

Input  : list1 =  1->2->3->4
         list2  = 1->2->2->1->2->3
Output : LIST NOT FOUND
Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Algorithm: 
1- Take first node of second list. 
2- Start matching the first list from this first node. 
3- If whole lists match return true. 
4- Else break and take first list to the first node again. 
5- And take second list to its second node. 
6- Repeat these steps until any of linked lists becomes empty. 
7- If first list becomes empty then list found else not.
Below is the implementation.*/
#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
};

bool findList(node *first, node *second){
    node *ptr1=first, *ptr2=second;
    if(first==NULL && second==NULL)
        return true;
    // if one is empty and other is not return false
    if(first==NULL||(first!=NULL && second==NULL))
        return false;
    
    while(second!=NULL)
    {
        ptr2=second;
        while(ptr1!=NULL)
        {
            // second list becomes empty
            if(ptr2==NULL)
                return false;
            // if data part is same go to next of both lists
            else if(ptr1->data==ptr2->data)
            {
                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }
            // if not equal
            else break;
        }
        if(ptr1==NULL)
            return true;

        ptr1=first;
        second=second->next;
    }
    return false;
}

void printList(node *node){
    do{
        cout<<node->data;
        node=node->next;
    }while(node!=NULL && printf("->"));
    cout<<endl;
}

node *newNode(int key){
    node *t=new node;
    t->data=key;
    t->next=NULL;
    return t;
}

int main()
{
    /* Let us create two linked lists to test
    the above functions. Created lists shall be
        a: 1->2->3->4
        b: 1->2->1->2->3->4*/
    node *a = newNode(1);
    a->next = newNode(2);
    a->next->next = newNode(3);
    a->next->next->next = newNode(4);
 
    node *b = newNode(1);
    b->next = newNode(2);
    b->next->next = newNode(1);
    b->next->next->next = newNode(2);
    b->next->next->next->next = newNode(3);
    b->next->next->next->next->next = newNode(4);
 
    findList(a,b) ? cout << "LIST FOUND"<<endl :
                    cout << "LIST NOT FOUND"<<endl;
    printList(a);
    printList(b);
    return 0;
}