/*Position of rightmost set bit
Difficulty Level : Medium
Last Updated : 09 Jun, 2021
Write a one line function to return position of first 1 from right to left, in binary representation of an Integer. 

I/P    18,   Binary Representation 010010
O/P   2
I/P    19,   Binary Representation 010011
O/P   1 
Algorithm: (Example 12(1100))
Let I/P be 12 (1100)
1. Take two’s complement of the given no as all bits are reverted
except the first ‘1’ from right to left (0100)
2  Do a bit-wise & with original no, this will return no with the
required one only (0100)
3  Take the log2 of the no, you will get (position – 1) (2)
4  Add 1 (3)

Explanation –

(n&~(n-1)) always return the binary number containing rightmost set bit as 1.

if N = 12 (1100) then it will return 4 (100) */
#include <iostream>
#include <cmath>
#include <chrono>

u_int32_t getFirstSetBitPos(int n)
{
    return log2(n & -n)+1;
}

u_int32_t positionRightMostBit(int n)
{
    u_int32_t position=1;
    int m=1;

    while(!(n&m)) {
        m <<= 1;
        position++;
    }
    return position;
}

int main(int argc, char const *argv[])
{
    int n=12;
    // clock_t begin, end;
    // double time_spent;
    // begin=clock();
    // end=clock();
    // time_spent = (double)(end-begin)/CLOCKS_PER_SEC;


    auto start=std::chrono::high_resolution_clock::now();
    std::cout<<"Pos = "<<getFirstSetBitPos(n)<<std::endl;
    auto end=std::chrono::high_resolution_clock::now();
    auto duration=std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
    std::cout<<duration.count()<<" ms"<<std::endl;
    //--------------------------------------------

    start=std::chrono::high_resolution_clock::now();
    std::cout<<"Pos = "<<positionRightMostBit(n)<<std::endl;
    end=std::chrono::high_resolution_clock::now();

    duration=std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
    std::cout<<duration.count()<<" ms"<<std::endl;
    remove(argv[0]);
    return 0;
}
