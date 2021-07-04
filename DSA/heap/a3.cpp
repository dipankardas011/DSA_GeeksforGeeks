// Fibonacci Heap – Insertion and Union
// Difficulty Level : Medium
// Last Updated : 14 Dec, 2020
// Prerequisites: Fibonacci Heap (Introduction)

// Fibonacci Heap is a collection of trees with min-heap or max-heap property. In Fibonacci Heap, trees can have any shape even all trees can be single nodes (This is unlike Binomial Heap where every tree has to be Binomial Tree).
// In this article, we will discuss Insertion and Union operation on Fibonacci Heap. 

// Insertion: To insert a node in a Fibonacci heap H, the following algorithm is followed: 

// Create a new node ‘x’.
// Check whether heap H is empty or not.
// If H is empty then: 
// Make x as the only node in the root list.
// Set H(min) pointer to x.
// Else: 
// Insert x into root list and update H(min).
// Example: 
// Union: Union of two Fibonacci heaps H1 and H2 can be accomplished as follows: 

// Join root lists of Fibonacci heaps H1 and H2 and make a single Fibonacci heap H.
// If H1(min) < H2(min) then: 
// H(min) = H1(min).
// Else: 
// H(min) = H2(min).

#include <cstdlib>
#include <iostream>

using namespace std;

struct node {
    node *parent;
    node *child;
    node *left;
    node *right;
    int key;
};

node *mini=NULL;

int no_nodes=0;

void insertion(int val)
{
    node *newnode = new node;
    newnode->key = val;
    newnode->parent=newnode->child=NULL;
    newnode->left = newnode->right = newnode;

    if (mini !=NULL) {
        // here 
        // left and right pointer denotes
        // prev and next pointer in double circular ll
        mini->left->right=newnode;
        newnode->right=mini;
        newnode->left=mini->left;
        mini->left=newnode;
        if (newnode->key < mini->key) mini=newnode;

    }
    else {
        // no nodes present
        mini = newnode;
    }
}

void display (node *mini)
{
    node *ptr=mini;
    if(ptr==NULL)
        cout<<"the heap is EMPTY!"<<endl;
    
    else {
        cout<< "the root nodes of heap are: "<<endl;
        do {
            cout<<ptr->key;
            ptr=ptr->right;

            if(ptr!=mini){
                cout<<"->";
            }
        }while(ptr!=mini && ptr->right!=NULL);
        cout<<endl
            <<"the heap has ="
            <<no_nodes<<" nodes"<<endl;
    }
}

void FindMin(node *mini)
{   cout<<"min of heap: "<<mini->key<<endl; }

int main()
{
    no_nodes=7;
    insertion(4);
    display(mini);
    FindMin(mini);

    insertion(3);
    display(mini);
    FindMin(mini);
    
    insertion(7);
    display(mini);
    FindMin(mini);
    
    insertion(5);
    display(mini);
    FindMin(mini);
    
    insertion(2);
    display(mini);
    FindMin(mini);
    
    insertion(1);
    display(mini);
    FindMin(mini);

    insertion(10);
    display(mini);
    FindMin(mini);
    return 0;
}