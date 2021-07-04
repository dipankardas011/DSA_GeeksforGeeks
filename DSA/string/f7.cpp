/*Lexicographically smallest string obtained after concatenating array
Difficulty Level : Easy
Last Updated : 27 May, 2021
Given n strings, concatenate them in an order that produces the lexicographically smallest possible string.
Examples: 
 

Input :  a[] = ["c", "cb", "cba"]
Output : cbacbc
Possible strings are ccbcba, ccbacb, 
cbccba, cbcbac, cbacbc and cbaccb. 
Among all these strings, cbacbc is 
the lexicographically smallest.

Input :  a[] = ["aa", "ab", "aaa"]
Output : aaaaaab*/
#include<bits/stdc++.h>
using namespace std;

bool compare(string a, string b){
    return (a+b < b+a);
}

string lexSmallest(string a[], int n){
    sort(a,a+n,compare);
    string ans="";
    for(int i=0;i<n;i++)
        ans+=a[i];

    return ans;
}

int main(void){
    string a[]={"c","cb","cba"};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<lexSmallest(a,n)<<endl;
    return 0;
}