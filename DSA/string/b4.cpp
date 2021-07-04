/*Longest common subsequence with permutations allowed
Difficulty Level : Easy
Last Updated : 06 Nov, 2020
Given two strings in lowercase, find the longest string whose permutations are subsequences of given two strings. The output longest string must be sorted.

Examples:

Input  :  str1 = "pink", str2 = "kite"
Output : "ik" 
The string "ik" is the longest sorted string 
whose one permutation "ik" is subsequence of
"pink" and another permutation "ki" is 
subsequence of "kite". 

Input  : str1 = "working", str2 = "women"
Output : "now"

Input  : str1 = "geeks" , str2 = "cake"
Output : "ek"

Input  : str1 = "aaaa" , str2 = "baba"
Output : "aa"*/
#include <bits/stdc++.h>
using namespace std;

void exec(string s1, string s2)
{
    int c1[26]={0};
    int c2[26]={0};
    for(int i=0;i<s1.length();i++)
        c1[s1[i]-'a']++;
    for(int i=0;i<s2.length();i++)
        c2[s2[i]-'a']++;

    string s;
    for(int i=0;i<26;i++)
    // if no occurences the j<=0
        for(int j=1;j<=min(c1[i],c2[i]);j++)
            s.push_back(i+'a');
    
    cout<<s<<endl;
}

int main(){
    exec("pink","kite");
    exec("working","women");
    exec("geeks","cake");
    exec("aaaa","baba");
    return 0;
}