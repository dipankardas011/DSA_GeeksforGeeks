/*Btree introduction*/
#include <iostream>
using namespace std;

class btreenode{
    int *keys; // arrays of keys
    int t;// minimum degree (range for the number of keys)
    btreenode **c;// array for child pointers
    int n;//current number of keys
    bool leaf;
    
    public:
    btreenode(int _t, bool _leaf);//constructor
    // f() that will traverse all nodes in a subtree rooted with this node
    void traverse();
    // a function to search a key in the subtree rooted with this node
    btreenode *search(int k);

    // make the btree friend of this so that we can access private members of it
    // class in the btree functions
    friend class btree;
};

class btree
{
    btreenode *root;//pointer to troot node
    int t;//minium degree
public:
    btree(int _t){  root=NULL; t=_t; }

    void treverse(){
        if(root!=NULL)
            root->traverse();
    }

    btreenode *search(int k){
        return (root==NULL)?NULL:root->search(k);
    }
};



// constructor for Btreenode
btreenode::btreenode(int _t, bool _leaf){
    t=_t;// cpy the given minmum degree and leaf property
    leaf=_leaf;

    //allocate memory for maxmium number of possible keys and child pointers
    keys=new int[2*t-1];
    c=new btreenode* [2*t];
    // initialize the no. of keys=0
    n=0;
}

void btreenode::traverse()
{
    //there are n keys and n+1 children travers through n keys and first n children 
    int i;
    for(i=0;i<n;i++)
    {
        // If this is not leaf, then before printing key[i],
        // traverse the subtree rooted with child C[i].
        if(leaf==false)
            c[i]->traverse();
        cout<<" "<<keys[i];
    }
    //print the subtreee rooted with last child
    if(leaf==false)
        c[i]->traverse();
}

btreenode* btreenode::search(int k)
{
    
    // Find the first key greater than or equal to k
    int i=0;
    while(i<n && k>keys[i])
        i++;
    // If the found key is equal to k, return this node

    if(keys[i]==k)
        return this;
    // If the key is not found here and this is a leaf node

    if(leaf==true)
        return NULL;
    // go to the correct child
    return c[i]->search(k);
}