/*Btree introduction*/
#include <iostream>
using namespace std;

class btreenode
{
    int *keys;     // arrays of keys
    int t;         // minimum degree (range for the number of keys)
    btreenode **c; // array for child pointers
    int n;         //current number of keys
    bool leaf;

public:
    btreenode(int _t, bool _leaf); //constructor
    // f() that will traverse all nodes in a subtree rooted with this node
    //a utility function to insert a new key in the subtree rooted with this node. the assumption is the node must be non-full when this is called
    void insertNonFull(int k);

    //a utility f() to split the child y of this node i is index of y in child array c[] the child y must be full when this function is called
    void splitChild(int i, btreenode *y);

    void traverse();
    // a function to search a key in the subtree rooted with this node
    btreenode *search(int k);

    // make the btree friend of this so that we can access private members of it
    // class in the btree functions
    friend class btree;
};

class btree
{
    btreenode *root; //pointer to troot node
    int t;           //minium degree
public:
    btree(int _t)
    {
        root = NULL;
        t = _t;
    }

    void treverse()
    {
        if (root != NULL)
            root->traverse();
    }

    btreenode *search(int k)
    {
        return (root == NULL) ? NULL : root->search(k);
    }

    // the main functio that inserts a new key
    void insert(int k);
};

// constructor for btreenode
btreenode::btreenode(int _t, bool _leaf)
{
    t = _t; // cpy the given minmum degree and leaf property
    leaf = _leaf;

    //allocate memory for maxmium number of possible keys and child pointers
    keys = new int[2 * t - 1];
    c = new btreenode *[2 * t];
    // initialize the no. of keys=0
    n = 0;
}

void btreenode::traverse()
{
    //there are n keys and n+1 children travers through n keys and first n children
    int i;
    for (i = 0; i < n; i++)
    {
        // If this is not leaf, then before printing key[i],
        // traverse the subtree rooted with child C[i].
        if (leaf == false)
            c[i]->traverse();
        cout << " " << keys[i];
    }
    //print the subtreee rooted with last child
    if (leaf == false)
        c[i]->traverse();
}

btreenode *btreenode::search(int k)
{

    // Find the first key greater than or equal to k
    int i = 0;
    while (i < n && k > keys[i])
        i++;
    // If the found key is equal to k, return this node

    if (keys[i] == k)
        return this;
    // If the key is not found here and this is a leaf node

    if (leaf == true)
        return NULL;
    // go to the correct child
    return c[i]->search(k);
}

void btree::insert(int k)
{
    // if the tree is empty
    if (root == NULL)
    {
        root = new btreenode(t, true);
        root->keys[0] = k;
        root->n = 1; //update number of keys in root
    }
    else
    {
        // if tree is not empty
        // if root is full then tree grows in height
        if (root->n == 2 * t - 1)
        {
            //allocate memory for new root
            btreenode *s = new btreenode(t, false);

            // make old root as child of new root
            s->c[0] = root;
            //split the old root and move 1 key to the new root
            s->splitChild(0, root);
            // new root has 2 children now decide which is going to have new key
            int i = 0;
            if (s->keys[0] < k)
                i++;

            s->c[i]->insertNonFull(k);
            root = s;
        }
        else // If root is not full, call insertNonFull for root
            root->insertNonFull(k);
    }
}

void btreenode::insertNonFull(int k)
{
    // initializin index as index of rightmost element
    int i = n - 1;

    // if theis is a leaf node
    if (leaf == true)
    {
        //a) finds the location of new key to be inserted
        //b) moves all greater keys to one place ahead
        while (i >= 0 && keys[i] > k)
        {
            keys[i + 1] = keys[i];
            i--;
        }

        // inseert then new key
        keys[i + 1] = k;
        n = n + 1;
    }
    else
    {
        // if this node is not leaf
        // find the child which is going to have the new keys
        while (i >= 0 && keys[i] > k)
            i--;

        //see if the found child is full
        if (c[i + 1]->n == 2 * t - 1)
        {
            // if the child is full then split it
            splitChild(i + 1, c[i + 1]);

            // after split the middle keys of c[i] goes up and c[i] is splitted into 2
            if (keys[i + 1] < k)
                i++;
        }
        c[i + 1]->insertNonFull(k);
    }
}

void btreenode::splitChild(int i, btreenode *y)
{
    // Create a new node which is going to store (t-1) keys
    // of y
    btreenode *z = new btreenode(y->t, y->leaf);
    z->n = t - 1;

    // Copy the last (t-1) keys of y to z
    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    // Copy the last t children of y to z
    if (y->leaf == false)
    {
        for (int j = 0; j < t; j++)
            z->c[j] = y->c[j + t];
    }

    // Reduce the number of keys in y
    y->n = t - 1;

    // Since this node is going to have a new child,
    // create space of new child
    for (int j = n; j >= i + 1; j--)
        c[j + 1] = c[j];

    // Link the new child to this node
    c[i + 1] = z;

    // A key of y will move to this node. Find the location of
    // new key and move all greater keys one space ahead
    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    // Copy the middle key of y to this node
    keys[i] = y->keys[t - 1];

    // Increment count of keys in this node
    n = n + 1;
}

int main()
{
    btree t(3); //min degree os 3
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    cout << "traversal of the constucted tree is";
    t.treverse();
    int k = 6;
    (t.search(k) != NULL) ? cout << "\nPresent" : cout << "\nnot present";
    k = 15;
    (t.search(k) != NULL) ? cout << "\nPresent" : cout << "\nnot present";

    return 0;
}