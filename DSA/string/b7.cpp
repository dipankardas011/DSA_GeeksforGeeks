/*Check if strings are rotations of each other or not | Set 2

Given two strings s1 and s2, check whether s2 is a rotation of s1. 
Examples: 

Input : ABACD, CDABA
Output : True

Input : GEEKS, EKSGE
Output : True
We have discussed an approach in earlier post which handles substring match as a pattern. In this post, we will be going to use KMP algorithm’s lps (longest proper prefix which is also suffix) construction, which will help in finding the longest match of the prefix of string b and suffix of string a. By which we will know the rotating point, from this point match the characters. If all the characters are matched, then it is a rotation, else not.*/
// C++ program to check if
// two strings are rotations
// of each other
#include <bits/stdc++.h>
using namespace std;

bool isRotation(string s1, string s2){
    //to check if the s2 rotation of s1
    // rotate s2

    if(s1.length() != s2.length())  return false;
    int ind=1;
    int start=s2.length()-1;
    int end=s2.length()-2;
    while(ind++ < s2.length())
    {
        //rotate
        // using the index
        string kk=s2.substr(start)+s2.substr(0,end+1);
        // cout<<kk<<endl;
        int iter;
        for(iter=0;iter<s1.length();iter++)
            if(kk[iter] != s1[iter])
                break;
        if(iter==s1.length())
            return true;
        start--;
        end--;
    }
    return false;
}

int main(){
    string s1="ABACD";
    string s2="CDABA";
    cout<<(isRotation(s1,s2)?"YES" : "NO")<<endl;

    string s21="GEEKS";
    string s22="EKSGE";
    cout<<(isRotation(s21,s22)?"YES" : "NO")<<endl;
    return 0;
}