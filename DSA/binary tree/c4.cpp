/*Convert a given Binary Tree to Doubly Linked List | Set 4
*/
#include <iostream>
using namespace std;
struct tree{
    int data;
    tree* left, *right;
};
struct dlinkl{
    // double linklist
    int data;
    dlinkl* prev, *next;
};

tree* root=0;
dlinkl* head=0;
dlinkl* tail=0;

tree* createT(int val){
    tree* t=new tree;
    t->data=val;
    t->left=t->right=0;
    return t;
}

dlinkl* createDL(int k){
    dlinkl* d=new dlinkl;
    d->data=k;
    d->next=0;
    d->prev=0;
    return d;
}

void insertDoubleLink(int val){
    dlinkl* temp=createDL(val);
    if(head==0){
        head=tail=temp;
        return ;
    }
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}

void inorder(tree* t){
    // left-root-right
    if(t){
        inorder(t->left);
        insertDoubleLink(t->data);
        inorder(t->right);
    }
}


void display(){
    // the ddl
    if(head==0){
        cout<<"ERROR! empty\n";
        return;
    }
    cout<<endl;
    dlinkl* t=head;
    do{
        cout<<t->data;
        t=t->next;
    }while(t && cout<<" <-> ");
    cout<<endl;
}

void deleteT(tree *t){
    if(!t){
        return;
    }
    deleteT(t->left);
    deleteT(t->right);
    free(t);
}

void deleteDL(){
    dlinkl* t=head;
    dlinkl* temp;
    do{
        temp=t;
        temp=temp->next;
        free(temp);
        t=temp;
    }while(t);
}

int main(){
    /*
        10
        / \
       12   15
      / \   /
    25  30  36
    */
    root=createT(10);
    root->left=createT(12);
    root->right=createT(15);
    root->left->left=createT(25);
    root->left->right=createT(30);
    root->right->left=createT(36);
    inorder(root);
    display();
    deleteT(root);
    deleteDL();
}