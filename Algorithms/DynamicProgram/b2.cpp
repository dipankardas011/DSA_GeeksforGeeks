/*Longest Even Length Substring such that Sum of First and Second Half is same
Difficulty Level : Hard
Last Updated : 21 May, 2021
Given a string ‘str’ of digits, find the length of the longest substring of ‘str’, such that the length of the substring is 2k digits and sum of left k digits is equal to the sum of right k digits. 
Examples : 

Input: str = "123123"
Output: 6
The complete string is of even length and sum of first and second
half digits is same

Input: str = "1538023"
Output: 4
The longest substring with same first and second half sum is "5380"*/
#include <iostream>
#include <string>

int findLength(std::string str, int n)
{
    int ans = 0;

    for (int i = 0; i <= n - 2; i++)
    {
        /* For current midpoint 'i', keep expanding substring on both sides, if sum of both sides becomes equal update ans */
        int l = i, r = i + 1;

        int lsum=0, rsum=0;
        while(l<r && l>=0)
        {
            lsum+=str[l]-'0';
            rsum+=str[r]-'0';
            if(lsum==rsum)
                ans=std::max(lsum,rsum);
            l--;
            r++;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    std::string str="123123";
    std::cout<<"length of the substrning= "<<findLength(str,str.length())<<std::endl;
    remove(argv[0]);
    return 0;
}
