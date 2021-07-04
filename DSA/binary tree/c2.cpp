/*Construct Complete Binary Tree from its Linked List Representation
Given Linked List Representation of Complete Binary Tree, construct the Binary tree. A complete binary tree can be represented in an array in the following approach.
If root node is stored at index i, its left, and right children are stored at indices 2*i+1, 2*i+2 respectively.
Suppose tree is represented by a linked list in same way, how do we convert 
this into normal linked representation of binary tree where every node has data, left and right pointers? In the linked list representation, we cannot directly access the children of the current node unless we traverse the list.
*/
#include <iostream>
#include <queue>

using namespace std;

struct linkl{
    int data;
    linkl* next;
};
struct tree{
    int data;
    tree* left, *right;
};

linkl* head=0;
tree* root=0;

linkl* createL(int val){
    linkl* t=new linkl;
    t->data=val;
    t->next=0;
    return t;
}

tree* createT(int val){
    tree* t=new tree;
    t->data=val;
    t->left=t->right=0;
    return t;
}

void insert(int m){
    linkl* temp=createL(m);
    if(head==0){
        head=temp;
        return ;
    }
    linkl* k=head;
    while(k->next!=0){
        k=k->next;
    }
    k->next=temp;
}

void deleteL(){
    linkl* t=head;linkl* temp;
    while(t){
        temp=t;
        temp=temp->next;
        free(t);
    }
    free(temp);
}

void deleteT(tree *t){
    if(!t){
        return;
    }
    else{
        deleteT(t->left);
        deleteT(t->right);
        free(t);
    }
}

void constructTreeLink(){
    queue<tree*> q;
    if(head==NULL){
        root=NULL;
        return ;
    }
    root=createT(head->data);
    q.push(root);
    head=head->next;

    while(head!=0){
        tree* parent=q.front();
        q.pop();
        tree* l=0;tree *r=0;
        l=createT(head->data);
        q.push(l);
        head=head->next;
        if(head){//checking another time to ensure the head is not NULL
            r=createT(head->data);
            q.push(r);
            head=head->next;
        }
        parent->left=l;
        parent->right=r;
    }
}

void inorder(tree*t){
    if(t){
        inorder(t->left);
        cout<<t->data<<" ";
        inorder(t->right);
    }
}


int main(){
    insert(10);
    insert(12);
    insert(15);
    insert(25);
    insert(30);
    insert(36);
    constructTreeLink();
    inorder(root);
    deleteL();
    
    deleteT(root);
}