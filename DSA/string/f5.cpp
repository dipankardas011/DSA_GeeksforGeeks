/*Generate n-bit Gray Codes
Difficulty Level : Medium
Last Updated : 15 Jun, 2021
Given a number N, generate bit patterns from 0 to 2^N-1 such that successive patterns differ by one bit. 

Examples:

Input: N = 2
Output: 00 01 11 10

Input: N = 3
Output: 000 001 011 010 110 111 101 100
n-bit Gray Codes can be generated from list of (n-1)-bit Gray codes using following steps. 

Let the list of (n-1)-bit Gray codes be L1. Create another list L2 which is reverse of L1.
Modify the list L1 by prefixing a ‘0’ in all codes of L1.
Modify the list L2 by prefixing a ‘1’ in all codes of L2.
Concatenate L1 and L2. The concatenated list is required list of n-bit Gray codes
For example, following are steps for generating the 3-bit Gray code list from the list of 2-bit Gray code list. 
L1 = {00, 01, 11, 10} (List of 2-bit Gray Codes) 
L2 = {10, 11, 01, 00} (Reverse of L1) 
Prefix all entries of L1 with ‘0’, L1 becomes {000, 001, 011, 010} 
Prefix all entries of L2 with ‘1’, L2 becomes {110, 111, 101, 100} 
Concatenate L1 and L2, we get {000, 001, 011, 010, 110, 111, 101, 100}
To generate n-bit Gray codes, we start from list of 1 bit Gray codes. The list of 1 bit Gray code is {0, 1}. We repeat above steps to generate 2 bit Gray codes from 1 bit Gray codes, then 3-bit Gray codes from 2-bit Gray codes till the number of bits becomes equal to n. 

Method3: (Using bitset)

We should first find binary no from 1 to n and then convert it into string and then print it using substring function of string.*/
#include <bits/stdc++.h>
using namespace std;
void greyCode(int n){
    for(int i=0;i<(1<<n);i++)
    {
        int val=(i^(i>>1));
        std::bitset<32> r(val);
        string s=r.to_string();
        cout<<s.substr(32-n)<<endl;
    }
}

int main(void){
    int n;
    n=5;
    greyCode(n);
    return 0;
}