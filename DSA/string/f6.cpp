/*Lexicographic rank of a string using STL
Difficulty Level : Easy
Last Updated : 12 Apr, 2019
You are given a string, find its rank among all its permutations sorted lexicographically.

Examples:

Input : str[] = "acb"
Output : Rank = 2

Input : str[] = "string"
Output : Rank = 598

Input : str[] = "cba"
Output : Rank = 6

In this post, we use the STL function “next_permutation ()” to generate all possible permutations of the given string and, as it gives us permutations in lexicographic order, we will put an iterator to find the rank of each string. While iterating when Our permuted string becomes identical to the original input string, we break from the loop and the iterator value for the last iteration is our required result.
*/
#include<bits/stdc++.h>
using namespace std;

int findRank(string str){
    string org=str;
    sort(str.begin(), str.end());

    long int i =1;
    do{
        if(str==org)
            break;
        i++;
    }while(std::next_permutation(str.begin(), str.end()));
    return i;
}
int main(void){
    string str="string";
    cout<<findRank(str)<<endl;
    return 0;
}