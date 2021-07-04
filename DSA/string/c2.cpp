/*Program to sort string in descending order
Difficulty Level : Basic
Last Updated : 04 May, 2021
Given a string, sort it in descending order.
Examples: 
 

Input : alkasingh
Output : snlkihgaa 

Input : nupursingh
Output : uusrpnnihg 

Input : geeksforgeeks
Output : ssrokkggfeeee */

#include <bits/stdc++.h>
using namespace std;
#define max_char 26

void sortString(string s){
    int charCount[max_char]={0};
    for(int i=0;i<s.length();i++){
        charCount[s[i]-'a']++;
    }
    for(int i=max_char-1;i>=0;i--)
        for(int j=0;j<charCount[i];j++)
            cout<<(char)('a' + i);
    return;
}

int main(){
    // create a hash table
    string s="alkasingh";
    sortString(s);
    cout<<endl;
    return 0;
}