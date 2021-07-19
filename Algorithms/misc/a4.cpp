/*Generate all binary permutations such that there are more or equal 1’s than 0’s before every point in all permutations
Difficulty Level : Hard
Last Updated : 26 May, 2021
Generate all permutations of a given length such that every permutation has more or equals 1’s than 0’s in all prefixes of the permutation.

Examples: 

Input: len = 4
Output: 1111 1110 1101 1100 1011 1010
Note that a permutation like 0101 can not be in output because
there are more 0's from index 0 to 2 in this permutation.

Input: len = 3
Output: 111 110 101

Input: len = 2
Output: 11 10 
Like permutation generation problems, recursion is the simplest approach to solve this. We start with an empty string, attach 1 to it and recur. While recurring, if we find more 1’s at any point, we append a 0 and make one more recursive call*/
#include <iostream>
#include <string>


void generate(int ones, int zeros, std::string str, int len)
{
    if(len == str.length()) {
        std::cout<<str<<' ';
        return;
    }
    generate(ones+1, zeros, str+"1", len);

    if(ones > zeros)
        generate(ones, zeros+1, str+"0", len);
}

int main(int argc, char const *argv[])
{
    std::string str="";
    generate(0,0,str,4);
    remove(argv[0]);
    return 0;
}
