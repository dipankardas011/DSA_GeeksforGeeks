/*Check whether two strings are anagram of each other
Difficulty Level : Easy
Last Updated : 15 Jun, 2021
 
Write a function to check whether two given strings are anagram of each other or not. An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, “abcd” and “dabc” are an anagram of each other.*/
#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s1, string s2){
    int n1=s1.length();
    int n2=s2.length();

    if(n1!=n2)
        return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    for(int i=0;i<n1;i++)
        if(s1[i]!=s2[i])
            return false;
    return true;
}

int main(){
    string s1="triangle";
    string s2="integral";
    cout<<((isAnagram(s1,s2))? "the 2 strings are anagram":"the 2 strings are not a anagram")<<endl;
    return 0;
}