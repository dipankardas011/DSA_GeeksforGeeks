/*Program for credit card number validation
Difficulty Level : Medium
Last Updated : 16 Feb, 2021
Write a program that prompts the user to enter a credit card number as a long integer and Display whether that card is valid or invalid.
Credit card numbers follow certain patterns. 
A credit card number must have between 13 and 16 digits. It must start with:
 

4 for Visa cards
5 for Master cards
37 for American Express cards
6 for Discover cards
The problem can be solved by using Luhn algorithm. 
Luhn check or the Mod 10 check, which can be described as follows (for illustration, 
consider the card number 4388576018402626):
Step 1. Double every second digit from right to left. If doubling of a digit results in a 
two-digit number, add up the two digits to get a single-digit number (like for 12:1+2, 18=1+8).
Step 2. Now add all single-digit numbers from Step 1. 
4 + 4 + 8 + 2 + 3 + 1 + 7 + 8 = 37
Step 3. Add all digits in the odd places from right to left in the card number. 
6 + 6 + 0 + 8 + 0 + 7 + 8 + 3 = 38
Step 4. Sum the results from Step 2 and Step 3. 
37 + 38 = 75
Step 5. If the result from Step 4 is divisible by 10, the card number is valid; otherwise, it is invalid. 
Examples : 
 

Input : 379354508162306
Output : 379354508162306 is Valid

Input : 4388576018402626
Output : 4388576018402626 is invalid*/
/**
 * length() must be 13<len<16
 * we need to check the startsWith()
 * in even places 2* and add if >9 then sum of digits
 * in odd places sum 
 * then (even+odd)%10 == 0 valid else invalid
 */
#include <iostream>
#include <string>
#include <cstring>
using namespace std;


int sumOfDigits(int num)
{
    int i=num;
    int sum=0;
    while(i>0){
        sum+=i%10;
        i/=10;
    }
    return sum;
}

bool startWith(string str){
    if(str[0]=='4') return true;
    else if(str[0]=='5')    return true;
    else if(str[0]=='6')    return true;
    else if(str[0]=='3' && str[1]=='7')  return true;
    else
        return false;

}

int sumEven(string str){
    int sum=0;
    for(int i=str.length()-2;i>=0;i-=2)
    {
        int digit=str[i]-'0';
        digit*=2;
        if(digit>9)
            sum+=sumOfDigits(digit);
        else    
            sum+=digit;
    }
    return sum;
}

int sumOdd(string str){
    int sum=0;
    for(int i=str.length()-1;i>=0;i-=2)
    {
        sum+=str[i]-'0';
    }
    return sum;
}

bool isValidCreditCardNumber(string str){
    
    if(startWith(str) && (str.length()>=13 && str.length()<=16)
        && (sumEven(str)+sumOdd(str))%10==0)
        return true;
    return false;
} 

int main(){
    string n="379354508162306";
    cout<<((isValidCreditCardNumber(n))?"Valid":"InValid")<<endl;
    n="4388576018402626";
    cout<<((isValidCreditCardNumber(n))?"Valid":"InValid")<<endl;
    return 0;
}