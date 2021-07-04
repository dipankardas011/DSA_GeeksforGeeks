/*Move all occurrences of an element to end in a linked list
Difficulty Level : Medium
Last Updated : 18 May, 2021
Given a linked list and a key in it, the task is to move all occurrences of the given key to the end of the linked list, keeping the order of all other elements the same.

Examples:  

Input  : 1 -> 2 -> 2 -> 4 -> 3
         key = 2 
Output : 1 -> 4 -> 3 -> 2 -> 2

Input  : 6 -> 6 -> 7 -> 6 -> 3 -> 10
         key = 6
Output : 7 -> 3 -> 10 -> 6 -> 6 -> 6
Efficient Solution 3: is to maintain a separate list of keys. We initialize this list of keys as empty. We traverse the given list. For every key found, we remove it from the original list and insert it into a separate list of keys. We finally link the list of keys at the end of the remaining given list. The time complexity of this solution is also O(n) and it also requires only one traversal of the list.*/
#include <iostream>
#include <list>
using namespace std;
int key=2;

int main(){
    int count=0;
    list<int> l={1,2,2,4,3};
    for(auto it=l.begin(); it!=l.end(); it++)
        if(*it == key)
            count++;
    
    l.remove_if([](int x){return x==key;});

    for(int i=0;i<count;i++)
        l.push_back(key);

    for(auto it=l.begin(); it!=l.end() && printf("->"); it++)
        cout<<(*it);
    cout<<endl;
    return 0;
}