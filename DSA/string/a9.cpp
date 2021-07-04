/*Count of distinct substrings of a string using Suffix Trie

Given a string of length n of lowercase alphabet characters, we need to count total number of distinct substrings of this string.
Examples:

Input  : str = “ababa”
Output : 10
Total number of distinct substring are 10, which are,
"", "a", "b", "ab", "ba", "aba", "bab", "abab", "baba"
and "ababa"

The idea is create a Trie of all suffixes of given string. Once the Trie is constricted, our answer is total number of nodes in the constructed Trie. For example below diagram represent Trie of all suffixes for “ababa”. Total number of nodes is 10 which is our answer.

How does this work?
Each root to node path of a Trie represents a prefix of words present in Trie. Here we words are suffixes. So each node represents a prefix of suffixes.
Every substring of a string “str” is a prefix of a suffix of “str”.*/
#include <bits/stdc++.h>
using namespace std;
#define MAX_CHAR 26

class suffixtrienode{
    public:
    suffixtrienode *child[MAX_CHAR];
    suffixtrienode(){
        for(int i=0;i<MAX_CHAR;i++)
            child[i]=NULL;
    }
    // to insert a suffix of the s in subtree rooted with this node
    void insertSuffix(string suffix);
};

class suffixtrie{
    suffixtrienode *root;
    int _countNodesInTrie(suffixtrienode *);
    public:

    suffixtrie(string s){
        root=new suffixtrienode();

        for(int i=0;i<s.length();i++)
            root->insertSuffix(s.substr(i));
    }

    // to count total nodes in suffix trie
    int countNodesInTrie(){
        return _countNodesInTrie(root);
    }
};

void suffixtrienode::insertSuffix(string s){
    if(s.length() > 0){
        // here are are making the first char as the key in trie tree
        char cindex=s.at(0)-'a';

        if(child[cindex]==NULL)
            child[cindex]=new suffixtrienode();

        child[cindex]->insertSuffix(s.substr(1));
    }
}

int suffixtrie::_countNodesInTrie(suffixtrienode *node)
{
    if(!node)   return 0;

    int count=0;
    for(int i=0;i<MAX_CHAR;i++)
        if(node->child[i]!=NULL)
            count+=_countNodesInTrie(node->child[i]);

    return (count+1);
}

int countDistinctSubstring(string s){
    suffixtrie obj(s);
    cout<<"sizeof(u_int32_t)"<<sizeof(u_int64_t)<<endl;
    return obj.countNodesInTrie();
}

int main(){
    string str = "ababa";
    cout << "Count of distinct substrings is "<< countDistinctSubstring(str)<<endl;
    return 0;
}