/*1’s and 2’s complement of a Binary Number
Given a Binary Number as a string, print its 1’s and 2’s complements.

1’s complement of a binary number is another binary number obtained by toggling all bits in it, i.e., transforming the 0 bit to 1 and the 1 bit to 0.

Examples: 

1's complement of "0111" is "1000"
1's complement of "1100" is  "0011" 
2’s complement of a binary number is 1, added to the 1’s complement of the binary number. 

Examples: 

2's complement of "0111" is  "1001"
2's complement of "1100" is  "0100" 
Another trick to finding two’s complement:
Step 1:  Start from the Least Significant Bit and traverse left until you find a 1.  Until you find 1, the bits stay the same

Step 2: Once you have found 1, let the 1 as it is, and now

Step 3: Flip all the bits left into the 1.

Illustration
Suppose we need to find 2s Complement of 100100

Step 1: Traverse and let the bit stay the same until you find 1. Here x is not known yet. Answer = xxxx00 –

Step 2: You found 1. Let it stay the same. Answer = xxx100

Step 3: Flip all the bits left into the 1. Answer = 011100.

Hence, the 2s complement of 100100 is 011100.*/
#include <iostream>
#include <string>

using namespace std;

char flipBit(char bit)
{
    return (bit=='0')?'1':'0';
}

void onesComplement(string &x)
{
    for (int i = 0; i < x.length(); i++)
        x[i] = flipBit(x[i]);
}

void exec(string bits)
{
    string ones = bits;
    // 1's complement
    onesComplement(ones);
    std::cout << "the 1's complement= " << ones << std::endl;
    string twos = bits;
    int bitInd = 0;
    for (int i = twos.length() - 1; i >= 0; i--)
    {
        if ((twos[i] - '0') == 1)
        {
            bitInd = i - 1;
            break;
        }
    }
    if (bitInd < 0)
    {
        cout << "the 2's complement = " << twos << endl;
        return;
    }
    while (bitInd >= 0)
    {
        twos[bitInd] = flipBit(twos[bitInd]);
        bitInd--;
    }
    cout << "the 2's complement = " << twos << endl;
    return;
}

int main(void)
{
    string xyz="1100";
    exec(xyz);
    return 0;
}