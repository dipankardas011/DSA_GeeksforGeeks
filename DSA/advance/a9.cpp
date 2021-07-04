/*Print all valid words that are possible using Characters of Array

Given a dictionary and a character array, print all valid words that are possible using characters from the array.

Examples:

Input : Dict - {"go","bat","me","eat","goal", 
                                "boy", "run"} 
        arr[] = {'e','o','b', 'a','m','g', 'l'} 
Output : go, me, goal. 
Asked In : Microsoft Interview

The idea is to use Trie data structure to store dictionary, then search words in Trie using characters of given array.



1.Create an empty Trie and insert all words of given dictionary into the Trie.
2.After that, we have pick only those characters in ‘Arr[]’ which are a child of the root of Trie.
3.To quickly find whether a character is present in array or not, we create a hash of character arrays.*/
#include <bits/stdc++.h>
using namespace std;
#define char_int(c) ((int)c-(int)'a')

#define int_to_char(c) ((char)c+(char)'a')

#define size 26

struct trienode
{
    trienode* child[size];
    bool leaf;
};

trienode* getnode(void)
{
    trienode* node=new trienode;
    node->leaf=false;
    for(int i=0;i<size;i++)
        node->child[i]=NULL;

    return node;
}

void insert(trienode* root, char* key)
{
    int n=strlen(key);
    trienode* pchild=root;
    for(int i=0;i<n;i++){
        int index=char_int(key[i]);
        if(pchild->child[index]==NULL)
            pchild->child[index]=getnode();
        pchild=pchild->child[index];
    }
    pchild->leaf=true;
}

void searchWord(trienode* root, bool hash[], string str){
    // found word in trie/dictionary
    if(root->leaf==true)
        cout<<str<<endl;
    for(int k=0;k<size;k++)
    {
        if(hash[k]==true && root->child[k]!=NULL)
        {
            char c=int_to_char(k);

            searchWord(root->child[k],hash, str+c);
        }
    }
}

void printallwords(char arr[], trienode* root, int n)
{
    bool hash[size];
    for(int i=0;i<n;i++)
        hash[char_int(arr[i])]=true;
    trienode* pchild=root;
    string str="";
    for(int i=0;i<size;i++)
    {
        // we start searching for word in dictionary
        // if we found a character which is child
        // of Trie root
        if (hash[i] == true && pchild->child[i] )
        {
            str = str+(char)int_to_char(i);
            searchWord(pchild->child[i], hash, str);
            str = "";
        }
    }
}

int main(){
    // Let the given dictionary be following
    char Dict[][20] = {"go", "bat", "me", "eat",
                       "goal", "boy", "run"} ;
  
    // Root Node of Trie
    trienode *root = getnode();
  
    // insert all words of dictionary into trie
    int n = sizeof(Dict)/sizeof(Dict[0]);
    for (int i=0; i<n; i++)
        insert(root, Dict[i]);
  
    char arr[] = {'e', 'o', 'b', 'a', 'm', 'g', 'l'} ;
    int N = sizeof(arr)/sizeof(arr[0]);
  
    printallwords(arr, root, N);
    return 0;
}