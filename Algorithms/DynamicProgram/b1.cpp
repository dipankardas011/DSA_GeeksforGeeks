/*Count number of ways to reach a given score in a game
Difficulty Level : Medium
Last Updated : 09 Apr, 2021
Consider a game where a player can score 3 or 5 or 10 points in a move. Given a total score n, find number of ways to reach the given score.
Examples: 
 

Input: n = 20
Output: 4
There are following 4 ways to reach 20
(10, 10)
(5, 5, 10)
(5, 5, 5, 5)
(3, 3, 3, 3, 3, 5)

Input: n = 13
Output: 2
There are following 2 ways to reach 13
(3, 5, 5)
(3, 10)*/
#include <iostream>

int count(int n){
    int table[n+1], i;
    for(int j=0;j<n+1; j++)
        table[j]=0;
    
    table[0]=1;

    for(i=3;i<=n;i++)
        table[i]+=table[i-3];
    for(i=5;i<=n;i++)
        table[i]+=table[i-5];
    for(i=10;i<=n;i++)
        table[i]+=table[i-10];
    
    return table[n];
}

int main(int argc, char const *argv[])
{
    int n=20; // required score
    // finding the number of possible ways to get the score
    std::cout<<"count for score "<<n<<"= "<<count(n)<<std::endl;
    remove(argv[0]);
    return 0;
}
