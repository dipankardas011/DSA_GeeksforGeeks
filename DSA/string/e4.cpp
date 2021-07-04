/*Minimum Number of Manipulations required to make two Strings Anagram Without Deletion of Character
Difficulty Level : Easy
Last Updated : 30 Apr, 2021
Given two strings s1 and s2, we need to find the minimum number of manipulations required to make two strings anagram without deleting any character. 

Note:- The anagram strings have same set of characters, sequence of characters can be different. 
If deletion of character is allowed and cost is given, refer to Minimum Cost To Make Two Strings Identical
Question Source: Yatra.com Interview Experience | Set 7 

Examples: 

Input : 
       s1 = "aba"
       s2 = "baa"
Output : 0
Explanation: Both String contains identical characters

Input :
       s1 = "ddcf"
       s2 = "cedk"
Output : 2
Explanation : Here, we need to change two characters
in either of the strings to make them identical. We 
can change 'd' and 'f' in s1 or 'e' and 'k' in s2.*/
#include <bits/stdc++.h>
using namespace std;

int makeAnagramCost(string a, string b){
    int count=0;
    int charCount[26]={0};
    memset(charCount,0,26*sizeof(int));
    for(int i=0;i<a.length();i++)
        charCount[a[i]-'a']++;
    for(int i=0;i<b.length();i++)
        charCount[b[i]-'a']--;
    
    for(int i=0;i<26;i++)
        if(charCount[i]!=0)
            count+=abs(charCount[i]);
    
    return count;
}

int main(){
    string a="ddcf";
    string b="cedk";
    cout<<makeAnagramCost(a,b)<<endl;
}