/*sLength of Longest Balanced Subsequence
Difficulty Level : Medium
Last Updated : 24 May, 2021
Given a string S, find the length of the longest balanced subsequence in it. A balanced string is defined as:- 

A null string is a balanced string.
If X and Y are balanced strings, then (X)Y and XY are balanced strings.
Examples: 

Input : S = "()())"
Output : 4

()() is the longest balanced subsequence 
of length 4.

Input : s = "()(((((()"
Output : 4

Approach 2: This approach solves the problem in a more efficient manner. 

* Count the number of braces to be removed to get the longest balanced parentheses sub-sequence.
* If the i-th index number of close braces is greater than the number of open braces, then that close brace has to be removed.
* Count the number of close braces that need to be removed.
* In the end, the number of extra open braces will also be removed.
* So, the total count to be removed would be the sum of extra open braces and invalid close braces. */
#include <iostream>
#include <cstring>
using namespace std;

int maxLength(char s[], int n){
    // As it's subsequence - assuming first open brace would map to a first close brace which occurs after the open brace to make subsequence balanced and second open brace would map to second close brace and so on. Variable to count all the open brace that does not have the corresponding closing brace.
    int INVopenBrac=0;
    int INVclosBrac=0;
    for(int i=0;i<n;i++){
        if(s[i]=='(')
            INVopenBrac++;
        else{
            if(INVopenBrac==0) // number of clos bracs that cannot be mapped to any open brace
                INVclosBrac++;
            
            else    //mapping the ith closing brace to tone of the open brace
                INVopenBrac--;
        }
    }
    return (n-(INVopenBrac+INVclosBrac));
}

int main(){
    char s[]="()(((((()";
    int n=strlen(s);
    cout<<maxLength(s,n)<<endl;
    return 0;
}