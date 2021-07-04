/*Serialize and Deserialize an N-ary Tree
Difficulty Level : Hard
Last Updated : 21 May, 2021
Given an N-ary tree where every node has at-most N children. How to serialize and deserialize it? Serialization is to store tree in a file so that it can be later restored. The structure of tree must be maintained. Deserialization is reading tree back from file.
This post is mainly an extension of below post. 
Serialize and Deserialize a Binary Tree

In an N-ary tree, there are no designated left and right children. An N-ary tree is represented by storing an array or list of child pointers with every node. 

The idea is to store an ‘end of children’ marker with every node. The following diagram shows serialization where ‘)’ is used as end of children marker*/
#include <iostream>
#include <cstdlib>
#define MARKER ')'
#define N 5
using namespace std;

struct node{
    char key;
    node *child[N]; // for N children
};

node *newNode(int t){
    node *p=new node;
    p->key=t;
    for(int i=0;i<N;i++)    p->child[i]=NULL;

    return p;
}

void serialize(node *root, FILE *fp)
{
    if(!root)   return ;

    fprintf(fp, "%c ", root->key);
    for(int i=0;i<N && root->child[i]; i++)
        serialize(root->child[i],fp);
    //stroe marjer at the end of children
    fprintf(fp, "%c ",MARKER);
}

int deSerialize(node *&root, FILE *fp)
{
    char val;
    if(!fscanf(fp, "%c ",&val) || val==MARKER)
    return 1;

    root=newNode(val);
    for(int i=0;i<N;i++)
    if(deSerialize(root->child[i], fp))
    break;

    return 0;
}

void inOrder(node *x){
    if(x){
        printf("%c\t",x->key);
        for(int i=0;i<N;i++)
            inOrder(x->child[i]);
    }
}

int main(){
    node *root = newNode('A');
    root->child[0] = newNode('B');
    root->child[1] = newNode('C');
    root->child[2] = newNode('D');
    root->child[0]->child[0] = newNode('E');
    root->child[0]->child[1] = newNode('F');
    root->child[2]->child[0] = newNode('G');
    root->child[2]->child[1] = newNode('H');
    root->child[2]->child[2] = newNode('I');
    root->child[2]->child[3] = newNode('J');
    root->child[0]->child[1]->child[0] = newNode('K');
    FILE *fp;
    fp=fopen("treeStored.txt","w");
    if(!fp){
        puts("Sorry! ~~~~ NO file exists!");
        return 0;
    }
    serialize(root,fp);
    fclose(fp);

    node *ROO=NULL;
    fp=fopen("treeStored.txt","r");
    deSerialize(ROO, fp);
    cout<<"The stored tree :";
    inOrder(ROO);
    return 0;
}