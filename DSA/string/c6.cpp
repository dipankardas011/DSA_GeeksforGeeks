/*Case conversion (Lower to Upper and Vice Versa) of a string using BitWise operators in C/C++
Difficulty Level : Medium
Last Updated : 28 Aug, 2018
Given a string, write a function that converts it either from lower to upper case or from upper to lower case using the bitwise operators &(AND), |(OR), ~(NOT) in place and returns the string.

Many of us know that Bitwise manipulations are faster than performing arithmetic operations for a compiler as the data is stored in binary form 0’s and 1’s.

Examples:

Input : "LowerToUpPer"
Output : "LOWERTOUPPER"
   Letters already in the uppercase remains the same. 
   while rest get converted to uppercase.

Input : "UPPerTOloweR"
Output : "uppertolower"
   Letters already in the lowercase remains the same.
   while rest get converted to lowercase.*/
#include <iostream>
using namespace std;
#define x 32
/*Lower to Upper Case
This method simply subtracts a value of 32 from the ASCII value of lowercase letter by Bitwise ANDing (&) with negation (~) of 32 converting the letter to uppercase.*/
char *toUpperCase(char *a){
    for(int i=0;a[i]!='\0';i++)
        a[i]=a[i]&~x;
    return a;
}
/*Upper to Lower Case
Similarly, it adds a value of 32 to the ASCII value of uppercase letter by Bitwise ORing (|) with 32 converting the letter to lowercase.*/
char *toLowerCase(char *a){
    for(int i=0;a[i]!='\0';i++)
        a[i]=a[i]|x;
    return a;
}

int main(int argc, char const *argv[]){
    char s1[]="SanjaYKannA";
    cout<<toUpperCase(s1)<<endl;

    char s2[]="SanjaYKannA";
    cout<<toLowerCase(s2)<<endl;
    return 0;
}
