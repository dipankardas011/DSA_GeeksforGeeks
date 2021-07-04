/*Trie | (Delete)

In the previous post on trie we have described how to insert and search a node in trie. Here is an algorithm how to delete a node from trie.
During delete operation we delete the key in bottom up manner using recursion. The following are possible conditions when deleting key from trie, 

Key may not be there in trie. Delete operation should not modify trie.
Key present as unique key (no part of key contains another key (prefix), nor the key itself is prefix of another key in trie). Delete all the nodes.
Key is prefix key of another long key in trie. Unmark the leaf node.
Key present in trie, having atleast one other key as prefix key. Delete nodes from end of key until first leaf node of longest prefix key.*/
#include <bits/stdc++.h>
using namespace std;

#define AlphabetSize 26

struct Trienode
{
    struct Trienode *children[AlphabetSize];
    bool IsEndOfWord;
};

Trienode *getNode()
{
    Trienode *t = new Trienode;
    t->IsEndOfWord = false;
    for (int i = 0; i < AlphabetSize; i++)
        t->children[i] = NULL;

    return t;
}

void insert(Trienode *root, string key)
{
    Trienode *pcrawl = root;
    for (int i = 0; i < key.size(); i++)
    {
        // assuming that the all the letter are small alphabets
        int index = key[i] - 'a';
        if (!pcrawl->children[index])
            pcrawl->children[index] = getNode();

        pcrawl = pcrawl->children[index];
    }
    // marks the last node as leaf
    pcrawl->IsEndOfWord = true;
}

bool search(Trienode *root, string key)
{
    Trienode *pcrawl = root;
    for (int i = 0; i < key.size(); i++)
    {
        int index = key[i] - 'a';
        if (!pcrawl->children[index])
            // not there
            return false;

        pcrawl = pcrawl->children[index];
    }
    return (pcrawl != NULL && pcrawl->IsEndOfWord);
}

bool isempty(Trienode* root){
    for(int i=0;i<AlphabetSize;i++)
    if(root->children[i])   return false;
    return true;
}

Trienode *remove(Trienode* root, string key, int depth=0){
    if(!root)   return NULL;
    if(depth==key.size()){
        // character of the tree
        // so removing it then tree will not have endWord
        if(root->IsEndOfWord)   root->IsEndOfWord=false;

        if(isempty(root)){
            delete(root);
            root=NULL;
        }
        return root;
    }

    int index=key[depth]-'a';
    root->children[index]=remove(root->children[index],key,depth+1);
    if(isempty(root) && root->IsEndOfWord==false)
    {
        delete(root);
        root=NULL;
    }
    return root;
}

int main(){
    string keys[] = { "the", "a", "there",
                      "answer", "any", "by",
                      "bye", "their", "hero", "heroplane" };
    int n = sizeof(keys) / sizeof(keys[0]);
 
    struct Trienode* root = getNode();
 
    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);
 
    // Search for different keys
    search(root, "the") ? cout << "Yes\n" : cout << "No\n";
    search(root, "these") ? cout << "Yes\n" : cout << "No\n";
 
    remove(root, "heroplane");
    search(root, "hero") ? cout << "Yes\n" : cout << "No\n";
    return 0;
}