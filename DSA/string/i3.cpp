/*Program to check for a Valid IMEI Number
Difficulty Level : Easy
Last Updated : 02 Jun, 2021
International Mobile Equipment Identity (IMEI) is a number, usually unique, to identify mobile phones, as well as some satellite phones. It is usually found printed inside the battery compartment of the phone, but can also be displayed on-screen on most phones by entering *#06# on the dialpad, or alongside other system information in the settings menu on smartphone operating systems. The IMEI number is used by a GSM network to identify valid devices and therefore can be used for stopping a stolen phone from accessing that network. 
Source: Wikipedia
The IMEI (15 decimal digits: 14 digits plus a check digit) includes information on the origin, model, and serial number of the device. 
The IMEI is validated in following steps: 
 

Starting from the rightmost digit, double the value of every second digit (e.g., 7 becomes 14).
If doubling of a number results in a two digits number i.e greater than 9(e.g., 7 × 2 = 14), then add the digits of the product (e.g., 14: 1 + 4 = 5), to get a single digit number.
Now take the sum of all the digits.
Check if the sum is divisible by 10 i.e.(total modulo 10 is equal to 0) then the IMEI number is valid; else it is not valid.
Example:

Input IMEI : 490154203237518


Output : Since, 60 is divisible by 10, hence the given IMEI number is Valid.*/
#include <string>
#include <iostream>
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

bool isValidIMEI(string str){
    int len=str.length();

    int sum=0;
    if(len!=15) return false;
    // from the right -> left
    for(int i=0;i<len;i++)
    {
        if(!isdigit(str[i]))    return false;
        if((i+1)%2==0)//double the num
        {
            int n=str[i]-'0';
            n=2*n;
            if(n>9)
                sum+=sumOfDigits(n);
            else
                sum+=n;
        }
        else{
            sum+=(str[i]-'0');
        }
    }
    if(sum%10==0)   return true;
    else    return false;
}

int main(){
    string num="490154203237518";
    cout<<((isValidIMEI(num))?"Valid":"InValid")<<endl;
    return 0;
}