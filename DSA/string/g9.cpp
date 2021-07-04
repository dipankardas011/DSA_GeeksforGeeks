/*Minimum Word Break
Difficulty Level : Expert
Last Updated : 05 Feb, 2019
Given a string s, break s such that every substring of the partition can be found in the dictionary. Return the minimum break needed.
Examples:

Given a dictionary ["Cat", "Mat", "Ca", 
     "tM", "at", "C", "Dog", "og", "Do"]

Input :  Pattern "CatMat"
Output : 1 
Explanation: we can break the sentences
in three ways, as follows:
CatMat = [ Cat Mat ]  break 1
CatMat = [ Ca tM at ] break 2
CatMat = [ C at Mat ] break 2  so the 
         output is: 1

Input : Dogcat
Output : 1
Asked in: Facebook*/
/*Solution of this problem is based on the WordBreak Trie solution and level ordered graph. We start traversing given pattern and start finding a character of pattern in a trie. If we reach a node(leaf) of a trie from where we can traverse a new word of a trie(dictionary), we increment level by one and call search function for rest of the pattern character in a trie. In the end, we return minimum Break.

  MinBreak(Trie, key, level, start = 0 )
  ....  If start == key.length()
      ...update min_break
  for i = start to keylenght 
  ....If we found a leaf node in trie 
        MinBreak( Trie, key, level+1, i )*/

#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];

    // isEndOfWord is true if the node
    // represents end of a word
    bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

// If not present, inserts the key into the trie
// If the key is the prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}

// function break the string into minimum cut
// such the every substring after breaking
// in the dictionary.
void minWordBreak(struct TrieNode *root, string key, int start, int *min_Break, int level = 0)
{
    struct TrieNode *pCrawl = root;

    // base case, update minimum Break
    if (start == key.length())
    {
        *min_Break = std::min(*min_Break, level - 1);
        return;
    }

    // traverse given key(pattern)
    int minBreak = 0;
    for (int i = start; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return;

        // if we find a condition were we can
        // move to the next word in a trie
        // dictionary
        if (pCrawl->children[index]->isEndOfWord)
            minWordBreak(root, key, i + 1, min_Break, level + 1);

        pCrawl = pCrawl->children[index];
    }
}

int main()
{
    string dictionary[] = {"Cat", "Mat",
                           "Ca", "Ma", "at", "C", "Dog", "og", "Do"};
    int n = sizeof(dictionary) / sizeof(dictionary[0]);
    struct TrieNode *root = getNode();

    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, dictionary[i]);
    int min_Break = INT_MAX;

    minWordBreak(root, "CatMatat", 0, &min_Break, 0);
    cout << min_Break << endl;
    return 0;
}