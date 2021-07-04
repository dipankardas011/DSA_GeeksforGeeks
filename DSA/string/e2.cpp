/*Print all pairs of anagrams in a given array of strings
Difficulty Level : Medium
Last Updated : 23 Apr, 2021
Given an array of strings, find all anagram pairs in the given array. 
Example: 
 

Input: arr[] =  {"geeksquiz", "geeksforgeeks", "abcd",
                 "forgeeksgeeks", "zuiqkeegs"};
Output: (geeksforgeeks, forgeeksgeeks), (geeksquiz, zuiqkeegs)*/
#include <bits/stdc++.h>
using namespace std;
#define maxChar 256

bool areAnagram(string s1,string s2){
    int count[maxChar]={0};
    int i;
    for(i=0; s1[i] && s2[i] ;i++)
    {
        count[s1[i]]++;
        count[s2[i]]--;
    }
    if(s1[i]||s2[i])
        return false;

    for(i=0;i<maxChar;i++)
        if(count[i])
            return false;
    return true;
}

int main(){
    string arr[] =  {"geeksquiz", "geeksforgeeks", "abcd",
                 "forgeeksgeeks", "zuiqkeegs"};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(areAnagram(arr[i],arr[j]))
                cout<<"( "<<arr[i]<<", "<<arr[j]<<" )"<<endl;
    return 0;
}