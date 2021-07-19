/*How to check if two given sets are disjoint?
Difficulty Level : Easy
Last Updated : 21 Jun, 2021
Given two sets represented by two arrays, how to check if the given two sets are disjoint or not? It may be assumed that the given arrays have no duplicates.

Input: set1[] = {12, 34, 11, 9, 3}
       set2[] = {2, 1, 3, 5}
Output: Not Disjoint
3 is common in two sets.

Input: set1[] = {12, 34, 11, 9, 3}
       set2[] = {7, 2, 1, 5}
Output: Yes, Disjoint   */
#include <iostream>
#include <set>

bool areDisjoint(int *set1, int *set2, int n1, int n2)
{
    std::set<int> hash;

    for(int i=0;i<n1; i++)
        hash.insert(*(set1+i));

    for(int i=0;i<n2; i++)
        if(hash.find(*(set2+i)) != hash.end())
            return false;

    return true;
}

int main(int argc, char const *argv[])
{
    int set1[]={10,5,3,4,6};
    int set2[]={8,7,9,3};
    int n1=sizeof set1 / sizeof set1[0];
    int n2=sizeof set2 / sizeof set2[0];

    if(areDisjoint(set1,set2,n1,n2))
        std::cout<<"Yes\n";
    else
        std::cout<<"No\n";
    remove(argv[0]);
    return 0;
}
