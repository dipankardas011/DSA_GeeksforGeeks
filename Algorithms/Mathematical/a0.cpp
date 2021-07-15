/*Write a program to add two numbers in base 14
Difficulty Level : Medium
Last Updated : 10 Jun, 2021
Asked by Anshya.
Below are the different ways to add base 14 numbers.
Method 1 
Thanks to Raj for suggesting this method. 

  1. Convert both i/p base 14 numbers to base 10.
  2. Add numbers.
  3. Convert the result back to base 14.
Method 2 
Just add the numbers in base 14 in the same way we add in base 10. Add numerals of both numbers one by one from right to left. If there is a carry while adding two numerals, consider the carry for adding the next numerals.
Let us consider the presentation of base 14 numbers same as hexadecimal numbers  

   A --> 10
   B --> 11
   C --> 12
   D --> 13
Example:
   num1 =       1  2  A
   num2 =       C  D  3   

   1. Add A and 3, we get 13(D). Since 13 is smaller than 
14, carry becomes 0 and resultant numeral becomes D         

  2. Add 2, D and carry(0). we get 15. Since 15 is greater 
than 13, carry becomes 1 and resultant numeral is 15 - 14 = 1

  3. Add 1, C and carry(1). we get 14. Since 14 is greater 
than 13, carry becomes 1 and resultant numeral is 14 - 14 = 0

Finally, there is a carry, so 1 is added as leftmost numeral and the result becomes 
101D */
#include <bits/stdc++.h>
#define bool int

int getNumeralValue(char ch)
{
    if (ch >= '0' && ch <= '9')
        return (ch - '0');
    if (ch >= 'A' && ch <= 'D')
        return (ch - 'A' + 10);

    /* If we reach this line caller is giving
    invalid character so we assert and fail*/
    assert(0);
}

char getNumeral(int val)
{ // back convertion to char
    if (val >= 0 && val <= 9)
        return (val + '0');
    if (val >= 10 && val <= 14)
        return (val + 'A' - 10);

    assert(0);
}

char *sumBase14(char num1[], char num2[])
{
    int l1 = strlen(num1);
    int l2 = strlen(num2);
    char *res;
    int i;
    
    int nml1, nml2, res_nml;
    bool carry = 0;
    if (l1 != l2)
    {
        std::cout << "Different length number is NOT SUPPORTED⚠" << std::endl;
        assert(0);
    }
    /* Note the size of the allocated memory is one
        more than i/p lengths for the cases where we
        have carry at the last like adding D1 and A1 */
    res = new char[(sizeof(char) * (l1 + 1))];

    for(i=l1-1;i>=0 ;i--) {
        nml1=getNumeralValue(num1[i]);
        nml2=getNumeralValue(num2[i]);
        res_nml=nml1+nml2+carry;

        if(res_nml>=14) {
            carry=1;
            res_nml -=14;
        }else{
            carry=0;
        }
        res[i+1]=getNumeral(res_nml);
    }
    /* if there is no carry after last iteration
        then result should not include 0th character
        of the resultant string */
    if(carry==0)
        return (res+1);
        
    /* if we have carry after last iteration then
        result should include 0th character */
    res[0]='1';
    return res;
}

int main(int argc, char const *argv[])
{
    char num1[] = "DC2";
    char num2[] = "0A3";
    std::cout << "result " << sumBase14(num1, num2) << std::endl;
    remove(argv[0]);
    return 0;
}
