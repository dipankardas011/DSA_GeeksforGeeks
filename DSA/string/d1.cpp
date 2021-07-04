/*Convert to a string that is repetition of a substring of k length
Difficulty Level : Medium
Last Updated : 17 Jun, 2021
Given a string, find if it is possible to convert it to a string that is the repetition of a substring with k characters. To convert, we can replace one substring of length k with k characters.

Examples:  

Input: str = "bdac",  k = 2
Output: True
We can either replace "bd" with "ac" or 
"ac" with "bd".

Input: str = "abcbedabcabc",  k = 3
Output: True
Replace "bed" with "abc" so that the 
whole string becomes repetition of "abc".

Input: str = "bcacc", k = 3
Output: False
k doesn't divide string length i.e. 5%3 != 0

Input: str = "bcacbcac", k = 2
Output: False

Input: str = "bcdbcdabcedcbcd", k = 3
Output: False
This can be used in compression. If we have a string where the complete string is repetition except one substring, then we can use this algorithm to compress the string

One observation is, length of string must be a multiple of k as we can replace only one substring. 
The idea is to declare a map mp which maps strings of length k to an integer denoting its count. So, if there are only two different sub-strings of length k in the map container and the count of one of the sub-string is 1 then the answer is true. Otherwise, answer is false*/
#include <unordered_map>
#include <iostream>
using namespace std;

bool checking(string str, int k){
    int n=str.length();
    if(n%k!=0)
        return false;

    unordered_map<string,int> mp;
    for(int i=0;i<n;i+=k){
        mp[str.substr(i,k)]++;
    }
    // if the groups are only 1
    if(mp.size()==1)
        return true;
    // it the groups are more than 2 or no groups
    if(mp.size()!=2)
        return false;

    /*One of the two distinct must appear exactly once. Either the first entry appears once, or it appears n/k-1 times to make other substring appear once.*/
    if((mp.begin()->second == (n/k-1)) || (mp.begin()->second==1))
        return true;

    return false;
}


int main(int argc, char const *argv[])
{
    cout<<((checking("abcbedabcabc",3))?"YES":"NO")<<endl;
    return 0;
}
