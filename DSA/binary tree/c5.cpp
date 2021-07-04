/*Minimum swap required to convert binary tree to binary search tree
Given the array representation of Complete Binary Tree i.e, if index i is the parent, index 2*i + 1 is the left child and index 2*i + 2 is the right child. The task is to find the minimum number of swap required to convert it into Binary Search Tree.

Examples:  

Input : arr[] = { 5, 6, 7, 8, 9, 10, 11 }
Output : 3
Binary tree of the given array:
       5
    6     7
  8 9   10 11
Swap 1: Swap node 8 with node 5.
Swap 2: Swap node 9 with node 10.
Swap 3: Swap node 10 with node 7.
       8
    6     10
  5 7   9  11

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static int N;
int fcount=0;
void inorder(int arr[],vector<int>& v,int index){
    if(index<N){
        inorder(arr,v,2*index+1);
        v.push_back(arr[index]);
        inorder(arr,v,2*index+2);
    }
}

bool compare(int x,int y){
    if(x>y){
        fcount++;
        return true;
    }
    return false;
}

int main(){
    int arr[]={5, 6, 7, 8, 9, 10, 11};
    N=sizeof(arr)/sizeof(arr[0]);
    vector<int> v;
    inorder(arr,v,0);
    int final[N];
    int i=0;
    for(auto& it:v){
        final[i++]=it;
    }
    
    sort(final,final+N,compare);
    // it depends on algorithm
    cout<<"min no. of steps: "<<fcount<<endl;
}