/*Sorting array of strings (or words) using Trie
Difficulty Level : Medium
Last Updated : 10 Sep, 2017
Given an array of strings, print them in alphabetical (dictionary) order. If there are duplicates in input array, we need to print them only once.

Examples:

Input : "abc", "xy", "bcd"
Output : abc bcd xy         

Input : "geeks", "for", "geeks", "a", "portal", 
        "to", "learn", "can", "be", "computer", 
        "science", "zoom", "yup", "fire", "in", "data"
Output : a be can computer data fire for geeks
         in learn portal science to yup zoom
         
Trie is an efficient data structure used for storing data like strings. To print the string in alphabetical order we have to first insert in the trie and then perform preorder traversal to print in alphabetical order.*/
#include <iostream>
#include <string>
using namespace std;
#define MAX_CHAR 26

struct trie{
    int index;
    trie *child[MAX_CHAR];
    trie(){
        for(int i=0;i<MAX_CHAR;i++)
            child[i]=NULL;
        index=-1;
    }
};

void insert(trie *root, string str, int index)
{
    trie *node=root;
    for(int i=0;i<str.size();i++){
        char ind=str[i]-'a';
        // if the child is not present in that index make it
        if(!node->child[ind])
            node->child[ind]=new trie();
        //go to the next node
        node=node->child[ind];
    }
    // mark leaf (end of word) and store index of word in arr[]
    node->index=index;
}

bool preOrder(trie *node, string a[]){

    if(!node)   return false;
    for(int i=0;i<MAX_CHAR;i++){
        if(node->child[i]!=NULL){
            // if leaf node then print key
            // the leaf node marks the end
            // it acts like a base cond in recursion
            // first c is returned then b then a
            if(node->child[i]->index != -1)
                cout<<a[node->child[i]->index]<<endl;
            preOrder(node->child[i],a);
        }
    }
    return true;
}

void printSorted(string s[], int len)
{
    trie *root=new trie();
    //insertion
    for(int i=0;i<len;i++)
        insert(root,s[i],i);
    preOrder(root,s);
}

int main(){
    string a[]={"abc","xy","bcd"};
    int n=sizeof(a)/sizeof(a[0]);
    printSorted(a,n);
    return 0;
}