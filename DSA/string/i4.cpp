/*Program to check for ISBN

An ISBN (International Standard Book Number) is a 10 digit number that is used to identify a book.
The first nine digits of the ISBN number are used to represent the Title, Publisher and Group of the book and the last digit is used for checking whether ISBN is correct or not.
The first 9 digits of it, can take any value between 0 and 9, but the last digits, sometimes may take value equal to 10; this is done by writing it as ‘X’.

To verify an ISBN, calculate 10 times the first digit, plus 9 times the second digit, plus 8 times the third digit and so on until we add 1 time the last digit. If the final number leaves no remainder when divided by 11, the code is a valid ISBN.

Examples : 

Input : 007462542X
Output : Valid
007462542X = 10*0 + 9*0 + 8*7 + 7*4 + 6*6 + 
        5*2 + 4*5 + 3*4 + 2*2 + 1*10 = 176
Since 55 leaves no remainder when divided 
by 11, hence it is a valid ISBN.

Input : 0112112425
Output : Invalid
0112112425 = 10*0 + 9*1 + 8*1 + 7*2 + 6*1 +
           5*1 + 4*1 + 3*4 + 2*2 + 1*5 = 71
Since 71 is not divisible by 11, given number
is not a valid ISBN.
Now, we design a program to accept a ten digit code from the user and then we will check whether a number is ISBN or not. Display an appropriate message.*/
#include <iostream>
using namespace std;

bool isValidISBN(string x)
{
    if(x.length()!=10)  return false;
    int mul=10;
    int sum=0;
    int i;
    // not counnting the last digit
    for(i=0;i<x.length()-1;i++, mul--)
    {
        if(!isdigit(x[i]))  return false;
        int digit = x[i]-'0';
        sum+=(digit*mul);
    }
    if(x[i]=='X')   sum += 10*mul;
    else    sum+=mul*(x[i]-'0');
    cout<<sum<<endl;
    return (sum%11==0)? true:false;
}

int main(){
    string num="007462542X";
    cout<<((isValidISBN(num))?"Valid":"InValid")<<endl;
    num="0112112425";
    cout<<((isValidISBN(num))?"Valid":"InValid")<<endl;
    return 0;
}