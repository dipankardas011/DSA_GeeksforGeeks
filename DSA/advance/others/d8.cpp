/*LRU Cache Implementation
Difficulty Level : Hard
How to implement LRU caching scheme? What data structures should be used? 
We are given total possible page numbers that can be referred. We are also given cache (or memory) size (Number of page frames that cache can hold at a time). The LRU caching scheme is to remove the least recently used frame when the cache is full and a new page is referenced which is not there in cache. Please see the Galvin book for more details (see the LRU page replacement slide here).
 

Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.
We use two data structures to implement an LRU Cache. 
 

Queue which is implemented using a doubly linked list. The maximum size of the queue will be equal to the total number of frames available (cache size). The most recently used pages will be near front end and least recently pages will be near the rear end. 
 
A Hash with page number as key and address of the corresponding queue node as value.
When a page is referenced, the required page may be in the memory. If it is in the memory, we need to detach the node of the list and bring it to the front of the queue. 
If the required page is not in memory, we bring that in memory. In simple words, we add a new node to the front of the queue and update the corresponding node address in the hash. If the queue is full, i.e. all the frames are full, we remove a node from the rear of the queue, and add the new node to the front of the queue.
Example – Consider the following reference string : 
 

1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5
Find the number of page faults using least recently used (LRU) page replacement algorithm with 3 page frames. 
Explanation –s*/
#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUcache{
    list<int> dq;
    unordered_map<int, list<int>::iterator> ma;
    int csize;
    public:
    LRUcache(int);
    void refer(int);
    void display();
};

LRUcache::LRUcache(int n){
    csize=n;
}
// refer key x with in the LRU cache
void LRUcache::refer(int x)
{
    // not present in cache
    if(ma.find(x) == ma.end()){
        //cache is full
        if(dq.size() == csize){
            int last=dq.back();
            dq.pop_back();
            ma.erase(last);
        }
    }
    else{
        //present in chace
        dq.erase(ma[x]);
    }
    // update reference
    dq.push_front(x);
    ma[x]=dq.begin();
}

void LRUcache::display(){

    for(auto it=dq.begin(); it!=dq.end();it++)
        cout<<(*it)<<"\t";
    cout<<endl;
}

int main(){
    LRUcache ca(4);

    ca.refer(1);

    ca.refer(2);

    ca.refer(3);

    ca.refer(4);

    ca.refer(5);

    ca.display();

    return 0;
}