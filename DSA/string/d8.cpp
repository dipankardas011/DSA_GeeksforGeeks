/*Print all possible strings that can be made by placing spaces
Difficulty Level : Medium
Last Updated : 29 Apr, 2021
Given a string you need to print all possible strings that can be made by placing spaces (zero or one) in between them 

Examples : 

Input :  str[] = "ABC"
Output : ABC
         AB C
         A BC
         A B C

Input : str[] = "ABCD"
Output : ABCD
         A BCD
         AB CD
         A B CD
         ABC D
         A BC D
         AB C D
         A B C D*/
#include <bits/stdc++.h>
using namespace std;

void printSubsequences(string str){
    int n=str.length();
    unsigned int opsize=pow(2,n-1);
    for(int counter=0;counter<opsize;counter++){
        for(int j=0;j<n;j++){
            cout<<str[j];
            if(counter & (1<<j))
                cout<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    string str = "ABC";
    printSubsequences(str);
    return 0;
}