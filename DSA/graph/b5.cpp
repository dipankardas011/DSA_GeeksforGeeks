/*Given a sorted dictionary of an alien language, find order of characters

Given a sorted dictionary (array of words) of an alien language, find order of characters in the language.

Examples:  

Input:  words[] = {"baa", "abcd", "abca", "cab", "cad"}
Output: Order of characters is 'b', 'd', 'a', 'c'
Note that words are sorted and in the given language "baa" 
comes before "abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.

Input:  words[] = {"caa", "aaa", "aab"}
Output: Order of characters is 'c', 'a', 'b'*/
#include <iostream>
#include <list>
#include <vector>
#include <stack>

using namespace std;

class Graph{
    int v;
    list<int>* adj;
    public:
    Graph(int key){
        this->v=key;
        adj=new list<int>[v];
    }
    void addedge(int u, int v){
        adj[u].push_back(v);
    }
    void topogicalexec(int v, bool visited[], stack<int>& stk){
        visited[v]=true;
        for(auto i=adj[v].begin(); i!=adj[v].end(); i++)
        {
            if(!visited[*i])
                topogicalexec(*i, visited, stk);
        }
        stk.push(v);
    }
    void topogicalSort();
};

void Graph::topogicalSort()
{
    stack<int> s;
    bool visited[v];
    memset(visited, false, v);
    for(int i=0;i<v;i++)
        if(!visited[i])
            topogicalexec(i, visited, s);
    
    while(!s.empty())
    {
        cout<<(char)('a'+s.top())<<" ";
        s.pop();
    }
}

void extractionRAW_DATA(string w[], int n, int alpha)
{
    // aplha is the no of edges required
    Graph g(alpha);

    for(int i=0;i<n-1;i++)
    {
        string w1=w[i];
        string w2=w[i+1];
        for(int j=0;j< std::min(w1.length(), w2.length()); j++)
        {
            if(w1[j]!=w2[j]){
                g.addedge(w1[j]-'a', w2[j]-'a');
                break;
            }
        }
    }

    g.topogicalSort();
}


int main(){
    string words[] = {"caa", "aaa", "aab"};
    int size=sizeof(words)/sizeof(words[0]);
    extractionRAW_DATA(words, size, size);
    return 0;
}