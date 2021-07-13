/*Write a program to print all permutations of a given string
Difficulty Level : Medium
Last Updated : 04 Jun, 2021
A permutation, also called an “arrangement number” or “order,” is a rearrangement of the elements of an ordered list S into a one-to-one correspondence with S itself. A string of length n has n! permutation. 

Source: Mathword(http://mathworld.wolfram.com/Permutation.html)

Below are the permutations of string ABC. 
ABC ACB BAC BCA CBA CAB

Algorithm Paradigm: Backtracking 

Time Complexity: O(n*n!) Note that there are n! permutations and it requires O(n) time to print a permutation.

Note : The above solution prints duplicate permutations if there are repeating characters in input string. Please see below link for a solution that prints only distinct permutations even if there are duplicates in input.*/

#include <iostream>
#include <string>

void premute(std::string s, std::string answer)
{
    if(!s.length()) {
        std::cout<<answer<<' ';
        return ;
    }
    for(int i=0;i<s.length(); i++)
    {
        char c=s[i];
        std::string leftstr=s.substr(0,i);
        std::string rightstr=s.substr(i+1);
        std::string rest=leftstr+rightstr;
        premute(rest,answer+c);
    }
}

int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::string s;
    std::string ans="";
    std::cout<<"enter the string: ";
    std::cin>>s;
    std::cout<<"\nall possible strings are: ";
    premute(s,ans);

    remove(argv[0]);
    return 0;
}
