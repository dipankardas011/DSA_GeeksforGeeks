/*Find a string in lexicographic order which is in between given two strings
Difficulty Level : Easy
Last Updated : 18 May, 2021
Given two strings S and T, find a string of the same length which is lexicographically greater than S and smaller than T. Print “-1” if no such string is formed.(S > T) 
Note: string S = s1s2… sn is said to be lexicographically smaller than string T = t1t2… tn, if there exists an i, such that s1 = t1, s2 = t2, … si – 1 = ti – 1, si < ti.
Examples: 
 

Input : S = "aaa", T = "ccc"
Output : aab
Explanation: 
Here, 'b' is greater than any 
letter in S[]('a') and smaller 
than any letter in T[]('c').

Input : S = "abcde", T = "abcdf"
Output : -1
Explanation: 
There is no other string between
S and T.*/
#include <iostream>
#include <string>

using namespace std;

string lexNext(string s, int n){
    for(int i=n-1;i>=0;i--){

        if(s[i]!='z'){
            s[i]++;
            return s;
        }
        s[i]='a';
    }
    return s;
}

int main(void){
    string s="abcdeg",t="abcfgh";
    int n=s.length();
    string res=lexNext(s,n);

    cout<<((res!=t)?res:"-1")<<endl;
    return 0;
}