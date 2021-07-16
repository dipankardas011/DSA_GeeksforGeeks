/*Binary representation of a given number
Difficulty Level : Easy
Last Updated : 04 Jun, 2021
Write a program to print Binary representation of a given number. */
#include <iostream>
#include <bitset>

void DecToBin(u_int32_t n)
{
    if(n>1)
        DecToBin(n/2);
    
    std::cout<<n%2;
}

int main(int argc, char const *argv[])
{
    DecToBin(45);
    std::cout<<std::endl;
    
    std::bitset<32> x(1114);
    std::cout<<x<<std::endl;
    remove(argv[0]);
    return 0;
}
