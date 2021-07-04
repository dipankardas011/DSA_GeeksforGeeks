/*Find nth term of the Dragon Curve Sequence
Difficulty Level : Easy
Last Updated : 26 Apr, 2021
Dragon Curve Sequence is an infinite binary sequence of 0s and 1s. The first term of the sequence is 1. 
From the next term, we alternately insert 1 and 0 between each element of the previous term. 
To understand better refer the following explanations:
 

1 (starts with 1) 
 
“1” 1 “0” 
1 and 0 are inserted alternately to the left and right of the previous term. Here the number in the double quotes represents the newly added elements.
So the second term becomes 
1 1 0
“1” 1 “0” 1 “1” 0 “0” 
So the third term becomes 
1 1 0 1 1 0 0 
 
“1” 1 “0” 1 “1” 0 “0” 1 “1” 1 “0” 0 “1” 0 “0” 
The fourth term becomes 
1 1 0 1 1 0 0 1 1 1 0 0 1 0 0 
 
This is also popularly known as the regular paperfolding sequence. Given a natural number n. The task is to find the nth string formed by Dragon Curve sequence of length 2^n - 1 .
Examples:
 

Input: n = 4
Output: 110110011100100
Explanation:
We get 1 as the first term, 
"110" as the second term,
"1101100" as the third term ,
And hence our fourth term will be
"110110011100100"

Input: n = 3
Output: 1101100*/
#include <string>
#include <iostream>
using namespace std;

string dragonCurveSequence(int n){
    string s="1";
    for(int i=2;i<=n;i++){
        string temp="1";
        char prev='1',zero='0',one='1';
        for(int j=0;j<s.length();j++)
        {
            temp+=s[j];
            if(prev=='0'){
                temp+=one;
                prev=one;
            }
            else{
                // if previous add term was '1' then add '0'
                temp+=zero;

                prev=zero;
            }
        }
        s=temp;
    }
    return s;
}

int main(){
    int n=4;
    string s=dragonCurveSequence(n);
    cout<<s<<endl;
    return 0;
}