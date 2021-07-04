/*Add two bit strings
Difficulty Level : Medium
Last Updated : 14 Oct, 2019
Given two bit sequences as strings, write a function to return the addition of the two sequences. Bit strings can be of different lengths also. For example, if string 1 is “1100011” and second string 2 is “10”, then the function should return “1100101”.*/
#include <iostream>
#include <string>
using namespace std;

void addZeros(string& dest, int len){
    string add;
    int i=len-dest.length();
    while(i--){
        add+='0';
    }
    dest = add+dest;
}
/*Since the sizes of two strings may be different, we first make the size of a smaller string equal to that of the bigger string by adding leading 0s. After making sizes the same, we one by one add bits from rightmost bit to leftmost bit. In every iteration, we need to sum 3 bits: 2 bits of 2 given strings and carry. The sum bit will be 1 if, either all of the 3 bits are set or one of them is set. So we can do XOR of all bits to find the sum bit. How to find carry – carry will be 1 if any of the two bits is set. So we can find carry by taking OR of all pairs. Following is step by step algorithm.

1. Make them equal sized by adding 0s at the beginning of smaller string.
2. Perform bit addition
…..Boolean expression for adding 3 bits a, b, c
…..Sum = a XOR b XOR c
…..Carry = (a AND b) OR ( b AND c ) OR ( c AND a )*/
void exec(string s1, string s2){
    if(s1.length() > s2.length())
        addZeros(s2, s1.length());
    else
        addZeros(s1,s2.length());
    int carryBit=0;
    string res;
    for(int ind=s1.length()-1; ind>=0; ind--){
        int i=(s1[ind] - '0');
        int j=(s2[ind] - '0');
        int sum=(i^j^carryBit)+'0';
        res=(char)sum+res;
        carryBit=(i&j)|(j&carryBit)|(i&carryBit);
    }
    if(carryBit)
        res='1'+res;
    
    cout<<res<<endl;
}

int main(void){
    string s1="1100011";
    string s2="10";
    exec(s1,s2);
    return 0;
}